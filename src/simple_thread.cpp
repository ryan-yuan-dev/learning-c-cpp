
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void threadFunc()
{    
    cout << "Thread function called" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread function finished" << endl;
}

void create_thread()
{
    // 打印当前线程 id  
    cout << "Main thread id: " << this_thread::get_id() << endl;
    cout << "create a new thread" << endl;
    thread t(threadFunc);
    // 打印线程 id
    cout << "Thread id: " << t.get_id() << endl;    
    t.join();   
}



