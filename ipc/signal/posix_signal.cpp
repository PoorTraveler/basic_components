#include "osi_signal.h"


static const int kVectorReserve = 15;
static const int kSignalNumMax = 32;
static const int kSignalNumMin = 0;

Signal::SignalInfoVec* Signal::info_vec_ = nullptr;

Signal::Signal() {
  info_vec_ = new SignalInfoVec();
  info_vec_->reserve(kVectorReserve);
  sigemptyset(&act_.sa_mask);
  act_.sa_flags = SA_SIGINFO;
}

Signal::~Signal() {
  SignalInfo* temp = nullptr;
  while (!info_vec_->empty()) {
    temp = info_vec_->back();
    act_.sa_handler = SIG_DFL;
    sigaction(temp->signo_, &act_, nullptr);
    info_vec_->pop_back();
    delete temp;
    temp = nullptr;
  }
  delete info_vec_;
}

bool Signal::RegistrySignalAction(const SignalInfo& info) {
  assert(info.signo_ != SIGKILL && info.signo_ != SIGSTOP &&
         info.signo_ > kSignalNumMin && info.signo_ <= kSignalNumMax);
  SignalInfo* si = new SignalInfo();
  si->signo_ = info.signo_;
  si->cb_ = info.cb_;
  act_.sa_sigaction = SignalProcess;
  if (sigaction(info.signo_, &act_, nullptr) < 0) {
    delete si;
    return false;
  }
  info_vec_->push_back(si);
  return true;
}

bool Signal::CancelRegisteredSignal(int signo) {
  SignalInfoVecIterator it;
  SignalInfo* p = nullptr;
  for (it = info_vec_->begin(); it != info_vec_->end(); ++it) {
    if (signo == (*it)->signo_) {
      p = *it;
      info_vec_->erase(it);
      delete p;
      act_.sa_handler = SIG_DFL;
      if (sigaction(signo, &act_, nullptr) < 0) {
        return false;
      }
      break;
    }
  }
  return true;
}

void Signal::SignalProcess(int signo, siginfo_t* info, void* p) {
  SignalInfoVecIterator it;
  SignalInfoVec* sv = SignalList();
  for (it = sv->begin(); it != sv->end(); ++it) {
    if ((*it)->signo_ == signo) {
      if ((*it)->cb_ != nullptr) {
        (*it)->cb_(signo);
        break;
      } else
        break;
    }
  }
}

bool Signal::SendSignal(pid_t pid, int signo) {
  if (!ProcessIsExist(pid)) {
    return false;
  }
  return 0 == kill(pid, signo);
}

bool Signal::ProcessIsExist(pid_t pid) { return 0 == kill(pid, 0); }

