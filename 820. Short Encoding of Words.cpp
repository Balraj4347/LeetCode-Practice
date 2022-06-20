// map and sorting based 

class Solution {
public:
     static bool myCmp(string &word1, string &word2){
        return word1.size() > word2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int answer = 0;
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), myCmp);
        
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        
        for(int i = 0; i < words.size(); i++){
            int len = words[i].size();
            if(mp[words[i]] > 0){
                answer = answer + (len + 1); 
            }
            
            for(int j = len - 1; j >= 0; j-- ){
                string sub = words[i].substr(j, len-j);
                mp[sub] = 0;
            }
        }
        
        return answer;
        
    }
};
