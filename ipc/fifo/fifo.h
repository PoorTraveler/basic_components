#ifndef IPC_FIFO_HEADER_FILE
#define IPC_FIFO_HEADER_FILE

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>

//named pipe
namespace ipc{

class Fifo {
 public:
  Fifo(const std::string& path, mode_t mode);
  ~Fifo();
  bool Create();
  bool Open(int flags);
  bool Open(int flags, mode_t mode);
  ssize_t Read(void* buf, size_t num);
  ssize_t Write(const void* msg, size_t num);
  static bool IsExist(const std::string& path, mode_t mode = F_OK);

 private:
  int fd_;
  mode_t mode_;
  std::string name_;
};

} //namespace ipc
#endif
