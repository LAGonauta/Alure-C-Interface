#include <cstdint>

struct alureVersion
{
    uint32_t Major;
    uint32_t Minor;
    alureVersion() : Major(0), Minor(0) { }
    alureVersion(uint32_t major, uint32_t minor) : Major(major), Minor(minor) { }
};

struct alureVector3
{
    float x;
    float y;
    float z;
    alureVector3() : x(0), y(0), z(0) { }
    alureVector3(float x, float y, float z) : x(x), y(y), z(z) { }
};

struct alureOrientation
{
    alureVector3 At;
    alureVector3 Up;
    alureOrientation() : At(alureVector3()), Up(alureVector3()) { }
    alureOrientation(alureVector3 At, alureVector3 Up) : At(At), Up(Up) { }
};

struct alureLoopPoints
{
    uint32_t Start;
    uint32_t End;
    alureLoopPoints() : Start(0), End(0) { }
    alureLoopPoints(uint32_t start, uint32_t end) : Start(start), End(end) { }
};

struct alureGainRange
{
    float Min;
    float Max;
    alureGainRange() : Min(0), Max(0) { }
    alureGainRange(float min, float max) : Min(min), Max(max) { }
};

struct alureDistanceRange
{
    float Ref;
    float Max;
    alureDistanceRange() : Ref(0), Max(0) { }
    alureDistanceRange(float ref, float max) : Ref(ref), Max(max) { }
};