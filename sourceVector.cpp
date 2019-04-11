#include <stdexcept>
#include "source.hpp"
#include "sourceVector.hpp"
#include "wrapException.hpp"

sourceVector_t* sourceVector_create(std::vector<source_t*> vector)
{
  sourceVector_t* dm;

  dm = new sourceVector_t(vector);

  return dm;
}

void sourceVector_destroy(sourceVector_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  for (size_t i = 0; i < dm->obj.size(); ++i)
  {
      source_destroy(dm->obj[i],  nullptr);
  }
}

void sourceVector_destroyPointer(sourceVector_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  for (size_t i = 0; i < dm->obj.size(); ++i)
  {
      source_destroyPointer(dm->obj[i]);
  }

  delete dm;
}

uint64_t sourceVector_getSize(sourceVector_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint64_t { return static_cast<uint64_t>(dm->obj.size()); };
  return wrapException_wrapFunction<decltype(func), uint64_t>(func, "", exceptionPointer);
}

source_t* sourceVector_getAt(sourceVector_t* dm, uint64_t position, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm, &position]() -> source_t* { return dm->obj.at(position); };
  return wrapException_wrapFunction<decltype(func), source_t*>(func, "", exceptionPointer);
}