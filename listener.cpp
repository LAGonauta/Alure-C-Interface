#include "listener.hpp"

listener_t* listener_set(alure::Listener lis)
{
  listener_t* dm;

  dm = new listener { .obj = lis };

  return dm;
}

void listener_destroy(listener_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

void listener_setGain(listener_t* dm, ALfloat gain)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setGain(gain);
}

void listener_set3DParameters(listener_t* dm, const alureVector3* position, const alureVector3* velocity, const alureOrientation* orientation)
{
  if (dm == nullptr)
  {
    return;
  }

  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  dm->obj.set3DParameters(alure::Vector3(position->x, position->y, position->z), alure::Vector3(velocity->x, velocity->y, velocity->z), orientation_pair);
}

void listener_setPosition(listener_t* dm, const alureVector3* position)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setPosition(alure::Vector3(position->x, position->y, position->z));
}

void listener_setVelocity(listener_t* dm, const alureVector3* velocity)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setVelocity(alure::Vector3(velocity->x, velocity->y, velocity->z));
}

void listener_setOrientation(listener_t* dm, const alureOrientation* orientation)
{
  if (dm == nullptr)
  {
    return;
  }
  std::pair<alure::Vector3, alure::Vector3> orientation_pair = std::make_pair<alure::Vector3, alure::Vector3>(alure::Vector3(orientation->At.x, orientation->At.y, orientation->At.z), alure::Vector3(orientation->Up.x, orientation->Up.y, orientation->Up.z));
  dm->obj.setOrientation(orientation_pair);
}

void listener_setMetersPerUnit(listener_t* dm, ALfloat m_u)
{
  if (dm == nullptr)
  {
    return;
  }

  dm->obj.setMetersPerUnit(m_u);
}