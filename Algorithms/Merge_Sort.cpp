#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

void Merge(int a[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid; int a1[n1]; int b1[n2];
    for(int i=0;i<n1;i++){
        a1[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        b1[i]=a[mid+1+i];
    }
    int x=0;int y=0;int z=l;
    while(x<n1 && y<n2){
        
        if(a1[x]<b1[y]){
            a[z]=a1[x];
           x++; z++;
        }
        else{
            a[z]=b1[y];
          y++; z++;
        }
      
    }
    while(x<n1){
        a[z++]=a1[x++];
            
    }
     while(y<n2){
        a[z++]=b1[y++];
           
    }
    
}
void MergeSort(int a[],int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        MergeSort(a,l,mid); MergeSort(a,mid+1,r);
        Merge(a,l,mid,r);
    }
    else
    return;
}
int main(){
    sync;
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}