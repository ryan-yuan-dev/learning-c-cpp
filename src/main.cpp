// Copyright 2020 <Ryan>

#include "include/common_include.h"
#include "include/simple_thread.h"

int main(int argc, char const *argv[]) {
  loongflavors::CreateThread();
  std::cout << "Hello World!" << std::endl;
  int c = 0;
  do {
    std::cout << "Press q to exit" << std::endl;
    c = std::cin.get();
  } while (c != 'q');
  // 从1打印到100
  return 0;
}
