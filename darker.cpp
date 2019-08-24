#include<bits/stdc++.h>
using namespace std;
const long long MAX {1005};

vector <pair<int,int>> cord = {
    {0,0},{0,1},{1,0},{1,1},
    {-1,-1},{-1,0},{0,-1}
};
queue <pair<int,int>> que;
vector <vector<bool>> visited(MAX);
vector <pair<int,int>> dist[MAX*2];
// process is a lambda function. it is specified when called the bfs function.
void bfs(int s, const function<void(pair<int,int>)>& process)
{
     
    dist[que.front] = 0;

    while (not que.empty())
    {
        auto u = que.front();
        que.pop();

        process(u);

        for (const auto& v : cord)
        {
            if (visited[v.first][v.second])
                continue;

            visited[v.first][v.second] = true;
            dist[v.first][v.second] = dist[u] + 1;
            que.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    size_t h,w;
    char dot;
    cin >> h >> w; 
    
    for (int i = 0; i < h; i++) { 
        // declare  the i-th row to size of column 
        visited[i] = vector<bool>(w); 
    }

    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> dot;
            // mark the node as unvisited
            if(dot == '.') visited[i][j] = false;
            else if(dot == '#'){
                // mark the node as visited
                visited[i][j] = true;
                // insert the node with # in the BFS queue
                que.push({i,j});
            }
        }
    }


    return 0;
}