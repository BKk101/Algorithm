#include <iostream>

using namespace std;

int main()
{
    int num;
    int i,j;

    cin>>num;
    for(i = 0;i < num;i++)
    {
        for(j = 0;j <= i;j++)
            cout<<"*";
        for(;j < num;j++)
            cout<<" ";  
        for(j = 0;j < num - (i+1);j++)
            cout<<" ";
        for(;j < num;j++)
            cout<<"*";
        cout<<endl;
    }
    for(i = 1;i < num;i++)
    {
        for(j = 0;j < num - i;j++)
            cout<<"*";
        for(;j < num;j++)
            cout<<" ";  
        for(j = 0;j < i;j++)
            cout<<" ";
        for(;j < num;j++)
            cout<<"*";
        cout<<endl;
    }
    return 0;
}