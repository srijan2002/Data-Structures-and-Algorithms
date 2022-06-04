#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
 
void topological_sort(bool vis[], stack<lli>& S, lli i,vector<lli> adj[]){
      vis[i] = true;
      for(auto j :adj[i]){
          if(!vis[j])
          topological_sort(vis,S,j,adj);
      }
      S.push(i);
}

void topological(lli n, vector<lli> adj[]){
    bool vis[n]; stack<lli> S;
    for(lli i=0;i<n;i++)
    vis[i]=false;

    for(lli i=0;i<n;i++){
        if(!vis[i])
        topological_sort(vis,S,i,adj);
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;
}

int main(){
    sync;
   lli n,m; cin>>n>>m;
   vector<lli> adj[n];
   for(lli i=0;i<m;i++)
   {
       lli x,y; cin>>x>>y; 
       
       adj[y].push_back(x);
    
   }
   topological(n,adj);
 
    return 0;
}