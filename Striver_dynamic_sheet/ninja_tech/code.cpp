#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int day,int last,vector<vector<int>>&points,vector<vector<int>>&t){
    if(day==0){
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(t[day][last]!=-1){
        return t[day][last];
    }
    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[day][i]+solve(day-1,i,points,t);
            maxi=max(maxi,point);
        }
    }
    return t[day][last]=maxi;
}
int maximumskills(int n,vector<vector<int>>&points,vector<vector<int>>&t){
    return solve(n-1,3,points,t);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>points(n,vector<int>(3));
    vector<vector<int>>t(n+1,vector<int>(4,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }
    cout<<maximumskills(n,points,t);
    return 0;
}