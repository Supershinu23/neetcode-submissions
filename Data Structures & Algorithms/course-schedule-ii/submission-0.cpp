class Solution {
public:
bool func(vector<vector<int>> adj, vector<int> &vis, int curr,stack<int> &s){
        if(vis[curr]==1)return false;
        if(vis[curr]==2)return true;

        vis[curr] = 1 ;
        bool flag = true;
        for(int i=0;i<adj[curr].size();i++){
            flag = flag && func(adj, vis, adj[curr][i],s);
        }
        if(flag)vis[curr]=2;
        s.push(curr);
        return flag ;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        stack<int> s ;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> ans ;

        for(int i = 0; i<numCourses;i++){
            if(vis[i]==0 && !func(adj, vis, i, s))return ans;
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            ans.push_back(t);
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
