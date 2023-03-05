/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

class Solution {
public:
    int strStr(string text, string pattern) {
        int m = text.size();
        int n = pattern.size();
        // taking m-n since if in last m - n is not equal to pattern size then it is not pattern
        for(int i = 0; i <= m - n; i++){
            int j = 0;
            // if pattern not completed
            while(j < n){
                if(text[i+j] != pattern[j]){
                    break;
                }
                j++;
            }
            // if pattern is completed return index
            if(j == n){
                return i;
            }
        }
        return -1;
    }
};
// Traverse all the possible starting points of text (from 0 to text.length() - pattern.length()) and see if the following characters in haystack match those of needle.
// Tc: O(m) | Sc: O(1)
