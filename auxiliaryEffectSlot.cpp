#include "auxiliaryEffectSlot.hpp"
#include "effect.hpp"
#include "wrapException.hpp"

auxiliaryEffectSlot_t* auxiliaryEffectSlot_set(alure::AuxiliaryEffectSlot effectSlot)
{
  auxiliaryEffectSlot_t* dm;

  dm = new auxiliaryEffectSlot(effectSlot);

  return dm;
}

alure::AuxiliaryEffectSlot auxiliaryEffectSlot_get(auxiliaryEffectSlot_t* dm)
{
  if (dm == nullptr)
  {
    return alure::AuxiliaryEffectSlot();
  }

  return dm->obj;
}

void auxiliaryEffectSlot_destroy(auxiliaryEffectSlot_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.destroy(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void auxiliaryEffectSlot_destroyPointer(auxiliaryEffectSlot_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { delete dm; };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void auxiliaryEffectSlot_setGain(auxiliaryEffectSlot_t* dm, float gain, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &gain]() -> void { dm->obj.setGain(gain); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void auxiliaryEffectSlot_setSendAuto(auxiliaryEffectSlot_t* dm, bool sendAuto, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &sendAuto]() -> void { dm->obj.setSendAuto(sendAuto); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void auxiliaryEffectSlot_applyEffect(auxiliaryEffectSlot_t* dm, effect_t* effect, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &effect]() -> void { dm->obj.applyEffect(effect_get(effect)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

//Vector<SourceSend> auxiliaryEffectSlot_getSourceSends(auxiliaryEffectSlot_t* dm, void* exceptionPointer);

uint64_t auxiliaryEffectSlot_getUseCount(auxiliaryEffectSlot_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> uint64_t { return dm->obj.getUseCount(); };
  return wrapException_wrapFunction<decltype(func), uint64_t>(func, "", exceptionPointer);
}