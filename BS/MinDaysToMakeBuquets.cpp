#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(vector<int>&arr,int day,int m,int k){
        int count=0;
        int noofB=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                count++;
            }
            else{
                noofB +=(count/k);
                count=0;
            }

        }
        noofB +=(count/k);
        return noofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        int n=bloomDay.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
             mini=min(mini,bloomDay[i]);
             maxi=max(maxi,bloomDay[i]);
        }
        int low=mini,high=maxi;
        while(low<=high){
            long long mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;

            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};