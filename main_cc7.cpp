#include <iostream>
#include <algorithm> //STL 算法包
#include <cctype> // 用到函数指针
#include <utility>

using namespace std; //命名空间，java中的内部类

/**
 * C++ STL 标准模版库 容器 + 迭代器 + 算法
 *
 * @return
 */
int main() {
    string str1 = "123";
    string str2("123");
    string str3(5, 'A'); // AAAAA

    cout << str1 << endl;
    cout << str1.c_str() << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    // string 转 char*
    const char *c_str1 = str1.c_str();
    cout << c_str1 << endl;
    // char* 转string
    string str4(c_str1);
    cout << str4 << endl;


    string str5 = "1234567";
    int i = 0;
    for (; i < str5.length(); i++) {
        cout << str5[i] << endl; // 会宕机或者打印其他的字符串
        try {
            cout << str5.at(i + 1) << endl;
        } catch (out_of_range oor) {
            cout << oor.what() << endl;
        }
    }

    // 迭代器遍历
    for (string::iterator it = str5.begin(); it < str5.end(); it++) {
        cout << *it << endl;
    }

    // 添加，删除，替换，查找，大小写转换
    string str6 = "123";
    string str7 = "456";
    // 添加
    str6 += str7;
    str6.append(str7);
    cout << str6 << endl;

    // 删除
    str6.erase(0, 3);// 从哪里开始，删除几个 (默认值，字符串结尾)
    cout << str6 << endl;
    // 迭代器删除 删除一个之后，从头开始计算
    for (string::iterator it = str6.begin(); it < str6.begin() + 3; it++) {
        str6.erase(it);
    }
    cout << str6 << endl;

    // 替换
    str6.replace(0, 3, "788");
    cout << str6 << endl;

    // 查找
    int position = str6.find("8", 0);
    cout << position << endl;
    int lastPosition = str6.rfind("8");//从后往前
    cout << lastPosition << endl;

    // 大小写转换
    str6.append("aBcv");
    transform(str6.begin(), str6.end(), str6.begin(), ::toupper);
    cout << str6 << endl;

    return 0;
}
