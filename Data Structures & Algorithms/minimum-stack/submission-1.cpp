class MinStack {
public:
    vector<int> vec;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ;
    int curr_min;
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
        pq.push({val,vec.size()-1});
    }
    
    void pop() {
        while(!pq.empty() && vec.size()-1<=pq.top().second){
            pq.pop();
        }
        vec.pop_back();
    }
    
    int top() {
        return vec[vec.size()-1];
    }
    
    int getMin() {
       return pq.top().first;
    }
};
