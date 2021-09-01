 #include<bits/stdc++.h>
#include<stack>
typedef long long int lli;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 int t=0;cin>>t;
 while(t!=0){
 
 int n;
 cin>>n;
 lli a[n]; int s[n]; int h[n]; int x[n];
  
 for(int i=0;i<n;i++)
 cin>>a[i];

stack<int> S;// Stack stores the indices

s[0]=0;
S.push(0);
for(int i=1;i<n;i++)
{
    s[i]=0;
    while(S.empty()==false && a[i]>=a[S.top()]){ // popping the indices out of the stack who's price is <= a[i]
    if(a[i]==a[S.top()])
    s[i]=s[S.top()]+1;  // ONE MORE THAN THE NUMBER OF SAME HEIGHT ALREADY SEEN BY THE PREVIOUS

    S.pop();
    
    }

    S.push(i);  //push the current index for future comparison with next price
}
 stack<int> P;// Stack stores the indices

  x[n-1]=0;
    P.push(n-1);
    for(int i=n-2;i>=0;i--)
    {  
        x[i]=0;
        
        while(P.empty()==false && a[i]>=a[P.top()]){  // popping the indices out of the stack who's price is <= a[i]
         if(a[i]==a[P.top()])
          x[i]=x[P.top()]+1; //ONE MORE THAN THE NUMBER OF SAME HEIGHT ALREADY SEEN BY THE PREVIOUS
        P.pop();
        }

        P.push(i);  //push the current index for future comparison with next price
    }

 
for(int i=0;i<n;i++)
{
    h[i]=s[i]+x[i];
    cout<<h[i]<<" ";
}
t--;
}
    return 0;
}