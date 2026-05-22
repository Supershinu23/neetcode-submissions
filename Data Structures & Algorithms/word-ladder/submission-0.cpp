class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            pair<string, int> p = q.front();
            q.pop();
            if(p.first==endWord)return p.second;

            for(int i=0;i<p.first.size();i++){
                char temp = p.first[i];
                for(char j='a';j<='z';j++){
                    p.first[i] = j ;
                    if(s.find(p.first) != s.end()){
                        s.erase(p.first);
                        q.push({p.first, p.second+1});
                    }
                }
                p.first[i] = temp;
            }
        }
        return 0;
    }
};
