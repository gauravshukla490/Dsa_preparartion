#include<bits/stdc++.h>
using namespace std;

void sub(vector<int>&nums,vector<int>&arr,int target,int n,int k){
     int sum=0;
     if(k >= n){
        for(int x:arr){
            sum += x;
        }
        if(sum == target){
             for(int x:arr){
                 cout<<x<<" ";
             }
             cout<<endl;
        }
        return;
     }
     arr.push_back(nums[k]);
     sub(nums,arr,target,n,k+1);
     arr.pop_back();
     sub(nums,arr,target,n,k+1);
}

int main(){
    vector<int>nums={2,1,1,0};
    vector<int>arr;
    int n=nums.size();
     sub(nums,arr,2,n,0);
     return 0;
}