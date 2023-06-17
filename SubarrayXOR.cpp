#include<bits/stdc++.h>
using namespace std;
int solve(int* A, int n1, int B) {
    int xr=0;
    unordered_map<int,int>mpp;
    mpp[xr]++;//{0,1} add to map;
    int cnt=0;
    for(int i=0;i<n1;i++){
        xr=xr^A[i];
        int x=xr^B;
        cnt+=mpp[x];
        mpp[xr]++;
    }
}
