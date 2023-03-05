/* 
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. 
Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, 
and people continue passing the pillow in the opposite direction.
    For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

Example 1:
Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
Afer five seconds, the pillow is given to the 2nd person.

Example 2:
Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
Afer two seconds, the pillow is given to the 3rd person.
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int curr_postion = 1;
        int direction = 1; // 1 means moving towards the end of the line
                            // -1 means moving towards the beginning of the line

        for (int i = 0; i < time; i++) {
            curr_postion += direction;

            // Check if the pillow has reached the end of the line
            if (curr_postion == n+1) {
                curr_postion = n-1;
                direction = -1;
            } 
            // Check if the pillow has reached the beginning of the line
            else if (curr_postion == 0) {
                curr_postion = 2;
                direction = 1;
            }
        }
        return curr_postion;
    }
};

// TC: O(Time)
