#include "common.h"

#ifndef __WRAP_AUXILIARYEFFECTSLOT_H__
#define __WRAP_AUXILIARYEFFECTSLOT_H__

#ifdef __cplusplus
DLL_LOCAL alure::AuxiliaryEffectSlot auxiliaryEffectSlot_get(auxiliaryEffectSlot_t* dm);

extern "C"
{
#endif

DLL_PUBLIC auxiliaryEffectSlot_t* auxiliaryEffectSlot_set(alure::AuxiliaryEffectSlot effectSlot);
DLL_PUBLIC void auxiliaryEffectSlot_destroyPointer(auxiliaryEffectSlot_t* dm, void* exceptionPointer);
DLL_PUBLIC void auxiliaryEffectSlot_destroy(auxiliaryEffectSlot_t* dm, void* exceptionPointer);
DLL_PUBLIC void auxiliaryEffectSlot_setGain(auxiliaryEffectSlot_t* dm, float gain, void* exceptionPointer);
DLL_PUBLIC void auxiliaryEffectSlot_setSendAuto(auxiliaryEffectSlot_t* dm, bool sendauto, void* exceptionPointer);
DLL_PUBLIC void auxiliaryEffectSlot_applyEffect(auxiliaryEffectSlot_t* dm, effect_t* effect, void* exceptionPointer);
//DLL_PUBLIC Vector<SourceSend> auxiliaryEffectSlot_getSourceSends(auxiliaryEffectSlot_t* dm, void* exceptionPointer);
DLL_PUBLIC uint64_t auxiliaryEffectSlot_getUseCount(auxiliaryEffectSlot_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_AUXILIARYEFFECTSLOT_H__ */
