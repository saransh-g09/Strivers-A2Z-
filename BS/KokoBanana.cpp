#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMax(vector<int>&v){
        int maxi=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }
    long long findTotalHrs(vector<int>&v,int m){
        int n=v.size();
        long long totalH=0;
        for(int i=0;i<n;i++){
            totalH +=ceil((double)v[i]/(double)m);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
            long long mid=(low+high)/2;
            long long totalHrs=findTotalHrs(piles,mid);
            if(totalHrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};