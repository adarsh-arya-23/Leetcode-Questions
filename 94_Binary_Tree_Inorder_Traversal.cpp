/*

Approach:
1. We can use a recursive approach to perform an inorder traversal of the binary tree.
2. We will define a helper function that takes the current node and a reference to a vector to store the traversal result.
3. In the helper function, we will first recursively call the left subtree, then add the current node's value to the vector, and finally recursively call the right subtree.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void helper(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        
        helper(root->left, v);    
        v.push_back(root->val);     
        helper(root->right, v);     
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    
    cout << "Inorder Traversal of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root->right->left;
    delete root->right;
    delete root;
    
    return 0;
}