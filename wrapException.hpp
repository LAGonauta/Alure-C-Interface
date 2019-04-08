#include <exception>

// Types:
// std::runtime_error
// std::out_of_range
// std::system_error (al_error)
// std::exception (generic)
// unknown error

#include "common.h"

#ifndef __WRAPEXCEPTION_H__
#define __WRAPEXCEPTION_H__

#ifdef __cplusplus
extern "C" {
#endif

wrapException_t* wrapException_create(const std::exception& e, const std::string& type, const std::string& comment);
void wrapException_destroy(wrapException_t* dm);

wrapString_t* wrapException_what(const wrapException_t* dm);
wrapString_t* wrapException_type(const wrapException_t* dm);
wrapString_t* wrapException_comment(const wrapException_t* dm);

#ifdef __cplusplus
}

template<class funcType, class returnType>
returnType wrapException_wrapFunction(const funcType someFunc, const std::string exceptionComment, void* exceptionPointerValue)
{
  try
  {
    return someFunc();
  }
  catch(const std::system_error& except)
  {
    *static_cast<intptr_t*>(exceptionPointerValue) = reinterpret_cast<intptr_t>(wrapException_create(except, "std::system_error", exceptionComment));
  }
  catch(const std::runtime_error& except)
  {
    *static_cast<intptr_t*>(exceptionPointerValue) = reinterpret_cast<intptr_t>(wrapException_create(except, "std::runtime_error", exceptionComment));
  }
  catch(const std::out_of_range& except)
  {
    *static_cast<intptr_t*>(exceptionPointerValue) = reinterpret_cast<intptr_t>(wrapException_create(except, "std::out_of_range", exceptionComment));
  }
  catch(const std::exception& except)
  {
    *static_cast<intptr_t*>(exceptionPointerValue) = reinterpret_cast<intptr_t>(wrapException_create(except, "std::exception", "Other error."));
  }
  return returnType();
}
#endif

#endif /* __WRAPEXCEPTION_H__ */
