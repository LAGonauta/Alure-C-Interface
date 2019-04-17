#include "common.h"

#ifndef __WRAP_LISTENER_H__
#define __WRAP_LISTENER_H__

#ifdef __cplusplus
extern "C" {
#endif

listener_t* listener_set(alure::Listener ctx);
void listener_destroy(listener_t* dm);

void listener_setGain(listener_t* dm, ALfloat gain);

void listener_set3DParameters(listener_t* dm, const alureVector3_t* position, const alureVector3_t* velocity, const alureOrientation_t* orientation);
void listener_setPosition(listener_t* dm, const alureVector3_t* position);
void listener_setVelocity(listener_t* dm, const alureVector3_t* velocity);

void listener_setOrientation(listener_t* dm, const alureOrientation_t* orientation);

void listener_setMetersPerUnit(listener_t* dm, ALfloat m_u);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_LISTENER_H__ */
