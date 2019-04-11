#include "deviceManager.hpp"
#include "device.hpp"
#include "wrapString.hpp"
#include "wrapStringVector.hpp"

deviceManager_t* deviceManager_create()
{
  deviceManager_t* dm;

  dm = new deviceManager_t(alure::DeviceManager::getInstance());

  return dm;
}

void deviceManager_destroy(deviceManager_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

bool deviceManager_queryExtension(deviceManager_t* dm, const char* extension)
{
  if (dm == nullptr)
  {
    return false;
  }

  return dm->obj.queryExtension(extension);
}

device_t* deviceManager_openPlayback(deviceManager_t* dm, const char* name) noexcept
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return device_set(dm->obj.openPlayback(name, std::nothrow));
}

wrapStringVector_t* deviceManager_enumerate(deviceManager_t* dm, alure::DeviceEnumeration type)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto result = dm->obj.enumerate(type);
  std::vector<wrapString_t*> string_vector;
  for (size_t i = 0; i < result.size(); ++i)
  {
    string_vector.push_back(wrapString_create(result[i]));
  }

  return wrapStringVector_create(string_vector);
}

wrapString_t* deviceManager_defaultDeviceName(deviceManager_t* dm, alure::DefaultDeviceType type)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return wrapString_create(dm->obj.defaultDeviceName(type));
}

