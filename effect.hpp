#include "common.h"

#ifndef __WRAP_EFFECT_H__
#define __WRAP_EFFECT_H__

#ifdef __cplusplus
extern "C" {
#endif

effect_t* effect_set(alure::Effect effect);
void effect_destroyPointer(effect_t* dm, void* exceptionPointer);
void effect_destroy(effect_t* dm, void* exceptionPointer);

void effect_setReverbProperties(effect_t* dm, const EFXEAXREVERBPROPERTIES& props, void* exceptionPointer);
void effect_setChorusProperties(effect_t* dm, const EFXCHORUSPROPERTIES& props, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_EFFECT_H__ */
