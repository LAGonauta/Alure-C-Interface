#include <vector>

#include "common.h"

#ifndef __SOURCEVECTOR_H__
#define __SOURCEVECTOR_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC sourceVector_t* sourceVector_create(std::vector<source_t*> vector);
DLL_PUBLIC void sourceVector_destroy(sourceVector_t* dm);
DLL_PUBLIC void sourceVector_destroyPointer(sourceVector_t* dm);
DLL_PUBLIC uint64_t sourceVector_getSize(sourceVector_t* dm, void* exceptionPointer);
DLL_PUBLIC source_t* sourceVector_getAt(sourceVector_t* dm, uint64_t position, void* exceptionPointer);

#ifdef __cplusplus
}
#endif

#endif /* __SOURCEVECTOR_H__ */
