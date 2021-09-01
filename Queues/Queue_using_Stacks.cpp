#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
struct Queue {
    stack<int> s1, s2;
 
    void enQueue(int x)
    { 
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
  
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int deQueue()
    {
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};
 
int main()
{
    Queue q;
     int c;cin>>c;
     while(c!=0){
         if(c==1){
             int d;cin>>d;
             q.enQueue(d);
         }
         if(c==2)
         {
             cout<<q.deQueue()<<endl;
         }
         if(c==0)
         break;

         cin>>c;
     }
 
 
    return 0;
}