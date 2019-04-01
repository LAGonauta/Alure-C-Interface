
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
