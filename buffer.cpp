#include "buffer.hpp"
#include "wrapException.hpp"

buffer_t* buffer_set(alure::Buffer buf)
{
  buffer_t* dm;

  dm = new buffer;
  dm->obj = buf;

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

  auto func = [dm]() -> uint32_t { return dm->obj.getLength(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "Was the buffer removed?", exceptionPointer);
}

uint32_t buffer_getFrequency(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [dm]() -> uint32_t { return dm->obj.getFrequency(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "Was the buffer removed?", exceptionPointer);
}

alure::ChannelConfig buffer_getChannelConfig(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alure::ChannelConfig::Mono;
  }

  auto func = [dm]() -> alure::ChannelConfig { return dm->obj.getChannelConfig(); };
  return wrapException_wrapFunction<decltype(func), alure::ChannelConfig>(func, "Was the buffer removed?", exceptionPointer);
}

alure::SampleType buffer_getSampleType(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alure::SampleType::UInt8;
  }

  auto func = [dm]() -> alure::SampleType { return dm->obj.getSampleType(); };
  return wrapException_wrapFunction<decltype(func), alure::SampleType>(func, "Was the buffer removed?", exceptionPointer);
}

uint32_t buffer_getSize(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [dm]() -> uint32_t { return dm->obj.getSize(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "Was the buffer removed?", exceptionPointer);
}

void buffer_setLoopPoints(buffer_t* dm, alureLoopPoints points, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [dm, points]() -> void { return dm->obj.setLoopPoints(points.Start, points.End); };
  return wrapException_wrapFunction<decltype(func), void>(func, "Was the buffer removed?", exceptionPointer);
}

alureLoopPoints buffer_getLoopPoints(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureLoopPoints() = {0, 0};
  }

  try
  {
  auto points = dm->obj.getLoopPoints();
  return alureLoopPoints() = {points.first, points.second};
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << "Exception getting buffer loopPoints: " << e.what() << ". Was the buffer removed?" << std::endl;
    return alureLoopPoints() = {0, 0};
  }
}
//Vector<Source> buffer_getSources(buffer_t* dm, void* exceptionPointer);

const char* buffer_getName(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return dm->obj.getName().begin();
}

uint64_t buffer_getSourceCount(buffer_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.getSourceCount();
}
