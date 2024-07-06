#include <dlfcn.h>
#include <stdio.h>

// void hello();

int main(int argc, char *argv[]) {
  void *handle = dlopen("./libhello.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "Error: %s\n", dlerror());
    return 1;
  }
  // 获取动态库中的函数指针
  void (*hello_func)() = dlsym(handle, "hello");
  if (!hello_func) {
    fprintf(stderr, "Error: %s\n", dlerror());
    dlclose(handle);
    return 1;
  }
  hello_func();
  getchar();
  return 0;
}
