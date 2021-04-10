#include <iostream>

using namespace std; //命名空间，java中的内部类

// 应用相当于指针
void change(int &number) {//相当于change(int* number)
    number = 12;//  相当于*number = 12
}

int get() {
    int number = 10;
    return number;
}

int &get1() {
    int number = 10;
    return number;
}

/**
 * const
 * @return
 */
int main() {

    int number = 1;

    //常量指针
    const int *n_p1 = &number;
    //*n_p1 = 23;

    // 指针常量
    int *const n_p2 = &number;
    //n_p2 = n_p1;

    // c/c++ const区别
    // c中const只是编译期的一个检测
    // c++里面不光在编译期做处理，还在运行时做了处理

    // 应用做左值和右值的问题
    int number1 = get();//10
    cout << number1 << endl;

    int number2 = get1();//10
    cout << number2 << endl;

    int& number3 = get1();//野指针
    cout << number3 << endl;

    return 0;
}
