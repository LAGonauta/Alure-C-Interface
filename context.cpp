#include "context.hpp"
#include "buffer.hpp"
#include "device.hpp"
#include "effect.hpp"
#include "listener.hpp"
#include "source.hpp"
#include "auxiliaryEffectSlot.hpp"
#include "wrapString.hpp"
#include "wrapStringVector.hpp"
#include "wrapException.hpp"

void context_makeCurrent(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    auto func = []() -> void { alure::Context::MakeCurrent(nullptr); };
    wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
  }
  else
  {
    auto func = [&dm]() -> void { alure::Context::MakeCurrent(dm->obj); };
    wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
  }
}

context_t* context_getCurrent(void* exceptionPointer)
{
    auto func = []() -> context_t* { return context_set(alure::Context::GetCurrent()); };
    return wrapException_wrapFunction<decltype(func), context_t*>(func, "", exceptionPointer);
}

void context_makeThreadCurrent(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    auto func = []() -> void { alure::Context::MakeThreadCurrent(nullptr); };
    wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
  }
  else
  {
    auto func = [&dm]() -> void { alure::Context::MakeThreadCurrent(dm->obj); };
    wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
  }
}

context_t* context_getThreadCurrent(void* exceptionPointer)
{
    auto func = []() -> context_t* { return context_set(alure::Context::GetThreadCurrent()); };
    return wrapException_wrapFunction<decltype(func), context_t*>(func, "", exceptionPointer);
}

context_t* context_set(alure::Context ctx)
{
  context_t* dm;

  dm = new context(ctx);

  return dm;
}

void context_destroy(context_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.destroy();
}

void context_destroyPointer(context_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

device_t* context_getDevice(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> device_t* { return device_set(dm->obj.getDevice()); };
  return wrapException_wrapFunction<decltype(func), device_t*>(func, "", exceptionPointer);
}

void context_startBatch(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.startBatch(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void context_endBatch(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.endBatch(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

listener_t* context_getListener(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> listener_t* { return listener_set(dm->obj.getListener()); };
  return wrapException_wrapFunction<decltype(func), listener_t*>(func, "", exceptionPointer);
}

// SharedPtr<MessageHandler> setMessageHandler(SharedPtr<MessageHandler> handler);
// SharedPtr<MessageHandler> getMessageHandler() const;

// interval in ms
void context_setAsyncWakeInterval(context_t* dm, int64_t interval, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &interval]() -> void { dm->obj.setAsyncWakeInterval(std::chrono::milliseconds(interval)); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

int64_t context_getAsyncWakeInterval(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> int64_t { return dm->obj.getAsyncWakeInterval().count(); };
  return wrapException_wrapFunction<decltype(func), int64_t>(func, "", exceptionPointer);
}

//SharedPtr<Decoder> context_createDecoder(context_t* dm, StringView name);

bool context_isSupported(context_t* dm, alure::ChannelConfig channels, alure::SampleType type, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return false;
  }

  auto func = [&dm, &channels, &type]() -> bool { return dm->obj.isSupported(channels, type); };
  return wrapException_wrapFunction<decltype(func), bool>(func, "", exceptionPointer);
}

wrapStringVector_t* context_getAvailableResamplers(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> alure::ArrayView<alure::String> { return dm->obj.getAvailableResamplers(); };
  auto result = wrapException_wrapFunction<decltype(func), alure::ArrayView<alure::String>>(func, "", exceptionPointer);

  std::vector<wrapString_t*> string_vector;
  for (size_t i = 0; i < result.size(); ++i)
  {
    string_vector.push_back(wrapString_create(result[i]));
  }

  return wrapStringVector_create(string_vector);
}

int32_t context_getDefaultResamplerIndex(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return 0;
  }

  auto func = [&dm]() -> int32_t { return dm->obj.getDefaultResamplerIndex(); };
  return wrapException_wrapFunction<decltype(func), int32_t>(func, "", exceptionPointer);
}

buffer_t* context_getBuffer(context_t* dm, const char* name, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm, &name]() -> buffer_t* { return buffer_set(dm->obj.getBuffer(name)); };
  return wrapException_wrapFunction<decltype(func), buffer_t*>(func, "", exceptionPointer);
}
//SharedFuture<Buffer> getBufferAsync(StringView name);
//void precacheBuffersAsync(ArrayView<StringView> names);
//Buffer createBufferFrom(StringView name, SharedPtr<Decoder> decoder);
//SharedFuture<Buffer> createBufferAsyncFrom(StringView name, SharedPtr<Decoder> decoder);
//Buffer findBuffer(StringView name);
//SharedFuture<Buffer> findBufferAsync(StringView name);

void context_removeBuffer(context_t* dm, const char* name, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &name]() -> void { dm->obj.removeBuffer(name); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

//void removeBuffer(Buffer buffer);

source_t* context_createSource(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> source_t* { return source_set(dm->obj.createSource()); };
  return wrapException_wrapFunction<decltype(func), source_t*>(func, "", exceptionPointer);
}

auxiliaryEffectSlot_t* context_createAuxiliaryEffectSlot(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> auxiliaryEffectSlot_t* { return auxiliaryEffectSlot_set(dm->obj.createAuxiliaryEffectSlot()); };
  return wrapException_wrapFunction<decltype(func), auxiliaryEffectSlot_t*>(func, "", exceptionPointer);
}

effect_t* context_createEffect(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto func = [&dm]() -> effect_t* { return effect_set(dm->obj.createEffect()); };
  return wrapException_wrapFunction<decltype(func), effect_t*>(func, "", exceptionPointer);
}

// SourceGroup createSourceGroup();

void context_setDopplerFactor(context_t* dm, float factor, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &factor]() -> void { dm->obj.setDopplerFactor(factor); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void context_setSpeedOfSound(context_t* dm, float speed, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &speed]() -> void { dm->obj.setSpeedOfSound(speed); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void context_setDistanceModel(context_t* dm, alure::DistanceModel model, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm, &model]() -> void { dm->obj.setDistanceModel(model); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}

void context_update(context_t* dm, void* exceptionPointer)
{
  if (dm == nullptr)
  {
    return;
  }

  auto func = [&dm]() -> void { dm->obj.update(); };
  wrapException_wrapFunction<decltype(func), void>(func, "", exceptionPointer);
}