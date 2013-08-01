#include "cplusplusfs/file.h"
#include "cplusplusfs/path.h"

namespace cplusplusfs {

File::File(const char *file_name)
{ 
}

File::File(const wchar_t *file_name)
{ 
}

File::File(const std::string &file_name)
{ 
}

File::File(const std::wstring &file_name)
{ 
}

File::File(const cplusplusfs::Path &path)
{
}

bool File::Exists() const
{

}

File::FileType File::Type() const
{
}

File::DeviceFileType File::DeviceType() const
{
}

cplusplusfs::Path File::Path()
{
}

cplusplusfs::Path File::AbsolutePath()
{
}

cplusplusfs::Path File::ResolvedAbsolutePath()
{
}

cplusplusfs::Path File::RelativePath(File other_file)
{
}

cplusplusfs::Path File::ResolvedRelativePath(File other_file)
{
}

File File::Parent() const
{
}

File File::Root() const
{
}

File::~File()
{
}

}
