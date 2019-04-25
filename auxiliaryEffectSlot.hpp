#include "common.h"

#ifndef __WRAP_AUXILIARYEFFECTSLOT_H__
#define __WRAP_AUXILIARYEFFECTSLOT_H__

#ifdef __cplusplus
extern "C" {
#endif

auxiliaryEffectSlot_t* auxiliaryEffectSlot_set(alure::AuxiliaryEffectSlot effectSlot);
alure::AuxiliaryEffectSlot auxiliaryEffectSlot_get(auxiliaryEffectSlot_t* dm);
void auxiliaryEffectSlot_destroyPointer(auxiliaryEffectSlot_t* dm, void* exceptionPointer);
void auxiliaryEffectSlot_destroy(auxiliaryEffectSlot_t* dm, void* exceptionPointer);

void auxiliaryEffectSlot_setGain(auxiliaryEffectSlot_t* dm, float gain, void* exceptionPointer);
void auxiliaryEffectSlot_setSendAuto(auxiliaryEffectSlot_t* dm, bool sendauto, void* exceptionPointer);
void auxiliaryEffectSlot_applyEffect(auxiliaryEffectSlot_t* dm, effect_t* effect, void* exceptionPointer);
//Vector<SourceSend> auxiliaryEffectSlot_getSourceSends(auxiliaryEffectSlot_t* dm, void* exceptionPointer);
uint64_t auxiliaryEffectSlot_getUseCount(auxiliaryEffectSlot_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_AUXILIARYEFFECTSLOT_H__ */
