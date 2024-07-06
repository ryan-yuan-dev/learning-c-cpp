#include <iostream>

#ifdef __cplusplus
extern "C" {
void hello() {
  std::cout << "hello world!" << std::endl;
}
}
#endif