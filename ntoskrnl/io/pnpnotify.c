/*
 * COPYRIGHT:      See COPYING in the top level directory
 * PROJECT:        ReactOS kernel
 * FILE:           ntoskrnl/io/pnpmgr/remlock.c
 * PURPOSE:        Plug & Play notification functions
 * PROGRAMMER:     Filip Navara (xnavara@volny.cz)
 * UPDATE HISTORY:
 *  22/09/2003 FiN Created
 */

/* INCLUDES ******************************************************************/

#include <ntoskrnl.h>
#include <internal/debug.h>

/* FUNCTIONS *****************************************************************/

/*
 * @unimplemented
 */
ULONG
STDCALL
IoPnPDeliverServicePowerNotification(
	ULONG		VetoedPowerOperation OPTIONAL,
	ULONG		PowerNotification,
	ULONG		Unknown OPTIONAL,
	BOOLEAN  	Synchronous
	)
{
	UNIMPLEMENTED;
	return 0;
}

/*
 * @unimplemented
 */
NTSTATUS
STDCALL
IoRegisterPlugPlayNotification(
  IN IO_NOTIFICATION_EVENT_CATEGORY EventCategory,
  IN ULONG EventCategoryFlags,
  IN PVOID EventCategoryData  OPTIONAL,
  IN PDRIVER_OBJECT DriverObject,
  IN PDRIVER_NOTIFICATION_CALLBACK_ROUTINE CallbackRoutine,
  IN PVOID Context,
  OUT PVOID *NotificationEntry)
{
  DPRINT("IoRegisterPlugPlayNotification called (UNIMPLEMENTED)\n");
  return STATUS_NOT_IMPLEMENTED;
}

/*
 * @unimplemented
 */
NTSTATUS
STDCALL
IoUnregisterPlugPlayNotification(
  IN PVOID NotificationEntry)
{
  DPRINT("IoUnregisterPlugPlayNotification called (UNIMPLEMENTED)\n");
  return STATUS_NOT_IMPLEMENTED;
}

/* EOF */
