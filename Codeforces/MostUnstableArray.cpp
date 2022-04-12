#include <bits/stdc++.h>
using namespace std;

struct numset
{
	int n;
	int m;
};

int main()
{
	int t;
	numset temp;
	vector<numset> arr;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>temp.n>>temp.m;
		arr.push_back(temp);
	}
	for(int i=0;i<t;i++){
		if(arr[i].n == 1)
			cout<<0<<endl;
		else if(arr[i].n == 2)
			cout<<arr[i].m<<endl;
		else
			cout<<2 * arr[i].m<<endl;
	}
}