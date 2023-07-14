#include <stdio.h>
#include <Python.h>
using namespace std;

void int_object(){
    // 第一种方式
    PyObject *py_ival = Py_BuildValue("i", -5987);   // Python有符号整型
    PyObject *py_ival2 = PyLong_FromLong(-8979);
    int ival = PyLong_AsLong(py_ival);   // 把Python有字符整型转换成C的有字符整型
    int ival2 = PyLong_AsLong(py_ival2);   // 把Python有字符整型转换成C的有字符整型
    printf("ival = %d, ival2 = %d\n", ival, ival2);

    // 第二种方式
    PyObject *py_uval = Py_BuildValue("I", 465486);   // Python无符号整型
    PyObject *py_uval2 = PyLong_FromUnsignedLong(1654864);
    unsigned int uval = PyLong_AsUnsignedLong(py_uval);        // 把Python无字符整型转换成C的无字符整型
    unsigned int uval2 = PyLong_AsUnsignedLong(py_uval2);        // 把Python无字符整型转换成C的无字符整型
    printf("uval = %u, uval2 = %u\n", uval, uval2);
}

void double_object(){
    // 第一种方式
    float fval = 632.045;
    PyObject *py_fval = Py_BuildValue("d", fval);   // Python 浮点类型
    float c_fval = PyFloat_AsDouble(py_fval);    // C的浮点类型
    printf("fval = %f\n", c_fval);

    // 第二种方式
    double  dval = 48941546.578;
    PyObject *py_dval = PyFloat_FromDouble(dval);   // Python 浮点类型
    double c_dval = PyFloat_AsDouble(py_dval);   // C的浮点类型
    printf("c_dval = %lf\n", c_dval);
}

void boolean_object(){
    // 第一种方式
    bool bval = true;   // false 反之
    PyObject *py_bval = Py_BuildValue("b", bval);   // Python 布尔类型
    int c_bval = PyLong_AsLong(py_bval);
    printf("c_bval = %d\n", c_bval);

    // 第二种方式
    bool bval2 = false;
    PyObject *py_bval2 = PyBool_FromLong(bval2);   // Python 布尔类型
    int c_bval2 = PyLong_AsLong(py_bval2);
    printf("c_bval2 = %d\n", c_bval2);
}

void string_object(){
    // 第一种方式
    const char *pstr = "this is a test";
    PyObject *py_str = Py_BuildValue("s", pstr);   // Python 字符串对象
    const char *c_pstr = PyUnicode_AsUTF8(py_str);   // 转成C的字符指针
    printf("c_pstr = %s\n", c_pstr);
}

int main() {

    // 初始化Python虚拟机
    Py_Initialize();
    // 判断Python虚拟机是否成功
    if (Py_IsInitialized() == 0){
        printf("fal to initialize Python\n");
        return -1;
    }

    printf("server start\n");

    int_object();
    double_object();
    boolean_object();
    string_object();

    // 退出Python虚拟机
    Py_Finalize();
    printf("server end\n");

    return 0;
}