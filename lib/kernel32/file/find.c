/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS system libraries
 * FILE:            lib/kernel32/file/find.c
 * PURPOSE:         Find functions
 * PROGRAMMER:      Ariadne ( ariadne@xs4all.nl)
 * UPDATE HISTORY:
 *                  Created 01/11/98
 */

/* INCLUDES *****************************************************************/

#include <windows.h>
#include <wstring.h>
#include <ddk/ntddk.h>

#define NDEBUG
#include <kernel32/kernel32.h>

/* TYPES ********************************************************************/

typedef struct _KERNEL32_FIND_FILE_DATA
{
   HANDLE DirectoryHandle;
   FILE_BOTH_DIRECTORY_INFORMATION FileInfo;
   WCHAR FileNameExtra[MAX_PATH];
   UNICODE_STRING PatternStr;
} KERNEL32_FIND_FILE_DATA, *PKERNEL32_FIND_FILE_DATA;

typedef struct _WIN32_FIND_DATA_UNICODE {
  DWORD dwFileAttributes; 
  FILETIME ftCreationTime; 
  FILETIME ftLastAccessTime; 
  FILETIME ftLastWriteTime; 
  DWORD    nFileSizeHigh; 
  DWORD    nFileSizeLow; 
  DWORD    dwReserved0; 
  DWORD    dwReserved1; 
  WCHAR    cFileName[ MAX_PATH ]; 
  WCHAR    cAlternateFileName[ 14 ]; 
} WIN32_FIND_DATA_UNICODE, *PWIN32_FIND_DATA_UNICODE; 

typedef struct _WIN32_FIND_DATA_ASCII { 
  DWORD dwFileAttributes; 
  FILETIME ftCreationTime; 
  FILETIME ftLastAccessTime; 
  FILETIME ftLastWriteTime; 
  DWORD    nFileSizeHigh; 
  DWORD    nFileSizeLow; 
  DWORD    dwReserved0; 
  DWORD    dwReserved1; 
  CHAR    cFileName[ MAX_PATH ]; 
  CHAR    cAlternateFileName[ 14 ]; 
} WIN32_FIND_DATA_ASCII, *PWIN32_FIND_DATA_ASCII; 


/* FUNCTIONS *****************************************************************/

WINBOOL STDCALL InternalFindNextFile(HANDLE hFindFile,
                                     LPWIN32_FIND_DATA lpFindFileData)
{
   IO_STATUS_BLOCK IoStatusBlock;
   NTSTATUS Status;
   PKERNEL32_FIND_FILE_DATA IData;
   
   IData = (PKERNEL32_FIND_FILE_DATA)hFindFile;
   
   Status = NtQueryDirectoryFile(IData->DirectoryHandle,
                                 NULL,
                                 NULL,
                                 NULL,
                                 &IoStatusBlock,
                                 (PVOID)&IData->FileInfo,
                                 sizeof(IData->FileInfo) +
                                 sizeof(IData->FileNameExtra),
                                 FileBothDirectoryInformation,
                                 TRUE,
                                 &(IData->PatternStr),
                                 FALSE);
   DPRINT("Found %w\n",IData->FileInfo.FileName);
   lpFindFileData->dwFileAttributes = IData->FileInfo.FileAttributes;
   if (Status != STATUS_SUCCESS)
   {
        return(FALSE);
   }
   return(TRUE);
}

static FileDataToWin32Data(LPWIN32_FIND_DATA lpFindFileData
                            ,PKERNEL32_FIND_FILE_DATA IData)
{
 int i;
   lpFindFileData->dwFileAttributes = IData->FileInfo.FileAttributes;
//   memcpy(&lpFindFileData->ftCreationTime,&IData->FileInfo.CreationTime,sizeof(FILETIME));
//   memcpy(&lpFindFileData->ftLastAccessTime,&IData->FileInfo.LastAccessTime,sizeof(FILETIME));
//   memcpy(&lpFindFileData->ftLastWriteTime,&IData->FileInfo.LastWriteTime,sizeof(FILETIME));
   lpFindFileData->nFileSizeHigh = IData->FileInfo.EndOfFile>>32;
   lpFindFileData->nFileSizeLow = IData->FileInfo.EndOfFile;
   for (i=0; i<IData->FileInfo.FileNameLength; i++)
   {
        lpFindFileData->cFileName[i] = IData->FileInfo.FileName[i];
   }
   lpFindFileData->cFileName[i] = 0;
   for(i=0;i<IData->FileInfo.ShortNameLength;i++)
   {
      lpFindFileData->cAlternateFileName[i] = IData->FileInfo.ShortName[i];
   }
   lpFindFileData->cAlternateFileName[i] = 0;
}

