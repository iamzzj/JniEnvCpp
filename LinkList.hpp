//
// Created by z on 2021/4/21.
//

#ifndef JNIENVCPP_LINKLIST_H
#define JNIENVCPP_LINKLIST_H

#include <iostream>

using namespace std;

template<class T>
struct Node {
    T value;
    Node<T> *next;

public:
    Node(T value, Node<T> *next) {
        this->value = value;
        this->next = next;
    }
};

template<class T>
class LinkList {
private:
    Node<T> *head = NULL;
    int len = 0;
public:
    LinkList();

    ~LinkList();

public:
    Node<T> *node(int index);

    int size();

    void push(T t);

    T get(int index);

    void insert(int index, T t);

    void remove(int index);
};

template<class T>
LinkList<T>::LinkList() {
    cout << "LinkList()" << endl;
}

template<class T>
LinkList<T>::~LinkList() {
    cout << "~LinkList()" << endl;
    for (int i = len - 1; i >= 0; i--) {
        delete node(i);
    }
}

template<class T>
Node<T> *LinkList<T>::node(int index) {
    Node<T> *start = head;
    for (int i = 0; i < index; i++) {
        start = start->next;
    }
    return start;
}

template<class T>
int LinkList<T>::size() {
    return len;
}

template<class T>
void LinkList<T>::push(T t) {
    Node<T> *pushNode = new Node<T>(t, NULL);

    if (head) {
        node(len - 1)->next = pushNode;
    } else {
        head = pushNode;
    }

    len++;
}

template<class T>
T LinkList<T>::get(int index) {
    if (index < 0 || index >= len) {
        return NULL;
    }
    return node(index)->value;
}

template<class T>
void LinkList<T>::insert(int index, T t) {

    if (index < 0 || index > len) {
        cout << "err remove " << index << endl;
        return;
    }

    if (index == 0) {
        Node<T> *newNode = new Node<T>(t, head);

        head = newNode;
    } else {
        Node<T> *newNode = new Node<T>(t, NULL);

        //上一个节点
        Node<T> *pre = node(index - 1);

        //上一个节点的下一个节点
        Node<T> *preNext = pre->next;

        //上一个节点的下一个节点为当前节点
        pre->next = newNode;

        //当前节点的下一个节点为上次上一个节点的下一个节点
        newNode->next = preNext;
    }

    len++;
}

template<class T>
void LinkList<T>::remove(int index) {
    if (index < 0 || index >= len) {
        cout << "err remove " << index << endl;
        return;
    }
    if (index == 0) {
        Node<T> *next = head->next;
        head = next;
        delete head;
    } else {
        //上一个节点
        Node<T> *pre = node(index - 1);

        Node<T> *current = pre->next;

        Node<T> *next = current->next;

        delete current;

        pre->next = next;
    }

    len--;
}


#endif //JNIENVCPP_LINKLIST_H
