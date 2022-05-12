class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int i=0,j=0,k=0;
        int x=0, y=0;
        while(i<=((n+m)/2))
        {
            if(k>=m || (j<n && nums1[j]<nums2[k]))
            {
                y=x;
                x=nums1[j++];
            }
            else
            {
                y=x;
                x=nums2[k++];
            }
            i++;
        }
        if((n+m)%2==0)
            return (double)(x+y)/2;
        return (double)x;
    }
};
