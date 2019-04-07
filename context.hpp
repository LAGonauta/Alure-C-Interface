#include "common.h"

#ifndef __WRAP_CONTEXT_H__
#define __WRAP_CONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif

void context_makeCurrent(context_t* ctx); //static
context_t* context_getCurrent(); //static

void context_makeThreadCurrent(context_t* ctx); //static
context_t* context_getThreadCurrent(); //static

context_t* context_set(alure::Context ctx);
void context_destroy(context_t* dm);
void context_destroyPointer(context_t* dm);

device_t* context_getDevice(context_t* dm);

void context_startBatch(context_t* dm);
void context_endBatch(context_t* dm);

listener_t* context_getListener(context_t* dm);

// SharedPtr<MessageHandler> setMessageHandler(SharedPtr<MessageHandler> handler);
// SharedPtr<MessageHandler> getMessageHandler() const;

// interval in ms
void context_setAsyncWakeInterval(context_t* dm, uint64_t interval);
int64_t context_getAsyncWakeInterval(context_t* dm);

//SharedPtr<Decoder> context_createDecoder(context_t* dm, StringView name);

bool context_isSupported(context_t* dm, alure::ChannelConfig channels, alure::SampleType type);

wrapStringVector_t* context_getAvailableResamplers(context_t* dm);
int32_t context_getDefaultResamplerIndex(context_t* dm);

buffer_t* context_getBuffer(context_t* dm, const char* name);
//SharedFuture<Buffer> getBufferAsync(StringView name);
//void precacheBuffersAsync(ArrayView<StringView> names);
//Buffer createBufferFrom(StringView name, SharedPtr<Decoder> decoder);
//SharedFuture<Buffer> createBufferAsyncFrom(StringView name, SharedPtr<Decoder> decoder);
//Buffer findBuffer(StringView name);
//SharedFuture<Buffer> findBufferAsync(StringView name);

void context_removeBuffer(context_t* dm, const char* name);
//void removeBuffer(Buffer buffer);

// Source createSource();
// AuxiliaryEffectSlot createAuxiliaryEffectSlot();
// Effect createEffect();
// SourceGroup createSourceGroup();

void context_setDopplerFactor(context_t* dm, float factor);
void context_setSpeedOfSound(context_t* dm, float speed);
void context_setDistanceModel(context_t* dm, alure::DistanceModel model);

void context_update(context_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_CONTEXT_H__ */


