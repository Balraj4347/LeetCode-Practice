// counting sort method T.C : O(n),S.C :O(1) "technically" else O(max possible)
class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int freq[1001]{0};
        for(auto a:boxTypes)
            freq[a[1]] += a[0];
       int result=0;
        for(int i=1000; truckSize>0 && i>0; --i){
            result += min(truckSize, freq[i])* i;
            truckSize -= freq[i];
       }
        
        return result;
    }
};
//greedy. //sorting -> O(n logn) , space complexity : O(1) but sorting also use some space
class Solution {
public:
    static bool cmp (vector<int> a, vector<int> b ){
        
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int result =0;
        for(auto item : boxTypes){
            int x = min(item[0],truckSize);
            result = result + x*item[1];
            truckSize = truckSize - x;
            if(!truckSize) break;
        }  
        
        return result;
    }
};
