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
    
 
public:
    // 75. Find Peak Element
    // There is an integer array which has the following features:

    // The numbers in adjacent positions are different.
    // A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
    // We define a position P is a peak if:

    // A[P] > A[P-1] && A[P] > A[P+1]
    // Find a peak element in this array. Return the index of the peak.

    // Example
    // Given [1, 2, 1, 3, 4, 5, 7, 6]

    // Return index 1 (which is number 2) or 6 (which is number 7)

    // Challenge
    // Time complexity O(logN)
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        if ( A.size() == 0 )
        {
            return 0;
        }
        
        int start = 1;
        int end = A.size() - 1;
        
        while ( start + 1 < end )
        {
            int mid = start + (end - start) / 2;
            if ( A[mid] > A[mid-1] && A[mid] > A[mid+1] )
            {
                return mid;
            }
            else if (A[mid] > A[mid-1])
            {
                start = mid;
            }else if (A[mid] < A[mid-1])
            {
                end = mid;
            }
        }
    }    
    
    
};
