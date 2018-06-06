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
        
        int start = 0;
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
    

public:
    // 62. Search in Rotated Sorted Array
    // Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    // (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    // You are given a target value to search. If found in the array return its index, otherwise return -1.

    // You may assume no duplicate exists in the array.

    // Example
    // For [4, 5, 1, 2, 3] and target=1, return 2.

    // For [4, 5, 1, 2, 3] and target=0, return -1.

    // Challenge
    // O(logN) time    
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if ( A.size() == 0)
        {
            return -1;
        }
        
        int start = 0;
        int end = A.size() - 1;
        
        while ( start + 1 < end )
        {
            int mid = start + (end - start) / 2;
            if ( A[mid] == target )
            {
                return mid;
            }
            
            if ( A[start] < A[mid])
            {
                if( target >= A[start] && target < A[mid] )
                {
                    end = mid;
                }else
                {
                    start = mid;
                }
            }else
            {
                if ( target >= A[mid] && target <= A[end] )
                {
                    start = mid;
                }else
                {
                    end = mid;
                }
            }
            
        }

//         // method 2
        
//         // step 1: find smallest number
//         int last = A[end];
//         while ( start + 1 < end)
//         {
//             int mid = start + (end - start) / 2;
//             if ( A[mid] <= last )
//             {
//                 end = mid;
//             }else
//             {
//                 start = mid;
//             }
//         }
        
//         int small = 0;
        
//         if ( A[start] > A[end])
//         {
//             small = end;
//         }else
//         {
//             small = start;
//         }
        
//         // step 2: find target
//         //// determine start and end
//         if ( A[small] > target )
//         {
//             return -1;
//         }else if ( target <= last )
//         {
//             start = small;
//             end = A.size() - 1;
//         }else
//         {
//             start = 0;
//             end = small -1;
//         }
//         //// compare mid and target
//         while( start+1 < end )
//         {
//             int mid = start + (end - start) / 2;
//             if ( A[mid] == target )
//             {
//                 return mid;
//             }else if (A[mid] > target)
//             {
//                 end = mid;
//             }else
//             {
//                 start = mid;
//             }
            
//         }        
        
        if ( A[start] == target )
        {
            return start;
        }
        if( A[end] == target )
        {
            return end;
        }
        
        return -1;
    }    
    

public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
     
    // 460. Find K Closest Elements
    // Given a target number, a non-negative integer k and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

    // Example
    // Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

    // Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

    // Challenge
    // O(logn + k) time complexity.    
    
    // find target
    int findTarget(vector<int> &A, int target)
    {
        int start = 0;
        int end = A.size() -1 ;
        int loc_target = 0; 
        while ( start + 1 < end )
        {
            int mid = start + (end - start)/2;
            if ( A[mid] == target)
            {
                return mid;
            }else if ( A[mid] > target )
            {
                end = mid;
            }else
            {
                start = mid;
            }
        }
        if (abs(A[start] - target) < abs(A[end] - target))
        {
            return start;
        }else if (abs(A[start] - target) > abs(A[end] - target))
        {
            return end;
        }else if ( A[start] < target )
        {
            return start;
        }
    }
     
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        vector<int> result;
        if ( A.size() == 0 || k <= 0 || A == nullptr )
        {
            return result;
        }
    
        int loc_target = findTarget(A, target); 
        result.push_back(A[loc_target]);
        
        // find K nearest
        int left = loc_target - 1;
        int right = loc_target + 1;
        int count = 1;
        
        while (count++ < k)
        {
            if (left >= 0 && right < A.size())
            {
                if ( abs(A[left] - target) < abs(A[right] - target) )
                {
                    result.push_back(A[left--]);
                }else if ( abs(A[left] - target) > abs(A[right] - target) )
                {
                    result.push_back(A[right++]);
                }else
                {
                    if (A[left] < A[right])
                    {
                        result.push_back(A[left--]);
                    }else
                    {
                        result.push_back(A[right++]);
                    }
                }
                
            }else if ( right == A.size() )
            {
                result.push_back(A[left--]);
            }else
            {
                result.push_back(A[right++]);
            }
        }
        
        return result;
    }
    

 public:
    //  428. Pow(x, n)
    // Implement pow(x, n).

    // Example
    // Pow(2.1, 3) = 9.261
    // Pow(0, 1) = 0
    // Pow(1, 0) = 1
    // Challenge
    // O(logn) time   
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here
    
        if ( n < 0 ) return 1.0 / power(x, -n);
        else return power(x, n);

        // wrong solution when input 2, -2147483648 return 1
        // if (n < 0)
        // {
        //     x = 1 / x;
        //     n = -n;
        // }
        
        // double ans = 1, tmp = x;
        // while ( n != 0)
        // {
        //     if ( n % 2 == 1 )
        //     {
        //         ans = ans * tmp;
        //     }
        //     tmp *= tmp; 
        //     n /= 2;
        // }
        
        // return ans;
    }
private:
    double power(double x, int n)
    {
        if ( n == 0) return 1;
        double v = power(x, n / 2);
        if ( n % 2 == 0) return v * v;
        else return v * v * x;
    }
    
    
    
    
    
public:
    // 140. Fast Power
    // Calculate the an % b where a, b and n are all 32bit integers.

    // Example
    // For 231 % 3 = 2

    // For 1001000 % 1000 = 0

    // Challenge
    // O(logn)    
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        
        if ( n == 0 )
        {
            return 1 % b;
        }
        
        if ( n == 1 )
        {
            return a % b;
        }
        
        long long temp = fastPower( a, b, n/2);
        if (n % 2 == 0 ) return(temp * temp ) % b;
        else return (temp * temp % b * a) % b;
        
    }

    
public:
    // 415. Valid Palindrome
    // Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    // Example
    // "A man, a plan, a canal: Panama" is a palindrome.

    // "race a car" is not a palindrome.

    // Challenge
    // O(n) time without extra memory.
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        if (s.size() == 0) return true;
         int start = 0;
         int end = s.length() - 1;
         while( start < end )
         {
             if (!isdigit(s[start]) && !isalpha(s[start]))
             {
                 start++;
             }
             if (!isdigit(s[end]) && !isalpha(s[end]))
             {
                 end--;
             }
             
             if (start > end) break;
             
             if (toupper(s[start]) != toupper(s[end]))
             {
                 return false;
             }
             start++;
             end--;
         }
         return true;
    }
    
    
public:

    // 627. Longest Palindrome
    // Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

    // This is case sensitive, for example "Aa" is not considered a palindrome here.

    // Example
    // Given s = "abccccdd" return 7

    // One longest palindrome that can be built is "dccaccd", whose length is 7.
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        if (s.size() == 0) return 0;
        
        int charStateArray[52] = {0};   // ASCII a(97)-z(122) + A(65)-Z(90)
        for (char ch: s)
        {
            if (ch >= 97) 
            {
                charStateArray[26 + ch -'a']++;
            }else
            {
                charStateArray[ ch -'A']++;
            }
        }
        
        int evencount = 0;
        int oddcount = 0;
        for (int count: charStateArray)
        {
            if (count != 0)
            {
                if (count % 2 == 0)
                {
                    evencount += count;
                }else
                {
                    evencount += count - 1;
                    oddcount++;
                }
            }
        }
        
        return oddcount > 0 ? (1 + evencount) : evencount;
    }  
    
};
