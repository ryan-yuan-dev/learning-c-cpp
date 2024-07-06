# 将 C++ 代码编译成独立的目标文件
g++ -c -fPIC hello.cpp -o hello.o

# 将目标文件链接成共享库
g++ -shared -o libhello.so hello.o

# 链接共享库到可执行文件
gcc -o main main.c -ldl -Wl,-rpath,libhello

# 运行可执行文件
./main

# 清理
# rm libhello.so
# rm hello.o