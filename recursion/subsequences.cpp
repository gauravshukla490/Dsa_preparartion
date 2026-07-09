#include <bits/stdc++.h>
using namespace std;



void solve(int idx,int n,vector<int>ans,vector<int>&arr){
    if(idx==n){
       for(int x:ans){
        cout<<x<<" ";
       }
       cout<<endl;
       return;
    }
    ans.push_back(arr[idx]);
    solve(idx+1,n,ans,arr);
    ans.pop_back();
    solve(idx+1,n,ans,arr);
}

int main(){
   vector<int>arr;
   arr.push_back(3);
   arr.push_back(1);
   arr.push_back(2);
   arr.push_back(4);
   vector<int>ans;

   solve(0,4,ans,arr);
   return 0;
}