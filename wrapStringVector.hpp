#include <vector>

#include "common.h"

#ifndef __WRAPSTRINGVECTOR_H__
#define __WRAPSTRINGVECTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

wrapStringVector_t* wrapStringVector_create(std::vector<wrapString_t*> vector);
void wrapStringVector_destroy(wrapStringVector_t* dm);

uint64_t wrapStringVector_getSize(wrapStringVector_t* dm);

wrapString_t* wrapStringVector_getAt(wrapStringVector_t* dm, uint64_t position);

#ifdef __cplusplus
}
#endif

#endif /* __WRAPSTRINGVECTOR_H__ */
