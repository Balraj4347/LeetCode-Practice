class Solution {
public:
    vector<string> ans;
    void rec(int n, int open, int close, string &s, int len)
    {
        if(len == 2*n)
        {
            ans.push_back(s);
            return;
        }    
        if(open == close)
        {
            s.push_back('(');
            rec(n, open+1, close, s, len+1);
            s.pop_back();
        }
        else if(open == n)
        {
            s.push_back(')');
            rec(n, open, close+1, s, len+1);
            s.pop_back();
        }
        else
        {
            s.push_back('(');
            rec(n, open+1, close, s, len+1);
            s.pop_back();
            s.push_back(')');
            rec(n, open, close+1, s, len+1);
            s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        rec(n, 0, 0, s, 0);
        return ans;
    }
};
