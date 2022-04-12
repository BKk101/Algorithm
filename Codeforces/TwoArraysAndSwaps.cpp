#include <bits/stdc++.h>
using namespace std;

struct tcase
{
	int n;
	int k;
	int* a;
	int* b;
};

int find_min(int* a, int len)
{
	int min = a[0];
	int rtn = 0;
	for (int i=0;i<len;i++){
		if (a[i] < min){
			min = a[i];
			rtn = i;
		}
	}
	return rtn;
}

int find_max(int* a, int len)
{
	int max = a[0];
	int rtn = 0;
	for (int i=0;i<len;i++){
		if (a[i] > max){
			max = a[i];
			rtn = i;
		}
	}
	return rtn;
}

int main()
{
	int t;
	cin>>t;
	tcase temp;
	vector<tcase> arr;
	//input
	for (int i=0;i<t;i++){
		cin>>temp.n>>temp.k;
		temp.a = new int[temp.n];
		temp.b = new int[temp.n];
		for(int j=0;j<temp.n;j++){
			cin>>temp.a[j];
		}
		for(int j=0;j<temp.n;j++){
			cin>>temp.b[j];
		}
		arr.push_back(temp);
	}
	//output
	for (int i=0;i<t;i++){
		int minidx, maxidx, temp;
		for (int j=0;j<arr[i].k;j++){//swap
			minidx = find_min(arr[i].a, arr[i].n);
			maxidx = find_max(arr[i].b, arr[i].n);
			temp = arr[i].a[minidx];
			arr[i].a[minidx] = arr[i].b[maxidx];
			arr[i].b[maxidx] = temp;
		}
		int sum=0;
		for (int j=0;j<arr[i].n;j++){
			sum += arr[i].a[j];
		}
		cout<<sum<<endl;
	}
}