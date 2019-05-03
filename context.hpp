#include "common.h"

#ifndef __WRAP_CONTEXT_H__
#define __WRAP_CONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif

void context_makeCurrent(context_t* ctx, void* exceptionPointer); //static
context_t* context_getCurrent(void* exceptionPointer); //static

void context_makeThreadCurrent(context_t* ctx, void* exceptionPointer); //static
context_t* context_getThreadCurrent(void* exceptionPointer); //static

context_t* context_set(alure::Context ctx);
void context_destroy(context_t* dm);
void context_destroyPointer(context_t* dm);

device_t* context_getDevice(context_t* dm, void* exceptionPointer);

void context_startBatch(context_t* dm, void* exceptionPointer);
void context_endBatch(context_t* dm, void* exceptionPointer);

listener_t* context_getListener(context_t* dm, void* exceptionPointer);

// SharedPtr<MessageHandler> setMessageHandler(SharedPtr<MessageHandler> handler, void* exceptionPointer);
// SharedPtr<MessageHandler> getMessageHandler() const;

// interval in ms
void context_setAsyncWakeInterval(context_t* dm, uint64_t interval, void* exceptionPointer);
int64_t context_getAsyncWakeInterval(context_t* dm, void* exceptionPointer);

//SharedPtr<Decoder> context_createDecoder(context_t* dm, StringView name);

bool context_isSupported(context_t* dm, alure::ChannelConfig channels, alure::SampleType type, void* exceptionPointer);

wrapStringVector_t* context_getAvailableResamplers(context_t* dm, void* exceptionPointer);
int32_t context_getDefaultResamplerIndex(context_t* dm, void* exceptionPointer);

buffer_t* context_getBuffer(context_t* dm, const char* name, void* exceptionPointer);
//SharedFuture<Buffer> getBufferAsync(StringView name);
//void precacheBuffersAsync(ArrayView<StringView> names);
//Buffer createBufferFrom(StringView name, SharedPtr<Decoder> decoder);
//SharedFuture<Buffer> createBufferAsyncFrom(StringView name, SharedPtr<Decoder> decoder);
//Buffer findBuffer(StringView name);
//SharedFuture<Buffer> findBufferAsync(StringView name);

void context_removeBuffer(context_t* dm, const char* name, void* exceptionPointer);
//void removeBuffer(Buffer buffer);

source_t* context_createSource(context_t* dm, void* exceptionPointer);
auxiliaryEffectSlot_t* context_createAuxiliaryEffectSlot(context_t* dm, void* exceptionPointer);
effect_t* context_createEffect(context_t* dm, void* exceptionPointer);
// SourceGroup createSourceGroup();

void context_setDopplerFactor(context_t* dm, float factor, void* exceptionPointer);
void context_setSpeedOfSound(context_t* dm, float speed, void* exceptionPointer);
void context_setDistanceModel(context_t* dm, alure::DistanceModel model, void* exceptionPointer);

void context_update(context_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_CONTEXT_H__ */


