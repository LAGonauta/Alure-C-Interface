#include "common.h"

#ifndef __WRAP_LISTENER_H__
#define __WRAP_LISTENER_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC listener_t* listener_set(alure::Listener ctx);
DLL_PUBLIC void listener_destroy(listener_t* dm);
DLL_PUBLIC void listener_setGain(listener_t* dm, ALfloat gain);
DLL_PUBLIC void listener_set3DParameters(listener_t* dm, const alureVector3_t* position, const alureVector3_t* velocity, const alureOrientation_t* orientation);
DLL_PUBLIC void listener_setPosition(listener_t* dm, const alureVector3_t* position);
DLL_PUBLIC void listener_setVelocity(listener_t* dm, const alureVector3_t* velocity);
DLL_PUBLIC void listener_setOrientation(listener_t* dm, const alureOrientation_t* orientation);
DLL_PUBLIC void listener_setMetersPerUnit(listener_t* dm, ALfloat m_u);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_LISTENER_H__ */
