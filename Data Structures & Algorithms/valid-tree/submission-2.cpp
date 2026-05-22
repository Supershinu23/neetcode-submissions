class Solution {
public:
    bool func(vector<vector<int>> & adj, int curr, vector<int> &vis, int par){
        if(vis[curr]==1)return false;
        if(vis[curr]==2)return true;

        vis[curr] = 1;
        bool flag = true;
        for(int i=0;i<adj[curr].size();i++){
            if(par== -1 || par!=adj[curr][i])flag = flag && func(adj, adj[curr][i], vis, curr);
        }
        if(flag)vis[curr]=2;
        return flag;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0)count++;
            if(vis[i]==0 && !func(adj, i, vis,-1))return false;
        }
        if(count>1)return false;
        return true;
    }
};
