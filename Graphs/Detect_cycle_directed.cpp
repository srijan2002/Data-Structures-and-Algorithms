#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
bool isCycle(bool stack[],bool vis[],lli i, vector<lli> adj[]){
    stack[i]=true;
    if(!vis[i]){
        vis[i]=true;
        for(auto j:adj[i]){
            if(!vis[j] && isCycle(stack,vis,j,adj))
            return true;

            if(stack[j])
            return true;
        }
    }
    stack[i]=false;
    return false;
}
int main(){
    sync;
     lli n,m; cin>>n>>m;
   vector<lli> adj[n];
   for(lli i=0;i<m;i++)
   {
       lli x,y; cin>>x>>y; 
       
       adj[x].push_back(y);
    
   }
   bool cycle=false; bool stack[n]; bool vis[n];
   for(lli i=0;i<n;i++){
       stack[i]=false; vis[i]=false;
   }
   for(lli i=0;i<n;i++){
       if(!vis[i] && isCycle(stack,vis,i,adj))
       cycle=true;
   }
   if(cycle)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
    return 0;
}