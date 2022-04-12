#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testcase, temp = 0;

	cin>>testcase;
	int* input[testcase];
	vector <int> n;

	for(int i=0;i<testcase;i++)
	{
		cin>>temp;
		n.push_back(temp);
		input[i] = new int[temp];
		for(int j=0;j<temp;j++){
			cin>>input[i][j];
		}
	}
	for(int i=0;i<testcase;i++){
		
		long long sum = 0;
		int max;

		if (input[i][0] > 0)
			max = 0;
		else
			max = -pow(10,9);
		if(input[i][0] > max)
			max = input[i][0];
		for(int j=1;j<n[i];j++){
			if(input[i][j-1] < 0 && input[i][j] > 0 || input[i][j-1] > 0 && input[i][j] < 0){
				sum+=max;
				if (input[i][j] > 0)
					max = 0;
				else
					max = -pow(10,9);
			}
			if(input[i][j] > max)
				max = input[i][j];
		}
		sum+=max;
		cout<<sum<<endl;
	}
}
