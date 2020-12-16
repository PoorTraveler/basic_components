#ifndef IPC_PIPE_HEADER_FILE
#define IPC_PIPE_HEADER_FILE

#include <unistd.h>
#include <assert.h>

namespace ipc{

class Pipe  {
 public:
  Pipe();
  ~Pipe();
  bool Open();
  ssize_t Write(void* msg, size_t count);
  ssize_t Read(void* buf, size_t count);
  void CloseWriteEnd();
  void CloseReadEnd();
  void Close();
  
 private:
  // fd_array_[0]:  read
  // fd_array_[1]:  write
  int fd_array_[2] = {-1, -1};
};

} //namespace ipc
#endif
