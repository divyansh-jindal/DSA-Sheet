class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        
        q.push({beginWord,1});
        
        while(!q.empty()){
            string word = q.front().first;
            int num= q.front().second;
            q.pop();
            
            if(word==endWord) return num;
            
            for(int i=0;i<word.length();i++){
                char original = word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push({word,num+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
            
        }
        return 0;
    }
};