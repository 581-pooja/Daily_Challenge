class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        return paintinlesscost(colors,N);
    }
    
    int paintinlesscost(vector<vector<int>> &colors, int N){   
        if(N==0) return 0;
        //p=0,b=1,y=2
        //Now we have to paint the each wall by checking the min cost in the walls
        vector<vector<int>> store(N,vector<int>(3,0));
        //Pink
        store[0][0] = colors[0][0];
        //Black
        store[0][1] = colors[0][1];
        //Yellow
        store[0][2] = colors[0][2];
        //{wall 1 = {14,2,11} = {PINK,BLACK,YELLOW}}
        
        for(int i=1;i<N;i++){
        //Now the first wall has been painted
        store[i][0] = min(store[i-1][1],store[i-1][2])+ colors[i][0];
        store[i][1] = min(store[i-1][0],store[i-1][2])+ colors[i][1];
        store[i][2] = min(store[i-1][1],store[i-1][0])+ colors[i][2];
        }
        return min(store[N-1][0],min(store[N-1][1],store[N-1][2])); 
    }
};
// TC: O(N * 3) SC: O(N * 3)

/*
Question:
There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. 
Alexa can color each wall with either pink, black, or yellow. The cost associated with coloring each wall with a particular color is represented by a 2D array 
colors of size N*3 , where colors[i][0], colors[i][1], and colors[i][2] is the cost of painting ith wall with colors pink, black, and yellow respectively.

You need to find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Example 1:
Input:
N = 3
colors[][] = {{14, 2, 11},
             {11, 14, 5},
             {14, 3, 10}}
Output:
10
Explanation:
Color wall 0 with black. Cost = 2. 
Color wall 1 with yellow. Cost = 5. 
Color wall 2 with black. Cost = 3.
Total Cost = 2 + 5 + 3 = 10
*/
