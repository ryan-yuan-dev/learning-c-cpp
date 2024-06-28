// Copyright 2020 <Ryan>
#include <iostream>

#include "include/simple_thread.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  create_thread();
  cout << "Hello World!" << endl;
  int c = 0;
  do {
    cout << "Press q to exit" << endl;
    c = cin.get();
  } while (c != 'q');
  return 0;
}
