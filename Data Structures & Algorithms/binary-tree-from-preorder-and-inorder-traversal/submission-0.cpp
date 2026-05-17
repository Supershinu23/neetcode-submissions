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
    int findInd(vector<int> &vec, int k, int l, int r){
        for(int i=l;i<r;i++){
            if(k==vec[i])return i;
        }
        return 0;
    }

    TreeNode* helper(vector<int> & inorder, stack<int> &st, int l, int r){
        if(l==r)return nullptr;
        int val = st.top();
        st.pop();
        int ind = findInd(inorder, val, l, r);
        TreeNode* root = new TreeNode(val);
        root->left = helper(inorder, st, l, ind);
        root->right = helper(inorder, st, ind+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<int> s ;
        for(int i=preorder.size()-1;i>=0;i--){
            s.push(preorder[i]);
        }
        return helper(inorder, s, 0, inorder.size());
    }
};
