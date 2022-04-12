#include <iostream>
#include <cstdlib>

using namespace std;

struct fertile_land
{
    int xpos;
    int ypos;
};

//함수 선언
int **init_map(int, int);
char **make_comb(int, int, int);
//void read_map(int ***);

int main()
{
    int row, col;
    int g_fertile_num, r_fertile_num;
    int fertile_land_num = 0;
    int i, j, k;    

    cin>>col>>row>>g_fertile_num>>r_fertile_num;

    int **map_col = init_map(row, col);

    for (i = 0; i < col; i++) //입력받기
    {
        for (j = 0; j < row; j++)
        {
            cin>>map_col[i][j];
            if (map_col[i][j] == 2)
                fertile_land_num++;
        }
    }

    fertile_land fertile_list[fertile_land_num]; //배양액 땅 리스트 만들기
    k = 0;
    for (i = 0; i < col; i++) //
    {
        for (j = 0; j < row; j++)
        {
            if (map_col[i][j] == 2)
            {
                fertile_list[k].xpos = j;
                fertile_list[k].ypos = i;
                k++;
            }
        }
    }

    char **g_comb = make_comb(fertile_land_num, g_fertile_num, r_fertile_num);//조합 만들기


}

char **make_comb(int fertile_land_num, int g_fertile_num, int r_fertile_num)
{
    int i, g_sum = 1, r_sum = 1;
    char **res;

    for (i = fertile_land_num;i > 0;i--)
        g_sum *= i;
    for (i = g_fertile_num;i > 0;i--)
        g_sum /= i;
    
    for (i = fertile_land_num - g_fertile_num;i > 0;i--)
        r_sum *= i;
    for (i = r_fertile_num;i > 0;i--)
        r_sum /= i;
    
    res = (char **)malloc(sizeof(char *) * (g_sum + r_sum));
    for (i = 0;i < g_sum + r_sum;i++)
        res[i] = (char *)malloc(sizeof(char) * g_fertile_num + r_fertile_num);
    comb(res[0], fertile_land_num, g_fertile_num, 0);
    return (res);
}

void comb(char *str, int total, int pick, int state)
{
    int i;

    if (state == pick)
        return ;
    for (i = state;i < total - state + 1; i++)
        comb(str + 1, total, pick, state + 1);
    str[state] = i + '0';
}

int **init_map(int row, int col)
{
    int i = 0;

    int **map_col = (int **)malloc(sizeof(int *) * col); //맵생성
    while (i < col)
    {
        map_col[i] = (int *)malloc(sizeof(int) * row);
        i++;
    }
    return (map_col); 
}

