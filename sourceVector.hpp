#include <vector>

#include "common.h"

#ifndef __SOURCEVECTOR_H__
#define __SOURCEVECTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

sourceVector_t* sourceVector_create(std::vector<source_t*> vector);
void sourceVector_destroy(sourceVector_t* dm);
void sourceVector_destroyPointer(sourceVector_t* dm);

uint64_t sourceVector_getSize(sourceVector_t* dm, void* exceptionPointer);

source_t* sourceVector_getAt(sourceVector_t* dm, uint64_t position, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __SOURCEVECTOR_H__ */
