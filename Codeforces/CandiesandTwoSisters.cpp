#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,cnt;
	cin>>t;
	int *arr = new int[t];
	for(i=0;i<t;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<t;i++)
	{
		if (arr[i]%2 == 0)
			cout<<arr[i]/2 - 1<<endl;
		else
			cout<<(arr[i]/2)<<endl;
	}
	return 0;
}