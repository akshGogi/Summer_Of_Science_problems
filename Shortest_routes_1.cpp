#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
const long long int INF = 1e17;
void Djikstra ( long long int distance[],vector<pair<int,long long int>>adj[],int n,int source,bool processed[]){
    // pass graph, distance array 
    for(int i=0 ;i<n;i++){
        distance[i]=INF;
    }
    distance[source-1]=0;
    // priority que orders pair by first then sec 
    priority_queue<pair<long long int,int>> q;
    q.push({0,source-1});
    while(!q.empty()){
        //
        int a=q.top().second;q.pop();
        //
        if(processed[a]){
                continue;
        }
        //
        else{
        processed[a]=true;
            for(auto x:adj[a]){
                if(distance[x.first]>distance[a]+x.second){
                    distance[x.first]=distance[a]+x.second;
                    q.push({-distance[x.first],x.first});
                }
            }
        }

    }

}
int main() {
    int n,m;
    cin>>n>>m;
    long long int distance[n];
    vector<pair<int,long long int>>adj[n];
    int a,b,w;
    for (int i=0 ;i<m;i++){
        cin>>a>>b>>w;
        adj[a-1].push_back({b-1,w});

    }
    bool processed[n]={false};
    Djikstra(distance,adj,n,1,processed);
    for(int i=0;i<n;i++){
        cout<<distance[i]<<" ";
    }
    // shortest path to all, djikstra's seems appropriate - prior quque and run 

}