class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> vec = m[key];
        int n = vec.size();
        if(n==0)return "";
        int l = 0 ;
        int r = n-1;
        int mini = 0 ;
        while(r>=l){
            int mid= (r+l)/2;
            if(vec[mid].second==timestamp)return vec[mid].first;
            if(vec[mid].second<timestamp){
                mini = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        if(vec[mini].second <= timestamp)return vec[mini].first;
        return "";
    }
};
