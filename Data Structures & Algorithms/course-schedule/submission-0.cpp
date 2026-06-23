class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegreeCourse(n,0);
        vector<vector<int>> adjList(n);
        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegreeCourse[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegreeCourse[i]){
                q.push(i);
            }
        }
        int total = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            total++;
            for(auto it : adjList[temp]){
                indegreeCourse[it]--;
                if(!indegreeCourse[it]){
                    q.push(it);
                }
            }
        }
        return total == n;
    }
};