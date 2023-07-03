#include<bits/stdc++.h>
using namespace std;
long long sum(vector<int>&a,int divs){
	long long sum=0;
	for(int i=0;i<a.size();i++){
		sum+=ceil((double)a[i]/(double)divs);
	}
	return sum;
}
int smallestDivisor(vector<int>& arr, int limit)
{	
	int n=arr.size();
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		maxi=max(maxi,arr[i]);
	}
	int low=1;
	int high=maxi;
	int ans=-1; // if the doesn't exist a divisior then return -1
	while(low<=high){
		long long mid=(low+high)/2;
		if(sum(arr,mid)<=limit){ //this condition is true,so we have a divisor but to we want smallest so high=mid-1
			ans=mid;
			high=mid-1;

		}
		else{
			low=mid+1;
		}

	}
	return ans;
}