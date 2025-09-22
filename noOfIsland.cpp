#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col,vector<vector<int>>& visited,vector<vector<int>>& grid){
    visited[row][col]=1;
    queue<pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    q.push({row,col});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int newRow=-1;newRow<=1;newRow++){
            for(int newCol=-1;newCol<=1;newCol++){
                int row1=row+newRow;
                int col1=col+newCol;
                if(row1>=0 && row1<n && col1>=0 && col1<m 
                && grid[row1][col1]==1 && !visited[row1][col1]){
                    visited[row1][col1]=1;
                    q.push({row1,col1});
                }
            }
        }
    }
}

int numofIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]==1){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return count;
}
int main() {
    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,1,1},
        {1,0,0,0,0}
    };

    cout << "Number of Islands: " << numofIslands(grid) << endl;
    return 0;
}