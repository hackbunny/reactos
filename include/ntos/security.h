#ifndef __INCLUDE_SECURITY_H
#define __INCLUDE_SECURITY_H

#include <ntos/ntdef.h>
#include <ntos/types.h>

/* Privileges */
#define SE_MIN_WELL_KNOWN_PRIVILEGE		(2L)
#define SE_CREATE_TOKEN_PRIVILEGE		(2L)
#define SE_ASSIGNPRIMARYTOKEN_PRIVILEGE		(3L)
#define SE_LOCK_MEMORY_PRIVILEGE		(4L)
#define SE_INCREASE_QUOTA_PRIVILEGE		(5L)
#define SE_UNSOLICITED_INPUT_PRIVILEGE		(6L)  /* unused */
#define SE_MACHINE_ACCOUNT_PRIVILEGE		(6L)
#define SE_TCB_PRIVILEGE			(7L)
#define SE_SECURITY_PRIVILEGE			(8L)
#define SE_TAKE_OWNERSHIP_PRIVILEGE		(9L)
#define SE_LOAD_DRIVER_PRIVILEGE		(10L)
#define SE_SYSTEM_PROFILE_PRIVILEGE		(11L)
#define SE_SYSTEMTIME_PRIVILEGE			(12L)
#define SE_PROF_SINGLE_PROCESS_PRIVILEGE	(13L)
#define SE_INC_BASE_PRIORITY_PRIVILEGE		(14L)
#define SE_CREATE_PAGEFILE_PRIVILEGE		(15L)
#define SE_CREATE_PERMANENT_PRIVILEGE		(16L)
#define SE_BACKUP_PRIVILEGE			(17L)
#define SE_RESTORE_PRIVILEGE			(18L)
#define SE_SHUTDOWN_PRIVILEGE			(19L)
#define SE_DEBUG_PRIVILEGE			(20L)
#define SE_AUDIT_PRIVILEGE			(21L)
#define SE_SYSTEM_ENVIRONMENT_PRIVILEGE		(22L)
#define SE_CHANGE_NOTIFY_PRIVILEGE		(23L)
#define SE_REMOTE_SHUTDOWN_PRIVILEGE		(24L)
#define SE_MAX_WELL_KNOWN_PRIVILEGE		SE_REMOTE_SHUTDOWN_PRIVILEGE

#if 0
/* Security descriptor control. */
#define SECURITY_DESCRIPTOR_REVISION	(1)
#define SECURITY_DESCRIPTOR_MIN_LENGTH	(20)
#define SE_OWNER_DEFAULTED	(1)
#define SE_GROUP_DEFAULTED	(2)
#define SE_DACL_PRESENT	(4)
#define SE_DACL_DEFAULTED	(8)
#define SE_SACL_PRESENT	(16)
#define SE_SACL_DEFAULTED	(32)
#define SE_SELF_RELATIVE	(32768)
#endif

/* This is defined in the Win 32 API headers as something else: */
#if defined(__NTOSKRNL__) || defined(__NTDRIVER__) || defined(__NTHAL__) || defined(__NTDLL__) || defined(__NTAPP__)
typedef ULONG ACCESS_MODE, *PACCESS_MODE;
#endif

#if 0
typedef struct _ACE_HEADER
{
  CHAR AceType;
  CHAR AceFlags;
  USHORT AceSize;
  ACCESS_MASK AccessMask;
} ACE_HEADER, *PACE_HEADER;

typedef struct
{
  ACE_HEADER Header;
} ACE, *PACE;
#endif

#ifdef __GNU__
typedef struct _SECURITY_DESCRIPTOR_CONTEXT
{
} SECURITY_DESCRIPTOR_CONTEXT, *PSECURITY_DESCRIPTOR_CONTEXT;
#endif


#ifndef __USE_W32API

#define SYSTEM_LUID                     { 0x3E7, 0x0 }
#define ANONYMOUS_LOGON_LUID            { 0x3e6, 0x0 }
#define LOCALSERVICE_LUID               { 0x3e5, 0x0 }
#define NETWORKSERVICE_LUID             { 0x3e4, 0x0 }
    
