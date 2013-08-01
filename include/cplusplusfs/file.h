#ifndef CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_

#include <string>

class File
{
public:
  File(const char *);
  File(const std::string &);
  File(const std::wstring &);

  // Return true if a file (regular file, directory, symlink, named pipe, socket, device or door)
  // already exists at this path, else return false.
  //
  // Examples :
  //
  // // next statement sould return true because the '/' directory already exists
  // File("/").Exists();
  //
  // // next statement sould return true because the '/dev/urandom' device file already exists
  // File("/dev/urandom").Exists();
  //
  // // next statement sould return false because the '/dev/i_am_an_imaginary_device' file
  // // doesn't exists most of the time
  // File("/dev/i_am_an_imaginary_device").Exists();
  //
  bool Exists();

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
  // File("/").Exists();
  //
  // // next statement sould return FileType::device because the '/dev/urandom' file is a character device
  // File("/dev/urandom").Exists();
  //
  // // next statement sould return FileType::unknown because the '/dev/i_am_an_imaginary_device'
  // // file doesn't exists most of the time and btw have no type
  // File("/dev/i_am_an_imaginary_device").Exists();
  //
  FileType Type();

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
  // File("/").Exists();
  //
  // // next statement sould return DeviceFileType::character because the '/dev/urandom' file is a character device
  // File("/dev/urandom").Exists();
  //
  // // next statement sould return DeviceFileType::block because the '/dev/sda' file is a block device
  // File("/dev/sda").Exists();
  //
  DeviceFileType DeviceType();

  ~File();
  /* data */
};

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_