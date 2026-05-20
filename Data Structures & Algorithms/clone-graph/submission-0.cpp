/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        unordered_map<int, Node*> mpp;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* top = q.front();
            cout<<top->val<<" --";
            q.pop();
            if(mpp.find(top->val)==mpp.end())mpp[top->val] = new Node(top->val);
            vector<Node*> temp;
            for(int i=0;i<top->neighbors.size();i++){
                if(mpp.find(top->neighbors[i]->val)!=mpp.end()){
                cout<<top->neighbors[i]->val<<" ";
                    temp.push_back(mpp[top->neighbors[i]->val]);
                }else{
                    Node* n = new Node(top->neighbors[i]->val);
                    mpp[top->neighbors[i]->val] = n ;
                    temp.push_back(n);
                    q.push(top->neighbors[i]);
                }
            }
            mpp[top->val]->neighbors = temp;
        }
        return mpp[node->val];
    }
};
