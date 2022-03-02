class Solution {
public:
    
    vector<bool> mark;
    int in;
    bool impossible = false;
    unordered_map<int, int> progress;
        
    void takeCourse(int ver, vector<vector<int>>& graph, vector<int>& res) {
        if(impossible) return;
        
        progress[ver] = 1;
        int i, v, n = graph[ver].size();
        for( i=0 ; i<n ; i++ ) {
            v = graph[ver][i];
            if(!mark[v]) {
                mark[v] = true;
                takeCourse(v, graph, res);
            }
            else if(progress[v]) impossible = true;
        }
        res[in--] = ver;
        progress[ver] = 0;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int i, j, u, v, len = prerequisites.size();
        
        vector<vector<int>> graph(numCourses);
        for( i=0 ; i<numCourses ; i++ ) mark.push_back(false);
        
        for( i=0 ; i<len ; i++ ) {
            u = prerequisites[i][0];
            v = prerequisites[i][1];
            graph[v].push_back(u);
        }
        
        vector<int> res(numCourses);
        in = numCourses - 1;
        for( i=0 ; i<numCourses ; i++ ) {
            if(!mark[i]) {
                mark[i] = true;
                takeCourse(i, graph, res);
            }
        }
        
        if(impossible) return {};
        return res;
    }
};