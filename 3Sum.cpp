#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        int i,j,k;
        for( i=0;i<n-2;i++){
            for(j=i+1;j<n-1;j++){
                for(k=j+1;k<n;k++){
                    temp.clear();
                    if(nums[i]+nums[j]+nums[k]==0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                    }
                    if(temp.size()!=0){
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};