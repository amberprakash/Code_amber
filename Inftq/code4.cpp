#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    if(n==1){
        return 0;
    }
    int temp;
    if(n%2==0){
        int x=n/2;
        temp=1+solve(x);
    }
    else{
        int x=(n*3)+1;
        temp=1+solve(x);
    }
    return temp;

}
int main(){
    cout<<solve(100)+1;
    return 0;
}