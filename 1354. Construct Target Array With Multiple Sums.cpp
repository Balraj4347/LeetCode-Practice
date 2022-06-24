class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        long long sum = accumulate(target.begin(),target.end(), (long long)0);
        priority_queue<int> pq(target.begin(),target.end());
        
        while(pq.top() != 1){
            
            int x= pq.top();
            pq.pop();
            sum=  sum- x;
            if( sum<=0 || sum>x )
                return false;
            
            //repeated subtraction causes TLE
            x = x%sum;
            sum += x;
            pq.push(x>0? x: sum);
            
            
        }
        
        
        return true;
    }
};
