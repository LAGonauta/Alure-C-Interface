#include "wrapException.hpp"
#include "wrapString.hpp"

struct wrapException {
  const std::string what;
  const std::string type;
  const std::string comment;
};

wrapException_t* wrapException_create(const std::exception& e, const std::string& type, const std::string& comment)
{
  wrapException_t *dm;

  dm = new wrapException { .what = e.what(), .type = type, .comment = comment };

  return dm;
}

void wrapException_destroy(wrapException_t* dm)
{
  if (dm == nullptr)
  {
    return;
  }

  delete dm;
}

wrapString_t* wrapException_what(const wrapException_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return wrapString_create(dm->what);
}

wrapString_t* wrapException_type(const wrapException_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return wrapString_create(dm->type);
}

wrapString_t* wrapException_comment(const wrapException_t* dm)
{
  if (dm == nullptr)
  {
    return nullptr;
  }

  return wrapString_create(dm->comment);
}