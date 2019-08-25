#include<bits/stdc++.h>
using namespace std;
const long long MAX {1005};

vector <pair<int,int>> adj = { {0,1},{1,0},{-1,0},{0,-1} };
queue <pair<int,int>> que;
vector <vector<bool>> visited(MAX);
vector <vector<int>> dist(MAX);

void bfs(size_t h,size_t w)
{
    //the queue is alread populated with the nodes we need to start
    dist[que.front().first][que.front().second] = 0;
    while (not que.empty())
    {
        auto u = que.front();
        que.pop();
        for (const auto& v : adj)
        {
            cout << u.first + v.first << u.second + v.second;
            if (visited[u.first + v.first][u.second + v.second] 
                or u.first + v.first > h-1
                or u.first + v.first < 0
                or u.second + v.second > w-1
                or u.second + v.second < 0 )
                continue;

            visited[u.first + v.first][u.second + v.second] = true;
            dist[v.first][v.second] = dist[u.first][u.second] + 1;
            que.push(v);
        }
    }
}

int main(){
    // turn off the sinc with stdio.h to make the program faster
    //ios::sync_with_stdio(false);
    size_t h,w;
    char dot;
    cin >> h >> w; 
    
    for (int i = 0; i < h; i++) { 
        // declare  the i-th row to size of column 
        visited[i] = vector<bool>(w);
        dist[i] =  vector<int>(w);
    }

    for(size_t i = 0; i<h; i++){
        for(size_t j = 0; j<w; j++){
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
    
    bfs(h,w);

    cout << dist[h-1][w-1] << endl;

    return 0;
}