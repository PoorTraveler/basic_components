#pragma once
#include <assert.h>
#include <signal.h>
#include <unistd.h>
#include <vector>
#include "noncopyable.h"

using SignalHandleType = void (*)(int);
struct SignalInfo {
  int signo_;
  SignalHandleType cb_;
};

class Signal : public common::Noncopyable {
 public:
  using SignalInfoVec = std::vector<SignalInfo*>;
  using SignalInfoVecIterator = SignalInfoVec::iterator;
  Signal();
  ~Signal();
  bool RegistrySignalAction(const SignalInfo& info);
  bool CancelRegisteredSignal(int signo);
  bool SendSignal(pid_t pid, int signo);

 private:
  bool ProcessIsExist(pid_t pid);
  static void SignalProcess(int signo, siginfo_t* info, void* p);
  static SignalInfoVec* SignalList() { return info_vec_; }

 private:
  sigset_t mask_;
  struct sigaction act_;
  static SignalInfoVec* info_vec_;
};

