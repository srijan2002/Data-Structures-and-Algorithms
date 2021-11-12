#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

void swap(int a[], int i, int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[], int l, int r){
    int i = l-1; int pivot = a[r]; int j;
    for(j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,r);
    return (i+1);
}
void QuickSort(int a[], int l,int r){
    if(l<r){
        int pivot = partition(a,l,r);
        QuickSort(a,0,pivot-1);
        QuickSort(a,pivot+1,r);
    }
}

int main(){
    sync;
    int n; cin>>n; int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    QuickSort(a,0,n-1);
    for(auto i:a)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}