#include <string>

#include "common.h"

#ifndef __WRAPSTRING_H__
#define __WRAPSTRING_H__

#ifdef __cplusplus
extern "C" {
#endif

struct wrapString;
typedef struct wrapString wrapString_t;

wrapString_t* wrapString_create(std::string text);
void wrapString_destroy(wrapString_t* dm);

const char* getString(wrapString_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAPSTRING_H__ */
