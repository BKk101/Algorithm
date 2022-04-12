#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct coordinate
{
    int idx;
    int xpos;
    int ypos;
};

void find_path(int xpos, int ypos, int **map)
{
    int i,j;

    for (i = 0;i <= ypos;i++)
        map[i][0] = 1;
    for (i = 0;i <= xpos;i++)
        map[0][i] = 1;
    for (i = 0;i <= ypos;i++)
    {
        for (j = 0;j <= xpos;j++)
        {
            if (map[i][j] == 0)
                map[i][j] = map[i - 1][j] + map[i][j - 1];
        }
    }
}

void find_path2(int xpos, int ypos, int **map, coordinate checkpoint)
{
    int i,j;

    for (i = checkpoint.ypos;i <= ypos;i++)
        map[i][checkpoint.xpos] = map[checkpoint.ypos][checkpoint.xpos];
    for (i = checkpoint.xpos;i <= xpos;i++)
        map[checkpoint.ypos][i] = map[checkpoint.ypos][checkpoint.xpos];
    for (i = checkpoint.ypos;i <= ypos;i++)
    {
        for (j = checkpoint.xpos;j <= xpos;j++)
        {
            if (map[i][j] == 0)
                map[i][j] = map[i - 1][j] + map[i][j - 1];
        }
    }
}

int main()
{
    int col;
    int row;
    int flag = 0;
    coordinate checkpoint = {0,-1,-1};

    cin>>col>>row>>checkpoint.idx;
    if (checkpoint.idx == 0)
    {
        checkpoint.idx = col * row;
        flag = 1;
    }
    checkpoint.xpos = (checkpoint.idx - 1) % row;
    checkpoint.ypos = (checkpoint.idx - 1) / row;
    
    int **map;
    int i;

    map = (int **)malloc(sizeof(int *) * col);
    for (i = 0;i < col;i++)
    {
        map[i] = (int *)malloc(sizeof(int) * row);
        memset(map[i], 0, sizeof(int) * row);
    }
    find_path(checkpoint.xpos, checkpoint.ypos, map);
    if (flag == 0)
        find_path2(row - 1, col - 1, map, checkpoint);
    cout<<map[col - 1][row - 1];
    return 0;
}