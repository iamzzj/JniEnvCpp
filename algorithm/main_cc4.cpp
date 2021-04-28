#include <iostream>
#include <cstdlib>
#include "PriorityQueue.hpp"

using namespace std; //命名空间，java中的内部类

/**
 * 自己和子节点比较，哪个大并交换位置
 *
 * @param array
 * @param index
 * @param len
 */
void compareParentNode(int *array, int index, int len) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left > len - 1 && right > len - 1) {
        return;
    }

    if (right > len - 1) {
        if (array[index] < array[left]) {
            swap(array[index], array[left]);
        }
    } else {
        int max = array[left] > array[right] ? left : right;

        if (array[index] < array[max]) {
            swap(array[index], array[max]);
            compareParentNode(array,max,len);
        }
    }
}

int main() {

    /*int n = 7;
    PriorityQueue<int> pQueue(n);

    for (int i = 0; i < n; i++) {
        pQueue.push(rand() % 100);
    }

    cout << "push " << endl;
    for (int i = 0; i < pQueue.getSize(); i++) {
        cout << "push data: " << pQueue.getElement()[i + 1] << endl;
    }

    pQueue.pop();

    cout << "pop " << endl;
    for (int i = 0; i < pQueue.getSize(); i++) {
        cout << "push data: " << pQueue.getElement()[i + 1] << endl;
    }*/

    int n = 20;
    int *array = new int[n]();
    // 堆排序
    for (int i = 0; i < n; i++) {
        array[i] = rand()%1000;
    }
    // 节点和它的子节点交换，从最后一个叶子节点开始
    for (int i = n / 2 - 1; i >= 0; i--) {
        compareParentNode(array, i, n);
    }
    // 第一个和最后一个交换,并且第一个进行节点交换
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        compareParentNode(array, 0, i);
    }

    cout << "dui: " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;

    return 0;
}
