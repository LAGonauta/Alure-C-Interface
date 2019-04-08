#include "common.h"

#ifndef __WRAP_SOURCE_H__
#define __WRAP_SOURCE_H__

#ifdef __cplusplus
extern "C" {
#endif

source_t* source_set(alure::Source ctx);
void source_destroy(source_t* dm);

void source_setGain(source_t* dm, ALfloat gain);

void source_set3DParameters(source_t* dm, const alureVector3* position, const alureVector3* velocity, const alureOrientation* orientation);
void source_setPosition(source_t* dm, const alureVector3* position);
void source_setVelocity(source_t* dm, const alureVector3* velocity);

void source_setOrientation(source_t* dm, const alureOrientation orientation);

#ifdef __cplusplus
}
#endif

#endif /* __WRAP_SOURCE_H__ */
