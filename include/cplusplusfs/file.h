#ifndef CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_

#include <string>
#include "cplusplusfs/functions.h"
#include "cplusplusfs/status.h"

namespace cplusplusfs {

class Path;

class File {
public:
  File(const char *);
  explicit File(const wchar_t *);

  File(const std::string &);
  explicit File(const std::wstring &);
  explicit File(const cplusplusfs::Path &);

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

  cplusplusfs::Path Path();

  cplusplusfs::Path AbsolutePath();

  cplusplusfs::Path ResolvedAbsolutePath();

  cplusplusfs::Path RelativePath(File other_file = cplusplusfs::CurrentDirectory());

  cplusplusfs::Path ResolvedRelativePath(File other_file = cplusplusfs::CurrentDirectory());

  File Parent() const;

  File Root() const;

  Status Create();

  std::vector<File> Files();

  bool Writable();

  bool Readable();

  bool Executable();

  struct Permissions {
    enum class User {
      Execute = 0100,
      Write = 0200,
      Read = 0400,
      All = 0700,
    };

    enum class Group {
      Execute = 010,
      Write = 020,
      Read = 040,
      All = 070,
    };

    enum class Other {
      Execute = 01,
      Write = 02,
      Read = 04,
      All = 07,
    };

    struct {
      bool Writable();

      bool Readable();

      bool Executable();
    } user;

    struct {
      bool Writable();

      bool Readable();

      bool Executable();
    } group;

    struct {
      bool Writable();

      bool Readable();

      bool Executable();        
    } other;

    private:
      int permissions_;
  };

  template  <typename... Args>
  Status SetPermissions(Permissions::User user_permission, Args... args);

  template  <typename... Args>
  Status SetPermissions(Permissions::Group group_permission, Args... args);

  template  <typename... Args>
  Status SetPermissions(Permissions::Other other_permission, Args... args);

  // File(".").GetPermissions().user.Writable()
  Permissions GetPermissions();

  template  <typename... Args>
  Status Copy(const cplusplusfs::Path &path, Args... args);

  template  <typename... Args>
  Status Move(const cplusplusfs::Path &path, Args... args);

  std::size_t Size();

  std::size_t TrueSize();

  File &operator()();

  ~File();
  /* data */
};

}

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_FILE_H_
