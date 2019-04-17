#include "buffer.hpp"
#include "source.hpp"
#include "sourceVector.hpp"
#include "wrapException.hpp"
#include "wrapString.hpp"

buffer_t* buffer_set(alure::Buffer buf)
{
  buffer_t* dm;

  dm = new buffer_t(buf);

  return dm;
}

void buffer_destroy(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

uint32_t buffer_getLength(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint32_t { return dm->obj.getLength(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "Was the buffer removed?", exceptionPointer);
}

uint32_t buffer_getFrequency(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint32_t { return dm->obj.getFrequency(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "Was the buffer removed?", exceptionPointer);
}

alure::ChannelConfig buffer_getChannelConfig(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alure::ChannelConfig::Mono;
  }

  auto func = [&dm]() -> alure::ChannelConfig { return dm->obj.getChannelConfig(); };
  return wrapException_wrapFunction<decltype(func), alure::ChannelConfig>(func, "Was the buffer removed?", exceptionPointer);
}

alure::SampleType buffer_getSampleType(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alure::SampleType::UInt8;
  }

  auto func = [&dm]() -> alure::SampleType { return dm->obj.getSampleType(); };
  return wrapException_wrapFunction<decltype(func), alure::SampleType>(func, "Was the buffer removed?", exceptionPointer);
}

uint32_t buffer_getSize(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint32_t { return dm->obj.getSize(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "Was the buffer removed?", exceptionPointer);
}

void buffer_setLoopPoints(buffer_t* dm, alureLoopPoints_t points, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &points]() -> void { dm->obj.setLoopPoints(points.Start, points.End); };
  wrapException_wrapFunction<decltype(func), void>(func, "Was the buffer removed?", exceptionPointer);
}

alureLoopPoints_t buffer_getLoopPoints(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureLoopPoints();
  }


  auto func = [&dm]() -> std::pair<uint32_t, uint32_t> { return dm->obj.getLoopPoints(); };
  auto result = wrapException_wrapFunction<decltype(func), std::pair<uint32_t, uint32_t>>(func, "Was the buffer removed?", exceptionPointer);
  return alureLoopPoints(result.first, result.second);
}

sourceVector_t* buffer_getSources(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> alure::Vector<alure::Source> { return dm->obj.getSources(); };
  auto sources = wrapException_wrapFunction<decltype(func), alure::Vector<alure::Source>>(func, "Was the buffer removed?", exceptionPointer);
  if (exceptionPointer != nullptr && *static_cast<intptr_t*>(exceptionPointer) == 0)
  {
    std::vector<source_t*> final_result;
    for (auto& source : sources)
    {
      final_result.push_back(source_set(source));
    }

    return sourceVector_create(final_result);
  }
  else
  {
    return nullptr;
  }
}

wrapString_t* buffer_getName(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> wrapString_t* { return wrapString_create(dm->obj.getName().data()); };
  return wrapException_wrapFunction<decltype(func), wrapString_t*>(func, "Was the buffer removed?", exceptionPointer);
}

uint64_t buffer_getSourceCount(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint64_t { return dm->obj.getSourceCount(); };
  return wrapException_wrapFunction<decltype(func), uint64_t>(func, "Was the buffer removed?", exceptionPointer);
}
