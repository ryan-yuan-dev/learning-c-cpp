// Copyright 2024 Ryan <ryan.yuen@qq.com>
#include <chrono>
#include <iostream>
#include <thread>

namespace loongflavors {
/**
 * @brief 线程函数，用于计算从0到99的累加和
 * @param result 指向计算结果的指针
 *
 * 这个函数创建一个线程，计算从0到99的整数累加和。
 * 在线程执行过程中，它将打印一条消息指示线程开始，然后休眠2秒。
 * 线程结束时，它将打印另一条消息指示线程结束，并通过result指针返回累加和的结果。
 * 同时，它还会打印线程的ID和计算结果。
 */
void CaluteInSubthread(int *result) {
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

/**
 * @brief 创建一个线程并等待其结束
 * @param none
 * @return none
 */
void CreateThread() {
  // 打印当前线程 id
  std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
  std::cout << "Create a subthread" << std::endl;
  auto result = 0;
  std::thread t(CaluteInSubthread, &result);
  t.join();
  std::cout << "Subthread calculated result: " << result << std::endl;
}
}  // namespace loongflavors

#ifdef __cplusplus

extern "C" {
void loongflavors_calute_in_subthread(int *result) {
  loongflavors::CaluteInSubthread(result);
}

void loongflavors_create_thread() {
  loongflavors::CreateThread();
}
}
#endif