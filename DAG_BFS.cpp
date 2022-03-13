#include<bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int> > &graph, int k, int n) {
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(k);

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        if(!visited[i]) {
            visited[i] = true;
            cout<<i<<" ";
        }


        for(int j=0;j<graph[i].size();j++) {
            if(!visited[graph[i][j]]) {
                q.push(graph[i][j]);
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

    BFS(graph, 0, n);


    return 0;
}
