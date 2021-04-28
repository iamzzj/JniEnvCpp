#include <iostream>

using namespace std; //命名空间，java中的内部类

template<class T>
class TreeNode {
public:
    T data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
public:
    TreeNode(T data) {
        this->data = data;
    }
};

/**
 * 前序
 * @tparam T
 * @param pNode
 */
template<class T>
void preOrderTraverse(TreeNode<T> *pNode) {
    cout << pNode->data;

    if (pNode->left) {
        preOrderTraverse(pNode->left);
    }

    if (pNode->right) {
        preOrderTraverse(pNode->right);
    }
}

/**
 * 树的深度
 * @tparam T
 * @param pNode
 * @return
 */
template<class T>
int deepTree(TreeNode<T> *pNode) {
    if (!pNode) {
        return 0;
    }
    int left = deepTree(pNode->left);
    int right = deepTree(pNode->right);

    return max(left, right) + 1;
}

/**
 *
 * 是否是平衡二叉树
 *
 * 可以是一颗空树，
 * 左右子树的高度差不会超过1
 * 并且左右两颗子树都是一颗平衡二叉树
 *
 * @tparam T
 * @param pNode
 * @return
 */
template<class T>
bool isBalanceTree(TreeNode<T> *pNode) {
    if (!pNode) {
        return true;
    }
    int left = deepTree(pNode->left);
    int right = deepTree(pNode->right);

    if (abs(left - right) > 1) {
        return false;
    } else {
        return isBalanceTree(pNode->left) &&
               isBalanceTree(pNode->right);
    }
}

/**
 * 前序
 * @tparam T
 * @param pNode
 */
template<class T>
void middleOrderTraverse(TreeNode<T> *pNode) {
    if (pNode->left) {
        middleOrderTraverse(pNode->left);
    }

    cout << pNode->data;

    if (pNode->right) {
        middleOrderTraverse(pNode->right);
    }
}

template<class T>
void levelOrderTraverse(TreeNode<T> *pNode) {

    if (pNode->left) {
        cout << pNode->left->data;
    }
    if (pNode->right) {
        cout << pNode->right->data;
    }

    if (pNode->left) {
        levelOrderTraverse(pNode->left);
    }
    if (pNode->right) {
        levelOrderTraverse(pNode->right);
    }
}

/**
 * 后序
 * @tparam T
 * @param pNode
 */
template<class T>
void endOrderTraverse(TreeNode<T> *pNode) {
    if (pNode->left) {
        endOrderTraverse(pNode->left);
    }

    if (pNode->right) {
        endOrderTraverse(pNode->right);
    }

    cout << pNode->data;
}

/**
 * 反序列化
 * @param pString
 * @return
 */
TreeNode<char> *deserializeTree(char **pString) {
    if (**pString == '#') {
        *pString += 1;
        return NULL;
    }

    TreeNode<char> *node = new TreeNode<char>(**pString);
    *pString += 1;
    node->left = deserializeTree(pString);
    node->right = deserializeTree(pString);
    return node;
}

/**
 * 序列化
 * @param pNode
 * @param pString
 */
void serializeTree(TreeNode<char> *pNode, string *pString) {
    if (!pNode) {
        pString->append("#");
        return;
    }

    pString->append(string(1, pNode->data));
    serializeTree(pNode->left, pString);
    serializeTree(pNode->right, pString);
}

int main() {

    /**
     *              A
     *             / \
     *            B   C
     *          / \    \
     *         D   E    F
     *
     * 前序：首先访问根节点，然后访问左节点，最后访问右节点
     *      ABDECF
     * 中序：首先访问左节点，然后访问根节点，最后访问右节点
     *      DBEACF
     * 后序：首先访问左节点，然后访问右节点，最后访问根节点
     *      DEBFCA
     */
    TreeNode<char> *A = new TreeNode<char>('A');
    TreeNode<char> *B = new TreeNode<char>('B');
    TreeNode<char> *C = new TreeNode<char>('C');
    TreeNode<char> *D = new TreeNode<char>('D');
    TreeNode<char> *E = new TreeNode<char>('E');
    TreeNode<char> *F = new TreeNode<char>('F');
    TreeNode<char> *G = new TreeNode<char>('G');

    A->left = B;
    A->right = C;

    B->left = D;
    B->right = E;

    C->right = F;
    F->right = G;

    cout << "前序" << endl;
    preOrderTraverse(A);
    cout << endl;

    cout << "中序" << endl;
    middleOrderTraverse(A);
    cout << endl;

    cout << "后序" << endl;
    endOrderTraverse(A);
    cout << endl;

    cout << "层序" << endl;
    cout << A->data;
    levelOrderTraverse(A);
    cout << endl;

    cout << "深度" << deepTree(A) << endl;
    cout << "是否是平衡二叉树" << isBalanceTree(A) << endl;

    char *nodeStr = "ABD##E##C#F#G##";
    auto node = deserializeTree(&nodeStr);

    string str;
    serializeTree(node, &str);
    cout << "序列化 " << str << endl;

    return 0;
}

