#include "invalidOperationException.h"

InvalidOperationException::InvalidOperationException(){
  message = "The operation attempted is invalid.";
}

InvalidOperationException::~InvalidOperationException(){
  message.clear();
}

std::exception& InvalidOperationException::operator=(const std::exception e){
  message = string(e.what());
  return *this;
}

const char* InvalidOperationException::what() const{
  return message.c_str();
}
