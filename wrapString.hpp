#include <string>

#include "common.h"

#ifndef __WRAPSTRING_H__
#define __WRAPSTRING_H__

#ifdef __cplusplus
extern "C" {
#endif

wrapString_t* wrapString_create(std::string text);
void wrapString_destroy(wrapString_t* dm);

const char* wrapString_getString(wrapString_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAPSTRING_H__ */