HANDLE STDCALL InternalFindFirstFile(LPCWSTR lpFileName, 
                                      LPWIN32_FIND_DATA lpFindFileData)
{
   WCHAR CurrentDirectory[MAX_PATH];
   WCHAR Pattern[MAX_PATH];
   WCHAR Directory[MAX_PATH];
   PWSTR End;
   PKERNEL32_FIND_FILE_DATA IData;
   OBJECT_ATTRIBUTES ObjectAttributes;
   UNICODE_STRING DirectoryNameStr;
   IO_STATUS_BLOCK IoStatusBlock;
   
   DPRINT("FindFirstFileW(lpFileName %w, lpFindFileData %x)\n",
	   lpFileName, lpFindFileData);
   
   GetCurrentDirectoryW(MAX_PATH, CurrentDirectory);
   Directory[0] = '\\';
   Directory[1] = '?';
   Directory[2] = '?';
   Directory[3] = '\\';
   Directory[4] = 0;
   DPRINT("Directory %w\n",Directory);
   wcscat(Directory, CurrentDirectory);
   DPRINT("Directory %w\n",Directory);
   wcscat(Directory, lpFileName);
   DPRINT("Directory %w\n",Directory);
   End = wcsrchr(Directory, '\\');
   *End = 0;
   
   wcscpy(Pattern, End+1);
   *(End+1) = 0;
   *End = '\\';
   
   DPRINT("Directory %w Pattern %w\n",Directory,Pattern);
   
   IData = HeapAlloc(GetProcessHeap(), 
		     HEAP_ZERO_MEMORY, 
		     sizeof(KERNEL32_FIND_FILE_DATA));
   
   RtlInitUnicodeString(&DirectoryNameStr, Directory);
   InitializeObjectAttributes(&ObjectAttributes,
			      &DirectoryNameStr,
			      0,
			      NULL,
			      NULL);
   
   if (ZwOpenFile(&IData->DirectoryHandle,
		  FILE_LIST_DIRECTORY,
		  &ObjectAttributes,
		  &IoStatusBlock,
          FILE_OPEN_IF,
		  OPEN_EXISTING)!=STATUS_SUCCESS)
     {
	return(NULL);
     }
   
   RtlInitUnicodeString(&(IData->PatternStr), Pattern);
   
   NtQueryDirectoryFile(IData->DirectoryHandle,
			NULL,
			NULL,
			NULL,
			&IoStatusBlock,
			(PVOID)&IData->FileInfo,
			sizeof(IData->FileInfo) +
			sizeof(IData->FileNameExtra),
			FileBothDirectoryInformation,
			TRUE,
                        &(IData->PatternStr),
			FALSE);
   DPRINT("Found %w\n",IData->FileInfo.FileName);
   

   return(IData);
}

HANDLE FindFirstFileA(LPCTSTR lpFileName, LPWIN32_FIND_DATA lpFindFileData)
{
   WCHAR lpFileNameW[MAX_PATH];
   ULONG i;
   PKERNEL32_FIND_FILE_DATA IData;
   PWIN32_FIND_DATA_ASCII Ret;

   i = 0;
   while (lpFileName[i]!=0)
     {
        lpFileNameW[i] = lpFileName[i];
	i++;
     }
   lpFileNameW[i] = 0;
   
   IData = InternalFindFirstFile(lpFileNameW,lpFindFileData);
   if (IData == NULL)
     {
	DPRINT("Failing request\n");
	return(NULL);
     }
   FileDataToWin32Data(lpFindFileData,IData);

   
   return(IData);
}

WINBOOL FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATA lpFindFileData)
{
   PWIN32_FIND_DATA_ASCII Ret;
   PKERNEL32_FIND_FILE_DATA IData;
   ULONG i;

   IData = (PKERNEL32_FIND_FILE_DATA)hFindFile;   
   if (IData == NULL)
     {
	return(FALSE);
     }
   if (!InternalFindNextFile(hFindFile, lpFindFileData))
   {
        return(FALSE);
   }

   Ret = (PWIN32_FIND_DATA_ASCII)lpFindFileData;
   FileDataToWin32Data(lpFindFileData,IData);
   return(TRUE);
}

BOOL FindClose(HANDLE hFindFile)
{
   PKERNEL32_FIND_FILE_DATA IData;
   
   dprintf("FindClose(hFindFile %x)\n",hFindFile);
   
   IData = (PKERNEL32_FIND_FILE_DATA)hFindFile;
   NtClose(IData->DirectoryHandle);
   HeapFree(GetProcessHeap(), 0, IData);
   return(TRUE);
}

HANDLE STDCALL FindFirstFileW(LPCWSTR lpFileName, 
			      LPWIN32_FIND_DATA lpFindFileData)
{
   PWIN32_FIND_DATA_UNICODE Ret;
   PKERNEL32_FIND_FILE_DATA IData;
   int i;

   IData = InternalFindFirstFile(lpFileName,lpFindFileData);
   Ret = (PWIN32_FIND_DATA_UNICODE)lpFindFileData;
   FileDataToWin32Data(lpFindFileData,IData);

   for (i=0; i<IData->FileInfo.FileNameLength; i++)
   {
        Ret->cFileName[i] = IData->FileInfo.FileName[i];
   }
   Ret->cFileName[i] = 0;
   for(i=0;i<IData->FileInfo.ShortNameLength;i++)
   {
      Ret->cAlternateFileName[i] = IData->FileInfo.ShortName[i];
   }

   return(IData);
}

WINBOOL STDCALL FindNextFileW(HANDLE hFindFile,
			      LPWIN32_FIND_DATA lpFindFileData)
{
   PWIN32_FIND_DATA_UNICODE Ret;
   PKERNEL32_FIND_FILE_DATA IData;
   int i;

   IData = (PKERNEL32_FIND_FILE_DATA)hFindFile;   
   if (!InternalFindNextFile(hFindFile, lpFindFileData))
   {
        return(FALSE);
   }

   Ret = (PWIN32_FIND_DATA_UNICODE)lpFindFileData;
   FileDataToWin32Data(lpFindFileData,IData);

   for (i=0; i<IData->FileInfo.FileNameLength; i++)
   {
        Ret->cFileName[i] = IData->FileInfo.FileName[i];
   }
   Ret->cFileName[i] = 0;
   for(i=0;i<IData->FileInfo.ShortNameLength;i++)
   {
      Ret->cAlternateFileName[i] = IData->FileInfo.ShortName[i];
   }

   return(TRUE);
}
