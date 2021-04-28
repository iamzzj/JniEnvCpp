#include <iostream>
#include <cstdarg>

using namespace std; //命名空间，java中的内部类

/**
 * 可变参数
 * @param ...
 */
int sum(int count, ...) {
    va_list vp;
    // 可变参数指定开始, count代表从哪里开始
    va_start(vp, count);

    int sum = 0, i = 0;

    for (; i < count; i++) {
        int number = va_arg(vp, int);
        sum += number;
    }

    va_end(vp);

    return sum;
}

/*int main() {

    int result = sum(4, 1, 2, 5, 3);

    cout << result << endl;

    return 0;
}*/

class Worker {
private:
    char *name;
    int age;
public:
    static int tag;

    static void changeTag() {
        tag += 12;
    }

    void change() {
        changeTag();
    }
};

/**
 * 静态属性在c++中必须要初始化，初始化必须这么写
 */
int Worker::tag = 12;

/**
 *  静态可以用类名去操作，
 *  静态的属性必须要初始化（实现）
 *  静态的方法只能去操作静态的属性或方法
 *  非静态的可以操作静态的
 * @return
 */
/*int main() {
    Worker::changeTag();

    Worker worker;
    worker.change();
    cout << worker.tag << endl;

    return 0;
}*/


class A {
public:
    double b;
    int a;
    char c;
    static float d;
public:
    int getA() {
        return this->a;
    }
};

class B {
public:
    double b;
    int a;
    char c;
    static float d;
};

class C {
public:
    double b;
    int a;

    C(int a) {
        this->a = a;
    }

public:
    int getA() {
        return this->a;
    }
};

/**
 * 1.对象大小和结构体的大小类似
 * 2.static静态变量和方法并没有算到类的大小中
 * 3.栈，堆，全局（静态，常量，字符串），代码区
 *      我们的大小只与普通属性有关系
 * @return
 */
/*
int main() {

    cout << "A的大小：" << sizeof(A) << endl;
    cout << "B的大小：" << sizeof(B) << endl;
    cout << "C的大小：" << sizeof(C) << endl;

    return 0;
}*/

/**
 * this指针：代表当前对象，因为类的方法存放在代码去，
 * 大家一起共享，所以要有this做区分
 *
 * @return
 */


class Worker1 {
public:
    char *name;
    int age = 0;
public:
    const void change() {
        age += 12;
    }

    /**
     * const在()后主要来限制this关键字
     * this = const Student *const this
     * 第一个const：常量指针，代表值不能修改
     * 第二个const：指针常量，代表指针的地址不能修改
     */
    void change1() const {
        //age += 12; 不能对类的属性进行修改
    }
};

/**
 * const修饰类中的函数
 * @return
 */
/*
int main() {
    Worker1 worker1;
    worker1.change();

    cout << worker1.age << endl;

    return 0;
}*/


/**
 * 友元函数
 */
class Person {
private:
    int age = 0;
    friend class PersonFriend;// PersonFriend 是Person的友元类
public:
    // 如果有自己写构造函数，默认覆盖无参数的构造函数
    Person(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    // 友元函数的声明
    friend void friendChange(Person *person, int age);
};

/**
 * 友元函数
 */
class PersonFriend{
public:
    Person person;
public:
    void changePerson(int age){
        person.age = age;
    }

    int getAge(){
        return person.age;
    }
};

// 友元函数的实现
void friendChange(Person *person, int age) {
    // 修改一下 age的值
    // 在类的内部才能访问私有属性
    // 如果该方法声明为友元函数，那么是可以在外部访问私有属性的
    person->age = age;
}

int main() {
    Person person(24);

    friendChange(&person, 26);

    cout << person.getAge() << endl;

    PersonFriend personFriend();

    return 0;
}