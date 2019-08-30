#include<bits/stdc++.h>
using namespace std;
const long long MAX {1005};

vector <pair<int,int>> adj = { {0,1},{1,0},{-1,0},{0,-1} };
queue <pair<int,int>> que;
vector <vector<bool>> visited(MAX,vector<bool>(MAX));
vector <vector<int>> dist(MAX,vector<int>(MAX));

void print_matrix(int h,int w){
    for(int i=0;i<h;i++){
        cout << "\n";
        for(int j=0;j<w;j++){
            cout << visited[i][j];
        }
    }
    cout << "\n";
}


pair <int,int> bfs(int h,int w)
{
    pair <int,int> u;
    //the queue is alread populated with the nodes we need to start
    dist[que.front().first][que.front().second] = 0;
    while (not que.empty())
    {
        u = que.front();
        que.pop();

        //iterate over adj vector atributing to v
        for (const auto& v : adj)
        {
            //verifing the boundaries of matrix
            if (u.first + v.first > h-1
                or u.first + v.first < 0
                or u.second + v.second > w-1
                or u.second + v.second < 0 )
                continue;
            //avoiding segmentation fault
            if (visited[u.first + v.first][u.second + v.second])
                continue;

            visited[u.first + v.first][u.second + v.second] = true;
            //print_matrix(h,w);
            dist[u.first + v.first][u.second + v.second] = dist[u.first][u.second] + 1;
            que.push({u.first + v.first,u.second + v.second});
        }
    }
    return u;
}

int main(){
    // turn off the sinc with stdio.h to make the program faster
    ios::sync_with_stdio(false);
    int h,w;
    char dot;
    cin >> h >> w; 

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
    //capture the distance betwen the first readed node and the last 
    auto res = bfs(h,w);
    cout << dist[res.first][res.second] << endl;

    return 0;
}