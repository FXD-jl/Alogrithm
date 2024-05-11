#include <iostream>
#include <sys/time.h>
#include <unistd.h>
struct TimerClass {

  TimerClass() : name{""} { gettimeofday(timestamp, NULL); }

  TimerClass(std::string classname) : name(classname) {
    gettimeofday(timestamp, NULL);
  }
  ~TimerClass() {
    if (timestamp != nullptr) {
      struct timeval init_timestamp;
      init_timestamp.tv_sec = timestamp->tv_sec;
      init_timestamp.tv_usec = timestamp->tv_usec;
      gettimeofday(timestamp, NULL);
      time_t time_t_div = timestamp->tv_sec - init_timestamp.tv_sec;
      suseconds_t suseconds_t_div = timestamp->tv_usec - init_timestamp.tv_usec;
      std::cout << name << "对象的生命周期为: " << time_t_div << "秒"
                << std::endl;
      std::cout << name << "对象的生命周期为: " << suseconds_t_div << "毫秒"
                << std::endl;
    }
    delete timestamp;
  }

  TimerClass(const TimerClass &other, std::string classname) : name(classname) {
    timestamp->tv_usec = other.timestamp->tv_usec;
    timestamp->tv_sec = other.timestamp->tv_sec;
  }

  TimerClass &operator=(TimerClass &other) {
    timestamp->tv_sec = other.timestamp->tv_sec;
    timestamp->tv_usec = other.timestamp->tv_usec;
    return *this;
  }

  TimerClass(TimerClass &&other, std::string name) {
    timestamp = other.timestamp;
    this->name = name;
    other.timestamp = nullptr;
    other.name = "";
  }

  TimerClass &operator=(TimerClass &&other) {
    timestamp = other.timestamp;
    other.name = "";
    other.timestamp = nullptr;
    return *this;
  }

private:
  struct timeval *timestamp = new struct timeval;
  std::string name;
};


