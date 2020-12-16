#include "pipe.h"

namespace ipc{

Pipe::Pipe() {}

Pipe::~Pipe() {}

//create a pipe
bool Pipe::Open(){
  return pipe(fd_array_) != -1;
}

ssize_t Pipe::Write(void* msg, size_t count) {
  assert(fd_array_[0] != -1 && fd_array_[1] != -1);
  return write(fd_array_[1], msg, count);
}

ssize_t Pipe::Read(void* buf, size_t count) {
  assert(fd_array_[0] != -1 && fd_array_[1] != -1);
  return read(fd_array_[0], buf, count);
}

void Pipe::CloseReadEnd() { (void)close(fd_array_[0]); }

void Pipe::CloseWriteEnd() { (void)close(fd_array_[1]); }

//destroy a pipe
void Pipe::Close(){
  (void)close(fd_array_[0]);
  (void)close(fd_array_[1]);
  fd_array_[0] = -1;
  fd_array_[1] = -1;
}

} //namespace ipc