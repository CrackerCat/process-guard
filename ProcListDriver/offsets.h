#pragma once

#define X86

#ifdef X86
// win7 x86 EPROCESS �е�ƫ��
#define EP_OFFSET_PID (0x0b4)

#define EP_OFFSET_AC_LINKS (0x0b8)

#define EP_OFFSET_PPID (0x140)

#define EP_OFFSET_IMAGE_NAME (0x16c)

#define EP_OFFSET_OB_TABLE (0x0f4)

#define EP_OFFSET_THREAD_LIST (0x188)

// HANDLE_TABLE
#define HT_OFFSET_LIST (0x010)

#define HT_OFFSET_PID (0x008)

#else

#define EP_OFFSET_PID (0x0b4)

#define EP_OFFSET_AC_LINKS (0x0b8)

#define EP_OFFSET_PPID (0x140)

#define EP_OFFSET_IMAGE_NAME (0x16c)

#define EP_OFFSET_OB_TABLE (0x0f4)

#define EP_OFFSET_THREAD_LIST (0x188)

#endif

#define IMAGE_NAME_TO_AC_LINKS (EP_OFFSET_IMAGE_NAME - EP_OFFSET_AC_LINKS)

#define PID_TO_AC_LINKS (EP_OFFSET_PID - EP_OFFSET_AC_LINKS)

#define PPID_TO_AC_LINKS (EP_OFFSET_PPID - EP_OFFSET_AC_LINKS)

#define PID_TO_EPROCESS (EP_OFFSET_PID)

#define PPID_TO_EPROCESS (EP_OFFSET_PPID)

#define AC_LINKS_TO_EPROCESS (EP_OFFSET_AC_LINKS)

#define PID_TO_OB_LIST_ENTRY (HT_OFFSET_PID - HT_OFFSET_LIST)


#define GET_LIST_ENTRY_FROM_EPROCESS(_eprocessPtr) \
	((PLIST_ENTRY)\
	((PBYTE)(_eprocessPtr) + AC_LINKS_TO_EPROCESS))

#define GET_EPROCESS_FROM_LIST_ENTRY(_listEntryPtr) \
	((PEPROCESS)\
	((PBYTE)(_listEntryPtr) - AC_LINKS_TO_EPROCESS))

#define GET_IMAGE_NAME_FROM_LIST_ENTRY(_listEntryPtr) \
	((PCHAR)\
	((PBYTE)(_listEntryPtr) + IMAGE_NAME_TO_AC_LINKS))

#define GET_PID_FROM_EPROCESS(_eprocessPtr) \
	(*(PULONG)\
	((PBYTE)(_eprocessPtr) + PID_TO_EPROCESS))

#define GET_PPID_FROM_EPROCESS(_eprocessPtr) \
	(*(PULONG)\
	((PBYTE)(_eprocessPtr) + PPID_TO_EPROCESS))

#define GET_IMAGE_NAME_FROM_EPROCESS(_eprocessPtr) \
	((PUCHAR)(_eprocessPtr) + PPID_TO_EPROCESS)

#define GET_OB_TABLE_FROM_EPROCESS(_eprocessPtr) \
	(*(PVOID*)\
	((PBYTE)(_eprocessPtr) + EP_OFFSET_OB_TABLE))

#define GET_LIST_ENTRY_FROM_OB_TABLE(_handleTable) \
	((PLIST_ENTRY)\
	((PBYTE)(_handleTable) + HT_OFFSET_LIST))

#define GET_PID_FROM_OB_TABLE(_handleTable) \
	(*(PULONG)\
	((PBYTE)(_handleTable) + HT_OFFSET_PID))

#define GET_PID_FROM_OB_LIST_ENTRY(_listEntry) \
	(*(PULONG)\
	((PBYTE)(_listEntry) + PID_TO_OB_LIST_ENTRY))
