/*
You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.

Example 1:
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:
Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
*/

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Using BFS and Min Heap
        if(root == NULL) return -1;
        priority_queue <long long, vector<long long>, greater<long long> > pq;   // min Heap
        queue <TreeNode*> q;
        vector<long long> ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<long long> level;
            long long sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)  q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                sum += node->val;
            }
            ans.push_back(sum);
        }
        
        if(ans.size() < k) return -1;
        // Find the Largest sum of k elements in ans array
        for(int i = 0; i < k; i++){
            pq.push(ans[i]); 
        }
        for(int i = k; i < ans.size(); i++){
            if(ans[i] > pq.top()){
                pq.pop();
                pq.push(ans[i]);
            }
        }
        return pq.top();
    }
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Using BFS and Max Heap
        if(root == NULL) return -1;
        priority_queue <long long> pq;   // Max Heap
        queue <TreeNode*> q;
        vector<long long> ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<long long> level;
            long long sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)  q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                sum += node->val;
            }
            pq.push(sum);
        }
        // Max Heap
        if(pq.size()<k)return -1;
        k=k-1;
        while(k--)pq.pop();
        return pq.top();
    }
};
// N is level of Tree BFS
// TC: O(N) + O(log N) (height of Tree BFS + Heap with N level) | SC: O(2*N) (Ans + Heap)
