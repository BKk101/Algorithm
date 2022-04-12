#include <iostream>
using namespace std;

int map_size = 0;
int total_addr = 0;
int addr_count[320] = {0};

void put_addrnum(char **map, int xpos, int ypos)
{
    if ( xpos == -1 || ypos == -1 || xpos == map_size || ypos == map_size)
        return ;
    if (map[ypos][xpos] == '1')
    {
        map[ypos][xpos] = '0' + total_addr + 1;
        addr_count[total_addr - 1]++;
    }
    else
        return ;    
    put_addrnum(map, xpos + 1, ypos);
    put_addrnum(map, xpos - 1, ypos);
    put_addrnum(map, xpos, ypos + 1);
    put_addrnum(map, xpos, ypos - 1);
}

void bubble_sort(int *tab, int size)
{
	int i;
	int temp;

	for (;size - 1 > 0;size--)
    {
        for (i = 0;i < size - 1;i++)
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
            }
        }
    }
}

int main()
{
    char **map;
    int i,j;

    cin>>map_size;
    map = new char*[map_size];
    for (i = 0;i < map_size;i++)
        map[i] = new char[map_size + 1];
    for (i = 0;i < map_size;i++) //입력받기
    {
        cin>>map[i];
    }
    for (i = 0;i < map_size;i++) //주소 붙이기
    {
        for (j = 0; j < map_size;j++)
        {
            if (map[i][j] == '1')
            {
                total_addr++;
                put_addrnum(map, j, i);
            }
        }
    }
    /*
    cout<<endl;
    for (i = 0;i < map_size;i++) //변환결과 확인
    {
        for (j = 0; j < map_size;j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
    }
    */
    cout<<total_addr<<endl;
    bubble_sort(addr_count, total_addr);
    for (i = 0;i < total_addr;i++)
    {
        cout<<addr_count[i]<<endl;
    }
    return 0;
}