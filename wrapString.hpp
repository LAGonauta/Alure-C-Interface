#include <string>

#include "common.h"

#ifndef __WRAPSTRING_H__
#define __WRAPSTRING_H__

#ifdef __cplusplus
extern "C"
{
#endif

DLL_PUBLIC wrapString_t* wrapString_create(const std::string text);
DLL_PUBLIC void wrapString_destroy(wrapString_t* dm);
DLL_PUBLIC const char* wrapString_getString(wrapString_t* dm);

#ifdef __cplusplus
}
#endif

#endif /* __WRAPSTRING_H__ */
