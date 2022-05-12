class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows <= 1) return s;

        vector<string> zigzag(numRows, "");
        string ans;
        int len = s.length();
        int state=0,row=0;
        for(int i=0; i<len ; )
        {
        	if(state==0)
        	{
        		zigzag[row] += s[i];
        		row++;i++;
        		if(row==numRows){
        			state=1;
        			row=numRows-2;
        		}
        	}
        	else
        	{	if(row>=1)
        		{
        	        		zigzag[row] += s[i];
        	        		row--;i++;
        	        		if (row == 0) state = 0;
        	    }
        		else{
        			row=0;state=0;
        		}
        	}
        	


        }
        for(auto a:zigzag)
        	ans+=a;

    return ans;
}
};