/* SID Auhority */
#define SECURITY_NULL_SID_AUTHORITY		{0,0,0,0,0,0}
#define SECURITY_WORLD_SID_AUTHORITY		{0,0,0,0,0,1}
#define SECURITY_LOCAL_SID_AUTHORITY		{0,0,0,0,0,2}
#define SECURITY_CREATOR_SID_AUTHORITY		{0,0,0,0,0,3}
#define SECURITY_NON_UNIQUE_AUTHORITY		{0,0,0,0,0,4}
#define SECURITY_NT_AUTHORITY			{0,0,0,0,0,5}

/* SID */
#define SECURITY_NULL_RID			(0L)
#define SECURITY_WORLD_RID			(0L)
#define SECURITY_LOCAL_RID			(0L)
#define SECURITY_CREATOR_OWNER_RID		(0L)
#define SECURITY_CREATOR_GROUP_RID		(0x1L)
#define SECURITY_CREATOR_OWNER_SERVER_RID	(0x2L)
#define SECURITY_CREATOR_GROUP_SERVER_RID	(0x3L)
#define SECURITY_DIALUP_RID			(0x1L)
#define SECURITY_NETWORK_RID			(0x2L)
#define SECURITY_BATCH_RID			(0x3L)
#define SECURITY_INTERACTIVE_RID		(0x4L)
#define SECURITY_LOGON_IDS_RID			(0x5L)
#define SECURITY_LOGON_IDS_RID_COUNT		(0x3L)
#define SECURITY_SERVICE_RID			(0x6L)
#define SECURITY_ANONYMOUS_LOGON_RID		(0x7L)
#define SECURITY_PROXY_RID			(0x8L)
#define SECURITY_ENTERPRISE_CONTROLLERS_RID	(0x9L)
#define SECURITY_SERVER_LOGON_RID		SECURITY_ENTERPRISE_CONTROLLERS_RID
#define SECURITY_PRINCIPAL_SELF_RID		(0xAL)
#define SECURITY_AUTHENTICATED_USER_RID		(0xBL)
#define SECURITY_RESTRICTED_CODE_RID		(0xCL)
#define SECURITY_LOCAL_SYSTEM_RID		(0x12L)
#define SECURITY_NT_NON_UNIQUE_RID		(0x15L)
#define SECURITY_BUILTIN_DOMAIN_RID		(0x20L)
#define DOMAIN_USER_RID_ADMIN			(0x1F4L)
#define DOMAIN_USER_RID_GUEST			(0x1F5L)
#define DOMAIN_GROUP_RID_ADMINS			(0x200L)
#define DOMAIN_GROUP_RID_USERS			(0x201L)
#define DOMAIN_ALIAS_RID_ADMINS			(0x220L)
#define DOMAIN_ALIAS_RID_USERS			(0x221L)
#define DOMAIN_ALIAS_RID_GUESTS			(0x222L)
#define DOMAIN_ALIAS_RID_POWER_USERS		(0x223L)
#define DOMAIN_ALIAS_RID_ACCOUNT_OPS		(0x224L)
#define DOMAIN_ALIAS_RID_SYSTEM_OPS		(0x225L)
#define DOMAIN_ALIAS_RID_PRINT_OPS		(0x226L)
#define DOMAIN_ALIAS_RID_BACKUP_OPS		(0x227L)
#define DOMAIN_ALIAS_RID_REPLICATOR		(0x228L)

/* ACCESS_MASK */
/* Generic rights */
#define GENERIC_READ			(0x80000000L)
#define GENERIC_WRITE			(0x40000000L)
#define GENERIC_EXECUTE			(0x20000000L)
#define GENERIC_ALL			(0x10000000L)
#define MAXIMUM_ALLOWED			(0x02000000L)
#define ACCESS_SYSTEM_SECURITY		(0x01000000L)

/* Standard rights */
#define STANDARD_RIGHTS_REQUIRED	(0x000f0000L)
#define STANDARD_RIGHTS_WRITE		(0x00020000L)
#define STANDARD_RIGHTS_READ		(0x00020000L)
#define STANDARD_RIGHTS_EXECUTE		(0x00020000L)
#define STANDARD_RIGHTS_ALL		(0x001f0000L)
#define SPECIFIC_RIGHTS_ALL		(0x0000ffffL)

/* Token rights */
#define TOKEN_ASSIGN_PRIMARY		(0x0001L)
#define TOKEN_DUPLICATE			(0x0002L)
#define TOKEN_IMPERSONATE		(0x0004L)
#define TOKEN_QUERY			(0x0008L)
#define TOKEN_QUERY_SOURCE		(0x0010L)
#define TOKEN_ADJUST_PRIVILEGES		(0x0020L)
#define TOKEN_ADJUST_GROUPS		(0x0040L)
#define TOKEN_ADJUST_DEFAULT		(0x0080L)

