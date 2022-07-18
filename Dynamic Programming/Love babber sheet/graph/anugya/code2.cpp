#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool canDivide(vector<int> c,ll mid, int n){
    ll count=0;
    for(auto& e : c){
        while(true){
            ll division=min(mid,(ll)e);
            if(division==0)
                break;
            ll q=e/division;
            if(q>0){
                count+=q;
                if(count>n){
                    return false;
                }
                e-=q*division;
            }
        }
    }
    return true;
}

int binarySearch(vector<int>& c, ll high,int n){
    ll low=1;
    ll ret=high;
    while(low<=high){
        ll mid=(low+high)/2;
        if(!canDivide(c,mid,n)){
            low=mid+1;
        }else{
            ret=min(ret,mid);
            high=mid-1;
        }
    }
    return ret;
}

int main() {
    //  n= number of students
    //  m= number of different colour
    //  color[i] represent no. of balls of that color
    //  you have to find maximum no. of balls we can give to each student
    //  one student must have all same color ball
	int n,m,h;
    h=0;
    scanf("%d%d",&n,&m);
    vector<int> color(m,0);
    for(int i=0;i<m;i++){
        scanf("%d",&color[i]);
        h=max(h,color[i]);// maximum no. of ball of perticular color
    }
    printf("%d\n",binarySearch(color,h,n));
    return 0;
}

