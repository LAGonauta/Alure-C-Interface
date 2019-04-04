#include <stdexcept>
#include "wrapStringVector.hpp"

struct wrapStringVector {
  std::vector<wrapString_t*> obj;
};

wrapStringVector_t* wrapStringVector_create(std::vector<wrapString_t*> vector)
{
  wrapStringVector_t* dm;

  dm = new wrapStringVector_t;
  dm->obj = vector;

  return dm;
}

void wrapStringVector_destroy(wrapStringVector_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  for (int i = 0; i < dm->obj.size(); ++i)
  {
      wrapString_destroy(dm->obj[i]);
  }

  delete dm;
}

int wrapStringVector_getSize(wrapStringVector_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.size();
}

wrapString_t* wrapStringVector_getAt(wrapStringVector_t* dm, int position)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return dm->obj.at(position);
}