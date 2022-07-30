//solution using vector for each word count and vector to pre process the wordB array;
// M:len of word2 array , N: len of Word1 array 
//T.C: O(M*word2[i].len) + O(N*word1[i].len)
class Solution {
public:

    bool checkUniversal(string& s, vector<int>& count){
        vector<int> preProc(26,0);
        for(char ch:s){
            preProc[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(count[i]){
                if(count[i]> preProc[i]) 
                    // checking if freq in word1 str is greater than Min freq required
                    //if not we return false;
                    return false;
            }
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> bCount(26,0);
        for(string& s:words2){
            vector<int> M(26,0);
            for(char ch: s){
                M[ch-'a']++;
                bCount[ch-'a']= max(bCount[ch-'a'],M[ch-'a']);
            }
        }
        
        vector<string> ans;
        for(string& s:words1){
            if(checkUniversal(s,bCount))
                   ans.push_back(s);
            
        }
        
        return ans;
    }
};
