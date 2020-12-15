#ifndef COMMON_NONCOPYABLE_HEADER_FILE
#define COMMON_NONCOPYABLE_HEADER_FILE

namespace common {
    
class Noncopyable {
 public:
  Noncopyable(const Noncopyable&) = delete;
  void operator=(const Noncopyable&) = delete;

 protected:
  Noncopyable() = default;
  ~Noncopyable() = default;
};

} //namespace common

#endif
