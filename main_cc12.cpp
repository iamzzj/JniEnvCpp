#include <iostream>
#include <set>
#include <functional>

using namespace std; //命名空间，java中的内部类

/**
 * 预定义函数对象和函数适配器
 * @return
 */
int main() {
    // c/c++提供了很多定义好的函数对象
    set<string, greater<string>> st;
    st.insert(st.end(), "aaa");
    st.insert(st.end(), "bbb");
    st.insert(st.end(), "ccc");

    // 常见几个less,greater
    plus<string> ps;//相加
    string result = ps("aaa", "bbb");
    cout << result << endl;

    // 是否包含aaa
    // 怎么写仿函数，一定要确定好，仿函数的参数
    auto find_it = find_if(st.begin(), st.end(),
                           bind2nd(equal_to<string>(), "aaa"));
    if (find_it != st.end()) {
        cout << "find:" << *find_it << endl;
    } else {
        cout << "no find" << endl;
    }

    // count_if() 计数
    // foreach, transform, find, find_if, merge,
    // sort ,random_shuffle,copy,replace
    // sort(vt.begin(),vt.end,less<int>);

    return 0;
}
