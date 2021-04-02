#include <iostream>
#include "Student.h"

using namespace std; //命名空间，java中的内部类

/**
 * c++ 支持重载 可以有默认值
 * @param num1
 * @param num2 默认为200可以不传
 * @return
 */
int add(int num1, int num2 = 200, bool bl = true) {
    return num1 + num2;
}

/**
 * c++ 支持重载
 * @param num1
 * @param num2
 * @param num3
 * @return
 */
int add(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

/**
 * 类的初探
 */
/*class Student {
private:
    char *name;
public:
    int age;
public:
    void setAge(int age) {
        // 自带this指针
        this->age = age;
    }

    void setName(char *name) {
        this->name = name;
    }

    int getAge() {
        return this->age;
    }

    char *getName() {
        return this->name;
    }
};*/

/**
 * 1. c++代码中可以混编 c代码，c++里面写c代码，也可以调用
 * 2. c++面向对象（Java），c面向过程
 * 3. 很多开源框架大部分是c++写的
 *
 *
 *
 * @return
 */
int main() {

    // << 操作符重载
    cout << "Hello, World!" << endl;

    /* 部分c可以修改 一个伪命题
    const int number = 10;
    int* numberP = &number;
    *numberP = 20;*/

    int a = 10;
    //引用，a的地址的另一个别名，地址都是同一个，
    int &b = a;

    int result = add(100);
    cout << result << endl;

    result = add(100, 100);
    cout << result << endl;

    result = add(100, 100, 200);
    cout << result << endl;

    bool cache = -1;// 0=false 其他=true
    if (cache) {
        cout << "ture" << endl;
    } else {
        cout << "false" << endl;
    }

    // 补充：开发过程重要，直接写的问题所在
    // class编译成so不能用，必须要有一个头文件
    // 实现方法要有命名空间 Student::getAge()
    auto *stu = new Student();
    stu->setName("Darren");
    stu->setAge(23);

    cout << stu->getName() << ", " << stu->age << endl;

    //1
    Student student;
    //2
    Student student2("name");
    //3
    Student *student3 = new Student("name");
    //4 不会调用构造参数
    Student *student4 = (Student *) malloc(sizeof(Student));

    delete student3;

    free(student4);
    // malloc，free，new，delete区别
    // 1. malloc/free是一套，new/delete 也是一套
    // 2. malloc/free不会调用构造函数/析构函数
    // 3. new/delete 会调用构造函数/析构函数
    // 4. 如果用了new一定要delete释放内存

    return 0;
}

