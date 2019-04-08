#include "common.h"

#ifndef __WRAP_BUFFER_H__
#define __WRAP_BUFFER_H__

#ifdef __cplusplus
extern "C" {
#endif

buffer_t* buffer_set(alure::Buffer buffer);
void buffer_destroy(buffer_t* dm);

uint32_t buffer_getLength(buffer_t* dm, void* exceptionPointer);
uint32_t buffer_getFrequency(buffer_t* dm, void* exceptionPointer);
alure::ChannelConfig buffer_getChannelConfig(buffer_t* dm, void* exceptionPointer);
alure::SampleType buffer_getSampleType(buffer_t* dm, void* exceptionPointer);
uint32_t buffer_getSize(buffer_t* dm, void* exceptionPointer);
void buffer_setLoopPoints(buffer_t* dm, alureLoopPoints points, void* exceptionPointer);
alureLoopPoints buffer_getLoopPoints(buffer_t* dm, void* exceptionPointer);
//Vector<Source> buffer_getSources(buffer_t* dm, void* exceptionPointer);
const char* buffer_getName(buffer_t* dm, void* exceptionPointer);
uint64_t buffer_getSourceCount(buffer_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_BUFFER_H__ */
