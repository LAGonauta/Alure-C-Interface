#include "wrapString.hpp"

struct wrapString {
  void *obj;
};

wrapString_t* wrapString_create(std::string text)
{
  wrapString_t *dm;
  std::string* obj;

  dm = (typeof(dm))malloc(sizeof(*dm));
  obj = new std::string(text);
  dm->obj = obj;

  return dm;
}

void wrapString_destroy(wrapString_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete static_cast<std::string*>(dm->obj);

  free(dm);
}

const char* getString(wrapString_t* dm)
{
  std::string* obj;

  if (dm == nullptr)
  {
    return nullptr;
  }

  obj = static_cast<std::string*>(dm->obj);

  return obj->c_str();
}