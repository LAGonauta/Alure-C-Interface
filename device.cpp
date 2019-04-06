#include "device.hpp"
#include "context.hpp"
#include "wrapString.hpp"
#include "wrapStringVector.hpp"

struct device {
  alure::Device obj;
};

device_t* device_create()
{
  device_t* dm;

  dm = new device;
  dm->obj = alure::Device();

  return dm;
}

device_t* device_set(alure::Device dev)
{
  device_t* dm;

  dm = new device;
  dm->obj = dev;

  return dm;
}

void device_destroy(device_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

wrapString_t* device_getName(device_t* dm, alure::PlaybackName type)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return wrapString_create(dm->obj.getName(type));
}

bool device_queryExtension(device_t* dm, const char* extension)
{
  if (dm == nullptr)
  {
    return false;
  }

  return dm->obj.queryExtension(extension);
}

alureVersion device_getALCVersion(device_t* dm)
{
  if (dm == nullptr)
  {
    return { 0, 0 };
  }

  auto version = dm->obj.getALCVersion();
  return { version.getMajor(), version.getMinor() };
}

alureVersion device_getEFXVersion(device_t* dm)
{
  if (dm == nullptr)
  {
    return { 0, 0 };
  }

  auto version = dm->obj.getEFXVersion();
  return { version.getMajor(), version.getMinor() };
}

uint32_t device_getFrequency(device_t* dm)
{
  if (dm == nullptr)
  {
    return false;
  }

  return dm->obj.getFrequency();
}

uint32_t device_getMaxAuxiliarySends(device_t* dm)
{
  if (dm == nullptr)
  {
    return false;
  }

  return dm->obj.getMaxAuxiliarySends();
}

wrapStringVector_t* device_enumerateHRTFNames(device_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto result = dm->obj.enumerateHRTFNames();
  std::vector<wrapString_t*> string_vector;
  for (int i = 0; i < result.size(); ++i)
  {
    string_vector.push_back(wrapString_create(result[i]));
  }

  return wrapStringVector_create(string_vector);
}

bool device_isHRTFEnabled(device_t* dm)
{
  if (dm == nullptr)
  {
    return false;
  }

  return dm->obj.isHRTFEnabled();
}

wrapString_t* device_getCurrentHRTF(device_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return wrapString_create(dm->obj.getCurrentHRTF());
}

void device_reset(device_t* dm, alure::AttributePair* attributes, uint64_t size)
{
  if (dm == nullptr)
  {
    return;
  }

  alure::ArrayView<alure::AttributePair> attr(attributes, size);
  dm->obj.reset(attr);
}

context_t* device_createContextWithAttr(device_t* dm, alure::AttributePair* attributes, uint64_t size) noexcept
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  if (attributes != nullptr && size > 0)
  {
    alure::ArrayView<alure::AttributePair> attr(attributes, size);
    return context_set(dm->obj.createContext(attr, std::nothrow));
  }
  else
  {
    return context_set(dm->obj.createContext(std::nothrow));
  }
}

void device_pauseDSP(device_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.pauseDSP();
}

void device_resumeDSP(device_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.resumeDSP();
}

int64_t device_getClockTime(device_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.getClockTime().count();
}

void device_close(device_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }
  
  dm->obj.close();
}