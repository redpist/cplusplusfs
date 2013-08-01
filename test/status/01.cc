#include "cplusplusfs/status.h"
#include <iostream>

void PrintStatusDetails(const cplusplusfs::Status &s) {
    std::cout << s << std::endl;
    std::cout << s.ErrorMessage() << std::endl;
}

int main(int argc, char const *argv[])
{
  {
    cplusplusfs::Status s(true);
    PrintStatusDetails(s);
  }
  {
    cplusplusfs::Status s(false, 0);
    PrintStatusDetails(s);
  }
  {
    cplusplusfs::Status s(false, 1);
    PrintStatusDetails(s);
  }
  {
    cplusplusfs::Status s(false, 2);
    PrintStatusDetails(s);
  }
  {
    cplusplusfs::Status s(false, 453);
    PrintStatusDetails(s);
  }
  {
    cplusplusfs::Status s(false, 4556463);
    PrintStatusDetails(s);
  }
  
  return 0;
}