/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
/**
    66. Binary Tree Preorder Traversal
    Given a binary tree, return the preorder traversal of its nodes' values.

    Example
    Given:

        1
       / \
      2   3
     / \
    4   5
    return [1,2,4,5,3].

    Challenge
    Can you do it without recursion?
 */
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    // step 1: define the function of recursion: put the preorder of root into result
    // result has to be reference
    vector<int> traverse( TreeNode * root, vector<int>& result)
    {
        // step 3: exit recursion
        if (root == nullptr) return result;
        
        // step 2: seperate recursion
        result.push_back(root->val);
        traverse(root->left, result);
        traverse(root->right, result);
        return result;
    }
    
    
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> result;
        traverse(root, result);
        return result;
    }
};
