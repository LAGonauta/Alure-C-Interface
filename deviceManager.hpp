#include "common.h"

#ifndef __WRAP_DEVICEMANAGER_H__
#define __WRAP_DEVICEMANAGER_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC deviceManager_t* deviceManager_create();
DLL_PUBLIC void deviceManager_destroy(deviceManager_t* dm);
DLL_PUBLIC bool deviceManager_queryExtension(deviceManager_t* dm, const char* extension);
DLL_PUBLIC device_t* deviceManager_openPlayback(deviceManager_t* dm, const char* name) noexcept;
DLL_PUBLIC wrapStringVector_t* deviceManager_enumerate(deviceManager_t* dm, alure::DeviceEnumeration type);
DLL_PUBLIC wrapString_t* deviceManager_defaultDeviceName(deviceManager_t* dm, alure::DefaultDeviceType type);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_DEVICEMANAGER_H__ */
