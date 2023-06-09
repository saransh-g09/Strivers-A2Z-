#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    vector<int>ans;
    int left=low;
    int right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
            ans.push_back(arr[right]);
        }
        while(left<=mid){
            ans.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            ans.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=ans[i-low];
        }
    }
}
void mergeSort(int arr[],int low,int high){
    if(low>=high){ 
        return;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    mergeSort(arr,low,high);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}


