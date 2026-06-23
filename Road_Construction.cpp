
// algo ech edge, find , same shi do ,you'll have a linked list of size, reach time any size 
//updates ,keep track of max size, and count number of edges being processed for number of 
//components 
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
    int unite(int a,int b){
        int x=find(a),y=find(b);
        if(size[x]<size[y]){
            link[x]=y;
            size[y]+=size[x];
            return size[y];
        }
        else{
            link[y]=x;
            size[x]+=size[y];
            return size[x];
        }
        
    }
    void Kruskal(vector<tuple<int,int,int>>&  edges,vector<tuple<int,int,int>>& output, bool min){
        sort(edges.begin(),edges.end());
        if(min){
            for(int i = 0; i < edges.size();i++){
                int w,a,b;
                tie(w,a,b)=edges[i];
                if(!same(a,b)){
                    unite(a,b);
                    output.push_back({a,b,w});
                }
            }
        }
        else{
            for(int i = edges.size()-1; i >=0 ;i--){
                int w,a,b;
                tie(w,a,b)=edges[i];
                if(!same(a,b)){
                    unite(a,b);
                    output.push_back({a,b,w});
                }
            }    
        }
    }
    
};

// store a tree, attatch smaller to larger =>new size - max of the two dpths 
int main() {
    //
    int n,m;
    cin>>n>>m;

    DSU dsu(n);
    int count =0;
    int size =1;
    int max=1;
    for(int i=0 ; i<m;i++){
    int a,b;
    cin>>a>>b;
    // check 
    if (!dsu.same(a,b)){
        // update size and unite
        size=dsu.unite(a,b);
        if(size>max){
            max=size;
        }
        count++;
    }
    cout<<n-count<<" "<<max<<endl; 
    }
    
    
}