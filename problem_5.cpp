/*
Largest Divisible Subset
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.
eg. Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        // sorting
        sort(arr.begin(), arr.end());
        // hash : extra space to store the previous indexes
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i = 0; i<n ; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                // checking previous index added is divisible by new element added
                if(arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i] ){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        // Finding the LIS
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

// Tc: O(N * log N + N * N)
// Sc: O(N ) + O(N) (Dp array + hash array)