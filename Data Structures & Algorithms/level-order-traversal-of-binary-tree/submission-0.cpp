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
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int, vector<int>> mpp;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans ;
        if(!root)return ans;
        q.push({root,0});

        while(!q.empty()){
            pair<TreeNode*, int> p= q.front();
            q.pop();
            mpp[p.second].push_back(p.first->val);

            if(p.first->left != nullptr)q.push({p.first->left, p.second+1});
            if(p.first->right != nullptr)q.push({p.first->right, p.second+1});
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
