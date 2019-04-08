#include "source.hpp"

struct source {
  alure::Source obj;
};

source_t* source_set(alure::Source sour)
{
  source_t* dm;

  dm = new source { .obj = sour };

  return dm;
}

void source_destroy(source_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

void source_setGain(source_t* dm, ALfloat gain)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setGain(gain);
}

void source_set3DParameters(source_t* dm, const alureVector3* position, const alureVector3* velocity, const alureOrientation* orientation)
{
  if (dm == nullptr)
  {
    return;
  }

  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  dm->obj.set3DParameters(alure::Vector3(position->x, position->y, position->z), alure::Vector3(velocity->x, velocity->y, velocity->z), orientation_pair);
}

void source_setPosition(source_t* dm, const alureVector3* position)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setPosition(alure::Vector3(position->x, position->y, position->z));
}

void source_setVelocity(source_t* dm, const alureVector3* velocity)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setVelocity(alure::Vector3(velocity->x, velocity->y, velocity->z));
}

void source_setOrientation(source_t* dm, const alureOrientation* orientation)
{
  if (dm == nullptr)
  {
    return;
  }
  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  dm->obj.setOrientation(orientation_pair);
}