#include "common.h"

#ifndef __WRAP_BUFFER_H__
#define __WRAP_BUFFER_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC buffer_t* buffer_set(alure::Buffer buffer);
DLL_PUBLIC void buffer_destroy(buffer_t* dm);
DLL_PUBLIC uint32_t buffer_getLength(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC uint32_t buffer_getFrequency(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC alure::ChannelConfig buffer_getChannelConfig(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC alure::SampleType buffer_getSampleType(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC uint32_t buffer_getSize(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC void buffer_setLoopPoints(buffer_t* dm, alureLoopPoints_t points, void* exceptionPointer);
DLL_PUBLIC alureLoopPoints_t buffer_getLoopPoints(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC sourceVector_t* buffer_getSources(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC wrapString_t* buffer_getName(buffer_t* dm, void* exceptionPointer);
DLL_PUBLIC uint64_t buffer_getSourceCount(buffer_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_BUFFER_H__ */
