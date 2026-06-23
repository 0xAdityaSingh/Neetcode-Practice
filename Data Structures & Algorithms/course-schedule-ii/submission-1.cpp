class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        for(auto it : pre){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for(int i = 0; i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it : adj[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};
