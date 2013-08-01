#ifndef CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_

#include <string>
#include <vector>

namespace cplusplusfs {

class File;

class Path {
public:
  Path(const char *);
  explicit Path(const wchar_t *);

  Path(const std::string &);
  explicit Path(const std::wstring &);

  Path(const Path&) = default;
  Path(const Path&&) = default;

  Path(const File&) explicit;

  Path Extension() const;

  Path Name() const;

  Path Parent() const;

  Path Root() const;

  std::vector<Path> Split() const;

  operator std::string() const;
  explicit operator std::wstring() const;
  explicit operator std::vector<Path>() const;

  ~Path();
  /* data */
};

}

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_
