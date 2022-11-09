#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* RECURSION

Rat In a Maze
- Consider a rat placed at (0,0) in a square matrix of order N*N,
it has to reach destination (n-1,n-1).
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which rat can move are 'U'up,'D'down,'L'left,'R'right. 
Value 0 at a cell in matrix represents that it is blocked & rat cannot move to it,
while 1 represents that rat can travel through it.
- In a path, no cell can be visited more that one time

Input: {{1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}}
Output: DDRDRR DRDDRR

Explaination:
- Movement
    1 up = (x-1,y)
    2 down = (x+1,y)
    3 left = (x,y-1)
    4 right = (x,y+1)
- At start, src x=0 & src y=0
    From 1 cell, we can either go U D L R
- We can get stuck in infinite loop, if we go to where we came from
    Create visited array, initialize by 0
    Go to only those, where it is possible & value index of that is unvisited(0)
    Mark visited 1 in visited array
- At (0,0) cell, path string is = ""
- To check of next cell is safe to move to, suppose it is [k][l]:
    It should be inside maze matrix
    maze[k][l]=1
    visited[k][l]=0 
- When we move:
    visited[k][l]=1
    when function call returns, visited[k][l]=0
*/

bool isSafe(int x, int y, int size, vector<vector<int> >visited, vector<vector<int> > &maze){
    if((x>=0 && x<size) && (y>=0 && y<size) && visited[x][y]==0 && maze[x][y]==1){
        return true;
    }
    return false;
}

void solve(vector<vector<int> > &maze, int size, vector<string> &ans, int x, int y, vector<vector<int> > visited, string path){
    if(x==size-1 && y==size-1){     // BASE CASE
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    
    int newx=x+1;   // DOWN
    int newy=y;
    if(isSafe(newx,newy,size,visited,maze)){
        path.push_back('D');
        solve(maze,size,ans,newx,newy,visited,path);
        path.pop_back();
    }
    newx=x-1;       // UP
    newy=y;
    if(isSafe(newx,newy,size,visited,maze)){
        path.push_back('U');
        solve(maze,size,ans,newx,newy,visited,path);
        path.pop_back();
    }
    newx=x;         // LEFT
    newy=y-1;
    if(isSafe(newx,newy,size,visited,maze)){
        path.push_back('L');
        solve(maze,size,ans,newx,newy,visited,path);
        path.pop_back();
    }
    newx=x;         // RIGHT
    newy=y+1;
    if(isSafe(newx,newy,size,visited,maze)){
        path.push_back('R');
        solve(maze,size,ans,newx,newy,visited,path);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int> > &maze, int size){
    vector<string>ans;
    if(maze[0][0]==0){
        return ans;
    }
    int srcx=0;
    int srcy=0;
    vector<vector<int> > visited = maze;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            visited[i][j]=0;
        }
    }
    string path="";
    solve(maze,size,ans,srcx,srcy,visited,path);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    
    vector<vector<int> > maze={{1,0,0,0},
                               {1,1,0,1},
                               {1,1,0,0},
                               {0,1,1,1}};
    int size=4;
    vector<string>ans=findPath(maze,size);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].length();j++){
            cout<<ans[i][j];
        }cout<<endl;
    }
    
    return 0;
}