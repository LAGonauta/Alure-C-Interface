#include "deviceManager.hpp"

struct deviceManager {
  void *obj;
};

deviceManager_t *deviceManager_create()
{
  deviceManager_t *dm;
  alure::DeviceManager *obj;

  dm = (typeof(dm))malloc(sizeof(*dm));
  obj = new alure::DeviceManager();
  dm->obj = obj;

  return dm;
}

void deviceManager_destroy(deviceManager_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete static_cast<alure::DeviceManager *>(dm->obj);

  free(dm);
}

bool queryExtension(deviceManager_t* dm, const char* extension)
{
  alure::DeviceManager *obj;

  if (dm == nullptr)
  {
    return false;
  }

  obj = static_cast<alure::DeviceManager *>(dm->obj);
  return obj->queryExtension(extension);
}

bool openDefaultPlayback(deviceManager_t* dm) // uses nothrow
{
  alure::DeviceManager *obj;

  if (dm == nullptr)
  {
    return false;
  }

  obj = static_cast<alure::DeviceManager *>(dm->obj);
  obj->openPlayback(std::nothrow); // return struct Device pointer, not bool. Update method later. TODO.
  return true;
}

bool openPlayback(deviceManager_t* dm, const char* name) // uses nothrow
{
  alure::DeviceManager *obj;

  if (dm == nullptr)
  {
    return false;
  }

  obj = static_cast<alure::DeviceManager *>(dm->obj);
  obj->openPlayback(name, std::nothrow); //TODO
  return true;
}

wrapString_t** enumerate(deviceManager_t* dm, alure::DeviceEnumeration type)
{
  alure::DeviceManager* obj;

  if (dm == nullptr)
  {
    return nullptr;
  }

  obj = static_cast<alure::DeviceManager*>(dm->obj);
  auto result = obj->enumerate(type);

  return nullptr;
}

wrapString_t* defaultDeviceName(deviceManager_t* dm, alure::DefaultDeviceType type)
{
  alure::DeviceManager* obj;

  if (dm == nullptr)
  {
    return nullptr;
  }

  obj = static_cast<alure::DeviceManager*>(dm->obj);

  return wrapString_create(obj->defaultDeviceName(type));
}

