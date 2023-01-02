/* 
Bulls and Cows
Using Array
    when same strings in secret and guess then increment bulls
    if(s == g) bulls++;

    when different strings in secret and guess and previous encountered and marked in the array then increment cows
    if s is previous encounterd in guess then it must be marked or decremented by 1 so numbers[s] < 0
    if(numbers[s] < 0) cows++;

    if g is previous encounterd in secret then it must be marked or increment by 1 so numbers[g] > 0
    if(numbers[g] > 0) cows++;

    For new secret element :do increment by 1 in array (+1)
    For new guess element :do decrement by 1 in array (-1)

Complexity
    Time complexity: O(N)
    Space complexity: O(10) Constant size for array

*/

#include <bits/stdc++.h>
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> numbers(10, 0);

        for(int i = 0; i < secret.size(); i++){
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if(s == g){
                bulls++;
            }
            else{
                // so g or s must be previously encounterd
                // if s is previous encounterd in guess then it must be marked or decremented by 1 so numbers[s] < 0
                if(numbers[s] < 0) cows++;
                if(numbers[g] > 0) cows++;
                // marking for new numbers
                numbers[s]++;
                numbers[g]--;
            }
        }
        return to_string(bulls)+ "A" + to_string(cows) +"B";
    }
};
// TC: O(N) | SC: O(10)