#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
struct DSU{
    vector<int> link,size;

    DSU(int n){
        link.resize(n+1);
        for(int i=1 ; i<n+1;i++){
            link[i]=i;
        }
        size.assign(n+1,1);
    }
    int find(int a){
         while(link[a]!=a){
            a=link[a];
         }
         return a;
    }
    bool same(int a,int b) {
        return ( find(a)==find(b));
    }
    void unite(int a,int b){
        int x=find(a),y=find(b);
        if(size[x]<size[y]){
            link[x]=y;
            size[y]+=size[x];
        }
        else{
            link[y]=x;
            size[x]+=size[y];
        }
    }
    long long int Kruskal(vector<tuple<long long int,int,int>>&  edges,vector<tuple<int,int,long long int>>& output, bool min){
        sort(edges.begin(),edges.end());
        long long int weight=0;
        if(min){
            for(int i = 0; i < edges.size();i++){
                int a,b;
                long long int w;
                tie(w,a,b)=edges[i];
                if(!same(a,b)){
                    unite(a,b);
                    output.push_back({a,b,w});
                    weight+=w;
                }
            }
        }
        else{
            for(int i = edges.size()-1; i >=0 ;i--){
                int a,b;
                long long int w;
                tie(w,a,b)=edges[i];
                if(!same(a,b)){
                    unite(a,b);
                    output.push_back({a,b,w});
                    weight+=w;

                }
            }    
        
        }
        return weight;
    }
    
};

// store a tree, attatch smaller to larger =>new size - max of the two dpths 
int main() {
    //
    int n,m;
    cin>>n>>m;
    vector<tuple<long long int,int, int>> edges;
    int w,a,b;
    DSU dsu(n);
    for(int i=0 ; i < m;i++){
        cin>>a>>b>>w;
        edges.push_back({w,a,b});
    }
    vector<tuple<int,int,long long int>> output;
    long long int  x=dsu.Kruskal(edges,output,1);
    if(output.size()==n-1){
        cout<<x;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    
    
    
}