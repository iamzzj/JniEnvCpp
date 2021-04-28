#include <iostream>
#include <utility>

using namespace std; //命名空间，java中的内部类

class Person {
public:
    int age;
public:
    Person() {
    }

    Person(int age) {
        this->age = age;
    }
};

class Student : public Person {

};

class Exception : public out_of_range {
private:
    string msg;
public:
    Exception(const string& msg) : out_of_range(msg) {
        this->msg = msg;
    }

public:
    string getMsg() {
        return this->msg;
    }
};

int main() {
    double number1 = 20.02;

    // 直接转换
    int number2 = number1;

    // static_cast静态转换
    // 1.用于基本数据类型之间的转换，如把int转换为char
    int number3 = static_cast<int>(number1);
    cout << number2 << endl;
    cout << number3 << endl;

    // 2.把类型转换成另一种类型，用于类层次结构中积累和派生类之间指针或引用的转换
    Student *student = new Student();
    Person *person1 = student;
    Person *person2 = static_cast<Person *>(student);

    // const_cast常量转换
    const Person *person3 = new Person(23);
    cout << person3->age << endl;
    Person *person4 = const_cast<Person *>(person3);
    person4->age = 25;
    cout << person3->age << endl;

    // reinterpret_cast强制类型转换
    Person *person5 = new Person();
    // 除了子父类，各种类型的转换 long->对象指针
    // 与static_cast 区别在于static_cast一般用于转换继承关系的类型
    Student *student2 = reinterpret_cast<Student *>(person5);

    // dynamic_cast动态转换类型，更安全，成功返回类型，失败返回NULL
    // 其他都是在编译时完成的，dynamic_cast在运行时转换


    // 异常的处理
    // c++中有自己的异常体系，不要去强记，可以抛任何数据类型
    try {
        int i = 0;
        if (i == 0) {
            throw Exception("exception");
        } else {
            i++;
            cout << i << endl;
        }
    } catch (int number) {
        cout << "catch: " << number << endl;
    } catch (Exception e) {
        cout << "catch: " << e.getMsg() << endl;
    }
    // jclass je = env->FindClass("java/lang/Exception");
    // env->ThrowNew(je, "unknown");

    return 0;
}
