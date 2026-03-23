/*

Approach:
1. We can use a recursive approach to compare the two trees.
2. We will check if both nodes are null, if so, they are the same.
3. If one of the nodes is null and the other is not, they are not the same.
4. If the values of the nodes are different, they are not the same.
5. If the values are the same, we will recursively check the left and right subtrees.
Time Complexity: O(n), where n is the number of nodes in the trees. We need to visit each node once.
Space Complexity: O(h), where h is the height of the tree. In the worst case, the height of the tree can be n (skewed tree), so the space complexity can be O(n) in the worst case. In the best case (balanced tree), the height is log(n), so the space complexity is O(log(n)).

*/

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(p, q);
    cout << (result ? "true" : "false") << endl;

    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}