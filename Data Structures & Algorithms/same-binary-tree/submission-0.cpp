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
    bool func(TreeNode* p, TreeNode* q){
        if(!p && q!=nullptr)return false;
        if(!q && p!=nullptr)return false;
        if(!p && !q)return true;
        if(p->val != q->val)return false;

        bool f1 = func(p->left, q->left);
        bool f2 = func(p->right, q->right);
        return f1 && f2;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return func(p, q);
        
    }
};
