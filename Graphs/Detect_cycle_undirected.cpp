#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

bool isCycle(int i, vector<lli> adj[], bool vis[], int parent){
   vis[i]=true;
   for(auto j: adj[i]){
       if(j!=parent){
           if(vis[j])
           return true;
            if(!vis[j] && isCycle(j,adj,vis,i))
            return true;
           
       }
   }
   return false;
}
int main(){
    sync;
    lli n,m; cin>>n>>m;
   vector<lli> adj[n];
   for(lli i=0;i<m;i++)
   {
       lli x,y; cin>>x>>y; 
       
       adj[y].push_back(x);
       adj[x].push_back(y);
    
   }
   bool vis[n]={false};
   bool cycle = false;
   for(lli i=0;i<n;i++){
       if(!vis[i] && isCycle(i,adj,vis,-1))
       cycle = true;
   }
   if(cycle)
   cout<<"Present"<<endl;
   else cout<<"Not Present"<<endl;

    return 0;
}