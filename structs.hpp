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

  typedef struct
  {
    float Inner;
    float Outer;
  } alureConeAngles_t;

  typedef struct
  {
    float Gain;
    float GainHF;
  } alureOuterConeGains_t;

  typedef struct
  {
    float Source;
    float Room;
  } alureRolloffFactors_t;

  typedef struct
  {
    float Left;
    float Right;
  } alureStereoAngles_t;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
inline alureVersion_t alureVersion()
{
  return alureVersion_t{ 0, 0 };
}

inline alureVersion_t alureVersion(uint32_t major, uint32_t minor)
{
  return alureVersion_t{ major, minor };
}

inline alureVector3_t alureVector3()
{
  return alureVector3_t{ 0, 0, 0 };
}

inline alureVector3_t alureVector3(float x, float y, float z)
{
  return alureVector3_t{ x, y, z };
}

inline alureOrientation_t alureOrientation()
{
  return alureOrientation_t{ alureVector3(), alureVector3() };
}

inline alureOrientation_t alureOrientation(alureVector3_t at, alureVector3_t up)
{
  return alureOrientation_t{ at, up };
}

inline alureLoopPoints_t alureLoopPoints()
{
  return alureLoopPoints_t{ 0, 0 };
}

inline alureLoopPoints_t alureLoopPoints(uint32_t start, uint32_t end)
{
  return alureLoopPoints_t{ start, end };
}

inline alureGainRange_t alureGainRange()
{
  return alureGainRange_t{ 0, 0 };
}

inline alureGainRange_t alureGainRange(float min, float max)
{
  return alureGainRange_t{ min, max };
}

inline alureDistanceRange_t alureDistanceRange()
{
  return alureDistanceRange_t{ 0, 0 };
}

inline alureDistanceRange_t alureDistanceRange(float ref, float max)
{
  return alureDistanceRange_t{ ref, max };
}

inline alureConeAngles_t alureConeAngles()
{
  return alureConeAngles_t{ 0, 0 };
}

inline alureConeAngles_t alureConeAngles(float inner, float outer)
{
  return alureConeAngles_t{ inner, outer };
}

inline alureOuterConeGains_t alureOuterConeGains()
{
  return alureOuterConeGains_t{ 0, 0 };
}

inline alureOuterConeGains_t alureOuterConeGains(float gain, float gainhf)
{
  return alureOuterConeGains_t{ gain, gainhf };
}

inline alureRolloffFactors_t alureRolloffFactors()
{
  return alureRolloffFactors_t{ 0, 0 };
}

inline alureRolloffFactors_t alureRolloffFactors(float source, float room)
{
  return alureRolloffFactors_t{ source, room };
}

inline alureStereoAngles_t alureStereoAngles()
{
  return alureStereoAngles_t{ 0, 0 };
}

inline alureStereoAngles_t alureStereoAngles(float left, float right)
{
  return alureStereoAngles_t{ left, right };
}
#endif