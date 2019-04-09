#include "wrapString.hpp"

wrapString_t* wrapString_create(const std::string text)
{
  wrapString_t *dm;

  dm = new wrapString_t { .obj = text };

  return dm;
}

void wrapString_destroy(wrapString_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

const char* wrapString_getString(wrapString_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return dm->obj.c_str();
}