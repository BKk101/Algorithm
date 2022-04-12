#include <bits/stdc++.h>
using namespace std;

int b_search(int n1, int n2, int max)
{
	int mid = (n1 + n2) / 2;
	int answer;

	if (n1 >= n2)
		return mid;
	if (mid * 2 <= max)
		answer = b_search(mid + 1, n2, max);
	else
		answer = b_search(n1, mid - 1, max);
	return answer;
}

int main()
{
	int tcase;
	int temp;
	vector<int> list;

	cin>>tcase;
	for(int i=0;i<tcase;i++){
		cin>>temp;
		list.push_back(b_search(1, temp, temp));
	}
	for(int i=0;i<tcase;i++){
		cout<<list[i]<<endl;
	}
	return 0;
}