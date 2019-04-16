#include "common.h"

#ifndef __WRAP_SOURCE_H__
#define __WRAP_SOURCE_H__

#ifdef __cplusplus
extern "C" {
#endif

// , void* exceptionPointer

source_t* source_set(alure::Source ctx);
void source_destroyPointer(source_t* dm);

void source_play(source_t* dm, buffer_t* buffer, void* exceptionPointer);
// void source_play(SharedPtr<Decoder> decoder, ALsizei chunk_len, ALsizei queue_size);
// void source_play(SharedFuture<Buffer> future_buffer);
void source_stop(source_t* dm, void* exceptionPointer);
void source_fadeOutToStop(source_t* dm, float gain, int64_t duration, void* exceptionPointer);
void source_pause(source_t* dm, void* exceptionPointer);
void source_resume(source_t* dm, void* exceptionPointer);
bool source_isPending(source_t* dm, void* exceptionPointer);
bool source_isPlaying(source_t* dm, void* exceptionPointer);
bool source_isPaused(source_t* dm, void* exceptionPointer);
bool source_isPlayingOrPending(source_t* dm, void* exceptionPointer);
// void source_setGroup(SourceGroup group);
// SourceGroup source_getGroup(source_t* dm, void* exceptionPointer);
void source_setPriority(source_t* dm, uint32_t priority, void* exceptionPointer);
uint32_t source_getPriority(source_t* dm, void* exceptionPointer);
void source_setOffset(source_t* dm, uint64_t offset, void* exceptionPointer);
// std::pair<uint64_t,std::chrono::nanoseconds> source_getSampleOffsetLatency(source_t* dm, void* exceptionPointer);
uint64_t source_getSampleOffset(source_t* dm, void* exceptionPointer);
// std::pair<Seconds,Seconds> source_getSecOffsetLatency(source_t* dm, void* exceptionPointer);
double source_getSecOffset(source_t* dm, void* exceptionPointer);
void source_setLooping(source_t* dm, bool looping, void* exceptionPointer);
bool source_getLooping(source_t* dm, void* exceptionPointer);
void source_setPitch(source_t* dm, float pitch, void* exceptionPointer);
float source_getPitch(source_t* dm, void* exceptionPointer);

void source_setGain(source_t* dm, float gain, void* exceptionPointer);
float source_getGain(source_t* dm, void* exceptionPointer);
void source_setGainRange(source_t* dm, float mingain, float maxgain, void* exceptionPointer);
alureGainRange source_getGainRange(source_t* dm, void* exceptionPointer);
float source_getMinGain(source_t* dm, void* exceptionPointer);
float source_getMaxGain(source_t* dm, void* exceptionPointer);
void source_setDistanceRange(source_t* dm, float refdist, float maxdist, void* exceptionPointer);
alureDistanceRange source_getDistanceRange(source_t* dm, void* exceptionPointer);
float source_getReferenceDistance(source_t* dm, void* exceptionPointer);
float source_getMaxDistance(source_t* dm, void* exceptionPointer);

void source_set3DParameters(source_t* dm, const alureVector3* position, const alureVector3* velocity, const alureOrientation* orientation, void* exceptionPointer);
void source_setPosition(source_t* dm, const alureVector3* position, void* exceptionPointer);
alureVector3 source_getPosition(source_t* dm, void* exceptionPointer);
void source_setVelocity(source_t* dm, const alureVector3* velocity, void* exceptionPointer);
alureVector3 source_getVelocity(source_t* dm, void* exceptionPointer);
void source_setDirection(source_t* dm, const alureVector3 &direction, void* exceptionPointer);
alureVector3 source_getDirection(source_t* dm, void* exceptionPointer);
void source_setOrientation(source_t* dm, const alureOrientation orientation, void* exceptionPointer);
alureOrientation source_getOrientation(source_t* dm, void* exceptionPointer);
void source_setConeAngles(source_t* dm, float inner, float outer, void* exceptionPointer);
// std::pair<float,float> source_getConeAngles(source_t* dm, void* exceptionPointer);
float source_getInnerConeAngle(source_t* dm, void* exceptionPointer);
float source_getOuterConeAngle(source_t* dm, void* exceptionPointer);
void source_setOuterConeGains(source_t* dm, float gain, float gainhf, void* exceptionPointer); //gainhf default = 1.0f
// std::pair<float,float> source_getOuterConeGains(source_t* dm, void* exceptionPointer);
float source_getOuterConeGain(source_t* dm, void* exceptionPointer);
float source_getOuterConeGainHF(source_t* dm, void* exceptionPointer);
void source_setRolloffFactors(source_t* dm, float factor, float roomfactor, void* exceptionPointer); //roomfactor default = 0.0f
// std::pair<float,float> source_getRolloffFactors(source_t* dm, void* exceptionPointer);
float source_getRolloffFactor(source_t* dm, void* exceptionPointer);
float source_getRoomRolloffFactor(source_t* dm, void* exceptionPointer);
void source_setDopplerFactor(source_t* dm, float factor, void* exceptionPointer);
float source_getDopplerFactor(source_t* dm, void* exceptionPointer);
void source_setRelative(source_t* dm, bool relative, void* exceptionPointer);
bool source_getRelative(source_t* dm, void* exceptionPointer);
void source_setRadius(source_t* dm, float radius, void* exceptionPointer);
float source_getRadius(source_t* dm, void* exceptionPointer);
void source_setStereoAngles(source_t* dm, float leftAngle, float rightAngle, void* exceptionPointer);
// std::pair<float,float> source_getStereoAngles(source_t* dm, void* exceptionPointer);
//void source_set3DSpatialize(source_t* dm, Spatialize spatialize, void* exceptionPointer);
//Spatialize source_get3DSpatialize(source_t* dm, void* exceptionPointer);
void source_setResamplerIndex(source_t* dm, uint32_t index, void* exceptionPointer);
uint32_t source_getResamplerIndex(source_t* dm, void* exceptionPointer);
void source_setAirAbsorptionFactor(source_t* dm, float factor, void* exceptionPointer);
float source_getAirAbsorptionFactor(source_t* dm, void* exceptionPointer);
void source_setGainAuto(source_t* dm, bool directhf, bool send, bool sendhf, void* exceptionPointer);
//std::tuple<bool,bool,bool> source_getGainAuto(source_t* dm, void* exceptionPointer);
bool source_getDirectGainHFAuto(source_t* dm, void* exceptionPointer);
bool source_getSendGainAuto(source_t* dm, void* exceptionPointer);
bool source_getSendGainHFAuto(source_t* dm, void* exceptionPointer);
// void source_setDirectFilter(source_t* dm, const FilterParams &filter, void* exceptionPointer);
// void source_setSendFilter(source_t* dm, ALuint send, const FilterParams &filter, void* exceptionPointer);
// void source_setAuxiliarySend(source_t* dm, AuxiliaryEffectSlot slot, ALuint send, void* exceptionPointer);
// void source_setAuxiliarySendFilter(source_t* dm, AuxiliaryEffectSlot slot, ALuint send, const FilterParams &filter, void* exceptionPointer);
void source_destroy(source_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_SOURCE_H__ */
