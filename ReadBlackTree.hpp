//
// Created by z on 2021/5/27.
//

#ifndef JNIENVCPP_READBLACKTREE_H
#define JNIENVCPP_READBLACKTREE_H

typedef bool rb_color;
// 红色
#define red true
// 黑色
#define black false

template<class K, class V>
class map {
private:
    struct TreeNode;
    int count;
    TreeNode *root;

public:
    map() : root(root) {
        count = 0;
    }

public:
    struct iterator;

    iterator insert(K key, V value) {

    }

    bool remove(K key) {

    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};

template<class K, class V>
struct map<K, V>::TreeNode {
private:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    K key;
    V value;
    rb_color color;
public:
    TreeNode(TreeNode *left,
             TreeNode *right,
             TreeNode *parent,
             K key,
             V value,
             rb_color color) :
            left(left),
            right(right),
            key(key),
            value(value),
            color(color) {
    }

    TreeNode *precursor() {
        if (left) {
            TreeNode *precursor = left;

            while (precursor->right) {
                precursor = precursor->right;
            }

            return precursor;
        } else {
            TreeNode *precursor = this;
            while (precursor->parent->right == precursor) {
                precursor = precursor->parent;
            }

            return precursor->parent;
        }
    }

    TreeNode *successor() {
        if (right) {
            TreeNode *successor = right;

            while (successor->left) {
                successor = successor->left;
            }

            return successor;
        } else {
            TreeNode *successor = this;
            while (successor->parent->left == successor) {
                successor = successor->parent;
            }

            return successor->parent;
        }


        return node;
    }
};

template<class K, class V>
struct map<K, V>::iterator {
private:
    TreeNode *node;
public:
    iterator(TreeNode *node) : node(node) {

    }

    /**
     * 前驱
     * @return
     */
    iterator &operator--() {
        node = node->precursor();
        return this;
    }

    /**
     * 后继
     * @return
     */
    iterator &operator++() {
        node = node->successor();
        return this;
    }

    V operator*() {
        return node->value;
    }
};

#endif //JNIENVCPP_READBLACKTREE_H
