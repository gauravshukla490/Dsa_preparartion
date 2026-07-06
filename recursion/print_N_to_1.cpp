#include <bits/stdc++.h>
using namespace std;

void print(int n){
    cout<<n<<" ";
    if(n==1) return;
    print(n-1);
}

int main(){
    int n=10;
    print(10);
    return 0;

}