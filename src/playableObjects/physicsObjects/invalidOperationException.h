#ifndef _INVALID_OPERATION_EXCEPTION_H_
#define _INVALID_OPERATION_EXCEPTION_H_

#include <exception>
#include <string>

class InvalidOperationException : std::exception{
 public:
  InvalidOperationException();
  ~InvalidOperationException();
  std::exception& operator=(const std::exception e);

  const char* what() const;

 private:
  std::string message;
};

#endif
