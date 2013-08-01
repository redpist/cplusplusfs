#ifndef CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_

#include <string>

class Path
{
public:
  Path(const char *);
  Path(const std::string &);
  Path(const std::wstring &);

  // Return true if a file or a directory already exists at this path, else return false.
  //
  // Examples :
  //
  // // next statement return true because the '/' directory already exists
  // Path("/").Exists();
  //
  // // next statement return true because the '/dev/urandom' file already exists
  // Path("/dev/urandom").Exists();
  //
  // // next statement sould return false because the '/dev/i_am_an_imaginary_device' file doesn't exists most of the time
  // Path("/dev/i_am_an_imaginary_device").Exists();
  //
  bool Exists();


  ~Path();
  /* data */
};

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_PATH_H_