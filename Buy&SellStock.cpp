#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // size of the array
        int n=prices.size();
        // initially minimum would be at the first index of array.
        int mini=prices[0]; 
        // so we don't want profit to be neg. so we would sell an buy at same day to avoid loss. so we are setting profit to be 0.
        int profit=0;
        //travesing array
        for(int i=0;i<n;i++){
            
            int cost=prices[i]-mini;
            profit=max(cost,profit);
            mini=min(prices[i],mini);
        }
        return profit;
    }
};