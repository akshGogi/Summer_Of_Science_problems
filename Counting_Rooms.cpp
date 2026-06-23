#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
int dfs(int i,int j,vector<vector<bool>>& map){
    if(map[i][j]) return 1;
    //process
    map[i][j]=true;
    if(!map[i+1][j])dfs(i+1,j,map);
    if(!map[i][j+1])dfs(i,j+1,map);
    if(!map[i-1][j])dfs(i-1,j,map);
    if(!map[i][j-1])dfs(i,j-1,map);
    return 1;
}
int main() {
    int n, m;
    cin>>n>>m;
    bool row[m]={false};
    vector<vector<bool>>map(n+2,vector<bool>(m+2,false)) ;
    for(int i = 0;i<1;i++){
        for(int j=0;j<m+2;j++){
            map[i][j]=true;
        }
    }
    for(int i = n+1;i>n;i--){
        for(int j=0;j<m+2;j++){
            map[i][j]=true;
        }
    }
    for(int i = 0;i<n+2;i++){
        for(int j=0;j<1;j++){
            map[i][j]=true;
        }
    }
    for(int i = 0;i<n+2;i++){
        for(int j=m+1;j>m;j--){
            map[i][j]=true;
        }
    }
    char temp;
    for ( int i =1; i <= n;i++ ){
        for(int j =1 ; j<=m ; j++){
            cin>>temp;
            temp=='#' ? map[i][j]=true:map[i][j]=false;
        }
    }
    int count=0;
    for(int i =1 ; i<=n;i++){
        for(int j=1 ; j<=m;j++){
            if(map[i][j]==false)count+=dfs(i,j,map);
            
        }
    }
    cout<<count;
    // run a dfs sort of thing on the visited array 
    //and make sure after each dfs, u get back
}