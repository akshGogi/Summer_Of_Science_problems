#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
// shortest  path , its details , length 
int main() {
    int n,m;
    cin>>n>>m;
    char map[n][m];
    int sx,sy,ex,ey;
    for(int i =0 ; i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]=='A'){
                sx =i;sy=j;
            }
            if(map[i][j]=='B'){
                ex = i;  ey=j;
            }
        }
    }
    // take array as input, 
    //BFS
    queue<pair<pair<int,int>,pair<int,int>>>q ;
    q.push({{sx,sy},{sx,sy}});
    vector<pair<pair<int,int>,pair<int,int>>>visited;
    bool found=false;
    while(!q.empty()){
        pair<pair<int,int>,pair<int,int>> node= q.front();
        int x=node.first.first;int y = node.first.second;
        //process node 
        if(map[x][y]!='#'){
            visited.push_back(node);
            
            if(map[x][y]=='B'){
                found=true;
                break;
            }
            map[x][y]='#';
            // end consdition => break loop, go through q via second indexes and store commands of LRDU in a vector, print that vector 
            //add neighbours to queue
            if(x+1<n&&map[x+1][y]!='#'){
                q.push({{x+1,y},{x,y}});
            }
            if(x-1>=0&&map[x-1][y]!='#'){
                q.push({{x-1,y},{x,y}});
            }
            if(y-1>=0&&map[x][y-1]!='#'){
                q.push({{x,y-1},{x,y}});
            }
            if(y+1<m&&map[x][y+1]!='#'){
                q.push({{x,y+1},{x,y}});
            }
        }
        q.pop();
    }
// this should run bfss and give me vector which is all of the visited nodes till i got to B 
        if (!found){
            cout<<"NO";
            return 0;
        }
        cout<<"YES"<<endl;
        pair<pair<int,int>,pair<int,int>> node={{-1,-1},{-1,-1}};
        vector<char>path;
        for(size_t i=visited.size()-1;i>=0;i--){
            if(visited[i].first.first==ex&&visited[i].first.second==ey){
                node = visited[i];
            }
            if(node.first.first!=-1){
                if(node.first==node.second){
                    break;
                }
                if(visited[i].first==node.second){
                    pair<int,int> move={node.first.first-visited[i].first.first,node.first.second-visited[i].first.second};
                    pair<int,int> p;
                    p={1,0};
                    if(move==p){
                        path.push_back('D');
                    }
                    p={0,1};
                    if(move==p){
                        path.push_back('R');

                    }
                    p={0,-1};
                    if(move==p){
                        path.push_back('L');

                    }
                    p={-1,0};
                    if(move==p){
                        path.push_back('U');
                    }
                    node=visited[i];
                }
            }
        } 
        cout<<path.size()<<endl;
        for (int i = int(path.size()) - 1; i >= 0; i--) {
        cout << path[i];
        }

        


    }
