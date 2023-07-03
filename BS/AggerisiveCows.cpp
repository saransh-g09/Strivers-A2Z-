#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int>&a,int dist,int k){
    int cntcows=1,last=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]-last>=dist){
            cntcows++;
            last=a[i];

        }
        if(cntcows>=k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(stalls,mid,k)==true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}