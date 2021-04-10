#include <iostream>
#include <map>
#include <vector>

using namespace std; //命名空间，java中的内部类

class Person {
private:
    string name;
public:
    Person(const string &name) : name(name) {
        cout << "Person(const string &name)" <<endl;
        this->name = name;
    }
    ~Person(){
        cout << "~Person" <<endl;
    }

    Person(const Person &person) {
        cout << "Person(const Person &person)" <<endl;
        this->name = person.name;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Person::name = name;
    }
};

int main() {

    // map 会key排序
    map<int, string> mp;

    // 添加数据
    mp.insert(pair<int, string>(1, "01"));
    mp.insert(make_pair(2, "02"));
    mp.insert(map<int, string>::value_type(3, "03"));
    mp[4] = "04";

    // 循环
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }

    // 查找
    auto find_it = mp.find(4);

    if (find_it != mp.end()) {
        cout << find_it->first << ", " << find_it->second << endl;
    }

    // multimap 可以键重复
    cout << "multimap" << endl;
    multimap<int, string> mmp;
    mmp.insert(pair<int, string>(1, "1"));
    mmp.insert(pair<int, string>(1, "1"));
    mmp.insert(pair<int, string>(2, "21"));
    mmp.insert(pair<int, string>(2, "23"));
    mmp.insert(pair<int, string>(2, "22"));
    mmp.insert(pair<int, string>(4, "32"));
    mmp.insert(pair<int, string>(4, "33"));

    auto mmp_find_it = mmp.find(4);
    while (mmp_find_it != mmp.end()) {
        cout << mmp_find_it->first << ", " << mmp_find_it->second << endl;
        mmp_find_it++;

        //  不是要找的组
        if (mmp_find_it == mmp.end() &&
            mmp_find_it->first != 4) {
            break;
        }
    }


    // 容器对象拷贝构造函数
    // 对象添加到集合 c++中会调用对象的拷贝构造函数
    vector<Person> vt;

    Person person("kevin");

    vt.insert(vt.begin(), person);

    person.setName("xm");

    cout << person.getName() << endl;
    cout << vt.front().getName() << endl;


    return 0;
}
