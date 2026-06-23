/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
// for monsters  , i want to analyse one bfs step fir every monster, then analyse each nide of that distsnce step, 
//make a tuple triplet, including distance,
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
// store the distance as well and then run the monsters loop above 
// and if the mosters queue is not empty and the monsters are all not above your distance of bfs, recontinue the loop 
// end - ifu reach the edge , if q empties before that =>died 
// how to start a loop for all the monsters 
// count monsters, array of monsters(tuple coord, distance = 0, 
//what if u just  add them to the main queues instead of seprate quues, it's like running bfs off of the middle of it ,
//coord), queues and 
*/
//queue<tuple<pair<int,int>,int,pair<int,int>>
//one queue for each 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;

int main(){
    int n,m;
    cin>>n>>m;
    char map[n][m];
    pair<int,int> s;
    queue<tuple<pair<int,int>,int>> mq;
    queue<tuple<pair<int,int>,int,pair<int,int>>> q;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]=='A'){
                q.push({{i,j},0,{i,j}});
            }
            if(map[i][j]=='M'){
                mq.push({{i,j},0});
            }
        }
    }
    int hdist;
    int mdist=hdist=0;
    vector<char>path;
    vector<tuple<pair<int,int>,int,pair<int,int>>> visited;
    bool found;
    while(!q.empty()){
        if( get<1>(mq.front())== get<1>(q.front())){  
            int x = get<0>(mq.front()).first;
            int y = get<0>(mq.front()).second;
            mdist = get<1>(mq.front());
            if(map[x][y]!='#'){
    // process node
                map[x][y]='#';
                if(x+1<n&&map[x+1][y]!='#'){
                    mq.push({{x+1,y},mdist+1});
                }
                if(x-1>=0&&map[x-1][y]!='#'){
                    mq.push({{x-1,y},mdist+1});
                }
                if(y-1>=0&&map[x][y-1]!='#'){
                    mq.push({{x,y-1},mdist+1});
                }
                if(y+1<m&&map[x][y+1]!='#'){
                    mq.push({{x,y+1},mdist+1});
                }
            }
            mq.pop();
        }
        
        //if next monster-nex
        if(mq.empty()||( get<1>(mq.front())== get<1>(q.front())+1)){
            int x = get<0>(q.front()).first;
            int y = get<0>(q.front()).second;
            hdist =get<1>(q.front());
            
            if(map[x][y]!='#'){
                visited.push_back(q.front());
                if(x==n-1||x==0||y==m-1||y==0){found=true;break;}
                map[x][y]='#';
                if(x+1<n&&map[x+1][y]!='#'){
                    q.push({{x+1,y},hdist+1,{x,y}});
                }
                if(x-1>=0&&map[x-1][y]!='#'){
                    q.push({{x-1,y},hdist+1,{x,y}});
                }
                if(y-1>=0&&map[x][y-1]!='#'){
                    q.push({{x,y-1},hdist+1,{x,y}});
                }
                if(y+1<m&&map[x][y+1]!='#'){
                    q.push({{x,y+1},hdist+1,{x,y}});
                }
            }
            q.pop();

        }


    }
    /*for(int i = 0 ; i<n;i++){
    for(int j = 0 ; j<m;j++){
        cout<<map[i][j];
    }
    cout<<endl;
    }*/
    
    if(found){
        cout<<"YES"<<endl;
        
    }
    pair<int,int> curr;
    for(int i = visited.size()-1;i>=0;i--){

        pair<int,int> self=get<0>(visited[i]);
        pair<int,int> prev = get<2>(visited[i]);
        pair<int,int> p= {1,0};

        if(i==visited.size()-1){
            curr=prev;
        }
        pair<int,int> move={self.first-prev.first,self.second-prev.second};
        if(curr==self||i==visited.size()-1){
            curr=prev;
            if(move==p){
                path.push_back('D');
            }
            p={-1,0};
            if(move==p){
                path.push_back('U');
            }
            p={0,1};
            if(move==p){
                path.push_back('R');
            }
            p={0,-1};
            if(move==p){
                path.push_back('L');
            }

        }
    }
        cout<<path.size()<<endl;
        
    for(int i = path.size()-1;i>=0;i--){
        cout<<path[i];
    }
    cout<<endl;



}