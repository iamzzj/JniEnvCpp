#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std; //命名空间，java中的内部类

class Compare {
public:
    void operator()() {
        cout << "仿函数" << endl;
    }
};

void compare() {
    cout << "普通函数" << endl;
}

// 一元谓词
void print(int number) {
    cout << number << endl;
}

// 仿函数，一元谓词 (能够记录状态)
class printClass {
private:
    int count = 0;
public:
    void operator()(int number) {
        count++;
        cout << number << endl;
    }

    int getCount() const {
        return count;
    }
};

class EqualsClass {
public:
    bool operator()(const string str1, const string str2) {
        return str1 < str2;
    }
};

/**
 * 函数对象（仿函数） 一元谓词，二元谓词
 * @return
 */
int main() {
    compare();//普通函数

    Compare compare;

    compare();//对象写()操作符号

    set<int> st;

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    // for_each 算法包
    cout << "for_each" << endl;
    for_each(st.begin(), st.end(), print);

    printClass pc;
    pc = for_each(st.begin(), st.end(), pc);
    cout << "count:" << pc.getCount() << endl;


    cout << "EqualsClass" << endl;
    // 二元谓词的仿函数
    set<string, EqualsClass> vt;
    vt.insert("aaa");
    vt.insert("bbb");
    vt.insert("ccc");
    vt.insert("ddd");

    // 是否包含aaa
    for (auto it = vt.begin(); it != vt.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
