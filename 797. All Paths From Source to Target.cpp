class Solution {
public:
    struct Path{
        vector<int> v;
    }path[16];
    
    vector<vector<int>>allPaths;
    int dest;
    bool mark[16];
    
    void DFS(vector<vector<int>>& graph, int n) {
        int i, node, col = graph[n].size();
        
        for(i=0 ; i<col ; i++) {
            node = graph[n][i];
            path[node].v.push_back(n);
            
            if(!mark[node]) {
                mark[node] = true;
                DFS(graph, node);
            }
        }
    }
    
    void findAllPaths(int n, vector<int> res) {
        if(n == 0) {
            res.push_back(n);
            vector<int> resPath;
            int len = res.size();
            for(int i=len-1 ; i>=0 ; i-- ) resPath.push_back(res[i]);
            allPaths.push_back(resPath);
            return;
        }
        
        res.push_back(n);
        for(int i=0 ; i<path[n].v.size() ; i++) {
            findAllPaths(path[n].v[i], res);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int i, j;
        
        allPaths.clear();
        dest = graph.size() - 1;
        
        for(i=0 ; i<16 ; i++) {
            mark[i] = false;
            path[i].v.clear();
        }
        
        mark[0] = true;
        DFS(graph, 0);
        
        vector<int> res;
        for(i=0 ; i<path[dest].v.size() ; i++) {
            res.clear();
            res.push_back(dest);
            findAllPaths(path[dest].v[i], res);
        }
        
        return allPaths;
    }
};