class Solution {
public:
    bool isPalindrome(int x) {
        
        int _x=0;
       if(x<0|| (x!=0 &&x%10==0)) return false;
        
        while(x >_x)
        {	
            _x = _x*10 + x % 10;
            x  = x / 10;
        }
            
        
       return x==_x || x== _x/10;
    }
};
