#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, temp;
	cin>>t;
	vector<int> arr;
	for(int i=0;i<t;i++){//input
		cin>>temp;
		arr.push_back(temp);
	}
	for(int i=0;i<t;i++){//output
		long long sum = 0;
		for(int j=1;j<=arr[i]/2;j++){
			sum += j * (pow(2*j + 1, 2) - pow(2*(j-1) + 1, 2));
		}
		cout<<sum<<endl;
	}
}