#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

void make_sets(lli i, lli parent[], lli size[]){
    parent[i]=i;
    size[i]=1;
}

int find_set(lli i, lli parent[]){
    if(i == parent[i]) // leading element of set
    return i;
    
    return parent[i]=find_set(parent[i],parent);
}

void union_sets(lli a, lli b, lli parent[], lli size[]){
    lli x = find_set(a,parent); lli y = find_set(b,parent);
    if(x!=y){
        if(size[x]<size[y])
        swap(x,y);

        size[x]+=size[y];
        parent[y]=x;
    }
}

int main(){
    sync;
      lli n,m; cin>>n>>m;
      lli parent[n]; lli size[n];
   vector<lli> adj[m];
   for(lli i=0;i<m;i++)
   {
       lli x,y; cin>>x>>y; 
       
      adj[i].push_back(x); adj[i].push_back(y);
    
   }
   for(lli i=0;i<n;i++)
   {
       make_sets(i,parent,size);
   }
   bool cycle =false;
   for(lli i=0;i<m;i++){
       lli x = adj[i][0];
       lli y = adj[i][1];
       lli a = find_set(x,parent); lli b = find_set(y,parent);
       if(a==b){
           cycle=true; break;
       }
       else{
           union_sets(a,b,parent,size);
       }

   }
   if(cycle)
   cout<<"Cycle"<<endl;
   else cout<<"No Cycle"<<endl;

    return 0;
}