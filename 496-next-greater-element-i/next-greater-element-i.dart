class Solution {
  List<int> nextGreaterElement(List<int> nums1, List<int> nums2) {
    List<int> ans = [];
    for (int i = 0; i < nums1.length; ++i) {
      for (int j = 0; j < nums2.length - 1; ++j) {
        if (nums1[i] == nums2[j]) {
          bool flag = false;
          for (int k = j + 1; k < nums2.length; k++) {
            if (nums1[i] < nums2[k]) {
              ans.add(nums2[k]);
              flag = true;
              break;
            }
          }
          if (!flag) {
            ans.add(-1);
          }
        }
      }
      if (nums1[i] == nums2[nums2.length - 1]) {
        ans.add(-1);
      }
    }
    return ans;
  }
}
