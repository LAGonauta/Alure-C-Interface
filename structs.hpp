#include <cstdint>

struct alureVersion
{
    uint32_t Major;
    uint32_t Minor;
};

struct alureVector3
{
    float x;
    float y;
    float z;
};

struct alureOrientation
{
    alureVector3 At;
    alureVector3 Up;
};

struct alureLoopPoints
{
    uint32_t Start;
    uint32_t End;
};