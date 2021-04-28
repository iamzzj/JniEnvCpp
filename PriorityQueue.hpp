//
// Created by z on 2021/4/27.
//

#ifndef JNIENVCPP_PRIORITYQUEUE_H
#define JNIENVCPP_PRIORITYQUEUE_H

#include <iostream>

using namespace std;

template<class E>
class PriorityQueue {
private:
    int count; //数组的大小
    int index = 0; //当前位置的角标
    E *array;// 数据数组

public:
    PriorityQueue(int count) {
        this->count = count;
        array = new E[count];
    }

    bool isEmpty() {
        return index == 0;
    }

    int getSize() {
        return index;
    }

    E *getElement() {
        return array;
    }

    void push(E e) {
        array[index + 1] = e;

        index++;

        // 不断地调整堆
        shiftUp(index);
    }

    E pop() {
        if (index == 0) {
            return NULL;
        }
        E max = array[1];
        swap(array[1], array[index]);
        index--;

        shiftDown(1);

        return max;
    }

private:
    /**
     * 最大的往上冒
     *
     * @param key
     */
    void shiftUp(int key) {
        if (key > 1 && array[key] > array[key / 2]) {
            swap(array[key], array[key / 2]);
            shiftUp(key / 2);
        }
    }

    /**
     * 移除第一个，和最后一个交换
     * 最上面的往下移
     *
     *        73
     *     /     \
     *    58     72
     *   /  \   /  \
     *  7   30 49   1
     *
     * @param key
     */
    void shiftDown(int key) {
        if (key * 2 < index) {
            int maxIndex = (array[key * 2] > array[key * 2 + 1]) ?
                           (key * 2) : (key * 2 + 1);
            swap(array[key], array[maxIndex]);
            shiftDown(maxIndex);
        } else if (key * 2 == index) {
            // 只有一个左节点时
            swap(array[key], array[index]);
        }
    }
};

#endif //JNIENVCPP_PRIORITYQUEUE_H
