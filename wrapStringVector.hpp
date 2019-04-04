#include <vector>

#include "common.h"
#include "wrapString.hpp"

#ifndef __WRAPSTRINGVECTOR_H__
#define __WRAPSTRINGVECTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

struct wrapStringVector;
typedef struct wrapStringVector wrapStringVector_t;

wrapStringVector_t* wrapStringVector_create(std::vector<wrapString_t*> vector);
void wrapStringVector_destroy(wrapStringVector_t* dm);

int wrapStringVector_getSize(wrapStringVector_t* dm);

wrapString_t* wrapStringVector_getAt(wrapStringVector_t* dm, int position);

#ifdef __cplusplus
}
#endif

#endif /* __WRAPSTRINGVECTOR_H__ */
