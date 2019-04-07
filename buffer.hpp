#include "common.h"

#ifndef __WRAP_BUFFER_H__
#define __WRAP_BUFFER_H__

#ifdef __cplusplus
extern "C" {
#endif

buffer_t* buffer_set(alure::Buffer buffer);
void buffer_destroy(buffer_t* dm);

uint32_t buffer_getLength(buffer_t* dm);
uint32_t buffer_getFrequency(buffer_t* dm);
alure::ChannelConfig buffer_getChannelConfig(buffer_t* dm);
alure::SampleType buffer_getSampleType(buffer_t* dm);
uint32_t buffer_getSize(buffer_t* dm);
void buffer_setLoopPoints(buffer_t* dm, alureLoopPoints points);
alureLoopPoints buffer_getLoopPoints(buffer_t* dm);
//Vector<Source> buffer_getSources(buffer_t* dm);
const char* buffer_getName(buffer_t* dm);
uint64_t buffer_getSourceCount(buffer_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_BUFFER_H__ */
