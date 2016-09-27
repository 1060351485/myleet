double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	int total = m + n;
	if (total & 0x1)
	  return findKth(nums1, m, nums2, n, total/2+1, 0, 0);
	else
	  return (findKth(nums1, m, nums2, n, total/2, 0, 0) + findKth(nums1, m, nums2, n, total/2+1, 0, 0))/2.0;

}

// start1, start2 starts from 0
// m, n, k starts form 1
double findKth(vector<int>& nums1, int m, vector<int> & nums2, int n, int k, int start1, int start2){
	if (m < n) 
	  return findKth(nums2, n, nums1, m, k, start2, start1);
	if (m == 0) return nums2[start2+k-1];
	else if (n == 0) return nums1[start1+k-1];
	if (k == 1) return min(nums1[start1], nums2[start2]);

	int i2 = min(n, k/2), i1 = k-i2;

	if (nums1[start1+i1-1] < nums2[start2+i2-1]){
		return findKth(nums1, m-i1, nums2, n, k-i1, start1+i1, start2);

	}else if (nums1[start1+i1-1] > nums2[start2+i2-1])
	  return findKth(nums1, m, nums2, n-i2, k-i2, start1, start2+i2);
	else
	  return nums1[start1+i1-1];

}
