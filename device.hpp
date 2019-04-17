#include "common.h"

#ifndef __WRAP_DEVICE_H__
#define __WRAP_DEVICE_H__

#ifdef __cplusplus
extern "C" {
#endif

device_t* device_create();
device_t* device_set(alure::Device dev);
void device_destroy(device_t* dm);

wrapString_t* device_getName(device_t* dm, alure::PlaybackName type);
bool device_queryExtension(device_t* dm, const char* extension);

alureVersion_t device_getALCVersion(device_t* dm);
alureVersion_t device_getEFXVersion(device_t* dm);

uint32_t device_getFrequency(device_t* dm);
uint32_t device_getMaxAuxiliarySends(device_t* dm);

wrapStringVector_t* device_enumerateHRTFNames(device_t* dm);
bool device_isHRTFEnabled(device_t* dm);

wrapString_t* device_getCurrentHRTF(device_t* dm);

void device_reset(device_t* dm, alure::AttributePair* attributes, uint64_t size);

context_t* device_createContextWithAttr(device_t* dm, alure::AttributePair* attributes, uint64_t size) noexcept;

void device_pauseDSP(device_t* dm);
void device_resumeDSP(device_t* dm);

int64_t device_getClockTime(device_t* dm);

void device_close(device_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_DEVICE_H__ */
