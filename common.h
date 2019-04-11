#pragma once

// https://stackoverflow.com/questions/2164827/explicitly-exporting-shared-library-functions-in-linux
#if defined(_MSC_VER)
    //  Microsoft 
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    //  GCC
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
#else
    //  do nothing and hope for the best?
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#include "alure/include/AL/alure2.h"
#include "structs.hpp"

struct deviceManager
{
  alure::DeviceManager obj;
  deviceManager(alure::DeviceManager dm) : obj(dm) { }
};
typedef struct deviceManager deviceManager_t;

struct device
{
  alure::Device obj;
  device(alure::Device devc) : obj(devc) { }
};
typedef struct device device_t;

struct listener
{
  alure::Listener obj;
  listener(alure::Listener lst) : obj(lst) { }
};
typedef struct listener listener_t;

struct buffer
{
  alure::Buffer obj;
  buffer(alure::Buffer bff) : obj(bff) { }
};
typedef struct buffer buffer_t;

struct source
{
  alure::Source obj;
  source(alure::Source src) : obj(src) { }
};
typedef struct source source_t;

struct context
{
  alure::Context obj;
  context(alure::Context ctx) : obj(ctx) { }
};
typedef struct context context_t;

struct wrapException
{
  const std::string what;
  const std::string type;
  const std::string comment;
  wrapException(const std::string what, const std::string type, const std::string comment) : what(what), type(type), comment(comment) { }
};
typedef struct wrapException wrapException_t;

struct wrapString
{
  const std::string obj;
  wrapString(const std::string text) : obj(text) { }
};
typedef struct wrapString wrapString_t;

struct wrapStringVector
{
  std::vector<wrapString_t*> obj;
  wrapStringVector(std::vector<wrapString_t*> wstrv) : obj(wstrv) { }
};
typedef struct wrapStringVector wrapStringVector_t;

struct sourceVector
{
  std::vector<source_t*> obj;
  sourceVector(std::vector<source_t*> wsourcev) : obj(wsourcev) { }
};
typedef struct sourceVector sourceVector_t;

// From http://gcc.gnu.org/wiki/Visibility
// #if defined _WIN32 || defined __CYGWIN__
//   #ifdef BUILDING_DLL
//     #ifdef __GNUC__
//       #define DLL_PUBLIC __attribute__ ((dllexport))
//     #else
//       #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
//     #endif
//   #else
//     #ifdef __GNUC__
//       #define DLL_PUBLIC __attribute__ ((dllimport))
//     #else
//       #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
//     #endif
//   #endif
//   #define DLL_LOCAL
// #else
//   #if __GNUC__ >= 4
//     #define DLL_PUBLIC __attribute__ ((visibility ("default")))
//     #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
//   #else
//     #define DLL_PUBLIC
//     #define DLL_LOCAL
//   #endif
// #endif
