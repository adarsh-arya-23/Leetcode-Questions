/*

Approach:
1. We can use a recursive approach to find the maximum depth of the binary tree.
2. If the current node is null, we return 0, indicating that we have reached the end of a path.
3. We will recursively calculate the maximum depth of the left and right subtrees.
4. The maximum depth of the current node will be 1 (for the current node) plus the maximum of the left and right subtree depths.
Time Complexity: O(n), where n is the number of nodes in the tree. We need to visit each node once.
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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+max(lh,rh);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.maxDepth(root);
    cout << "Maximum Depth of the Binary Tree: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}