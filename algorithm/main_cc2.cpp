#include <iostream>
#include "LinkList.hpp"

using namespace std; //命名空间，java中的内部类

int main() {
    LinkList<int> linkList;

    linkList.push(0);
    linkList.push(2);
    linkList.push(3);

    linkList.insert(0, 4);
    linkList.remove(1);

    for (int i = 0; i < linkList.size(); i++) {
        cout << linkList.get(i) << endl;
    }

    return 0;
}
