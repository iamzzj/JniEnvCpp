#include <iostream>

using namespace std; //命名空间，java中的内部类

class Vector {
private:
    int x;
    int y;
public:
    Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }

public:
    void setX(int x) {
        this->x = x;
    }

    int getX() {
        return this->x;
    }

    void setY(int y) {
        this->y = y;
    }

    int getY() {
        return this->y;
    }

    /*
     * 为什么要用引用，为了防止重复创建对象
     * const关键常量，为了防止修改值和重复赋值
     * 注意：const修饰不能调用方法
     */
    Vector operator-(const Vector &vector1) {
        Vector vector(this->getX() - vector1.x,
                      this->getY() - vector1.y);
        return vector;// 不建议返回引用，realse系统智能处理，没有析构该对象
    }

    // 自增减运算符
    void operator++() {
        this->setX(this->getX() + 1);
        this->setY(this->getY() + 1);
    }

    // 后置++
    void operator++(int) {
        this->setX(this->getX() + 1);
        this->setY(this->getY() + 1);
    }

    void operator--() {
        this->setX(this->getX() - 1);
        this->setY(this->getY() - 1);
    }

    // 输出运算符
    friend ostream &operator<<(ostream &ostr, const Vector &vector) {
        ostr << vector.x << ", " << vector.y;
        return ostr;
    }

    // 条件运算符
    bool operator==(const Vector &vector) const {
        return this->x == vector.x && this->y == vector.y;
    }
};

/**
 * 定义在类的外面，一般来说要定义在类的里面
 *
 * 重载运算符
 * @param vector1
 * @param vector2
 * @return
 */
Vector operator+(Vector vector1, Vector vector2) {
    Vector vector(vector1.getX() + vector2.getX(),
                  vector1.getY() + vector2.getY());
    return vector;
}

/*
int main() {
    Vector vector1(1, 2);
    Vector vector2(2, 3);

    // java 中 string + string
    //char *str = "123" + "456";

    // 重载+运算符
    Vector vector = vector1 - vector2;

    vector++;

    cout << vector.getX() << ", " << vector.getY() << endl;

    cout << vector << endl;

    cout << (vector1 == vector2) << endl;

    return 0;
}*/


class Array {
public:
    Array(int size) {
        this->size = size;
        this->array = (int *) malloc(sizeof(int) * size);
    }

    ~Array() {
        if (this->array) {
            free(this->array);
            this->array = NULL;
        }
    }

private:
    int size;
    int *array;
public:
    void set(int index, int value) {
        array[index] = value;
    }

    int get(int index) {
        return this->array[index];
    }

    int getSize() {
        return this->size;
    }

    // 操作符[]
    int operator[](int index) {
        return this->array[index];
    }
};

void printfArray(Array &array) {
    for (size_t i = 0; i < array.getSize(); i++) {
        // cout << array.get(i) << endl;
        cout << array[i] << endl;
    }
}

/*
int main() {
    auto array = new Array(5);

    array->set(0, 0);
    array->set(1, 1);
    array->set(2, 2);

    printfArray(*array);

    delete array;
    return 0;
}*/

class Person {
    /**
     * 变量修饰符
     * private 本类中使用
     * protected 子类中能使用（默认）
     * public 任何地方可以使用
     */
private:
    char *name;
    int age;
public:
    Person(char *name, int age) {
        cout << "Person(char *name, int age)" << endl;
        this->name = name;
        this->age = age;
    }

public:
    void print() {
        cout << this->name << ", " << this->age << endl;
    }
};

// 继承语法
// 类继承修饰符
class Student : public Person {
public:
    //Student() : Person("Darren", 24)
    Student(char *name, int age) : Person(name, age) {
        cout << "Student(char *name, int age)" << endl;
    }
};

class Teacher : public Person {
private:
    Student stu;
public:
    // 不光可以给父类初始化属性，还可以给本类的属性进行初始化，用，给开即可
    Teacher(char *name, int age) : Person(name, age), stu(name, age) {
        cout << "Teacher(char *name, int age)" << endl;
        //stu = Student("Darren", 24); 错误的方式
    }

    void print(){
        stu.print();
    }
};

int main() {
    Student stu("Darren", 24);

    stu.print();

    Teacher teacher("Darren" ,24);

    teacher.print();

    return 0;
}
