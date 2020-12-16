#include "fifo.h"

namespace ipc{

Fifo::Fifo(const std::string& path, mode_t mode) 
    : name_(path),mode_(mode) 
    {}

Fifo::~Fifo() {
  close(fd_);
  unlink(name_.c_str());
}

bool Fifo::Create(){
  if (!IsExist(name_, mode_)) {
    return -1 != mkfifo(name_.c_str(), mode_);
  }else{
    return false;
  }
}

bool Fifo::Open(int flags) {
  fd_ = open(name_.c_str(), flags);
  return -1 != fd_;
}

bool Fifo::Open(int flags, mode_t mode) {
  fd_ = open(name_.c_str(), flags, mode);
  return -1 != fd_;
}

ssize_t Fifo::Read(void* buf, size_t num) {
  return read(fd_, buf, num);
}

ssize_t Fifo::Write(const void* msg, size_t num) {
  return write(fd_, msg, num);
}

bool Fifo::IsExist(const std::string& path, mode_t mode) {
  return 0 == access(path.c_str(), mode);
}

} //namespace ipc
