#include "device.hpp"

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

//uint32_t device_getALCVersion(device_t* dm);
//uint32_t device_getEFXVersion(device_t* dm);

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

//void device_reset(ArrayView<AttributePair> attributes);

//Context device_createContext(ArrayView<AttributePair> attributes, const std::nothrow_t&) noexcept
//Context device_createContext(const std::nothrow_t&) noexcept;

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