class Solution 
{
public:
    /**
     * 159. Find Minimum in Rotated Sorted Array
     * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
     * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
     *  Find the minimum element.
     * Example
     * Given [4, 5, 6, 7, 0, 1, 2] return 0
     */
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) 
    {
        // write your code here
        if (nums.size() == 0)
            return 0;
        
        int start = 0;
        int end = nums.size() - 1;
        
        int last = nums[end];
        
        while ( (start + 1) < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= last)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if ( nums[start] < nums[end] )
        {
            return nums[start];
        }
        else
        {
            return nums[end];
        }
    }
    
    
public:
    
    // 585. Maximum Number in Mountain Sequence
    // Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.

    // Example
    // Given nums = [1, 2, 4, 8, 6, 3] return 8
    // Given nums = [10, 9, 8, 7], return 10
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        if ( nums.size() == 0 )
        {
            return 0;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while ( start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if ( nums[mid] > nums[mid+1] )
            {
                end = mid;
            }
            else if ( nums[mid] < nums[mid+1] )
            {
                start = mid;
            }
        }
        
        if (nums[start] > nums[end])
        {
            return nums[start];
        }else
        {
            return nums[end];
        }
    
    }
    
    
    
};
