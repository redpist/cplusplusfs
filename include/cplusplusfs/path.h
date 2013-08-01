#ifndef CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_

#include <string>
#include <vector>

#include "file.h"

namespace cplusplusfs {

class Path
{
public:
  Path(const char *);
  explicit Path(const wchar_t *);

  Path(const std::string &);
  explicit Path(const std::wstring &);

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
