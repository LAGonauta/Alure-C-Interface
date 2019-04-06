#include "common.h"

#ifndef __WRAP_DEVICEMANAGER_H__
#define __WRAP_DEVICEMANAGER_H__

#ifdef __cplusplus
extern "C" {
#endif

deviceManager_t* deviceManager_create();
void deviceManager_destroy(deviceManager_t* dm);

bool deviceManager_queryExtension(deviceManager_t* dm, const char* extension);

device_t* deviceManager_openPlayback(deviceManager_t* dm, const char* name) noexcept;

wrapStringVector_t* deviceManager_enumerate(deviceManager_t* dm, alure::DeviceEnumeration type);
wrapString_t* deviceManager_defaultDeviceName(deviceManager_t* dm, alure::DefaultDeviceType type);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_DEVICEMANAGER_H__ */
