/* ------------------------------------------------------------------|
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

 

示例 1：


输入：n = 4
输出：2
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：1
 

提示：

1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	dfs法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：5.8 MB, 在所有 C++ 提交中击败了91.68%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int res = 0;
vector<bool> col;
vector<bool> dia1;
vector<bool> dia2;

void dfs(int row, const int &n) {
    if (row == n) {
        res++;
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
        if (col[i]) {
            continue;
        }
        int dia1val = n - 1 + i - row;
        if (dia1[dia1val]) {
            continue;
        }
        int dia2val = i + row;
        if (dia2[dia2val]) {
            continue;
        }

        col[i] = 1;
        dia1[dia1val] = 1;
        dia2[dia2val] = 1;
        dfs(row + 1, n);
        
        col[i] = 0;
        dia1[dia1val] = 0;
        dia2[dia2val] = 0;
        }
    }
}

int totalNQueens(int n) {
    col.resize(n);
    dia1.resize(2 * n - 1);
    dia2.resize(2 * n - 1);
    int leftsum = 0;
    //第0行第i列填起
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (i == n / 2 - 1) {
            leftsum = res;
        }        
        int dia1val = n - 1 + i;
        int dia2val = i;

        col[i] = 1;
        dia1[dia1val] = 1;
        dia2[dia2val] = 1;

        dfs(1, n);

        col[i] = 0;
        dia1[dia1val] = 0;
        dia2[dia2val] = 0;
    }
    return n % 2 ? leftsum + res : res * 2;
}

int main() {
    totalNQueens(7);
}