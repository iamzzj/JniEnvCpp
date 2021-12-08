//
// Created by LLL on 2021/4/29.
//

#ifndef UNTITLED_AVL_HPP
#define UNTITLED_AVL_HPP

#include <iostream>

using namespace std;

template<class K, class V>
class AVLNode {
public:
    AVLNode<K, V> *left = NULL;
    AVLNode<K, V> *right = NULL;
    K k;
    V v;
    int height;
public:
    AVLNode(K k, V v) : height(1) {
        this->k = k;
        this->v = v;
    }

    AVLNode(AVLNode<K, V> *pNode) : height(pNode->height) {
        this->left = pNode->left;
        this->right = pNode->right;
        this->k = pNode->k;
        this->v = pNode->v;
    }
};

/**
 * 二分搜索树
 *
 */
template<class K, class V>
class AVLTree {
private:
    AVLNode<K, V> *root = NULL;
    int count = 0;
public:
    void insert(K k, V v) {
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
    void inorderTraversal(AVLNode<K, V> *node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->v << endl;
        inorderTraversal(node->right);
    }

    int getHeight(AVLNode<K, V> *pNode) {
        return pNode != NULL ? pNode->height : 0;
    }

    void updateHeight(AVLNode<K, V> *pNode) {
        pNode->height = max(getHeight(pNode->left), getHeight(pNode->right)) + 1;
    }

    /**
     * 右旋
     *
     *      3            2
     *     /            / \
     *    2            1   3
     *   /
     *  1
     * @param pNode  3
     * @return
     */
    AVLNode<K, V> *R_Rotation(AVLNode<K, V> *pNode) {
        AVLNode<K, V> *left = pNode->left;
        AVLNode<K, V> *leftRight = left->right;

        left->right = pNode;
        pNode->left = leftRight;

        //更新高度
        updateHeight(pNode);
        updateHeight(left);

        return left;
    }

    /**
     * 左旋
     *
     *      1             2
     *       \           / \
     *        2         1   3
     *         \
     *          3
     * @param pNode  1
     * @return
     */
    AVLNode<K, V> *L_Rotation(AVLNode<K, V> *pNode) {
        AVLNode<K, V> *right = pNode->right;
        AVLNode<K, V> *rightLeft = right->left;

        right->left = pNode;
        pNode->right = rightLeft;

        //更新高度
        updateHeight(pNode);
        updateHeight(right);

        return right;
    }

    /**
     * 先左旋再右旋
     *
     *      3           3        2
     *     /           /        / \
     *    1           2        1   3
     *     \         /
     *      2       1
     *
     * @param pNode
     * @return
     */
    AVLNode<K, V> *L_R_Rotation(AVLNode<K, V> *pNode) {
        pNode->left = L_Rotation(pNode->left);
        return R_Rotation(pNode);
    }

    /**
     * 先右旋再左旋
     *
     *      3           3            2
     *       \           \          / \
     *        2           2        1   3
     *       /             \
     *      1               1
     *
     * @param pNode
     * @return
     */
    AVLNode<K, V> *R_L_Rotation(AVLNode<K, V> *pNode) {
        pNode->right = R_Rotation(pNode->right);
        return L_Rotation(pNode);
    }

    /**
     * 递归增加节点
     * @param pNode
     * @param k
     * @param v
     * @return
     */
    AVLNode<K, V> *addNode(AVLNode<K, V> *pNode, K k, V v) {
        if (pNode == NULL) {
            count++;
            AVLNode<K, V> *newNode = new AVLNode<K, V>(k, v);
            return newNode;
        }

        if (pNode->k > k) {
            pNode->left = addNode(pNode->left, k, v);
            if (getHeight(pNode->left) - getHeight(pNode->right) == 2) {
                if (getHeight(pNode->left->right) > getHeight(pNode->left->left)) {
                    pNode = L_R_Rotation(pNode);
                } else {
                    pNode = R_Rotation(pNode);
                }
            }

        } else if (pNode->k < k) {
            pNode->right = addNode(pNode->right, k, v);

            if (getHeight(pNode->right) - getHeight(pNode->left) == 2) {
                if (getHeight(pNode->right->left) > getHeight(pNode->right->right)) {
                    pNode = R_L_Rotation(pNode);
                } else {
                    pNode = L_Rotation(pNode);
                }
            }
        } else {
            pNode->v = v;
        }

        //更新高度
        updateHeight(pNode);

        return pNode;
    }

    /**
     * 删除节点
     *
     * @param pNode
     * @param k
     * @return
     */
    AVLNode<K, V> *removeNode(AVLNode<K, V> *pNode, K k) {
        if (pNode == NULL) {
            return NULL;
        }

        if (pNode->k > k) {
            pNode->left = removeNode(pNode->left, k);

            if (getHeight(pNode->right) - getHeight(pNode->left) == 2) {
                if (getHeight(pNode->right->left) > getHeight(pNode->right->right)) {
                    pNode = R_L_Rotation(pNode);
                } else {
                    pNode = L_Rotation(pNode);
                }
            }
        } else if (pNode->k < k) {
            pNode->right = removeNode(pNode->right, k);

            if (getHeight(pNode->left) - getHeight(pNode->right) == 2) {
                if (getHeight(pNode->left->right) > getHeight(pNode->left->left)) {
                    pNode = L_R_Rotation(pNode);
                } else {
                    pNode = R_Rotation(pNode);
                }
            }
        } else {
            count--;
            if (pNode->left == NULL && pNode->right == NULL) {
                delete pNode;
                return NULL;
            } else if (pNode->left == NULL) {
                AVLNode<K, V> *childNode = pNode->right;
                delete pNode;
                return childNode;
            } else if (pNode->right == NULL) {
                AVLNode<K, V> *childNode = pNode->left;
                delete pNode;
                return childNode;
            } else {
                // 找到删除节点的，左节点最右边的节点，右节点最左边的节点，来代替它
                if (getHeight(pNode->left) > getHeight(pNode->right)) {
                    AVLNode<K, V> *leftMaxRightNode = leftMaxRight(pNode->left);
                    // 最右边的节点替换删除的节点
                    AVLNode<K, V> *newNode = new AVLNode<K, V>(leftMaxRightNode);
                    cout << "leftMaxRight: " << leftMaxRightNode->v << endl;

                    AVLNode<K, V> *lastLeft = pNode->left;
                    AVLNode<K, V> *lastRight = pNode->right;
                    delete pNode;

                    newNode->left = lastLeft;
                    newNode->right = lastRight;

                    // 删除最右边的节点，并将它的子节点丢给父节点
                    removeLeftMaxRightNode(newNode, leftMaxRightNode->k, true);
                    pNode = newNode;
                } else {
                    AVLNode<K, V> *rightMaxLeftNode = rightMaxLeft(pNode->right);
                    // 最右边的节点替换删除的节点
                    AVLNode<K, V> *newNode = new AVLNode<K, V>(rightMaxLeftNode);
                    cout << "leftMaxRight: " << rightMaxLeftNode->v << endl;

                    AVLNode<K, V> *lastLeft = pNode->left;
                    AVLNode<K, V> *lastRight = pNode->right;
                    delete pNode;

                    newNode->left = lastLeft;
                    newNode->right = lastRight;

                    // 删除最右边的节点，并将它的子节点丢给父节点
                    removeRightMaxLeftNode(newNode, rightMaxLeftNode->k, true);
                    pNode = newNode;
                }
            }
        }

        updateHeight(pNode);

        return pNode;
    }

    /**
     * 找到最右边的节点
     * 右节点为空
     * @return
     */
    AVLNode<K, V> *leftMaxRight(AVLNode<K, V> *pNode) {
        if (pNode->right == NULL) {
            return pNode;
        }

        return leftMaxRight(pNode->right);
    }

    /**
     * 找到最左边的节点
     * @param pNode
     * @return
     */
    AVLNode<K, V> *rightMaxLeft(AVLNode<K, V> *pNode) {
        if (pNode->left == NULL) {
            return pNode;
        }

        return rightMaxLeft(pNode->left);
    }

    /**
     * 替换后删除找到前驱节点
     *
     * @return
     */
    AVLNode<K, V> *removeLeftMaxRightNode(AVLNode<K, V> *node, K k, bool isFirst = false) {
        if (node == NULL) {
            return NULL;
        }
        if (node->k == k && !isFirst) {
            // 删除自己，并将自己的子节点给父节点
            AVLNode<K, V> *left = node->left;
            delete node;
            return left;
        }

        node->left = removeLeftMaxRightNode(node->left, k);
        node->right = removeLeftMaxRightNode(node->right, k);

        return node;
    }

    /**
     * 替换后删除找到后继节点
     *
     * @return
     */
    AVLNode<K, V> *removeRightMaxLeftNode(AVLNode<K, V> *node, K k, bool isFirst = false) {
        if (node == NULL) {
            return NULL;
        }
        if (node->k == k && !isFirst) {
            // 删除自己，并将自己的子节点给父节点
            AVLNode<K, V> *right = node->right;
            delete node;
            return right;
        }

        node->left = removeRightMaxLeftNode(node->left, k);
        node->right = removeRightMaxLeftNode(node->right, k);

        return node;
    }

    /**
     * 获取某一个节点
     * @param node
     * @param k
     * @return
     */
    V *getNode(AVLNode<K, V> *node, K k) {
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

#endif //UNTITLED_AVL_HPP
