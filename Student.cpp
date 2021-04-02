#include "Student.h"
#include <iostream>

using namespace std;

/**
 * 先会调用一个参数的构造函数，才会调用自己
 */
Student::Student() : Student("name") {
    cout << "无参数构造函数" << endl;
}

Student::Student(char *name) : age(0) {
    this->name = name;
    cout << "一个参数构造函数" << endl;
}

/**
 * 析构函数
 * 临终一眼，对象被回收的时候会调用
 *
 * 如果在对象内部开辟堆内存，可以在析构函数开辟内存
 */
Student::~Student() {
    cout << "析构函数" << endl;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setName(char *name) {
    this->name = name;
}

int Student::getAge() {
    return this->age;
}

char *Student::getName() {
    return this->name;
}





