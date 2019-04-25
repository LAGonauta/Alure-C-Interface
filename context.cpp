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

void context_makeCurrent(context_t* dm)
{
  if (dm == nullptr)
  {
    alure::Context::MakeCurrent(nullptr);
  }
  else
  {
    alure::Context::MakeCurrent(dm->obj);
  }
  
}

context_t* context_getCurrent()
{
    return context_set(alure::Context::GetCurrent());
}

void context_makeThreadCurrent(context_t* dm)
{
  if (dm == nullptr)
  {
    alure::Context::MakeThreadCurrent(nullptr);
  }
  else
  {
    alure::Context::MakeThreadCurrent(dm->obj);
  }
}

context_t* context_getThreadCurrent()
{
    return context_set(alure::Context::GetThreadCurrent());
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

device_t* context_getDevice(context_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return device_set(dm->obj.getDevice());
}

void context_startBatch(context_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.startBatch();
}

void context_endBatch(context_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.endBatch();
}

listener_t* context_getListener(context_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return listener_set(dm->obj.getListener());
}

// SharedPtr<MessageHandler> setMessageHandler(SharedPtr<MessageHandler> handler);
// SharedPtr<MessageHandler> getMessageHandler() const;

// interval in ms
void context_setAsyncWakeInterval(context_t* dm, int64_t interval)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setAsyncWakeInterval(std::chrono::milliseconds(interval));
}

int64_t context_getAsyncWakeInterval(context_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.getAsyncWakeInterval().count();
}

//SharedPtr<Decoder> context_createDecoder(context_t* dm, StringView name);

bool context_isSupported(context_t* dm, alure::ChannelConfig channels, alure::SampleType type)
{
  if (dm == nullptr)
  {
    return false;
  }

  return dm->obj.isSupported(channels, type);
}

wrapStringVector_t* context_getAvailableResamplers(context_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  auto result = dm->obj.getAvailableResamplers();
  std::vector<wrapString_t*> string_vector;
  for (size_t i = 0; i < result.size(); ++i)
  {
    string_vector.push_back(wrapString_create(result[i]));
  }

  return wrapStringVector_create(string_vector);
}

int32_t context_getDefaultResamplerIndex(context_t* dm)
{
  if (dm == nullptr)
  {
    return 0;
  }

  return dm->obj.getDefaultResamplerIndex();
}

buffer_t* context_getBuffer(context_t* dm, const char* name)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return buffer_set(dm->obj.getBuffer(name));
}
//SharedFuture<Buffer> getBufferAsync(StringView name);
//void precacheBuffersAsync(ArrayView<StringView> names);
//Buffer createBufferFrom(StringView name, SharedPtr<Decoder> decoder);
//SharedFuture<Buffer> createBufferAsyncFrom(StringView name, SharedPtr<Decoder> decoder);
//Buffer findBuffer(StringView name);
//SharedFuture<Buffer> findBufferAsync(StringView name);

void context_removeBuffer(context_t* dm, const char* name)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.removeBuffer(name);
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

void context_setDopplerFactor(context_t* dm, float factor)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setDopplerFactor(factor);
}

void context_setSpeedOfSound(context_t* dm, float speed)
{
  if (dm == nullptr)
  {
    return;
  }

  return dm->obj.setSpeedOfSound(speed);
}

void context_setDistanceModel(context_t* dm, alure::DistanceModel model)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setDistanceModel(model);
}

void context_update(context_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.update();
}