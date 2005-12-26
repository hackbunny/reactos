#ifndef __DEVMGR_RESOURCE_H
#define __DEVMGR_RESOURCE_H

#define IDI_DEVMGR		100

#define IDD_HARDWARE		100
#define IDD_DEVICEGENERAL	101
#define IDD_DEVICEDRIVER	102
#define IDD_DEVICERESOURCES	103

#define IDC_DEVICON		0x57B
#define IDC_DEVNAME		0x57C
#define IDC_DEVTYPE		0x57D
#define IDC_DEVMANUFACTURER	0x57E
#define IDC_DEVLOCATION		0x57F
#define IDC_DEVSTATUSGROUP	0x580
#define IDC_DEVSTATUS		0x581
#define IDC_DEVUSAGE		0x582
#define IDC_DEVICES		0x583
#define IDC_LV_DEVICES		0x584
#define IDC_PROPERTIESGROUP	0x585
#define IDC_MANUFACTURER	0x587
#define IDC_LOCATION		0x588
#define IDC_STATUS		0x586
#define IDC_TROUBLESHOOT	0x589
#define IDC_PROPERTIES		0x58A
#define IDC_DEVUSAGELABEL	0x58B
#define IDC_DEVPROBLEM		0x58C
#define IDC_DRVPROVIDER		0x58D
#define IDC_DRVDATE		0x58E
#define IDC_DRVVERSION		0x58F

#define IDS_NAME		0x100
#define IDS_TYPE		0x101
#define IDS_MANUFACTURER	0x102
#define IDS_LOCATION		0x103
#define IDS_STATUS		0x104
#define IDS_UNKNOWN		0x105
#define IDS_LOCATIONSTR		0x106
#define IDS_DEVCODE		0x107
#define IDS_DEVCODE2		0x108
#define IDS_ENABLEDEVICE	0x109
#define IDS_DISABLEDEVICE	0x10A
#define IDS_UNKNOWNDEVICE	0x10B
#define IDS_NODRIVERLOADED	0x10C
#define IDS_DEVONPARENT		0x10D
#define IDS_TROUBLESHOOTDEV	0x10E
#define IDS_ENABLEDEV		0x10F
#define IDS_PROPERTIES		0x110
#define IDS_UPDATEDRV		0x111
#define IDS_REINSTALLDRV	0x112
#define IDS_REBOOT		0x113

#define IDS_DEV_NO_PROBLEM			0x200
#define IDS_DEV_NOT_CONFIGURED			0x201
#define IDS_DEV_DEVLOADER_FAILED		0x202
#define IDS_DEV_DEVLOADER_FAILED2		0x203
#define IDS_DEV_OUT_OF_MEMORY			0x204
#define IDS_DEV_ENTRY_IS_WRONG_TYPE		0x205
#define IDS_DEV_LACKED_ARBITRATOR		0x206
#define IDS_DEV_BOOT_CONFIG_CONFLICT		0x207
#define IDS_DEV_FAILED_FILTER			0x208
#define IDS_DEV_DEVLOADER_NOT_FOUND		0x209
#define IDS_DEV_DEVLOADER_NOT_FOUND2		0x20A
#define IDS_DEV_DEVLOADER_NOT_FOUND3		0x20B
#define IDS_DEV_INVALID_DATA			0x20C
#define IDS_DEV_INVALID_DATA2			0x20D
#define IDS_DEV_FAILED_START			0x20E
#define IDS_DEV_LIAR				0x20F
#define IDS_DEV_NORMAL_CONFLICT			0x210
#define IDS_DEV_NOT_VERIFIED			0x211
#define IDS_DEV_NEED_RESTART			0x212
#define IDS_DEV_REENUMERATION			0x213
#define IDS_DEV_PARTIAL_LOG_CONF		0x214
#define IDS_DEV_UNKNOWN_RESOURCE		0x215
#define IDS_DEV_REINSTALL			0x216
#define IDS_DEV_REGISTRY			0x217
#define IDS_DEV_WILL_BE_REMOVED			0x218
#define IDS_DEV_DISABLED			0x219
#define IDS_DEV_DISABLED2			0x21A
#define IDS_DEV_DEVLOADER_NOT_READY		0x21B
#define IDS_DEV_DEVLOADER_NOT_READY2		0x21C
#define IDS_DEV_DEVLOADER_NOT_READY3		0x21D
#define IDS_DEV_DEVICE_NOT_THERE		0x21E
#define IDS_DEV_MOVED				0x21F
#define IDS_DEV_TOO_EARLY			0x220
#define IDS_DEV_NO_VALID_LOG_CONF		0x221
#define IDS_DEV_FAILED_INSTALL			0x222
#define IDS_DEV_HARDWARE_DISABLED		0x223
#define IDS_DEV_CANT_SHARE_IRQ			0x224
#define IDS_DEV_FAILED_ADD			0x225
#define IDS_DEV_DISABLED_SERVICE		0x226
#define IDS_DEV_TRANSLATION_FAILED		0x227
#define IDS_DEV_NO_SOFTCONFIG			0x228
#define IDS_DEV_BIOS_TABLE			0x229
#define IDS_DEV_IRQ_TRANSLATION_FAILED		0x22A
#define IDS_DEV_FAILED_DRIVER_ENTRY		0x22B
#define IDS_DEV_DRIVER_FAILED_PRIOR_UNLOAD	0x22C
#define IDS_DEV_DRIVER_FAILED_LOAD		0x22D
#define IDS_DEV_DRIVER_SERVICE_KEY_INVALID	0x22E
#define IDS_DEV_LEGACY_SERVICE_NO_DEVICES	0x22F
#define IDS_DEV_DUPLICATE_DEVICE		0x230
#define IDS_DEV_FAILED_POST_START		0x231
#define IDS_DEV_HALTED				0x232
#define IDS_DEV_PHANTOM				0x233
#define IDS_DEV_SYSTEM_SHUTDOWN			0x234
#define IDS_DEV_HELD_FOR_EJECT			0x235
#define IDS_DEV_DRIVER_BLOCKED			0x236
#define IDS_DEV_REGISTRY_TOO_LARGE		0x237
#define IDS_DEV_SETPROPERTIES_FAILED		0x238

#endif /* __DEVMGR_RESOURCE_H */

/* EOF */
