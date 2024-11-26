class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans(m+n);
        ans = nums1;
        for(int i=0; i<n; ++i){
            ans[i+m]=(nums2.at(i));
        }
        sort(ans.begin(), ans.end());
        nums1= ans;
    }
};