#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

int main(){
cout<<"Enter a high value"<<endl;
int n;cin>>n;  // arbitrary high value
vector<int> adj[n];
cout<<"Enter No. of branches"<<endl;
int m;cin>>m; // no of branches

bool vis[n] = {false}; // visited array
cout<<"Enter No. to Search"<<endl;
int res; cin>>res;
for(int i=0;i<m;i++){    // adjacency matrix
  int x,y;
  cin>>x>>y;
  adj[x].push_back(y);
  adj[y].push_back(x);
}
    //  Given :- Root Node, eg. :- 1
   // BFS
   queue<int> q;
   q.push(1); vis[1]= true; bool flag = false;
   while(!q.empty()){
       int temp  =q.front();
        if(temp==res){
            flag = true;break;
        }
       q.pop();
       for(auto i:adj[temp]){
           if(!vis[i]){
               vis[i]=true;
               q.push(i);
           }
       }
   }
   if(flag)
   cout<<"Exists"<<endl;
   else
   cout<<"Does not Exist"<<endl;

return 0;
}