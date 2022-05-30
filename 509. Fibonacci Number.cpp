class Solution {
public:
    int m[31]={0};
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
         if(m[n])
            return m[n];
        m[n]= fib(n-1)+ fib(n-2);
        return m[n];
    }
};
///////-----------///////-----------///////-----------///////-----------
class Solution {
public:
    int fib(int n) {
	if(n <= 1)
		return n;
	int prev2 = 0, prev1 = 1, cur;
	for(int i = 2; i <= n; i++)
		cur = prev2 + prev1, prev2 = prev1, prev1 = cur;
	return cur;
}
};
