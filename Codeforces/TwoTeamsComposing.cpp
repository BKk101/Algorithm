#include <bits/stdc++.h>
using namespace std;

struct stud
{
	int num;
	int *arr;
	int *key;
	int *value;
};

void bubble_sort(int list[], int n);

int main()
{
	int i,j,k,t;
	cin>>t;
	int* answer = new int[t];
	stud stu[t];

	for(i=0;i<t;i++)
	{
		cin>>stu[i].num;
		stu[i].arr = new int[stu[i].num];
		stu[i].key = new int[stu[i].num];
		stu[i].value = new int[stu[i].num];
		memset(stu[i].value, 0, sizeof(int) * stu[i].num);
		for(j=0;j<stu[i].num;j++)
		{
			cin>>stu[i].arr[j];
			stu[i].key[j] = stu[i].arr[j];
		}
		bubble_sort(stu[i].arr, stu[i].num);
	}

	int same_elenum, dif_elenum,maxsize;
	int samenum,samepos;
	for(i=0;i<t;i++)
	{
		same_elenum = 0;
		dif_elenum = 0;
		for(j=0;j<stu[i].num;j++)
		{
			for(k=0;k<stu[i].num;k++)
			{
				if(stu[i].arr[j] == stu[i].key[k])
					stu[i].value[k]++;
			}
		}
		for(j=0;j<stu[i].num;j++)
		{
			if(stu[i].value[j] == 1)
				dif_elenum++;
			else if(stu[i].value[j] != 1 && stu[i].value[j] > same_elenum)
				same_elenum = stu[i].value[j];
		}
		for(j=0;j<stu[i].num;j++)
		{
			if(stu[i].value[j] != 1 && stu[i].value[j] != same_elenum)
				dif_elenum++;
		}
		
		if(same_elenum > stu[i].num / 2)
			maxsize = stu[i].num / 2;
		else
			maxsize = same_elenum;
		//print answer
		if(same_elenum > dif_elenum && same_elenum > maxsize)
			cout<<maxsize<<endl;
		else if(same_elenum == 0 && stu[i].num > 1)
			cout<<1<<endl;
		else if(maxsize > dif_elenum)
			cout<<dif_elenum<<endl;
		else
			cout<<maxsize<<endl;
		//cout<<same_elenum<<dif_elenum;
	}
	return 0;
}

void bubble_sort(int list[], int n){
  int i, j, temp;

  for(i=n-1; i>0; i--){
    for(j=0; j<i; j++){
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}