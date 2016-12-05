/* 动态内存管理配置 */
#define TCL_MEMORY_ENABLE              (1)
#define TCL_MEMORY_POOL_ENABLE         (1)
#define TCL_MEMORY_POOL_PAGES          (256U)
#define TCL_MEMORY_BUDDY_ENABLE        (1)
#define TCL_MEMORY_BUDDY_PAGES         (64)

/**************
*                                     Trochili RTOS Kernel                                      *
*                                  Copyright(C) 2015 LIUXUMING                                  *
*                                       www.trochili.com                                        *
**************/
#ifndef _TCL_MEMORY_BUDDY_H
#define _TCL_MEMORY_BUDDY_H

#include "tcl.types.h"
#include "tcl.config.h"
#include "tcl.memory.h"

#if ((TCL_MEMORY_ENABLE) && (TCL_MEMORY_BUDDY_ENABLE))

	#define MEM_BUDDY_PAGE_TAGS  ((TCL_MEMORY_BUDDY_PAGES + 31u) >> 5u)
	#define MEM_BUDDY_NODE_TAGS (TCL_MEMORY_BUDDY_PAGES * 2u - 1u)
	#define MEM_PROP_READY (1)

	typedef struct MemBuddyDef {
	    TProperty Property;                       /* 内存页池属性                      */
	    TChar*    PageAddr;                       /* 被管理的内存的起始地址            */
	    TWord     PageSize;                       /* 内存页大小                        */
	    TWord     PageNbr;                        /* 内存页数目                        */
	    TWord     PageAvail;                      /* 可用内存页数目                    */
	    TBitMask  PageTags[MEM_BUDDY_PAGE_TAGS];  /* 内存页是否可用标记                */
	    TWord     NodeNbr;
	    TByte     NodeTags[MEM_BUDDY_NODE_TAGS];
	} TMemBuddy;

	extern TState xBuddyInit(TMemBuddy* pBuddy, TChar* pAddr, TWord pages, TWord pagesize, TError* pError);
	extern TState xBuddyDeinit(TMemBuddy* pBuddy, TError* pError);
	extern TState xBuddyMemMalloc(TMemBuddy* pBuddy, TWord length, void** pAddr, TError* pError);
	extern TState xBuddyMemFree(TMemBuddy* pBuddy, void* pAddr, TError* pError);

#endif

#endif /* _TCL_MEMORY_BUDDY_H  */
