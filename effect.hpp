#include "common.h"

#ifndef __WRAP_EFFECT_H__
#define __WRAP_EFFECT_H__

#ifdef __cplusplus
DLL_LOCAL alure::Effect effect_get(effect_t* dm);

extern "C"
{
#endif

DLL_PUBLIC effect_t* effect_set(alure::Effect effect);
DLL_PUBLIC void effect_destroyPointer(effect_t* dm, void* exceptionPointer);
DLL_PUBLIC void effect_destroy(effect_t* dm, void* exceptionPointer);
DLL_PUBLIC void effect_setReverbProperties(effect_t* dm, const EFXEAXREVERBPROPERTIES& props, void* exceptionPointer);
DLL_PUBLIC void effect_setChorusProperties(effect_t* dm, const EFXCHORUSPROPERTIES& props, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_EFFECT_H__ */
