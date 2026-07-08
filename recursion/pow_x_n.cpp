#include<bits/stdc++.h>
using namespace std;

long long power(int x , int n){
    if(n==0) return 1;
    return x * power(x,n-1);
}

int main(){
    int x;
    cin>>x;
    int n;
    cin>>n;

    long long ans= power(x,n);
    cout<<ans;

    return 0;
}