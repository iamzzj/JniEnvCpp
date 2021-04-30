#ifndef JNIENVCPP_BINARYSEARCHTREE_HPP
#define JNIENVCPP_BINARYSEARCHTREE_HPP

#include <iostream>

using namespace std;

template<class K, class V>
class BinarySearchNode {
public:
    BinarySearchNode<K, V> *left = NULL;
    BinarySearchNode<K, V> *right = NULL;
    K k;
    V v;
public:
    BinarySearchNode(K k, V v) {
        this->k = k;
        this->v = v;
    }

};

/**
 * 二分搜索树
 *
 */
template<class K, class V>
class BinarySearchTree {
private:
    BinarySearchNode<K, V> *root = NULL;
    int count = 0;
public:
    void put(K k, V v) {
        root = addNode(root, k, v);
    }

    void remove(K k) {
        root = removeNode(root, k);
    }

    V *get(K k) {
        return getNode(root, k);
    }

    int getCount() {
        return count;
    }

    /**
     * 中序遍历
     */
    void inorderTraversal() {
        cout << "inorderTraversal " << endl;
        inorderTraversal(root);
        cout << endl;
    }

private:
    /**
    * 中序遍历
    */
    void inorderTraversal(BinarySearchNode<K, V> *node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->v << endl;
        inorderTraversal(node->right);
    }

    /**
     * 递归增加节点
     * @param node
     * @param k
     * @param v
     * @return
     */
    BinarySearchNode<K, V> *addNode(BinarySearchNode<K, V> *node, K k, V v) {
        if (node == NULL) {
            count++;
            BinarySearchNode<K, V> *newNode = new BinarySearchNode<K, V>(k, v);
            return newNode;
        }

        if (node->k > k) {
            node->left = addNode(node->left, k, v);
        } else if (node->k < k) {
            node->right = addNode(node->right, k, v);
        } else {
            node->v = v;
        }

        return node;
    }

    /**
     * 删除节点
     *
     * @param node
     * @param k
     * @return
     */
    BinarySearchNode<K, V> *removeNode(BinarySearchNode<K, V> *node, K k) {
        if (node == NULL) {
            return NULL;
        }

        if (node->k > k) {
            node->left = removeNode(node->left, k);
        } else if (node->k < k) {
            node->right = removeNode(node->right, k);
        } else {
            count--;
            if (node->left == NULL && node->right == NULL) {
                return NULL;
            } else if (node->left == NULL) {
                BinarySearchNode<K, V> *childNode = node->right;
                delete node;
                return childNode;
            } else if (node->right == NULL) {
                BinarySearchNode<K, V> *childNode = node->left;
                delete node;
                return childNode;
            } else {
                // 找到删除节点的，左节点最右边的节点，右节点最左边的节点，来代替它
                BinarySearchNode<K, V> *leftMaxRightNode = leftMaxRight(node->left);
                // 最右边的节点替换删除的节点
                BinarySearchNode<K, V> *newNode = new BinarySearchNode<K, V>(
                        leftMaxRightNode->k, leftMaxRightNode->v);
                cout << "leftMaxRight: " << leftMaxRightNode->v << endl;

                BinarySearchNode<K, V> *lastLeft = node->left;
                BinarySearchNode<K, V> *lastRight = node->right;
                delete node;

                newNode->left = lastLeft;
                newNode->right = lastRight;

                // 删除最右边的节点，并将它的子节点丢给父节点
                removeLeftMaxRightNode(newNode, leftMaxRightNode->k, true);

                return newNode;
            }
        }

        return node;
    }

    /**
     * 找到最右边的节点
     * 右节点为空
     * @return
     */
    BinarySearchNode<K, V> *leftMaxRight(BinarySearchNode<K, V> *node) {
        if (node->right == NULL) {
            return node;
        }

        return leftMaxRight(node->right);
    }

    /**
     * 替换后删除找到前驱节点
     *
     * @return
     */
    BinarySearchNode<K, V> *removeLeftMaxRightNode(BinarySearchNode<K, V> *node, K k, bool isFirst = false) {
        if (node == NULL) {
            return NULL;
        }
        if (node->k == k && !isFirst) {
            // 删除自己，并将自己的子节点给父节点
            BinarySearchNode<K, V> *left = node->left;
            delete node;
            return left;
        }

        node->left = removeLeftMaxRightNode(node->left, k);
        node->right = removeLeftMaxRightNode(node->right, k);

        return node;
    }

    /**
     * 获取某一个节点
     * @param node
     * @param k
     * @return
     */
    V *getNode(BinarySearchNode<K, V> *node, K k) {
        if (node == NULL) {
            return NULL;
        }

        if (node->k > k) {
            return getNode(node->left, k);
        } else if (node->k < k) {
            return getNode(node->right, k);
        } else {
            return &(node->v);
        }
    }
};

#endif //JNIENVCPP_BINARYSEARCHTREE_HPP
