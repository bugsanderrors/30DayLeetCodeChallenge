/* 
    Search in Rotated Sorted Array

    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    You are given a target value to search. If found in the array return its index, otherwise return -1.

    You may assume no duplicate exists in the array.

    Your algorithm's runtime complexity must be in the order of O(log n).

    Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
*/

class Solution {
public:
    int findPivot(vector<int>& nums, int start, int end)
    {
        int n = nums.size();
        if(n==0 || nums.empty())
            return -1;
        if (n==1 || nums[0] <= nums[n-1])
            return 0;
        while(start<=end)
        {
            int mid = (start+end)/2;
            //Check if mid+1 is pivot or not.
            if(nums[mid] > nums[mid+1])
                return mid+1;
            else if(nums[start] <= nums[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return 0;
    }
    int binarysearch(vector<int>& nums, int start, int end, int target)
    {
        if(start<=end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                return binarysearch(nums, start, mid-1, target);
            return binarysearch(nums, mid+1, end, target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0 || nums.empty())
            return -1;
        
        int pivot = findPivot(nums, 0, nums.size()-1);
        
        if(pivot>0 && nums[0]<=target && target<=nums[pivot-1])
            return binarysearch(nums, 0, pivot-1, target);
        
        return binarysearch(nums, pivot, nums.size()-1, target);
    }
};