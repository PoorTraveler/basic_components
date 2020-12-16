#ifndef IPC_SEMAPHORE_HEADER_FILE
#define IPC_SEMAPHORE_HEADER_FILE

#include <semaphore.h>
#include <time.h>
#include <string>
#include <fcntl.h>
#include <assert.h>
#include "noncopyable.h"

namespace ipc{

using uint_t = unsigned int;

class Semaphore : public common::Noncopyable{
 public:
  // unnamed sem
  // if pshared == 0,the semaphore is shared between the threads of a process
  // else semaphore is shared between processes
  Semaphore(int psharead, uint_t init_value);
  // named sem
  Semaphore(const std::string &name, int flag);
  Semaphore(const std::string &name, int flag, mode_t mode,
                     uint_t init_value);
  // destroy unamed sem
  // close and unlink named sem(have kernel persistence)
  ~Semaphore();
  // sem value --1
  bool Wait();
  // sem value ++1
  bool Post();
  // errno maybe set EAGAIN
  bool TryWait();
  bool TimedWait(const struct timespec *abs_timeout);
  // get current sem value
  int  GetValue();
  bool IsNamed()const { return is_named; }
  // shared between the threads of a process
  bool IsProcessShared()const { return is_process_shared; }

 private:
  sem_t *sem_addr;
  bool is_named;
  bool is_process_shared;
  // named semaphore name
  std::string name;
};

} //namespace ipc
#endif
