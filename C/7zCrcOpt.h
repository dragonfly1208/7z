/* 7zAlloc.h -- Allocation functions
2017-04-03 : Igor Pavlov : Public domain */

#ifndef __7Z_CRCOPT_H
#define __7Z_CRCOPT_H
#include "7zTypes.h"
#include "CpuArch.h"
EXTERN_C_BEGIN

#ifdef MY_CPU_LE
#define CRC_NUM_TABLES 8
#else
#define CRC_NUM_TABLES 9

#define CRC_UINT32_SWAP(v) ((v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24))

UInt32 MY_FAST_CALL CrcUpdateT1_BeT4(UInt32 v, const void *data, size_t size, const UInt32 *table);
UInt32 MY_FAST_CALL CrcUpdateT1_BeT8(UInt32 v, const void *data, size_t size, const UInt32 *table);
#endif

#ifndef MY_CPU_BE
UInt32 MY_FAST_CALL CrcUpdateT4(UInt32 v, const void *data, size_t size, const UInt32 *table);
UInt32 MY_FAST_CALL CrcUpdateT8(UInt32 v, const void *data, size_t size, const UInt32 *table);
#endif

EXTERN_C_END

#endif
