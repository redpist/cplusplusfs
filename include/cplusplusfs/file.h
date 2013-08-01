#ifndef CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_

#include <string>

namespace cplusplusfs {

class File
{
public:
  File(const char *);
  File(const wchar_t *) explicit;

  File(const std::string &);
  File(const std::wstring &) explicit;

  // Return true if a file (regular file, directory, symlink, named pipe, socket, device or door)
  // already exists at this path, else return false.
  //
  // Examples :
  //
  // // next statement solutd return true because the '/' directory already exists
  // File("/").Exists();
  //
  // // next statement sould return true because the '/dev/urandom' device file already exists
  // File("/dev/urandom").Exists();
  //
  // // next statement sould return false because the '/dev/i_am_an_imaginary_device' file
  // // doesn't exists most of the time
  // File("/dev/i_am_an_imaginary_device").Exists();
  //
  bool Exists() const;

  enum class FileType {
    unknown = -1,
    regular_file = 0,
    directory,
    symlink,
    named_pipe,
    socket,
    device,
    door // unimplemented
  };

  // Return the type of the file (regular file, directory, symlink, named pipe, socket, device or door)
  //
  // Examples :
  //
  // // next statement sould return FileType::directory because the '/' file is a directory
  // File("/").Type();
  //
  // // next statement sould return FileType::device because the '/dev/urandom' file is a character device
  // File("/dev/urandom").Type();
  //
  // // next statement sould return FileType::unknown because the '/dev/i_am_an_imaginary_device'
  // // file doesn't exists most of the time and btw have no type
  // File("/dev/i_am_an_imaginary_device").Type();
  //
  FileType Type() const;

  enum class DeviceFileType {
    unknown = -1,
    character = 0,
    block
  };

  // If the file is a device return the type of device the file is (character, block) else return unknown
  //
  // Examples :
  //
  // // next statement sould return DeviceFileType::unknown because the '/' file is a directory, so not a device
  // File("/").DeviveType();
  //
  // // next statement sould return DeviceFileType::character because the '/dev/urandom' file is a character device
  // File("/dev/urandom").DeviveType();
  //
  // // next statement sould return DeviceFileType::block because the '/dev/sda' file is a block device
  // File("/dev/sda").DeviveType();
  //
  DeviceFileType DeviceType() const;

  Cplusplusfs::Path Path();

  Cplusplusfs::Path AbsolutePath();

  Cplusplusfs::Path ResolvedAbsolutePath();

  Cplusplusfs::Path RelativePath(File other_file = cplusplusfs::CurrentDirectory());

  Cplusplusfs::Path ResolvedRelativePath(File other_file = cplusplusfs::CurrentDirectory());

  File Parent() const;

  File Root() const;


  ~File();
  /* data */
};

}

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_