#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (max_size == 0) {
      throw std::logic_error{"Max size must be at least 1"};
    }
    buffer = new char[max_size];
  }

  SimpleString(const SimpleString &other)
      : buffer{new char[other.max_size]}, length{other.length},
        max_size{other.max_size} {
    std::strncpy(buffer, other.buffer, max_size);
  }

  SimpleString(SimpleString &&other) noexcept
      : buffer{other.buffer}, length{other.length}, max_size{other.max_size} {
    other.max_size = 0;
    other.length = 0;
    other.buffer = nullptr;
  }

  SimpleString &operator=(const SimpleString &other) {
    if (this == &other)
      return *this;
    max_size = other.max_size;
    // 因为复制是在类已存在的前提下，所以之前的资源要释放！
    delete[] buffer;
    buffer = new char[max_size];
    length = other.length;

    std::strncpy(buffer, other.buffer, max_size);
    return *this;
  }

  SimpleString &operator=(SimpleString &&other) noexcept {
    if (this == &other)
      return *this;
    delete[] buffer;
    buffer = other.buffer;
    max_size = other.max_size;
    length = other.length;
    other.buffer = nullptr;
    other.max_size = 0;
    other.length = 0;

    return *this;
  }

  void print(const char *tag) const { printf("%s: %s", tag, buffer); }

  bool append_line(char *x) {
    const auto len = strlen(x);
    if (length + len + 2 > max_size)
      return false;
    std::strncpy(buffer + length, x, max_size - length);
    length += len;
    buffer[length++] = '\n';
    buffer[length] = '\0';
    return true;
  }

  ~SimpleString() { delete[] buffer; }

private:
  size_t max_size;
  size_t length;
  char *buffer;
};
