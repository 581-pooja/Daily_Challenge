/*
Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

eg. Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/

class Solution {
public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // creating graph
        vector<vector<int>> adj(V);
        for (auto e : prerequisites)
            adj[e[1]].push_back(e[0]); 

        // marking indegree of the Nodes
        vector<int> indegree(V, 0);
	    for(int i = 0; i < V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }

	    // Pushing nodes with indegree 0 in to queue
	    queue <int> q;
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
        
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        count++;
	        // node is in your topo sort
	        // so please remove it from the indegree
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    if((count != V)) return false;
	    return true;
    }
};

// Tc: O(V) + O(V+E) (To get indegree + pushing nodes in the queue and traversing adjacent nodes)
// sc: O(V) + O(V) + O(V*V) (indegree array + queue + Adjacency Matrix)