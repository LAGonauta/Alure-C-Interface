#include <stdexcept>
#include "wrapString.hpp"
#include "wrapStringVector.hpp"

wrapStringVector_t* wrapStringVector_create(std::vector<wrapString_t*> vector)
{
  wrapStringVector_t* dm;

  dm = new wrapStringVector_t(vector);

  return dm;
}

void wrapStringVector_destroy(wrapStringVector_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  for (size_t i = 0; i < dm->obj.size(); ++i)
  {
      wrapString_destroy(dm->obj[i]);
  }

  delete dm;
}

uint64_t wrapStringVector_getSize(wrapStringVector_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return static_cast<uint64_t>(dm->obj.size());
}

wrapString_t* wrapStringVector_getAt(wrapStringVector_t* dm, uint64_t position)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return dm->obj.at(position);
}