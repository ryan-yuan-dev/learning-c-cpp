// Copyright 2020 <Ryan>

#include "include/common_include.h"
#include "include/simple_thread.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  loongflavors::create_thread();
  cout << "Hello World!" << endl;
  int c = 0;
  do {
    cout << "Press q to exit" << endl;
    c = cin.get();
  } while (c != 'q');
  // 从1打印到100
  return 0;
}
