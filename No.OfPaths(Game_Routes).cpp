#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
//count no of paths - i.e. run bfs, whever u hit the spot mark that particular path(1)
// if the dfs oath does not hit said spot, mark the entire path(2)
//2 - visited but can be visited again
// store number of paths from a point- in a hash
// - and mark each path,and re riterate through path to add oumber of paths to each node-//
//can also do bfs from end pt ig , keep adding numbers as oaths intersect and see what u get 
int dfs(int s,int e,int hash[],bool visited[],vector<int>adj[],int mod){
    if(visited[s]){
        return hash[s];
    }
    if(s==e){
        hash[s]=1;
        visited[s]=true;
        return 1;
    }
    int sum=0;
    visited[s]=true;
    for(auto x: adj[s]){
        sum=((sum+dfs(x,e,hash,visited,adj,mod))%mod);
    }
    hash[s]=sum;
    return sum;
} 
int main(){
    int s,e;
    s=1;
    cin>>e;
    int m;
    cin>>m;
    int a,b;
    int hash[e]={0};
    bool visited[e]={false};
    vector<int>adj[e];
    for(int i =0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    int mod=1e9+7;
    cout<<dfs(s-1,e-1,hash,visited,adj,mod);
}