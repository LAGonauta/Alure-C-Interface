#include "common.h"

#ifndef __WRAP_DEVICE_H__
#define __WRAP_DEVICE_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC device_t* device_create();
DLL_PUBLIC device_t* device_set(alure::Device dev);
DLL_PUBLIC void device_destroy(device_t* dm);
DLL_PUBLIC wrapString_t* device_getName(device_t* dm, alure::PlaybackName type);
DLL_PUBLIC bool device_queryExtension(device_t* dm, const char* extension);
DLL_PUBLIC alureVersion_t device_getALCVersion(device_t* dm);
DLL_PUBLIC alureVersion_t device_getEFXVersion(device_t* dm);
DLL_PUBLIC uint32_t device_getFrequency(device_t* dm);
DLL_PUBLIC uint32_t device_getMaxAuxiliarySends(device_t* dm);
DLL_PUBLIC wrapStringVector_t* device_enumerateHRTFNames(device_t* dm);
DLL_PUBLIC bool device_isHRTFEnabled(device_t* dm);
DLL_PUBLIC wrapString_t* device_getCurrentHRTF(device_t* dm);
DLL_PUBLIC void device_reset(device_t* dm, alure::AttributePair* attributes, uint64_t size);
DLL_PUBLIC context_t* device_createContextWithAttr(device_t* dm, alure::AttributePair* attributes, uint64_t size) noexcept;
DLL_PUBLIC void device_pauseDSP(device_t* dm);
DLL_PUBLIC void device_resumeDSP(device_t* dm);
DLL_PUBLIC int64_t device_getClockTime(device_t* dm);
DLL_PUBLIC void device_close(device_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_DEVICE_H__ */
