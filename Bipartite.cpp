#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
bool bip(int n,bool visited[],vector<int> adj[],bool col,bool biparr[]){
    if(visited[n]){
        if(col==biparr[n]){ 
            return true ;
        }
        else return false ;
    }
    else{
        biparr[n]=col;
        visited[n]=true;
        bool ret=true;
        for(auto x:adj[n]){
            ret=ret&&bip(x,visited,adj,!col,biparr);
        }
        return ret;
    }

}
int main() {
    int n; int m;
    cin>>n>>m;
    vector<int>adj[n];
    // take in graph
    int a,b;
    // run dfs , on all not in visited
    for(int i=0 ; i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bool biparr[n]={false};
    bool pos =true;
    bool visited[n]={false};
    for(int i = 0 ; i<n;i++){
        if(!visited[i]){
            pos=pos&&bip(i,visited,adj,false,biparr);
            // two colours 2 and 1 (bip array of 2 vectors)
            //if any dfs returns false => not bip
            // dfs algo - check if current vsited - if clr to assn = 
            //process - see if clr assn bit ,
        }
    }
    if(pos){
        for(int i = 0 ;i<n;i++){
        cout<<biparr[i]+1<<" ";
        }
    }
    else cout<<"IMPOSSIBLE"<<endl;

}
// check if bip - if while assigning colours, the clr to be
            // assigned != same clr => exit
            // simpler - find odd cycle ?
            //or after assigning run a n^2 loop to see if there is a edge there 
            //dfs - twice visit - allowed ig?? 
            //dfs - 
            //dfs called on each edge*2 
            //dfs process - n 
            // n+2m , can't afford to go again and check all vertices n^2 style 
            