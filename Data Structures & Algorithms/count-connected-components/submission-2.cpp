class Solution {
public:
    void func(vector<int> &vis, vector<vector<int>> &edges, int curr){
        if(vis[curr]==1)return;

        vis[curr] = 1 ;
        for(int i =0;i<edges[curr].size();i++){
            func(vis, edges, edges[curr][i]);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0 ;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                queue<int>q ;
                q.push(i);
                vis[i] = 1;
                ans++;
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    for(int i=0;i<adj[top].size();i++){
                        if(vis[adj[top][i]]==0){
                            q.push(adj[top][i]);
                            vis[adj[top][i]] = 1 ;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
