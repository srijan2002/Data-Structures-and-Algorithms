#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
class Stack {
    queue<int> q1, q2; int curr_size;
public:
    Stack()
    {
        curr_size = 0;
    }
    void push(int x)
    {
        curr_size++;
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1; q1 = q2; q2 = q;
    }
  
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }
  
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
  
    int size()
    {
        return curr_size;
    }
};
  
// Driver code
int main()
{
    Stack s;
    int c;cin>>c;
    while(c!=0){
        if(c==1)
        {
            int d;cin>>d;
            s.push(d);
        }
        if(c==2)
        s.pop();
        if(c==3)
        cout<<s.top()<<endl;
        if(c==4)
        cout<<s.size()<<endl;
        if(c==0)
        break;

        cin>>c;
    }
    return 0;
}