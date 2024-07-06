// copyright (c) 2024 by Ryan <ryan.yuen@qq.com>

#ifndef SRC_INCLUDE_SIMPLE_THREAD_H_
#define SRC_INCLUDE_SIMPLE_THREAD_H_

#ifdef __cplusplus
namespace loongflavors {
// 声明线程函数
void CaluteInSubthread(int *result);

// 声明创建线程的函数
void CreateThread();
}  // namespace loongflavors
#endif

#endif  //  SRC_INCLUDE_SIMPLE_THREAD_H_