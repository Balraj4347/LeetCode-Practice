class Solution {
public:
 int myAtoi(string s) {
        int i=0,sign=1;
        long solution=0;
        int size=s.length();
        while(s[i]==' '&&i<size){
            i++;
        }
        if(s[i]=='+'&&i<size){
            i++;
            sign=1;
        }
        else if(s[i]=='-'&&i<size){
            i++;
            sign=-1;
        }
        while(s[i]>='0'&&s[i]<='9'&&i<size){
            solution=solution*10+(s[i]-'0');
            if(solution>INT_MAX){
                if(sign==1){
                    return INT_MAX;
                }
                return INT_MIN;
            }
            i++;
        }
        return solution*sign;  
        
    }
};
