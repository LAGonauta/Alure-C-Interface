#include "common.h"

#ifndef __WRAP_CONTEXT_H__
#define __WRAP_CONTEXT_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC void context_makeCurrent(context_t* ctx, void* exceptionPointer); //static
DLL_PUBLIC context_t* context_getCurrent(void* exceptionPointer); //static
DLL_PUBLIC void context_makeThreadCurrent(context_t* ctx, void* exceptionPointer); //static
DLL_PUBLIC context_t* context_getThreadCurrent(void* exceptionPointer); //static
DLL_PUBLIC context_t* context_set(alure::Context ctx);
DLL_PUBLIC void context_destroy(context_t* dm);
DLL_PUBLIC void context_destroyPointer(context_t* dm);
DLL_PUBLIC device_t* context_getDevice(context_t* dm, void* exceptionPointer);
DLL_PUBLIC void context_startBatch(context_t* dm, void* exceptionPointer);
DLL_PUBLIC void context_endBatch(context_t* dm, void* exceptionPointer);
DLL_PUBLIC listener_t* context_getListener(context_t* dm, void* exceptionPointer);
//DLL_PUBLIC SharedPtr<MessageHandler> setMessageHandler(SharedPtr<MessageHandler> handler, void* exceptionPointer);
//DLL_PUBLIC SharedPtr<MessageHandler> getMessageHandler() const;
// interval in ms
DLL_PUBLIC void context_setAsyncWakeInterval(context_t* dm, uint64_t interval, void* exceptionPointer);
DLL_PUBLIC int64_t context_getAsyncWakeInterval(context_t* dm, void* exceptionPointer);
//DLL_PUBLIC SharedPtr<Decoder> context_createDecoder(context_t* dm, StringView name);
DLL_PUBLIC bool context_isSupported(context_t* dm, alure::ChannelConfig channels, alure::SampleType type, void* exceptionPointer);
DLL_PUBLIC wrapStringVector_t* context_getAvailableResamplers(context_t* dm, void* exceptionPointer);
DLL_PUBLIC int32_t context_getDefaultResamplerIndex(context_t* dm, void* exceptionPointer);
DLL_PUBLIC buffer_t* context_getBuffer(context_t* dm, const char* name, void* exceptionPointer);
//DLL_PUBLIC SharedFuture<Buffer> getBufferAsync(StringView name);
//DLL_PUBLIC void precacheBuffersAsync(ArrayView<StringView> names);
//DLL_PUBLIC Buffer createBufferFrom(StringView name, SharedPtr<Decoder> decoder);
//DLL_PUBLIC SharedFuture<Buffer> createBufferAsyncFrom(StringView name, SharedPtr<Decoder> decoder);
//DLL_PUBLIC Buffer findBuffer(StringView name);
//DLL_PUBLIC SharedFuture<Buffer> findBufferAsync(StringView name);
DLL_PUBLIC void context_removeBuffer(context_t* dm, const char* name, void* exceptionPointer);
//DLL_PUBLIC void removeBuffer(Buffer buffer);
DLL_PUBLIC source_t* context_createSource(context_t* dm, void* exceptionPointer);
DLL_PUBLIC auxiliaryEffectSlot_t* context_createAuxiliaryEffectSlot(context_t* dm, void* exceptionPointer);
DLL_PUBLIC effect_t* context_createEffect(context_t* dm, void* exceptionPointer);
//DLL_PUBLIC SourceGroup createSourceGroup();
DLL_PUBLIC void context_setDopplerFactor(context_t* dm, float factor, void* exceptionPointer);
DLL_PUBLIC void context_setSpeedOfSound(context_t* dm, float speed, void* exceptionPointer);
DLL_PUBLIC void context_setDistanceModel(context_t* dm, alure::DistanceModel model, void* exceptionPointer);
DLL_PUBLIC void context_update(context_t* dm, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_CONTEXT_H__ */


