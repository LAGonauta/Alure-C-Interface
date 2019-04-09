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
// SourceGroup source_getGroup(source_t* dm, void* exceptionPointer) const;
void source_setPriority(source_t* dm, uint32_t priority, void* exceptionPointer);
uint32_t source_getPriority(source_t* dm, void* exceptionPointer);
void source_setOffset(source_t* dm, uint64_t offset, void* exceptionPointer);
// std::pair<uint64_t,std::chrono::nanoseconds> source_getSampleOffsetLatency() const;
uint64_t source_getSampleOffset(source_t* dm, void* exceptionPointer);
// std::pair<Seconds,Seconds> source_getSecOffsetLatency() const;
double source_getSecOffset(source_t* dm, void* exceptionPointer);
void source_setLooping(source_t* dm, bool looping, void* exceptionPointer);
bool source_getLooping(source_t* dm, void* exceptionPointer);
void source_setPitch(source_t* dm, float pitch, void* exceptionPointer);
float source_getPitch(source_t* dm, void* exceptionPointer);

void source_setGain(source_t* dm, float gain, void* exceptionPointer);
float source_getGain(source_t* dm, void* exceptionPointer);
void source_setGainRange(source_t* dm, float mingain, float maxgain, void* exceptionPointer);
// std::pair<ALfloat,ALfloat> source_getGainRange() const;
float source_getMinGain(source_t* dm, void* exceptionPointer);
float source_getMaxGain(source_t* dm, void* exceptionPointer);
void source_setDistanceRange(source_t* dm, float refdist, float maxdist, void* exceptionPointer);
//std::pair<ALfloat,ALfloat> source_getDistanceRange() const;
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

    // void source_setOrientation(const std::pair<Vector3,Vector3> &orientation);
    // std::pair<Vector3,Vector3> source_getOrientation() const;
    // void source_setConeAngles(ALfloat inner, ALfloat outer);
    // std::pair<ALfloat,ALfloat> source_getConeAngles() const;
    // ALfloat source_getInnerConeAngle() const { return std::get<0>(source_getConeAngles()); }
    // ALfloat source_getOuterConeAngle() const { return std::get<1>(source_getConeAngles()); }
    // void source_setOuterConeGains(ALfloat gain, ALfloat gainhf=1.0f);
    // std::pair<ALfloat,ALfloat> source_getOuterConeGains() const;
    // ALfloat source_getOuterConeGain() const { return std::get<0>(getOuterConeGains()); }
    // ALfloat source_getOuterConeGainHF() const { return std::get<1>(getOuterConeGains()); }
    // void source_setRolloffFactors(ALfloat factor, ALfloat roomfactor=0.0f);
    // std::pair<ALfloat,ALfloat> source_getRolloffFactors() const;
    // ALfloat source_getRolloffFactor() const { return std::get<0>(getRolloffFactors()); }
    // ALfloat source_getRoomRolloffFactor() const { return std::get<1>(getRolloffFactors()); }
    // void source_setDopplerFactor(ALfloat factor);
    // ALfloat source_getDopplerFactor() const;
    // void source_setRelative(bool relative);
    // bool source_getRelative() const;
    // void source_setRadius(ALfloat radius);
    // ALfloat source_getRadius() const;
    // void source_setStereoAngles(ALfloat leftAngle, ALfloat rightAngle);
    // std::pair<ALfloat,ALfloat> source_getStereoAngles() const;
    // void source_set3DSpatialize(Spatialize spatialize);
    // Spatialize source_get3DSpatialize() const;
    // void source_setResamplerIndex(ALsizei index);
    // ALsizei source_getResamplerIndex() const;
    // void source_setAirAbsorptionFactor(ALfloat factor);
    // ALfloat source_getAirAbsorptionFactor() const;
    // void source_setGainAuto(bool directhf, bool send, bool sendhf);
    // std::tuple<bool,bool,bool> source_getGainAuto() const;
    // bool source_getDirectGainHFAuto() const { return std::get<0>(source_getGainAuto()); }
    // bool source_getSendGainAuto() const { return std::get<1>(source_getGainAuto()); }
    // bool source_getSendGainHFAuto() const { return std::get<2>(source_getGainAuto()); }
    // void source_setDirectFilter(const FilterParams &filter);
    // void source_setSendFilter(ALuint send, const FilterParams &filter);
    // void source_setAuxiliarySend(AuxiliaryEffectSlot slot, ALuint send);
    // void source_setAuxiliarySendFilter(AuxiliaryEffectSlot slot, ALuint send, const FilterParams &filter);
void source_destroy(source_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_SOURCE_H__ */
