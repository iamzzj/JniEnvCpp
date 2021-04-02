#include <iostream>
#include <utility>

using namespace std; //命名空间，java中的内部类

// 1.属性初始化
class Person {
protected:
    char *name;
    int age;
public:
    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Course {
public:
    string name;
public:
    Course(string name) {
        this->name = name;
    }
};

class Student : public Person {
private:
    //char *courseName;
    Course course;
public:
    Student(char *name, int age, Course course) : Person(name, age), course(course) {//初始化父类的属性
        //this->courseName = courseName;
    }

    void print() {
        cout << this->name << ", " << this->course.name.c_str() << endl;
    }
};

int main() {

    auto student = new Student("Darren", 24, Course("English"));

    student->print();

    delete student;

    return 0;
}
