#include "source.hpp"
#include "wrapException.hpp"

source_t* source_set(alure::Source sour)
{
  source_t* dm;

  dm = new source_t(sour);

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

alureGainRange_t source_getGainRange(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureGainRange();
  }

  auto func = [&dm]() -> std::pair<float, float> { return dm->obj.getGainRange(); };
  auto result = wrapException_wrapFunction<decltype(func), std::pair<float, float>>(func, "", exceptionPointer);
  return alureGainRange(result.first, result.second);
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

alureDistanceRange_t source_getDistanceRange(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureDistanceRange();
  }

  auto func = [&dm]() -> std::pair<float, float> { return dm->obj.getDistanceRange(); };
  auto result = wrapException_wrapFunction<decltype(func), std::pair<float, float>>(func, "", exceptionPointer);
  return alureDistanceRange(result.first, result.second);
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

void source_set3DParameters(source_t* dm, const alureVector3_t* position, const alureVector3_t* velocity, const alureOrientation_t* orientation, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  auto func = [&dm, &position, &velocity, &orientation_pair]() -> void { dm->obj.set3DParameters(alure::Vector3(position->x, position->y, position->z), alure::Vector3(velocity->x, velocity->y, velocity->z), orientation_pair); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void source_setPosition(source_t* dm, const alureVector3_t* position, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &position]() -> void { dm->obj.setPosition(alure::Vector3(position->x, position->y, position->z)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureVector3_t source_getPosition(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureVector3();
  }

  auto func = [&dm]() -> alure::Vector3 { return dm->obj.getPosition(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::Vector3>(func, "", exceptionPointer);
  return alureVector3(result[0], result[1], result[2]);
}

void source_setVelocity(source_t* dm, const alureVector3_t* velocity, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &velocity]() -> void { dm->obj.setVelocity(alure::Vector3(velocity->x, velocity->y, velocity->z)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureVector3_t source_getVelocity(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureVector3();
  }

  auto func = [&dm]() -> alure::Vector3 { return dm->obj.getVelocity(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::Vector3>(func, "", exceptionPointer);
  return alureVector3(result[0], result[1], result[2]);
}

void source_setDirection(source_t* dm, const alureVector3_t* direction, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &direction]() -> void { dm->obj.setDirection(alure::Vector3(direction->x, direction->y, direction->z)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureVector3_t source_getDirection(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureVector3();
  }

  auto func = [&dm]() -> alure::Vector3 { return dm->obj.getDirection(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::Vector3>(func, "", exceptionPointer);
  return alureVector3(result[0], result[1], result[2]);
}

void source_setOrientation(source_t* dm, const alureOrientation_t* orientation, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  auto func = [&dm, &orientation_pair]() -> void { dm->obj.setOrientation(orientation_pair); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

alureOrientation_t source_getOrientation(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return alureOrientation();
  }

  auto func = [&dm]() -> std::pair<alure::Vector3, alure::Vector3>  { return dm->obj.getOrientation(); };
  auto result = wrapException_wrapFunction<decltype(func), std::pair<alure::Vector3, alure::Vector3>>(func, "", exceptionPointer);
  return alureOrientation(alureVector3(result.first[0], result.first[1], result.first[2]), alureVector3(result.second[0], result.second[1], result.second[2]));
}

void source_setConeAngles(source_t* dm, float inner, float outer, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &inner, &outer]() -> void { dm->obj.setConeAngles(inner, outer); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}
// std::pair<float,float> source_getConeAngles(source_t* dm, void* exceptionPointer);

float source_getInnerConeAngle(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getInnerConeAngle(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

float source_getOuterConeAngle(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getOuterConeAngle(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setOuterConeGains(source_t* dm, float gain, float gainhf, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &gain, &gainhf]() -> void { dm->obj.setOuterConeGains(gain, gainhf); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

// std::pair<float,float> source_getOuterConeGains(source_t* dm, void* exceptionPointer);

float source_getOuterConeGain(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getOuterConeGain(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

float source_getOuterConeGainHF(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getOuterConeGainHF(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setRolloffFactors(source_t* dm, float factor, float roomfactor, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &factor, &roomfactor]() -> void { dm->obj.setRolloffFactors(factor, roomfactor); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

// std::pair<float,float> source_getRolloffFactors(source_t* dm, void* exceptionPointer);

float source_getRolloffFactor(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getRolloffFactor(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

float source_getRoomRolloffFactor(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getRoomRolloffFactor(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setDopplerFactor(source_t* dm, float factor, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &factor]() -> void { dm->obj.setDopplerFactor(factor); };
  return wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getDopplerFactor(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getDopplerFactor(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setRelative(source_t* dm, bool relative, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &relative]() -> void { dm->obj.setRelative(relative); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

bool source_getRelative(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.getRelative(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

void source_setRadius(source_t* dm, float radius, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &radius]() -> void { dm->obj.setRadius(radius); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getRadius(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getRadius(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setStereoAngles(source_t* dm, float leftAngle, float rightAngle, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &leftAngle, &rightAngle]() -> void { dm->obj.setStereoAngles(leftAngle, rightAngle); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);  
}

// std::pair<float,float> source_getStereoAngles(source_t* dm, void* exceptionPointer);

//void source_set3DSpatialize(source_t* dm, Spatialize spatialize, void* exceptionPointer);

//Spatialize source_get3DSpatialize(source_t* dm, void* exceptionPointer);

void source_setResamplerIndex(source_t* dm, uint32_t index, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &index]() -> void { dm->obj.setResamplerIndex(index); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);  
}

uint32_t source_getResamplerIndex(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint32_t { return dm->obj.getResamplerIndex(); };
  return wrapException_wrapFunction<decltype(func), uint32_t>(func, "", exceptionPointer);
}

void source_setAirAbsorptionFactor(source_t* dm, float factor, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &factor]() -> void { dm->obj.setAirAbsorptionFactor(factor); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

float source_getAirAbsorptionFactor(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> float { return dm->obj.getAirAbsorptionFactor(); };
  return wrapException_wrapFunction<decltype(func), float>(func, "", exceptionPointer);
}

void source_setGainAuto(source_t* dm, bool directhf, bool send, bool sendhf, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &directhf, &send, &sendhf]() -> void { dm->obj.setGainAuto(directhf, send, sendhf); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

//std::tuple<bool,bool,bool> source_getGainAuto(source_t* dm, void* exceptionPointer);

bool source_getDirectGainHFAuto(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.getDirectGainHFAuto(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

bool source_getSendGainAuto(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.getSendGainAuto(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

bool source_getSendGainHFAuto(source_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm]() -> bool { return dm->obj.getSendGainHFAuto(); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

// void source_setDirectFilter(source_t* dm, const FilterParams &filter, void* exceptionPointer);
// void source_setSendFilter(source_t* dm, ALuint send, const FilterParams &filter, void* exceptionPointer);
// void source_setAuxiliarySend(source_t* dm, AuxiliaryEffectSlot slot, ALuint send, void* exceptionPointer);
// void source_setAuxiliarySendFilter(source_t* dm, AuxiliaryEffectSlot slot, ALuint send, const FilterParams &filter, void* exceptionPointer);