#define TOKEN_ALL_ACCESS		(0xf00ffL)
#define TOKEN_READ			(0x20008L)
#define TOKEN_WRITE			(0x200e0L)
#define TOKEN_EXECUTE			(0x20000L)

typedef BOOL SECURITY_CONTEXT_TRACKING_MODE;

#define SECURITY_STATIC_TRACKING	(0)
#define SECURITY_DYNAMIC_TRACKING	(1)

typedef ULONG SECURITY_INFORMATION, *PSECURITY_INFORMATION;

#define OWNER_SECURITY_INFORMATION	(0x1L)
#define GROUP_SECURITY_INFORMATION	(0x2L)
#define DACL_SECURITY_INFORMATION	(0x4L)
#define SACL_SECURITY_INFORMATION	(0x8L)

typedef enum _TOKEN_INFORMATION_CLASS
{
  TokenUser = 1,
  TokenGroups,
  TokenPrivileges,
  TokenOwner,
  TokenPrimaryGroup,
  TokenDefaultDacl,
  TokenSource,
  TokenType,
  TokenImpersonationLevel,
  TokenStatistics,
  TokenRestrictedSids,
  TokenSessionId,
  TokenGroupsAndPrivileges,
  TokenSessionReference,
  TokenSandBoxInert,
  TokenAuditPolicy,
  TokenOrigin
} TOKEN_INFORMATION_CLASS;

typedef ULONG SECURITY_IMPERSONATION_LEVEL, *PSECURITY_IMPERSONATION_LEVEL;

#define SecurityAnonymous ((SECURITY_IMPERSONATION_LEVEL)0)
#define SecurityIdentification ((SECURITY_IMPERSONATION_LEVEL)1)
#define SecurityImpersonation ((SECURITY_IMPERSONATION_LEVEL)2)
#define SecurityDelegation ((SECURITY_IMPERSONATION_LEVEL)3)

typedef ULONG ACCESS_MASK, *PACCESS_MASK;
typedef ULONG TOKEN_TYPE, *PTOKEN_TYPE;

#define TokenPrimary           ((TOKEN_TYPE)1)
#define TokenImpersonation     ((TOKEN_TYPE)2)

typedef struct _SECURITY_QUALITY_OF_SERVICE
{
  ULONG Length;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
  BOOLEAN EffectiveOnly;
} SECURITY_QUALITY_OF_SERVICE;

typedef SECURITY_QUALITY_OF_SERVICE* PSECURITY_QUALITY_OF_SERVICE;

typedef struct _ACE_HEADER
{
  BYTE AceType;
  BYTE AceFlags;
  WORD AceSize;
} ACE_HEADER, *PACE_HEADER;

typedef struct _SID_IDENTIFIER_AUTHORITY
{
  BYTE Value[6];
} SID_IDENTIFIER_AUTHORITY, *PSID_IDENTIFIER_AUTHORITY;

typedef struct _SID
{
  UCHAR  Revision;
  UCHAR  SubAuthorityCount;
  SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
  ULONG SubAuthority[1];
} SID, *PISID;

typedef PVOID PSID;

typedef struct _ACL
{
  UCHAR AclRevision;
  UCHAR Sbz1;
  USHORT AclSize;
  USHORT AceCount;
  USHORT Sbz2;
} ACL, *PACL;

typedef struct _ACL_REVISION_INFORMATION
{
  ULONG AclRevision;
} ACL_REVISION_INFORMATION, *PACL_REVISION_INFORMATION;

typedef struct _ACL_SIZE_INFORMATION
{
  ULONG AceCount;
  ULONG AclBytesInUse;
  ULONG AclBytesFree;
} ACL_SIZE_INFORMATION, *PACL_SIZE_INFORMATION;

typedef enum _ACL_INFORMATION_CLASS
{
  AclRevisionInformation = 1,
  AclSizeInformation
} ACL_INFORMATION_CLASS;

typedef USHORT SECURITY_DESCRIPTOR_CONTROL, *PSECURITY_DESCRIPTOR_CONTROL;

typedef struct _LUID
{
  ULONG LowPart;
  LONG  HighPart;
} LUID, *PLUID;

