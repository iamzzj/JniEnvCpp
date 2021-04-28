#include <iostream>

using namespace std; //命名空间，java中的内部类

/**
 * 数据结构
 *
 * 集合结构
 * 线性结构
 * 树形结构
 * 图形结构
 *
 * 存储结构一般分为顺序存储和连式存储
 *
 * 程序 = 数据结构 + 算法
 *
 * 算法是指特定问题求解步骤的描述：
 * 算法特性：输入，输出，有穷性，确定性和可行性
 * 算法的优劣主要从算法的执行时间和所需占用的存储空间两个方便衡量
 * 也称之为时间复杂度和空间复杂度（O表示）
 *
 * 时间复杂度和空间复杂度
 * 概念：
 * 求复杂度：求时间复杂度和空间复杂度
 *
 */

/**
 * 时间复杂度：执行的步骤
 *
 * O(n)复杂度
 * @param n
 * @return
 */
int sum(int n) {
    int sum = 0;// 1步
    for (int i = 0; i <= n; i++) {// n步
        sum += i;
    }
    return sum;// 1步
}

/**
 * O1复杂度
 *
 * @param n
 * @return
 */
int sum2(int n) {
    return (1 + n) * n / 2;//1步
}

int main() {

    int s = sum(100);

    cout << s << endl;

    return 0;
}
