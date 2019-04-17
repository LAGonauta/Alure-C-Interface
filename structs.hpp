#include <cstdint>

#ifdef __cplusplus
extern "C"
{
#endif
  typedef struct
  {
    uint32_t Major;
    uint32_t Minor;
  } alureVersion_t;

  typedef struct
  {
    float x;
    float y;
    float z;
  } alureVector3_t;

  typedef struct
  {
    alureVector3_t At;
    alureVector3_t Up;
  } alureOrientation_t;

  typedef struct
  {
    uint32_t Start;
    uint32_t End;
  } alureLoopPoints_t;

  typedef struct
  {
    float Min;
    float Max;
  } alureGainRange_t;

  typedef struct
  {
    float Ref;
    float Max;
  } alureDistanceRange_t;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
inline alureVersion_t alureVersion()
{
  return alureVersion_t{ 0 };
}

inline alureVersion_t alureVersion(uint32_t major, uint32_t minor)
{
  auto result = alureVersion_t();
  result.Major = major;
  result.Minor = minor;
  return result;
}

inline alureVector3_t alureVector3()
{
  return alureVector3_t{ 0 };
}

inline alureVector3_t alureVector3(float x, float y, float z)
{
  auto result = alureVector3_t();
  result.x = x;
  result.y = y;
  result.z = z;
  return result;
}

inline alureOrientation_t alureOrientation()
{
  return alureOrientation_t{ alureVector3_t{ 0 }, alureVector3_t{ 0 } };
}

inline alureOrientation_t alureOrientation(alureVector3_t at, alureVector3_t up)
{
  auto result = alureOrientation_t();
  result.At = at;
  result.Up = up;
  return result;
}

inline alureLoopPoints_t alureLoopPoints()
{
  return alureLoopPoints_t{ 0 };
}

inline alureLoopPoints_t alureLoopPoints(uint32_t start, uint32_t end)
{
  auto result = alureLoopPoints_t();
  result.Start = start;
  result.End = end;
  return result;
}

inline alureGainRange_t alureGainRange()
{
  return alureGainRange_t{ 0 };
}

inline alureGainRange_t alureGainRange(float min, float max)
{
  auto result = alureGainRange_t();
  result.Min = min;
  result.Max = max;
  return result;
}

inline alureDistanceRange_t alureDistanceRange()
{
  return alureDistanceRange_t{ 0 };
}

inline alureDistanceRange_t alureDistanceRange(float ref, float max)
{
  auto result = alureDistanceRange_t();
  result.Ref = ref;
  result.Max = max;
  return result;
}
#endif