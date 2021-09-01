 #include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

void calculateSpan(int price[], int n, int span[])
{

    stack<int> S;
    S.push(0);

    span[0] = 1;

    for (int i = 1; i < n; i++) {
   
        while (!S.empty() && price[S.top()] <= price[i])
            S.pop();

        span[i] = (S.empty()) ? (i + 1) : (i - S.top());
        S.push(i);
    }
}
 
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    sync;
    int n;cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++)
    cin>>a[i];
    int span[n];
    calculateSpan(a, n, span);
  
    printArray(span, n);
 
    return 0;
}