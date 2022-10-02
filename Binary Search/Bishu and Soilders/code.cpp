#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>power(n);
	for(int i=0;i<n;i++){
		cin>>power[i];
	}
	int q;
	cin>>q;
	vector<int>bishuPower(q);
	for(int i=0;i<q;i++){
		cin>>bishuPower[i];
	}
	sort(power.begin(),power.end());
	
	for(int i=0;i<q;i++){
		int l=power[0];
		int h=power[n-1];
		int x=bishuPower[i];
		int pos=-1;
		if(x>h){
			int sum=0;
			int count=0;
			for(int j=0;j<n;j++){
				count++;
				sum+=power[j];
			}
			cout<<count<<" "<<sum<<endl;
			continue;
		}if(x<l){
			cout<<0<<" "<<0<<endl;
		}
		while(l<=h){
			int mid= l +(h-l)/2;
			if(power[mid]==x){
				pos=mid;
				break;
			}else if(power[mid]>x){
				h=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(pos==-1){
			l--;
			int sum=0;
			int count=0;
			for(int j=0;j<=l;j++){
				count++;
				sum+=power[j];
			}
			cout<<count<<" "<<sum<<endl;
		}else{
			int sum=0;
			int count=0;
			for(int j=0;j<=pos;j++){
				count++;
				sum+=power[j];
			}
			cout<<count<<" "<<sum<<endl;
		}

	}


	return 0;
}