#include "common.h"
#include "wrapString.hpp"
#include "alure/include/AL/alure2.h"

#ifndef __WRAP_DEVICEMANAGER_H__
#define __WRAP_DEVICEMANAGER_H__

#ifdef __cplusplus
extern "C" {
#endif

struct deviceManager;
typedef struct deviceManager deviceManager_t;

deviceManager_t* deviceManager_create();
void deviceManager_destroy(deviceManager_t* dm);

bool queryExtension(deviceManager_t* dm, const char* extension);

bool openDefaultPlayback(deviceManager_t* dm); // uses nothrow
bool openPlayback(deviceManager_t* dm, const char* name); // uses nothrow

wrapString_t** enumerate(deviceManager_t* dm, alure::DeviceEnumeration type);
wrapString_t* defaultDeviceName(deviceManager_t* dm, alure::DefaultDeviceType type);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_DEVICEMANAGER_H__ */
