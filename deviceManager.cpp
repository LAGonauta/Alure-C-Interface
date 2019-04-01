#include "deviceManager.hpp"

extern "C" 
{
    EXPORT int add(int a, int b)
    {
        return a + b;
    }

    EXPORT int subtract(int a, int b)
    {  
      return a - b;
    }  
}

