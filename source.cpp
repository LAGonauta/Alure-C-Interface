#include "source.hpp"
#include "wrapException.hpp"

source_t* source_set(alure::Source sour)
{
  source_t* dm;

  dm = new source { .obj = sour };

  return dm;
}

void source_destroyPointer(source_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

void source_destroy(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.destroy(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_play(source_t* dm, buffer_t* buffer, void* exceptionPointer)
{
  if  (dm == nullptr || buffer == nullptr)
  {
    return;
  }

  auto func = [&dm, &buffer]() -> void { dm->obj.play(buffer->obj); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_stop(source_t* dm, void* exceptionPointer)
{
  if  (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.stop(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_fadeOutToStop(source_t* dm, float gain, int64_t duration, void* exceptionPointer)
{
  if  (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &gain, &duration]() -> void { dm->obj.fadeOutToStop(gain, std::chrono::milliseconds(duration)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_pause(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.pause(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_resume(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.resume(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

bool source_isPending(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.isPending(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

bool source_isPlaying(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.isPlaying(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

bool source_isPaused(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.isPaused(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

bool source_isPlayingOrPending(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.isPlayingOrPending(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

void source_setPriority(source_t* dm, uint32_t priority, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &priority]() -> void { dm->obj.setPriority(priority); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

uint32_t source_getPriority(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint32_t { return dm->obj.getPriority(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "", exceptionPointer);
}

void source_setOffset(source_t* dm, uint64_t offset, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &offset]() -> void { dm->obj.setOffset(offset); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

uint64_t source_getSampleOffset(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint64_t { return dm->obj.getSampleOffset(); };
  return wrapException_wrapFunction<decltype(func), uint64_t>(func, "", exceptionPointer);
}

double source_getSecOffset(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> double { return dm->obj.getSecOffset().count(); };
  return wrapException_wrapFunction<decltype(func), double>(func, "", exceptionPointer);
}

void source_setLooping(source_t* dm, bool looping, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &looping]() -> void { dm->obj.setLooping(looping); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

bool source_getLooping(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.getLooping(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

void source_setPitch(source_t* dm, float pitch, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &pitch]() -> void { dm->obj.setPitch(pitch); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getPitch(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getPitch(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setGain(source_t* dm, float gain, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &gain]() -> void { dm->obj.setGain(gain); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getGain(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getGain(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setGainRange(source_t* dm, float mingain, float maxgain, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &mingain, &maxgain]() -> void { dm->obj.setGainRange(mingain, maxgain); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getMinGain(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getMinGain(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

float source_getMaxGain(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getMaxGain(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setDistanceRange(source_t* dm, float refdist, float maxdist, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &refdist, &maxdist]() -> void { dm->obj.setDistanceRange(refdist, maxdist); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getReferenceDistance(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getReferenceDistance(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

float source_getMaxDistance(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getMaxDistance(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_set3DParameters(source_t* dm, const alureVector3* position, const alureVector3* velocity, const alureOrientation* orientation, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  auto func = [&dm, &position, &velocity, &orientation_pair]() -> void { dm->obj.set3DParameters(alure::Vector3(position->x, position->y, position->z), alure::Vector3(velocity->x, velocity->y, velocity->z), orientation_pair); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_setPosition(source_t* dm, const alureVector3* position, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &position]() -> void { dm->obj.setPosition(alure::Vector3(position->x, position->y, position->z)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureVector3 source_getPosition(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureVector3();
  }

  auto func = [&dm]() -> alure::Vector3 { return dm->obj.getPosition(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::Vector3>(func, "", exceptionPointer);
  return alureVector3{.x = result[0], .y = result[1], .z = result[2]};
}

void source_setVelocity(source_t* dm, const alureVector3* velocity, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &velocity]() -> void { dm->obj.setVelocity(alure::Vector3(velocity->x, velocity->y, velocity->z)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureVector3 source_getVelocity(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureVector3();
  }

  auto func = [&dm]() -> alure::Vector3 { return dm->obj.getVelocity(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::Vector3>(func, "", exceptionPointer);
  return alureVector3{.x = result[0], .y = result[1], .z = result[2]};
}

void source_setDirection(source_t* dm, const alureVector3* direction, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &direction]() -> void { dm->obj.setDirection(alure::Vector3(direction->x, direction->y, direction->z)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureVector3 source_getDirection(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureVector3();
  }

  auto func = [&dm]() -> alure::Vector3 { return dm->obj.getDirection(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::Vector3>(func, "", exceptionPointer);
  return alureVector3{.x = result[0], .y = result[1], .z = result[2]};
}

void source_setOrientation(source_t* dm, const alureOrientation* orientation, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }
  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  auto func = [&dm, &orientation_pair]() -> void { dm->obj.setOrientation(orientation_pair); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureOrientation source_getOrientation(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureOrientation();
  }

  auto func = [&dm]() -> std::pair<alure::Vector3, alure::Vector3>  { return dm->obj.getOrientation(); };
  auto result = wrapException_wrapFunction<decltype(func), std::pair<alure::Vector3, alure::Vector3>>(func, "", exceptionPointer);
  return alureOrientation{ .At = alureVector3{.x = result.first[0], .y = result.first[1], .z = result.first[2]}, .Up = alureVector3{.x = result.second[0], .y = result.second[1], .z = result.second[2]}};
}