#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool check(int i,int j,int n){
    if(i<0 || j<0 || i>=n || j>=n){
        return false;
    }
    return true;
}
int minstep(int n,int end1,int end2){
    vector<vector<int>>visited(n,vector<int>(n,false));
    pair<int,int> start={0,0};
    pair<int,int> end={end1,end2};
    vector<pair<int,int>> cord = { {-1,2} , {1,2} , {-1,-2} , {1,-2} ,
	                                   {2,1} ,{2,-1} , {-2,-1} , {-2 , 1} };
    queue<pair<int,int>>q;
    q.push(start);
    int level=0;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(end==q.front()){
                return level;
            }
            for(int k=0;k<8;k++){
                int p=cord[k].first;
                int q=cord[k].second;
                if(!visited[x+p][y+q] && check(x+p,y+q,n)){
                    pair<int,int>temp={x+p,y+q};
                    q.push(temp);
                    visited[x+p][y+q]=true;
                }
            }

        }
        level++;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int end1,end2;
    cin>>end1>>end2;
    

    return 0;

}