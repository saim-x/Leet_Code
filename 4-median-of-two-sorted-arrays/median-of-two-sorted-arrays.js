/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let merged = nums1.concat(nums2);
    merged.sort((a, b) => a - b);
    let n = merged.length;
    if(n%2==0){return (merged[((n/2))-1] + merged[((n+2)/2)-1])/2;}
    else{return merged[(n+1)/2-1];}
};
