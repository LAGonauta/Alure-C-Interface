#include "effect.hpp"
#include "wrapException.hpp"

effect_t* effect_set(alure::Effect eff)
{
  effect_t* dm;

  dm = new effect(eff);

  return dm;
}

alure::Effect effect_get(effect_t* dm)
{
  if (dm == nullptr)
  {
    return alure::Effect();
  }

  return dm->obj;
}

void effect_destroy(effect_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.destroy(); };
  wrapException_wrapFunction(func, "", exceptionPointer);
}

void effect_destroyPointer(effect_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { delete dm; };
  wrapException_wrapFunction(func, "", exceptionPointer);
}

void effect_setReverbProperties(effect_t* dm, const EFXEAXREVERBPROPERTIES& props, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &props]() -> void { dm->obj.setReverbProperties(props); };
  wrapException_wrapFunction(func, "", exceptionPointer);
}

void effect_setChorusProperties(effect_t* dm, const EFXCHORUSPROPERTIES& props, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &props]() -> void { dm->obj.setChorusProperties(props); };
  wrapException_wrapFunction(func, "", exceptionPointer);
}