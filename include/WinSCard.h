/*
 * WinSCard.h
 *
 * SmartCard API
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __WINSCARD_H
#define __WINSCARD_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <WinSmCrd.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SCARD_S_SUCCESS                 NO_ERROR

#define SCARD_F_INTERNAL_ERROR          ((DWORD)0x80100001)
#define SCARD_E_CANCELLED               ((DWORD)0x80100002)
#define SCARD_E_INVALID_HANDLE          ((DWORD)0x80100003)
#define SCARD_E_INVALID_PARAMETER       ((DWORD)0x80100004)
#define SCARD_E_INVALID_TARGET          ((DWORD)0x80100005)
#define SCARD_E_NO_MEMORY               ((DWORD)0x80100006)
#define SCARD_F_WAITED_TOO_LONG         ((DWORD)0x80100007)
#define SCARD_E_INSUFFICIENT_BUFFER     ((DWORD)0x80100008)
#define SCARD_E_UNKNOWN_READER          ((DWORD)0x80100009)
#define SCARD_E_TIMEOUT                 ((DWORD)0x8010000A)
#define SCARD_E_SHARING_VIOLATION       ((DWORD)0x8010000B)
#define SCARD_E_NO_SMARTCARD            ((DWORD)0x8010000C)
#define SCARD_E_UNKNOWN_CARD            ((DWORD)0x8010000D)
#define SCARD_E_CANT_DISPOSE            ((DWORD)0x8010000E)
#define SCARD_E_PROTO_MISMATCH          ((DWORD)0x8010000F)
#define SCARD_E_NOT_READY               ((DWORD)0x80100010)
#define SCARD_E_INVALID_VALUE           ((DWORD)0x80100011)
#define SCARD_E_SYSTEM_CANCELLED        ((DWORD)0x80100012)
#define SCARD_F_COMM_ERROR              ((DWORD)0x80100013)
#define SCARD_F_UNKNOWN_ERROR           ((DWORD)0x80100014)
#define SCARD_E_INVALID_ATR             ((DWORD)0x80100015)
#define SCARD_E_NOT_TRANSACTED          ((DWORD)0x80100016)
#define SCARD_E_READER_UNAVAILABLE      ((DWORD)0x80100017)
#define SCARD_P_SHUTDOWN                ((DWORD)0x80100018)
#define SCARD_E_PCI_TOO_SMALL           ((DWORD)0x80100019)
#define SCARD_E_READER_UNSUPPORTED      ((DWORD)0x8010001A)
#define SCARD_E_DUPLICATE_READER        ((DWORD)0x8010001B)
#define SCARD_E_CARD_UNSUPPORTED        ((DWORD)0x8010001C)
#define SCARD_E_NO_SERVICE              ((DWORD)0x8010001D)
#define SCARD_E_SERVICE_STOPPED         ((DWORD)0x8010001E)
#define SCARD_E_UNEXPECTED              ((DWORD)0x8010001F)
#define SCARD_E_ICC_INSTALLATION        ((DWORD)0x80100020)
#define SCARD_E_ICC_CREATEORDER         ((DWORD)0x80100021)
#define SCARD_E_UNSUPPORTED_FEATURE     ((DWORD)0x80100022)
#define SCARD_E_DIR_NOT_FOUND           ((DWORD)0x80100023)
#define SCARD_E_FILE_NOT_FOUND          ((DWORD)0x80100024)
#define SCARD_E_NO_DIR                  ((DWORD)0x80100025)
#define SCARD_E_NO_FILE                 ((DWORD)0x80100026)
#define SCARD_E_NO_ACCESS               ((DWORD)0x80100027)
#define SCARD_E_WRITE_TOO_MANY          ((DWORD)0x80100028)
#define SCARD_E_BAD_SEEK                ((DWORD)0x80100029)
#define SCARD_E_INVALID_CHV             ((DWORD)0x8010002A)
#define SCARD_E_UNKNOWN_RES_MNG         ((DWORD)0x8010002B)
#define SCARD_E_NO_SUCH_CERTIFICATE     ((DWORD)0x8010002C)
#define SCARD_E_CERTIFICATE_UNAVAILABLE ((DWORD)0x8010002D)
#define SCARD_E_NO_READERS_AVAILABLE    ((DWORD)0x8010002E)
#define SCARD_E_COMM_DATA_LOST          ((DWORD)0x8010002F)
#define SCARD_E_NO_KEY_CONTAINER        ((DWORD)0x80100030)
#define SCARD_W_UNSUPPORTED_CARD        ((DWORD)0x80100065)
#define SCARD_W_UNRESPONSIVE_CARD       ((DWORD)0x80100066)
#define SCARD_W_UNPOWERED_CARD          ((DWORD)0x80100067)
#define SCARD_W_RESET_CARD              ((DWORD)0x80100068)
#define SCARD_W_REMOVED_CARD            ((DWORD)0x80100069)
#define SCARD_W_SECURITY_VIOLATION      ((DWORD)0x8010006A)
#define SCARD_W_WRONG_CHV               ((DWORD)0x8010006B)
#define SCARD_W_CHV_BLOCKED             ((DWORD)0x8010006C)
#define SCARD_W_EOF                     ((DWORD)0x8010006D)
#define SCARD_W_CANCELLED_BY_USER       ((DWORD)0x8010006E)
#define SCARD_W_CARD_NOT_AUTHENTICATED  ((DWORD)0x8010006F)

#define SCARD_SHARE_EXCLUSIVE (0x1)
#define SCARD_SHARE_SHARED    (0x2)
#define SCARD_SHARE_DIRECT    (0x3)

#define SCARD_LEAVE_CARD   (0x0)
#define SCARD_RESET_CARD   (0x1)
#define SCARD_UNPOWER_CARD (0x2)
#define SCARD_EJECT_CARD   (0x3)

#define SCARD_AUTOALLOCATE   ((DWORD)-1)
#define SCARD_SCOPE_USER     (0x0)
#define SCARD_SCOPE_TERMINAL (0x1)
#define SCARD_SCOPE_SYSTEM   (0x2)

#define SCARD_PROVIDER_PRIMARY (0x1)
#define SCARD_PROVIDER_CSP     (0x2)

typedef ULONG_PTR SCARDCONTEXT, *PSCARDCONTEXT, *LPSCARDCONTEXT;
typedef ULONG_PTR SCARDHANDLE, *PSCARDHANDLE, *LPSCARDHANDLE;
typedef const BYTE *LPCBYTE;

typedef struct _SCARD_READERSTATEA
{
  LPCSTR szReader;
  LPVOID pvUserData;
  DWORD dwCurrentState;
  DWORD dwEventState;
  DWORD cbAtr;
  BYTE rgbAtr[36];
} SCARD_READERSTATEA, *PSCARD_READERSTATEA, *LPSCARD_READERSTATEA;

typedef struct _SCARD_READERSTATEW
{
  LPCWSTR szReader;
  LPVOID pvUserData;
  DWORD dwCurrentState;
  DWORD dwEventState;
  DWORD cbAtr;
  BYTE rgbAtr[36];
} SCARD_READERSTATEW, *PSCARD_READERSTATEW, *LPSCARD_READERSTATEW;

typedef struct _SCARD_ATRMASK
{
  DWORD cbAtr;
  BYTE rgbAtr[36];
  BYTE rgbMask[36];
} SCARD_ATRMASK, *PSCARD_ATRMASK, *LPSCARD_ATRMASK;

HANDLE STDCALL SCardAccessStartedEvent(VOID);
LONG STDCALL SCardAddReaderToGroupA(SCARDCONTEXT, LPCSTR, LPCSTR);
LONG STDCALL SCardAddReaderToGroupW(SCARDCONTEXT, LPCWSTR, LPCWSTR);
LONG STDCALL SCardBeginTransaction(SCARDHANDLE);
LONG STDCALL SCardCancel(SCARDCONTEXT);
LONG STDCALL SCardConnectA(SCARDCONTEXT, LPCSTR, DWORD, DWORD, LPSCARDHANDLE, LPDWORD);
LONG STDCALL SCardConnectW(SCARDCONTEXT, LPCWSTR, DWORD, DWORD, LPSCARDHANDLE, LPDWORD);
LONG STDCALL SCardControl(SCARDHANDLE, DWORD, LPCVOID, DWORD, LPVOID, DWORD, LPDWORD);
LONG STDCALL SCardDisconnect(SCARDHANDLE, DWORD);
LONG STDCALL SCardEndTransaction(SCARDHANDLE, DWORD);
LONG STDCALL SCardEstablishContext(DWORD, LPCVOID, LPCVOID, LPSCARDCONTEXT);
LONG STDCALL SCardForgetCardTypeA(SCARDCONTEXT, LPCSTR);
LONG STDCALL SCardForgetCardTypeW(SCARDCONTEXT, LPCWSTR);
LONG STDCALL SCardForgetReaderA(SCARDCONTEXT, LPCSTR);
LONG STDCALL SCardForgetReaderW(SCARDCONTEXT, LPCWSTR);
LONG STDCALL SCardForgetReaderGroupA(SCARDCONTEXT, LPCSTR);
LONG STDCALL SCardForgetReaderGroupW(SCARDCONTEXT, LPCWSTR);
LONG STDCALL SCardFreeMemory(SCARDCONTEXT, LPCVOID);
LONG STDCALL SCardGetAttrib(SCARDHANDLE, DWORD, LPBYTE, LPDWORD);
LONG STDCALL SCardGetCardTypeProviderNameA(SCARDCONTEXT, LPCSTR, DWORD, LPSTR, LPDWORD);
LONG STDCALL SCardGetCardTypeProviderNameW(SCARDCONTEXT, LPCWSTR, DWORD, LPWSTR, LPDWORD);
LONG STDCALL SCardGetProviderIdA(SCARDCONTEXT, LPCSTR, LPGUID);
LONG STDCALL SCardGetProviderIdW(SCARDCONTEXT, LPCWSTR, LPGUID);
LONG STDCALL SCardGetStatusChangeA(SCARDCONTEXT, DWORD, LPSCARD_READERSTATEA, DWORD);
LONG STDCALL SCardGetStatusChangeW(SCARDCONTEXT, DWORD, LPSCARD_READERSTATEW, DWORD);
LONG STDCALL SCardIntroduceCardTypeA(SCARDCONTEXT, LPCSTR, LPCGUID, LPCGUID, DWORD, LPCBYTE, LPCBYTE, DWORD);
LONG STDCALL SCardIntroduceCardTypeW(SCARDCONTEXT, LPCWSTR, LPCGUID, LPCGUID, DWORD, LPCBYTE, LPCBYTE, DWORD);
LONG STDCALL SCardIntroduceReaderA(SCARDCONTEXT, LPCSTR, LPCSTR);
LONG STDCALL SCardIntroduceReaderW(SCARDCONTEXT, LPCWSTR, LPCWSTR);
LONG STDCALL SCardIntroduceReaderGroupA(SCARDCONTEXT, LPCSTR);
LONG STDCALL SCardIntroduceReaderGroupW(SCARDCONTEXT, LPCWSTR);
LONG STDCALL SCardIsValidContext(SCARDCONTEXT);
LONG STDCALL SCardListCardsA(SCARDCONTEXT, LPCBYTE, LPCGUID, DWORD, LPCSTR, LPDWORD);
LONG STDCALL SCardListCardsW(SCARDCONTEXT, LPCBYTE, LPCGUID, DWORD, LPCWSTR, LPDWORD);
LONG STDCALL SCardListInterfacesA(SCARDCONTEXT, LPCSTR, LPGUID, LPDWORD);
LONG STDCALL SCardListInterfacesW(SCARDCONTEXT, LPCWSTR, LPGUID, LPDWORD);
LONG STDCALL SCardListReaderGroupsA(SCARDCONTEXT, LPSTR, LPDWORD);
LONG STDCALL SCardListReaderGroupsW(SCARDCONTEXT, LPWSTR, LPDWORD);
LONG STDCALL SCardListReadersA(SCARDCONTEXT, LPCSTR, LPSTR, LPDWORD);
LONG STDCALL SCardListReadersW(SCARDCONTEXT, LPCWSTR, LPWSTR, LPDWORD);
LONG STDCALL SCardLocateCardsA(SCARDCONTEXT, LPCSTR, LPSCARD_READERSTATEA, DWORD);
LONG STDCALL SCardLocateCardsW(SCARDCONTEXT, LPCWSTR, LPSCARD_READERSTATEW, DWORD);
LONG STDCALL SCardLocateCardsByATRA(SCARDCONTEXT, LPSCARD_ATRMASK, DWORD, LPSCARD_READERSTATEA, DWORD);
LONG STDCALL SCardLocateCardsByATRW(SCARDCONTEXT, LPSCARD_ATRMASK, DWORD, LPSCARD_READERSTATEW, DWORD);
LONG STDCALL SCardReconnect(SCARDHANDLE, DWORD, DWORD, DWORD, LPDWORD);
LONG STDCALL SCardReleaseContext(SCARDCONTEXT);
VOID STDCALL SCardReleaseStartedEvent(HANDLE);
LONG STDCALL SCardRemoveReaderFromGroupA(SCARDCONTEXT, LPCSTR, LPCSTR);
LONG STDCALL SCardRemoveReaderFromGroupW(SCARDCONTEXT, LPCWSTR, LPCWSTR);
LONG STDCALL SCardSetAttrib(SCARDHANDLE, DWORD, LPCBYTE, DWORD);
LONG STDCALL SCardSetCardTypeProviderNameA(SCARDCONTEXT, LPCSTR, DWORD, LPCSTR);
LONG STDCALL SCardSetCardTypeProviderNameW(SCARDCONTEXT, LPCWSTR, DWORD, LPCWSTR);
LONG STDCALL SCardState(SCARDHANDLE, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
LONG STDCALL SCardStatusA(SCARDHANDLE, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
LONG STDCALL SCardStatusW(SCARDHANDLE, LPWSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
LONG STDCALL SCardTransmit(SCARDHANDLE, LPCSCARD_IO_REQUEST, LPCBYTE, DWORD, LPSCARD_IO_REQUEST, LPBYTE, LPDWORD);

#ifndef _DISABLE_TIDENTS

#ifdef UNICODE
typedef struct SCARD_READERSTATEW SCARD_READERSTATE, *PSCARD_READERSTATE, *LPSCARD_READERSTATE;
#define SCardAddReaderToGroup SCardAddReaderToGroupW
#define SCardConnect SCardConnectW
#define SCardForgetCardType SCardForgetCardTypeW
#define SCardForgetReader SCardForgetReaderW
#define SCardForgetReaderGroup SCardForgetReaderGroupW
#define SCardGetCardTypeProviderName SCardGetCardTypeProviderNameW
#define SCardGetProviderId SCardGetProviderIdW
#define SCardGetStatusChange SCardGetStatusChangeW
#define SCardIntroduceCardType SCardIntroduceCardTypeW
#define SCardIntroduceReader SCardIntroduceReaderW
#define SCardIntroduceReaderGroup SCardIntroduceReaderGroupW
#define SCardListCards SCardListCardsW
#define SCardListInterfaces SCardListInterfacesW
#define SCardListReaderGroups SCardListReaderGroupsW
#define SCardListReaders SCardListReadersW
#define SCardLocateCards SCardLocateCardsW
#define SCardLocateCardsByATR SCardLocateCardsByATRW
#define SCardRemoveReaderFromGroup SCardRemoveReaderFromGroupW
#define SCardSetCardTypeProviderName SCardSetCardTypeProviderNameW
#define SCardStatus SCardStatusW
#else /* !UNICODE */
typedef struct SCARD_READERSTATEA SCARD_READERSTATE, *PSCARD_READERSTATE, *LPSCARD_READERSTATE;
#define SCardAddReaderToGroup SCardAddReaderToGroupA
#define SCardConnect SCardConnectA
#define SCardForgetCardType SCardForgetCardTypeA
#define SCardForgetReader SCardForgetReaderA
#define SCardForgetReaderGroup SCardForgetReaderGroupA
#define SCardGetCardTypeProviderName SCardGetCardTypeProviderNameA
#define SCardGetProviderId SCardGetProviderIdA
#define SCardGetStatusChange SCardGetStatusChangeA
#define SCardIntroduceCardType SCardIntroduceCardTypeA
#define SCardIntroduceReader SCardIntroduceReaderA
#define SCardIntroduceReaderGroup SCardIntroduceReaderGroupA
#define SCardListCards SCardListCardsA
#define SCardListInterfaces SCardListInterfacesA
#define SCardListReaderGroups SCardListReaderGroupsA
#define SCardListReaders SCardListReadersA
#define SCardLocateCards SCardLocateCardsA
#define SCardLocateCardsByATR SCardLocateCardsByATRA
#define SCardRemoveReaderFromGroup SCardRemoveReaderFromGroupA
#define SCardSetCardTypeProviderName SCardSetCardTypeProviderNameA
#define SCardStatus SCardStatusA
#endif /* UNICODE */

#endif /* _DISABLE_TIDENTS */

extern const SCARD_IO_REQUEST g_rgSCardT0Pci;
extern const SCARD_IO_REQUEST g_rgSCardT1Pci;
extern const SCARD_IO_REQUEST g_rgSCardRawPci;

#ifdef __cplusplus
}
#endif
#endif /* __WINSCARD_H */

/* EOF */
