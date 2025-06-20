#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<vector<double>> ma, int up, int down, vector<double>que){
    int tim=0;
    while(up<=down){
        tim++;
        int m = up + (down-up)/2;
        if(ma[m][0] > que[0]){
            down = m-1;
        }
        else if(ma[m][0] < que[0]){
            up = m+1;
        }else{
             if(ma[m][1] > que[1]){
                down = m-1;
             }
             else if(ma[m][1] < que[1]){
                up = m+1;
             }
             else{
                 if(ma[m][2] > que[2]){
                    down = m-1;
                 }
                 else if(ma[m][2] < que[2]){
                    up = m+1;
                 }
                 else{
                    return tim;
                 }
             }
        }
    }
    return 0;
}
int main(){
    int n;cin>>n;
    vector<vector<double>> ma(n, vector<double>(3));
    for(int i =0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> ma[i][j];
        }
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        vector<double>que(3);
        for(int j=0;j<3;j++){
            cin >> que[j];
        }
        int tim = binarySearch(ma,0,n-1,que);
        if(tim==0) cout << "KHONG" << endl;
        else{cout << tim << endl;}
    }
    return 0;
}
