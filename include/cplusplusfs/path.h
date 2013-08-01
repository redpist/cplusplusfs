#ifndef CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_

#include <string>

namespace cplusplusfs {

class Path
{
public:
  Path(const char *);
  Path(const wchar_t *) explicit;

  Path(const std::string &);
  Path(const std::wstring &) explicit;

  Patch(const Path&) = default;
  Patch(const Path&&) = default;

  Path Extension() const;

  std::vector<Path> Split() const;

  operator std::string() const;
  explicit operator std::wstring() const;
  explicit operator std::vector<Path>() const;

  ~Path();
  /* data */
};

}

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_