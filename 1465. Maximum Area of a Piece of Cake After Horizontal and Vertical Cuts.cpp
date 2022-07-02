class Solution {
   
public:
     const long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        
        sort(hori.begin(),hori.end());
        sort(verti.begin(),verti.end());
        int sh= hori.size();
        vector<int> horiDiff;
        horiDiff.push_back(hori[0]);
        for(int i=1;i<sh;i++)
        {
            horiDiff.push_back(hori[i]-hori[i-1]);
        }
        horiDiff.push_back(h- hori[sh-1]);
        
        int sv= verti.size();
        vector<int> vertiDiff;
        vertiDiff.push_back(verti[0]);
        for(int i=1;i<sv;i++)
        {
            vertiDiff.push_back(verti[i]-verti[i-1]);
        }
        vertiDiff.push_back(w- verti[sv-1]);
        
         long long int a = *max_element(horiDiff.begin(), horiDiff.end());
        long long int b = *max_element(vertiDiff.begin(), vertiDiff.end());
        
        return (int)( a%mod * b%mod );
        
    }
};
