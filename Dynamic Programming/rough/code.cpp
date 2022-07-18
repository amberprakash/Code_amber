#include<bits/stdc++.h>
using namespace std;
int result;
unordered_map<int,int> mp;
int target;
    void get_result(vector<int>& nums)                          
    {
        int sum=0;
        mp.clear();
        mp[0]++;
        for(int &i:nums)
        {
            sum+=i;
            result+=mp[sum-target];       
            mp[sum]++;                   
        }
    }
int main(){
    
    target=7;
    vector<int>arr={3,4,7,2,-3,1,4,2,1};
    result=0;
    get_result(arr);
    cout<<result;
    
    
    return 0;
}