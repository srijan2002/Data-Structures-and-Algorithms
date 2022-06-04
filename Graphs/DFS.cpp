#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

bool vis[1000] = {false}; vector<int> adj[1000];
void dfs(int node){
    cout<<node<<endl;
    vis[node] = true;
    for(auto i:adj[node]){
        if(!vis[i])
        dfs(i);
    }
}
int main(){
  

cout<<"Enter No. of branches"<<endl;
int m;cin>>m; // no of branches

// visited array
 
for(int i=0;i<m;i++){    // adjacency matrix
  int x,y;
  cin>>x>>y;
  adj[x].push_back(y);
  adj[y].push_back(x);
}
    //  Given :- Root Node, eg. :- 1
   // DFS

    dfs(1);

return 0;
}