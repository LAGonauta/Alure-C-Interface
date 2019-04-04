#include "wrapString.hpp"

struct wrapString {
  std::string obj;
};

wrapString_t* wrapString_create(std::string text)
{
  wrapString_t *dm;

  dm = new wrapString_t;
  dm->obj = text;

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