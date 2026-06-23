//SM- visited[i]
// input nodes 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
void dfs(int n ,vector<int> adj[],bool visited[]){
    visited[n]=true;
    for(auto x: adj[n]){
        if(!visited[x]){
            dfs(x,adj,visited);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    int a,b;
    for(int i =0 ;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    // do all Q , build templates , then move on 
    bool visited[n]={false};
    vector<int>comp;
    comp.push_back(0);
    dfs(0,adj,visited);
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            comp.push_back(i);
            dfs(i,adj,visited);
        }
    }   
    //just connec t all components - common senes
    cout<<((comp.size()-1))<<endl;
    for(int i =0 ;i<comp.size()-1;i++){
        cout<<comp[i]+1<<" "<<comp[i+1]+1<<endl;
    }
    
}