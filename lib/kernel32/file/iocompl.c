/* $Id: iocompl.c,v 1.5 2002/09/07 15:12:26 chorns Exp $
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS system libraries
 * FILE:            lib/kernel32/file/iocompl.c
 * PURPOSE:         Io Completion functions
 * PROGRAMMER:      Ariadne ( ariadne@xs4all.nl)
 * UPDATE HISTORY:
 *                  Created 01/11/98
 */

#include <windows.h>
#define NTOS_USER_MODE
#include <ntos.h>
#include <wchar.h>
#include <kernel32/error.h>


VOID
STDCALL
FileIOCompletionRoutine(
	DWORD dwErrorCode,
	DWORD dwNumberOfBytesTransfered,
	LPOVERLAPPED lpOverlapped
	);


HANDLE
STDCALL
CreateIoCompletionPort(
    HANDLE FileHandle,
    HANDLE ExistingCompletionPort,
    DWORD CompletionKey,
    DWORD NumberOfConcurrentThreads
    )
{
	HANDLE CompletionPort = NULL;
	NTSTATUS errCode;
	FILE_COMPLETION_INFORMATION CompletionInformation;
	IO_STATUS_BLOCK IoStatusBlock;

        if ( ExistingCompletionPort == NULL && FileHandle == INVALID_HANDLE_VALUE ) {
                SetLastErrorByStatus (STATUS_INVALID_PARAMETER);
                return FALSE;
        }

        if ( ExistingCompletionPort != NULL ) {
                CompletionPort = ExistingCompletionPort;
	}
	else {
                errCode = NtCreateIoCompletion(&CompletionPort,GENERIC_ALL,&IoStatusBlock,NumberOfConcurrentThreads);
                if (!NT_SUCCESS(errCode) ) {
                        SetLastErrorByStatus (errCode);
                        return FALSE;
                }

        }
        if ( FileHandle != INVALID_HANDLE_VALUE ) {

		CompletionInformation.Port = CompletionPort;
                CompletionInformation.Key  = CompletionKey;

                errCode = NtSetInformationFile(FileHandle, &IoStatusBlock,&CompletionInformation,sizeof(FILE_COMPLETION_INFORMATION),FileCompletionInformation);
                if ( !NT_SUCCESS(errCode) ) {
			if ( ExistingCompletionPort == NULL )
                        	NtClose(CompletionPort);
                        SetLastErrorByStatus (errCode);
                        return FALSE;
                }
        }

        return CompletionPort;
}


WINBOOL
STDCALL
GetQueuedCompletionStatus(
			  HANDLE CompletionPort,
			  LPDWORD lpNumberOfBytesTransferred,
			  LPDWORD lpCompletionKey,
			  LPOVERLAPPED *lpOverlapped,
			  DWORD dwMilliseconds
			  )
{
	NTSTATUS errCode;
	ULONG CompletionStatus;
	LARGE_INTEGER TimeToWait;

	errCode = NtRemoveIoCompletion(CompletionPort,(PULONG)lpCompletionKey,(PIO_STATUS_BLOCK)lpOverlapped,&CompletionStatus,&TimeToWait);
	if (!NT_SUCCESS(errCode) ) {
		SetLastErrorByStatus (errCode);
		return FALSE;
	}

	return TRUE;
}


WINBOOL
STDCALL
PostQueuedCompletionStatus(
  HANDLE CompletionPort,
  DWORD dwNumberOfBytesTransferred,
  DWORD dwCompletionKey,
  LPOVERLAPPED lpOverlapped
)
{
	NTSTATUS errCode;
	errCode = NtSetIoCompletion(CompletionPort,  dwCompletionKey, (PIO_STATUS_BLOCK)lpOverlapped , 0, (PULONG)&dwNumberOfBytesTransferred );

	if ( !NT_SUCCESS(errCode) ) {
		SetLastErrorByStatus (errCode);
		return FALSE;
	}
	return TRUE;
}


// this should be a place holder ??????????????????
VOID
STDCALL
FileIOCompletionRoutine(
	DWORD dwErrorCode,
	DWORD dwNumberOfBytesTransfered,
	LPOVERLAPPED lpOverlapped
	)
{
	return;
}


/* EOF */
