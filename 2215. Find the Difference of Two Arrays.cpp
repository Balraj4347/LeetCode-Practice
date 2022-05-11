class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
 	vector<vector<int>> ans;
 			unordered_map<int,int> map1;
 			unordered_map<int,int> map2;
 			for(int i=0;i<nums1.size();i++)
 				map1.insert({nums1[i],i});
 			for(int i=0;i<nums2.size();i++)
 				map2.insert({nums2[i],i});
 			vector<int> rslt;
 	for(auto x:map1)
 		if(map2.find(x.first) == map2.end())
 			rslt.push_back(x.first);
 	ans.push_back(rslt);
 	rslt.clear();
 	for(auto x:map2)
 		if(map1.find(x.first) == map1.end())
 			rslt.push_back(x.first);
ans.push_back(rslt);
return ans;
        
    }
};
