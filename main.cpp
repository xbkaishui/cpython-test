#include <stdio.h>
#include <Python.h>
using namespace std;

int main() {

    // 初始化Python虚拟机
    Py_Initialize();
    // 判断Python虚拟机是否成功
    if (Py_IsInitialized() == 0){
        printf("fal to initialize Python\n");
        return -1;
    }

    printf("server start\n");

    // 退出Python虚拟机
    Py_Finalize();
    printf("server end\n");
    return 0;
}