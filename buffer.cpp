#include "buffer.hpp"

struct buffer {
  alure::Buffer obj;
};

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

uint32_t buffer_getLength(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  try
  {
    return dm->obj.getLength();
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << "Exception getting buffer length: " << e.what() << ". Was the buffer removed?" << std::endl;
    return 0;
  }
}

uint32_t buffer_getFrequency(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.getFrequency();
}
alure::ChannelConfig buffer_getChannelConfig(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return alure::ChannelConfig::Mono;
  }

  return dm->obj.getChannelConfig();
}

alure::SampleType buffer_getSampleType(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return alure::SampleType::UInt8;
  }

  return dm->obj.getSampleType();
}

uint32_t buffer_getSize(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  try
  {
    return dm->obj.getSize();
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << "Exception getting buffer size: " << e.what() << ". Was the buffer removed?" << std::endl;
    return 0;
  }

  
}

void buffer_setLoopPoints(buffer_t* dm, alureLoopPoints points)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setLoopPoints(points.Start, points.End);
}

alureLoopPoints buffer_getLoopPoints(buffer_t* dm)
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
//Vector<Source> buffer_getSources(buffer_t* dm);

const char* buffer_getName(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return dm->obj.getName().begin();
}

uint64_t buffer_getSourceCount(buffer_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.getSourceCount();
}
