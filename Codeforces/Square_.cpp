#include <bits/stdc++.h>
using namespace std;

struct rec{
	int wid;
	int hei;
};

int main() {
   int testcase,flag=0;
   int num1, num2;
   cin>>testcase;
   rec* ptr= new rec[testcase*2];
   for(int i=0;i<testcase;i++){
		cin>>ptr[2*i].wid>>ptr[2*i].hei;
		cin>>ptr[2*i+1].wid>>ptr[2*i+1].hei;
   }
   for(int i=0;i<testcase;i++){
	   flag = 0;
	   int area1 = ptr[2*i].wid * ptr[2*i].hei;
	   int area2 = ptr[2*i+1].wid * ptr[2*i+1].hei;
	   for (int i=1;i<142;i++){
		   if (sqrt(area1 + area2) == i){
			   cout<<"Yes"<<endl;
			   flag=1;
			   break;
		   }
	   }
	   if(flag == 0){
	   		cout<<"No"<<endl;
	   }
   }
    return 0;
}
