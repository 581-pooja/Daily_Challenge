
class Solution {
public:
    Node* constructQuadTree(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart,int colEnd){
        if(rowStart > rowEnd || colStart > colEnd) return NULL;
    
        bool isLeaf = true;
        int val = grid[rowStart][colStart];
        for(int i = rowStart; i <= rowEnd; i++){
            for(int j = colStart; j <= colEnd; j++){
                // if quad start ele not equal to same quad any ele then it is both of 0's and 1's
                if(grid[i][j] != val){   
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf) break;
        }
        
        // if the whole quad or cells have same value then return value and isLeaf as true
        if(isLeaf) return new Node(val, true);

        // if quad does not have same values then divide it further 
        int rowMid = (rowStart + rowEnd)/2;
        int colMid = (colStart + colEnd)/2;
        Node* topLeft = constructQuadTree(grid, rowStart, rowMid, colStart, colMid);
        Node* topRight = constructQuadTree(grid, rowStart, rowMid, colMid+1, colEnd);
        Node* bottomLeft = constructQuadTree(grid, rowMid + 1, rowEnd, colStart, colMid);
        Node* bottomRight = constructQuadTree(grid, rowMid + 1, rowEnd, colMid+1, colEnd);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        // return Node(isLeaf, value) -> false means 0 and true means 1
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, n-1, 0, n-1);
    }
};
// TC: O(N * log N) | Sc: O(log N)

// Refer Problem: For best explaination: https://leetcode.com/problems/construct-quad-tree/ 
