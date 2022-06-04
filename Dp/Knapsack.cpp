#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
int dp[1000][1000];
int Knapsack(int n,int w, int wt[], int val[]){
    if(n<=0)
    return 0;
    if(w<=0)
    return 0;
    if(dp[n][w]!=-1)
    return dp[n][w];

    if(wt[n-1]>w)
    dp[n][w] =  Knapsack(n-1,w,wt,val);
    else
   dp[n][w] =  max(Knapsack(n-1,w,wt,val), Knapsack(n-1,w-wt[n-1],wt,val)+val[n-1]);

   return dp[n][w];

}

int main(){
    sync;
    int n; cin>>n;
    int wt[n]; int val[n];
    for(int i=0;i<n;i++)
    cin>>wt[i];
     for(int i=0;i<n;i++)
    cin>>val[i];

    int w;
    cin>>w;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j] = -1;
        }
    }
    cout<<Knapsack(n,w,wt,val)<<endl;
    return 0;
}