class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);
        vector<vector<int>> adjList(n);

        for(auto it : pre){
            indegree[it[0]]++;
            adjList[it[1]].push_back(it[0]);
        }
        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int total=0;
        while(!q.empty()){
            int temp = q.front();
            total++;
            q.pop();

            for(auto it : adjList[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return total == n;
    }
};
