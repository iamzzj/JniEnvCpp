#include <iostream>
#include <utility>

using namespace std; //命名空间，java中的内部类

/**
 *  模版函数，编译器根据不同类型对应的生成方法
 */
template<typename T>
T add(T t1, T t2) {
    return t1 + t2;
}

/**
 * 普通函数和模版函数同时存在，
 * 优先调用普通函数
 */
int add(int t1, int t2) {
    return t1 + t2;
}


/**
 * 模版类
 */
template<typename T>
class Class {
public:
    void setT(T t) {
        cout << t << endl;
    }
};

/**
 * 模版类的继承，子类如果也是模版类
 */
template<class T>
class HttpClass : public Class<T> {

};

int main() {

    add(1, 2);
    add(1.0, 2.0);

    Class<int> *c = new Class<int>;
    c->setT(12);

    HttpClass<int> *hc = new HttpClass<int>;
    hc->setT(13);

    return 0;
}
