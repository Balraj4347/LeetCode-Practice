//Sliding Window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen =0;
        int i=0;
        int j=0;
        unordered_map<char,int> dict;
        while(j<s.length())
        {
              dict[s[j]]++;
            while(dict[s[j]] != 1){
                dict[s[i]]--;
                i++;
            }
            
            maxlen= max(maxlen, j-i+1);
            j++;
        }
        
        return maxlen;
    }
};
