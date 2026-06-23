// Q.POP, q.push, - implement bfs again ,found bit should've happened 
// foc/ pre plan
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;

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
    //if 1 to n posiible , 2nd - example of route 
    queue<int> q;
    // or make an alternate array which stores for each node where it came from 
    // bascally hashing 
    int prev[n];
    for(int i = 0 ; i<n; i++){
        prev[i]=-1;
    }
    bool visited[n]={false};
    bool found=false;
    q.push(0);
    while(!q.empty()){
        // run bfs and store prev int in it , if u hit n-, stop 
        if(q.front()==n-1){
            found =true;
            break;
        }
        visited[q.front()]=true;
        for(auto x: adj[q.front()]){
            if(prev[x]<0){
                prev[x]=q.front();
                q.push(x);
            }
        }
        q.pop();
        // don''t need the if not visited only then append 
        //, prev does it for u  
    }
    if(found){
    int it=n-1 ;
    vector<int> path;
    while(it!=0){
        path.push_back(it);
        it=prev[it];
    }
 
    path.push_back(0);
    cout<<path.size()<<endl;
    //for(auto i=path.begin();i!=path.end();i++){
      //  cout<<*i+1<<" ";
    //}
    for (int i  = path.size()-1;i>=0;i--){
        cout<<path[i]+1<<" ";
    }
}
else cout<<"IMPOSSIBLE";
}