class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]}) ;
        }
        
        queue<pair<int, int>> q;
        q.push({k, 0});

        vector<int> vis(n+1, INT_MAX);
        vis[k] = 0 ;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            vector<pair<int, int>> temp = adj[p.first];
            for(int i=0;i<temp.size();i++){
                if(vis[temp[i].first] > p.second+temp[i].second){
                    vis[temp[i].first] = p.second+temp[i].second;
                    q.push({temp[i].first, p.second+temp[i].second});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<vis.size();i++){
            if(vis[i]==INT_MAX)return -1;
            ans = max(ans, vis[i]);
        }
        return ans;

    }
};
