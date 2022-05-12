class Solution {
public:
   string longestPalindrome(string s)
{	
	int len = s.length();
	if(len<2)
		return s;
	int start=0;
	int maxLen=1;
	int left,right;
	for(int i=0;i<len;i++)
	{	
		//if odd
		left=right=i;
			
		while(left>=0 && right<len && s[left]==s[right])
		{
			
			if(right-left+1 >maxLen){
				start=left;
				maxLen= right-left+1;
			}
			left--;
			right++;
				
		}
		left=i;right=i+1;
		while(left>=0 && right<len && s[left]==s[right])
		{
			
			if(right-left+1 >maxLen){
				start=left;
				maxLen= right-left+1;
			}
			left--;
			right++;
				
		}
	}

    
    return s.substr(start,maxLen);


	
}
};
