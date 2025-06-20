#include <bits/stdc++.h>
using namespace std;
int partition(long long a[], int l, int r,int b[]){
    long long pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while(1){
        do{
            ++i;
        }while(a[i]<pivot);
        do{
            --j;
        }while(a[j]>pivot);
        if(i<j) {swap(a[i],a[j]); swap(b[i],b[j]);}
        else return j;
    }
}
void QuickSort(long long a[], int l, int r, int b[]){
    if(l>=r) return;
    int p = partition(a,l,r,b);
    QuickSort(a,l,p,b);
    QuickSort(a,p+1,r,b);
}
int BinarySearch(long long a[], int n, long long x){
    int l = 0, r = n-1, ans=-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(a[m]==x) {ans= m; r=m-1;}
        else if(a[m] < x) l=m+1;
        else r = m-1;
    }
    return ans;
}
int BinarySearch2(long long a[], int n, long long x){
    int l = 0, r = n-1,ans=-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(a[m]==x) {
            ans = m;
            l = m+1;
        }
        else if(a[m] < x) l=m+1;
        else r = m-1;
    }
    return ans;
}
int main(){
    int N; cin >> N; long long a[N];
    int Q; cin >> Q; int b[N], xy[Q][2];
    for(int i=0;i<N;i++){
        cin >> a[i];
        b[i]=i+1;
    }
    for(int j=0;j<Q;j++){
    string s; cin >> s; cin >> xy[j][0] >> xy[j][1];}
    QuickSort(a,0,N-1,b);
    for(int j=0;j<Q;j++){
        if(xy[j][0] == 1){
           int s= BinarySearch(a,N,xy[j][1]);
           if(s!=-1){
            cout << b[s] << endl; continue;
           }else{cout << "-1" << endl;continue;}
        }else{
            int s= BinarySearch2(a,N,xy[j][1]);
            if(s!=-1){
                cout << b[s] << endl;continue;
            }else{
                cout << "-1" << endl; continue;
            }
        }
    }
}
