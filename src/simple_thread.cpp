// Copyright 2024 Ryan <ryan.yuen@qq.com>
#include <chrono>
#include <iostream>
#include <thread>

namespace loongflavors {
void ThreadFunc(int *result) {
  int total = 0;
  for (size_t i = 0; i < 100; i++) {
    total += i;
  }
  std::cout << "Thread function called" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Thread function finished" << std::endl;
  *result = total;
  // 打印线程 id 和计算结果
  std::cout << "Thread id: " << std::this_thread::get_id()
            << " calculate result is " << *result << std::endl;
}

void CreateThread() {
  // 打印当前线程 id
  std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
  std::cout << "create a new thread" << std::endl;
  int result = 0;
  std::thread t(ThreadFunc, &result);
  t.detach();
}
}  // namespace loongflavors