typedef struct _SECURITY_DESCRIPTOR
{
  UCHAR  Revision;
  UCHAR  Sbz1;
  SECURITY_DESCRIPTOR_CONTROL Control;
  PSID Owner;
  PSID Group;
  PACL Sacl;
  PACL Dacl;
} SECURITY_DESCRIPTOR, *PSECURITY_DESCRIPTOR;

typedef struct _LUID_AND_ATTRIBUTES
{
  LUID  Luid;
  ULONG Attributes;
} LUID_AND_ATTRIBUTES, *PLUID_AND_ATTRIBUTES;

typedef struct _TOKEN_SOURCE
{
  CHAR SourceName[8];
  LUID SourceIdentifier;
} TOKEN_SOURCE, *PTOKEN_SOURCE;

typedef struct _TOKEN_CONTROL
{
  LUID TokenId;
  LUID AuthenticationId;
  LUID ModifiedId;
  TOKEN_SOURCE TokenSource;
} TOKEN_CONTROL, *PTOKEN_CONTROL;

typedef struct _SID_AND_ATTRIBUTES
{
  PSID  Sid;
  DWORD Attributes;
} SID_AND_ATTRIBUTES, *PSID_AND_ATTRIBUTES;

typedef SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
typedef SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;

typedef struct _TOKEN_USER
{
  SID_AND_ATTRIBUTES User;
} TOKEN_USER, *PTOKEN_USER;

typedef struct _TOKEN_PRIMARY_GROUP
{
  PSID PrimaryGroup;
} TOKEN_PRIMARY_GROUP, *PTOKEN_PRIMARY_GROUP;

typedef struct _TOKEN_GROUPS
{
  DWORD GroupCount;
  SID_AND_ATTRIBUTES Groups[ANYSIZE_ARRAY];
} TOKEN_GROUPS, *PTOKEN_GROUPS, *LPTOKEN_GROUPS;

typedef struct _TOKEN_PRIVILEGES
{
  DWORD PrivilegeCount;
  LUID_AND_ATTRIBUTES Privileges[ANYSIZE_ARRAY];
} TOKEN_PRIVILEGES, *PTOKEN_PRIVILEGES, *LPTOKEN_PRIVILEGES;

typedef struct _TOKEN_OWNER
{
  PSID Owner;
} TOKEN_OWNER, *PTOKEN_OWNER;

typedef struct _TOKEN_DEFAULT_DACL
{
  PACL DefaultDacl;
} TOKEN_DEFAULT_DACL, *PTOKEN_DEFAULT_DACL;

typedef struct _TOKEN_STATISTICS
{
  LUID  TokenId;
  LUID  AuthenticationId;
  LARGE_INTEGER ExpirationTime;
  TOKEN_TYPE TokenType;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  DWORD DynamicCharged;
  DWORD DynamicAvailable;
  DWORD GroupCount;
  DWORD PrivilegeCount;
  LUID  ModifiedId;
} TOKEN_STATISTICS, *PTOKEN_STATISTICS;

typedef struct _TOKEN_ORIGIN {
  LUID OriginatingLogonSession;
} TOKEN_ORIGIN, *PTOKEN_ORIGIN;

typedef struct _GENERIC_MAPPING
{
  ACCESS_MASK GenericRead;
  ACCESS_MASK GenericWrite;
  ACCESS_MASK GenericExecute;
  ACCESS_MASK GenericAll;
} GENERIC_MAPPING, *PGENERIC_MAPPING;

typedef struct _PRIVILEGE_SET
{
  DWORD PrivilegeCount;
  DWORD Control;
  LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
} PRIVILEGE_SET, *PPRIVILEGE_SET, *LPPRIVILEGE_SET;

#define INITIAL_PRIVILEGE_COUNT 3

typedef struct _INITIAL_PRIVILEGE_SET
{
  ULONG PrivilegeCount;
  ULONG Control;
  LUID_AND_ATTRIBUTES Privilege[INITIAL_PRIVILEGE_COUNT];
} INITIAL_PRIVILEGE_SET, *PINITIAL_PRIVILEGE_SET;

typedef struct _SECURITY_ATTRIBUTES
{
  DWORD  nLength;
  LPVOID lpSecurityDescriptor;
  BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#endif /* !__USE_W32API */

typedef struct
{
  ACE_HEADER Header;
  ACCESS_MASK AccessMask;
} ACE, *PACE;

#endif /* __INCLUDE_SECURITY_H */
