#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// for directe di nee dto check if a visited nde happens to be in the same dfs path, make a visited path bool to store what's been visi
//ideal - use a dict sort of struc with key neing nodes , to see if they've been visited nd store their dist, then sort by value and print keys (impldem later)
typedef double d;
int cycles(int n,vector<int>adj[],bool visited[],vector<int>&path,bool path_vis[]){
  // process node
  // func returns path repeater if cycle exists and if not , it returns -1
  if(visited[n]&&path_vis[n]){
            path.push_back(n);
            return n;
            }
  
  if(visited[n]){
    return -1;
  }
  //not visited
  path.push_back(n);
  visited[n]=true;
  path_vis[n]=true;
  int cyc=-1;
  for(auto x:adj[n]){
    // if cycles returns something positive then u take it in
    if((cyc=cycles(x,adj,visited,path,path_vis))>=0){     
        break;
    }
  }
  //if cycle dfs =>path is perfect rn 
  if(cyc>=0)
  return cyc;
  // if not the cycle dfs 
  else{
  path.pop_back();
  path_vis[n]=false;
  return -1;
  }
}
int main() {
    int n; int m;
    cin>>n>>m;
    int a,b;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    //take graph
    bool visited[n]={false};
    vector<int>path;
    bool path_vis[n]={false};
    int cyc=-1;
    bool found=false;
//cout<<"hello";
    for(int i = 0 ;i<n;i++){
        if(!visited[i]){
            if((cyc=cycles(i,adj,visited,path,path_vis))>=0){
                found =true;
                break;
            }
        }
    }

//cout<<visited[0];
    int idx;
    if(found){
        for(int i = 0 ; i<path.size();i++){
           if(path[i]==cyc){
               idx=i;
               break; 
            }
        }
       // cout<<idx<<endl;
        cout<<path.size()-idx<<endl;
        for(int i = idx;i<path.size();i++){
            cout<<path[i]+1<<" ";
        }
//cout<<cyc;
    }

    else cout<<"IMPOSSIBLE"<<endl;
}