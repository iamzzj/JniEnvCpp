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

        cout << "Person()" << endl;
    }

    ~Person() {
        cout << "~Person()" << endl;
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
        cout << "Student()" << endl;
    }

    ~Student() {
        cout << "~Student()" << endl;
    }

    void print() {
        cout << this->name << ", " << this->course.name.c_str() << endl;
    }
};

class A {
public:
    char *name;
public:
    A(char *name) {
        this->name = name;
    }

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        A::name = name;
    }
};

class B {
public:
    int age;
public:
    B(int age) {
        this->age = age;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        B::age = age;
    }
};

/**
 * 多继承，但不能有歧义
 */
class C : public A, public B {
public:
    C(char *name, int age) : A(name), B(age) {

    }
};


class D {
public:
    char *name;
};

/**
 * 虚继承（二义性）
 * 确保继承过来的属性，只存在一份拷贝
 */
class E : virtual public D {

};

class F : virtual public D {

};

class G : public E, public F {

};

/**
 * 多态
 */
class Activity {
public:
    /**
     * 虚函数，支持多态
     */
    virtual void onCreate() {
        cout << "Activity onCreate" << endl;
    }
};

void startActivity(Activity *activity) {
    activity->onCreate();
}

class MainActivity : public Activity {
public:
    void onCreate() {
        cout << "MainActivity onCreate" << endl;
    }
};

class WelcomeActivity : public Activity {
public:
    void onCreate() {
        cout << "WelcomeActivity onCreate" << endl;
    }
};

/**
 * 静态多态
 * @return
 */
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

/**
 * java中类似的抽象类，接口，纯虚函数
 */
class BaseActivity {
public:
    /**
     * 普通函数
     */
    void onCreate() {
        initData();
        initView();
    }

    /**
     * 纯虚函数
     * 必须实现
     */
    virtual void initData() = 0;

    virtual void initView() = 0;
};

/**
 * 如果不实现父类的纯虚函数，那么HelloActivity也会变成抽象类
 */
class HelloActivity : public BaseActivity {
public:
    void initData() override {
        cout << "initData" << endl;
    }

    void initView() override {
        cout << "initView" << endl;
    }
};

/**
 * 模版函数（java中的泛型）
 */
float add(float a, float b) {
    return a + b;
}

template<typename T>
T add(T num1, T num2) {
    return num1 + num2;
}

int main() {

    auto student = new Student("Darren", 24, Course("English"));

    student->print();

    delete student;

    C c("name", 23);

    cout << c.getName() << "," << c.getAge() << endl;


    G g;
    g.name = "name";

    cout << g.name << endl;


    Activity *activity = new MainActivity;

    // c++默认情况下不存在多态
    // 程序在编译时并不知道运行的状态，只有真正运行才知道所用的方法
    startActivity(activity);

    delete activity;

    //c++多态：动态多态（子父类），静态多态（函数的重载）
    add(1, 2);

    BaseActivity *baseActivity = new HelloActivity;

    baseActivity->onCreate();

    delete baseActivity;

    // 构造函数先父类，再子类
    // 析构函数先子类，再父类
    Student *stu = new Student("stu", 23, Course("english"));

    delete stu;

    return 0;
}
