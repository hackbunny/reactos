#ifndef _WIN32K_USERATOM_H
#define _WIN32K_USERATOM_H

RTL_ATOM FASTCALL
IntAddAtom(LPWSTR AtomName);
ULONG FASTCALL
IntGetAtomName(RTL_ATOM nAtom, LPWSTR lpBuffer, ULONG nSize);
RTL_ATOM FASTCALL IntAddGlobalAtom(LPWSTR,BOOL);

#endif /* _WIN32K_USERATOM_H */
