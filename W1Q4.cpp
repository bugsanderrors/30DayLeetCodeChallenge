/*
    Move Zeros
    
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Example:
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]

    Note:

        1.You must do this in-place without making a copy of the array.
        2.Minimize the total number of operations.
*/

void moveZeroes(vector<int>& nums) 
{
    int c = 0;
    int n = nums.size();
    for(int i=0; i<n; i++)
        if(nums[i] != 0)
            nums[c++] = nums[i];

    while(c < n)
        nums[c++] = 0;
}