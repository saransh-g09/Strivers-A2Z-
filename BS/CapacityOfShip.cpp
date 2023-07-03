#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int>&a){
        int n=a.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(a[i],maxi);
        }
        return maxi;
    }
    bool possible(vector<int>&arr,int div ,int target){
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)arr[i]/(double)div);
        }
        return sum<=target;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=findMax(nums);
        while(low<=high){
            long long mid=(low+high)/2;
            if(possible(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};