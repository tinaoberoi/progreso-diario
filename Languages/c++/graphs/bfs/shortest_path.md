### Shortest Path on the Grid

```/*
 I/P
 5 7
 S . . # . . .
 . # . . . # .
 . # . . . . .
 . . # # . . .
 # . # E . # .
 */

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;
vector<vector<char>> maze;
vector<vector<bool>> vis;
map<int, list<int>> adjList;
map<int, int> comp;

bool valid (int i, int j, int r, int c){
    if(i>=r || j>=c || maze[i][j] == '#' || i<0 || j<0){
        return false;
    }
    return true;
}

int bfs(int sx, int sy, int r, int c, int ex, int ey){
    int count = 0;
    vis[sx][sy] = true;
    queue<pair<pair<int , int>, int>> q;
    q.push({{sx, sy}, count});
    
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        auto coord = temp.first;
        auto count_now = temp.second;
        cout<<"############"<<endl;
        auto x = coord.first;
        auto y = coord.second;
        cout<<"("<<x<<","<<y<<")"<<"-"<<count_now<<endl;
        if(x == ex && y == ey){
            cout<<"returning count "<<count_now<<endl;
            return count_now;
        }
        if(valid(x+1, y, r, c) && !vis[x+1][y]){
            vis[x+1][y] = true;
            q.push({{x+1, y}, count_now+1});
            count = max(count, count_now+1);
            cout<<"Pushing ccord x+1, y =>";
            cout<<"("<<x+1<<","<<y<<")"<<"-"<<count_now+1<<endl;
        }
        if(valid(x, y+1, r, c) && !vis[x][y+1]){
            vis[x][y+1] = true;
            q.push({{x, y+1}, count_now+1});
            count = max(count, count_now+1);
            cout<<"Pushing ccord x, y+1 =>";
            cout<<"("<<x<<","<<y+1<<")"<<"-"<<count_now+1<<endl;
        }
        if(valid(x-1, y, r, c) && !vis[x-1][y+1]){
            vis[x-1][y] = true;
            q.push({{x-1, y}, count_now+1});
            count = max(count, count_now+1);
            cout<<"Pushing ccord x-1, y =>";
            cout<<"("<<x-1<<","<<y<<")"<<"-"<<count_now+1<<endl;
        }
        if(valid(x, y-1, r, c) && !vis[x][y-1]){
            vis[x][y-1] = true;
            q.push({{x, y-1}, count_now+1});
            count = max(count, count_now+1);
            cout<<"Pushing ccord x, y-1 =>";
            cout<<"("<<x<<","<<y-1<<")"<<"-"<<count_now+1<<endl;
        }
    }
    cout<<"Returning count from below"<<count<<endl;
    return count;
}

int main(){
    int r, c;
    cin>>r>>c;
    maze.resize(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));
    int sx, sy, ex, ey;
    for(int i =0; i<r; i++){
        for(int j = 0; j<c; j++){
            char input;
            cin>>input;
            if(input == 'S'){
                sx = i;
                sy = j;
            }
            if(input == 'E'){
                ex = i;
                ey = j;
            }
            maze[i][j] = input;
        }
    }
    
    for(int i =0; i<r; i++){
        for(int j = 0; j<c; j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<bfs(0, 0, r, c, 4, 3)<<endl;
    return 0;
}
```
Time Complexity: O(R+C)
Space Complexity: O(RC)