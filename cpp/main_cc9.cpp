#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>

using namespace std; //命名空间，java中的内部类

class Student {
public:
    string name;
    int age;
public:
    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

// 谓词(函数谓词)：按特定的规则所编写的函数谓词
bool compare(const Student &left, const Student &right) {
    return left.age > right.age;
}

// 函数对象，仿函数
struct comparefunction{
    //函数重载了（）运算符，函数对象，仿函数
    bool operator()(const Student &left, const Student &right) const{
        return left.age > right.age;
    }
};

int main() {

    // vector
    vector<int> vt;

    // v.begin 迭代器的位置
    vt.insert(vt.begin(), 12);
    vt.insert(vt.end(), 23);
    vt.insert(vt.end(), 34);
    vt.insert(vt.end(), 45);

    // 修改第一个
    vt.front() = 123;
    // 修改最后一个
    vt.back() = 44;

    // 插入最后一个
    vt.push_back(55);
    // 移除最后一个
    vt.pop_back();

    // 迭代器移除
    vt.erase(vt.begin());

    // 获取数据
    for (int i = 0; i < vt.size(); i++) {
        // cout << vt[i] << endl;
        cout << vt.at(i) << endl;
    }

    for (vector<int>::iterator it = vt.begin(); it != vt.end(); it++) {
        cout << *it << endl;
    }


    // stack 先进后出
    stack<int> st;

    // 压栈
    st.push(12);
    st.push(23);
    st.push(34);

    // 并不能通过角标获取值
    // 迭代器也没有

    int top = st.top();
    cout << "top:" << top << endl;

    st.pop();//弹出栈顶
    top = st.top();
    cout << "top:" << top << endl;


    // queue 先进先出
    queue<int> qu;

    qu.push(12);
    qu.push(23);
    qu.push(34);

    qu.front() = 01;
    cout << qu.front() << endl;

    qu.pop();
    cout << qu.front() << endl;
    cout << qu.back() << endl;


    // priority_queue优先队列 int存放的数据 greater从大到小，less从小到大
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(12);
    pq.push(44);
    pq.push(32);
    pq.push(10);

    //最大值
    cout << pq.top() << endl;


    // list 链表
    list<int> ls;
    // 插入
    ls.push_front(11);
    ls.push_back(22);
    ls.insert(ls.begin(), 10);

    // 修改
    ls.erase(ls.begin());
    ls.back() = 33;
    ls.front() = 44;

    // 不能通过角标去访问，也不能去修改

    // 迭代器循环
    cout << "list" << endl;
    for (list<int>::iterator it = ls.begin(); it != ls.end(); it++) {
        cout << *it << endl;
    }


    // set （红黑树结构），会对存入的数据进行排序，但是不允许元素相同
    set<int, greater<int>> s;
    cout << "set" << endl;

    //添加参数， 不需要用迭代器，也不需要指定位置
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // 重复插入，并不会报错
    pair<set<int>::iterator, bool> res = s.insert(3);
    cout << res.second << endl;

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }

    //multiset 和set一样，允许重复

    return 0;
}
