#include<bits/stdc++.h>

using namespace std;

void DFS(vector<bool> &visited, int k, vector<vector<int> > &graph) {
    if(k>=visited.size() || visited[k]) {
        return;
    }

    cout<<k<<" ";
    visited[k] = true;

    for(int i=0;i<graph[k].size();i++) {
        DFS(visited, graph[k][i], graph);
    }

}

void DAG_DFS_Stack(vector<bool> &visited, int k, vector<vector<int> > &graph) {
    stack<int> s;

    s.push(k);

    while(!s.empty()) {
        int i = s.top();
        s.pop();

        visited[i] = true;
        cout<<i<<" ";

        for(int j=0;j<graph[i].size();j++) {
            if(!visited[graph[i][j]]) {
                s.push(graph[i][j]);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<bool> visited(n, false);

    vector<vector<int> > graph {
        { 1, 2 },
        { 3 },
        { 3 },
        { 4 },
        {},
        {}
    };

    //DFS(visited, 0, graph);
    cout<<"\n";
    DAG_DFS_Stack(visited, 0, graph);


    return 0;
}
