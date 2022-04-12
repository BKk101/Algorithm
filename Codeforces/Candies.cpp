#include <bits/stdc++.h>
using namespace std;


int main()
{
	int test, temp, flag = 0;

	cin>>test;
	vector <int> input;
	vector <int> binary;

	for(int i=0;i<test;i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	for(int i=0;i<30;i++){
		binary.push_back(pow(2,i));
	}
	for (int i=0;i<test;i++){
		int sum = 1;
		for(int j=1;j<30;j++){
			sum += binary[j];
			if((input[i] % sum) == 0){
				cout<<input[i] / sum<<endl;
				break;
			}
		}
	}
	return 0;
}