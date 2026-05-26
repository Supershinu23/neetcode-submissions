class Solution {
public:
    bool func(int curr, int currPetrol, vector<int> &gas, vector<int> &cost, vector<int>&vis){
        if(currPetrol<0)return false;
        if(vis[curr%gas.size()])return true;
        vis[curr%gas.size()] = 1;
        return func(curr+1, currPetrol+gas[curr%gas.size()]-cost[curr%gas.size()], gas, cost, vis);
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<n;i++){
            vector<int> vis(n, 0);
            if(func(i, 0, gas, cost, vis))return i;
        }
        return -1;
    }
};
