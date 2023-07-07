#include<vector>
#include<bits/stdc++.h>
using namespace std;

    
// BRUTE FORCE METHOD: 
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n=a.size();
	int m= b.size();
	vector<long long> c;
	
	int left,right=0;
	while(left<n && right<m){
		if(a[left]<= b[right]){
			c.push_back(a[left]);
			
			left++;

		}
		else{
			c.push_back(b[right]);
			right++;
		}
	}
	// if right array is exhausted
	while(left<n){
		c.push_back(a[left]);
		left++;

	}
	while(right<m){
		c.push_back(b[right]);
		right++;
	}
	for(int i=0;i<n+m;i++){
		if(i<n) a[i]=c[i];
		else b[i-n]=c[i];
	}
	
}

//OPTIMAL APPROACH 1:

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
    int n=a.size();
    int m=b.size();
    int left =n-1;
    int right=0;
    while(left>=0 && right<m){
        if(a[left]>b[right]){
            swap(a[left],b[left]);
        }
        else{
            break;
        }
    }

    sort(a.begin(),a.end());
    sort(b.begin() ,b.end());
}

// OPTIMAL APPROACH 2 : Shell sort technique --> gap method
 
void swapIfGreater(vector<long long>a,vector<long long>b ,int ind1 ,int ind2){
    if(a[ind1]>b[ind2]){
        swap(a[ind1],b[ind2]);
    }

}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
    int n=a.size();
    int m=b.size();
    int len = (n + m);
    int gap = (len/2) + len%2; // if the lenght is odd so to get ceil value
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // left is in a & right is in b vector
            if(left<n && right>=n){
                swapIfGreater(a , b,left, right-n);
            }
            // left & right are in same vector b
            else if(left>=n){ 
                swapIfGreater(b,b,left-n,right-n);

            }
            // left && right in same vector a
            else{
                swapIfGreater(a ,a ,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;
        else gap=(gap/2)+ gap%2;
    }
}
