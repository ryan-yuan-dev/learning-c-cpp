// Copyright 2020 Ryan
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::thread;
using std::chrono::seconds;
using std::this_thread::get_id;
using std::this_thread::sleep_for;

void thread_func(int *result) {
  int total = 0;
  for (size_t i = 0; i < 100; i++) {
    total += i;
  }
  cout << "Thread function called" << endl;
  sleep_for(seconds(2));
  cout << "Thread function finished" << endl;
  *result = total;
  // 打印线程 id 和计算结果
  cout << "Thread id: " << get_id() << " calculate result is " << *result
       << endl;
}

void create_thread() {
  // 打印当前线程 id
  cout << "Main thread id: " << get_id() << endl;
  cout << "create a new thread" << endl;
  int result = 0;
  thread t(thread_func, &result);
  t.detach();
}
