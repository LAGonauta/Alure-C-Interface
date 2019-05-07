#include "common.h"

#ifndef __WRAP_SOURCE_H__
#define __WRAP_SOURCE_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC source_t* source_set(alure::Source ctx);
DLL_PUBLIC void source_destroyPointer(source_t* dm);
DLL_PUBLIC void source_play(source_t* dm, buffer_t* buffer, void* exceptionPointer);
//DLL_PUBLIC void source_play(SharedPtr<Decoder> decoder, ALsizei chunk_len, ALsizei queue_size);
//DLL_PUBLIC void source_play(SharedFuture<Buffer> future_buffer);
DLL_PUBLIC void source_stop(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_fadeOutToStop(source_t* dm, float gain, int64_t duration, void* exceptionPointer);
DLL_PUBLIC void source_pause(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_resume(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_isPending(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_isPlaying(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_isPaused(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_isPlayingOrPending(source_t* dm, void* exceptionPointer);
//DLL_PUBLIC void source_setGroup(SourceGroup group);
//DLL_PUBLIC SourceGroup source_getGroup(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setPriority(source_t* dm, uint32_t priority, void* exceptionPointer);
DLL_PUBLIC uint32_t source_getPriority(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setOffset(source_t* dm, uint64_t offset, void* exceptionPointer);
//DLL_PUBLIC std::pair<uint64_t,std::chrono::nanoseconds> source_getSampleOffsetLatency(source_t* dm, void* exceptionPointer);
DLL_PUBLIC uint64_t source_getSampleOffset(source_t* dm, void* exceptionPointer);
//DLL_PUBLIC std::pair<Seconds,Seconds> source_getSecOffsetLatency(source_t* dm, void* exceptionPointer);
DLL_PUBLIC double source_getSecOffset(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setLooping(source_t* dm, bool looping, void* exceptionPointer);
DLL_PUBLIC bool source_getLooping(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setPitch(source_t* dm, float pitch, void* exceptionPointer);
DLL_PUBLIC float source_getPitch(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setGain(source_t* dm, float gain, void* exceptionPointer);
DLL_PUBLIC float source_getGain(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setGainRange(source_t* dm, float mingain, float maxgain, void* exceptionPointer);
DLL_PUBLIC alureGainRange_t source_getGainRange(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getMinGain(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getMaxGain(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setDistanceRange(source_t* dm, float refdist, float maxdist, void* exceptionPointer);
DLL_PUBLIC alureDistanceRange_t source_getDistanceRange(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getReferenceDistance(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getMaxDistance(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_set3DParameters(source_t* dm, const alureVector3_t* position, const alureVector3_t* velocity, const alureOrientation_t* orientation, void* exceptionPointer);
DLL_PUBLIC void source_setPosition(source_t* dm, const alureVector3_t* position, void* exceptionPointer);
DLL_PUBLIC alureVector3_t source_getPosition(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setVelocity(source_t* dm, const alureVector3_t* velocity, void* exceptionPointer);
DLL_PUBLIC alureVector3_t source_getVelocity(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setDirection(source_t* dm, const alureVector3_t* direction, void* exceptionPointer);
DLL_PUBLIC alureVector3_t source_getDirection(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setOrientation(source_t* dm, const alureOrientation_t* orientation, void* exceptionPointer);
DLL_PUBLIC alureOrientation_t source_getOrientation(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setConeAngles(source_t* dm, float inner, float outer, void* exceptionPointer);
DLL_PUBLIC alureConeAngles_t source_getConeAngles(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getInnerConeAngle(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getOuterConeAngle(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setOuterConeGains(source_t* dm, float gain, float gainhf, void* exceptionPointer); //gainhf default = 1.0f
DLL_PUBLIC alureOuterConeGains_t source_getOuterConeGains(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getOuterConeGain(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getOuterConeGainHF(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setRolloffFactors(source_t* dm, float factor, float roomfactor, void* exceptionPointer); //roomfactor default = 0.0f
DLL_PUBLIC alureRolloffFactors_t source_getRolloffFactors(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getRolloffFactor(source_t* dm, void* exceptionPointer);
DLL_PUBLIC float source_getRoomRolloffFactor(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setDopplerFactor(source_t* dm, float factor, void* exceptionPointer);
DLL_PUBLIC float source_getDopplerFactor(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setRelative(source_t* dm, bool relative, void* exceptionPointer);
DLL_PUBLIC bool source_getRelative(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setRadius(source_t* dm, float radius, void* exceptionPointer);
DLL_PUBLIC float source_getRadius(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setStereoAngles(source_t* dm, float leftAngle, float rightAngle, void* exceptionPointer);
DLL_PUBLIC alureStereoAngles_t source_getStereoAngles(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_set3DSpatialize(source_t* dm, alure::Spatialize spatialize, void* exceptionPointer);
DLL_PUBLIC alure::Spatialize source_get3DSpatialize(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setResamplerIndex(source_t* dm, uint32_t index, void* exceptionPointer);
DLL_PUBLIC uint32_t source_getResamplerIndex(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setAirAbsorptionFactor(source_t* dm, float factor, void* exceptionPointer);
DLL_PUBLIC float source_getAirAbsorptionFactor(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setGainAuto(source_t* dm, bool directhf, bool send, bool sendhf, void* exceptionPointer);
DLL_PUBLIC gainsAuto_t source_getGainAuto(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_getDirectGainHFAuto(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_getSendGainAuto(source_t* dm, void* exceptionPointer);
DLL_PUBLIC bool source_getSendGainHFAuto(source_t* dm, void* exceptionPointer);
DLL_PUBLIC void source_setDirectFilter(source_t* dm, alure::FilterParams* filter, void* exceptionPointer);
DLL_PUBLIC void source_setSendFilter(source_t* dm, uint32_t send, alure::FilterParams* filter, void* exceptionPointer);
DLL_PUBLIC void source_setAuxiliarySend(source_t* dm, auxiliaryEffectSlot_t* slot, uint32_t send, void* exceptionPointer);
DLL_PUBLIC void source_setAuxiliarySendFilter(source_t* dm, auxiliaryEffectSlot_t* slot, uint32_t send, alure::FilterParams* filter, void* exceptionPointer);
DLL_PUBLIC void source_destroy(source_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_SOURCE_H__ */
