class Solution {
public:
    bool func(vector<vector<int>> adj, vector<int> &vis, int curr){
        if(vis[curr]==1)return false;
        if(vis[curr]==2)return true;

        vis[curr] = 1 ;
        bool flag = true;
        for(int i=0;i<adj[curr].size();i++){
            flag = flag && func(adj, vis, adj[curr][i]);
        }
        if(flag)vis[curr]=2;
        return flag ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i<numCourses;i++){
            if(vis[i]==0 && !func(adj, vis, i))return false;
        }
        return true;
    }
};
