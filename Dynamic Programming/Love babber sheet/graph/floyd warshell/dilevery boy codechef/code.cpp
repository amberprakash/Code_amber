#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>cost(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    //Floyd Warshell 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int dist=cost[j][i]+cost[i][k];
                if(dist<cost[j][k]){
                    cost[j][k]=dist;
                }
            }
        }
    }
    int m;
    cin>>m;
    while(m--){
        int s,g,d;
        cin>>s>>g>>d;
        int t1=cost[s][g]+cost[g][d];
        int t2=cost[s][d];
        cout<<t1<<" "<<t1-t2<<endl;
    }

    return 0;
}