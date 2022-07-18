#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int minCost(vector<pair<int,int>>&points){
    int n=points.size();
    // min-heap to store min value edge at top
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
    
    vector<bool>inMST(n,0);
    heap.push({0,0});

    int mstCost=0;
    int edgused=0;

    while(edgused<n){
        pair<int,int>topElement=heap.top();
        heap.pop();
        int weight=topElement.first;
        int currNode=topElement.second;
        if(inMST[currNode]){
            continue;
        }
        inMST[currNode]=true;
        mstCost+=weight;
        edgused++;
        for(int nextNode=0;nextNode<n;nextNode++){
            if(!inMST[nextNode]){
                int nextWeight= abs(points[currNode].first - points[nextNode].first) +
                                abs(points[currNode].second - points[nextNode].second);
                heap.push({nextWeight,nextNode});                
            }  
        }

    }
    return mstCost;

}
int main(){
    vector<pair<int,int>>points;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        points.push_back({a,b});
    }
    cout<<minCost(points);
    return 0;
}
// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20