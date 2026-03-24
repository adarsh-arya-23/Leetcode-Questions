/*

Approach:
1. We can use a recursive approach to perform a preorder traversal of the binary tree.
2. In a preorder traversal, we visit the current node first, then recursively visit the left subtree, and finally recursively visit the right subtree.
3. We will maintain a vector to store the values of the nodes in the order they are visited.
Time Complexity: O(n), where n is the number of nodes in the tree. We need to visit each node once.
Space Complexity: O(h), where h is the height of the tree. In the worst case, the height of the tree can be n (skewed tree), so the space complexity can be O(n) in the worst case. In the best case (balanced tree), the height is log(n), so the space complexity is O(log(n)).

*/

#include <iostream>
#include <vector>
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
    void PreOrder(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        PreOrder(root->left, v);
        PreOrder(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        PreOrder(root, v);
        return v;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.preorderTraversal(root);
    cout << "Preorder Traversal of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}