#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char *get_num(void)
{
    int size = 1;
    char buf;
    char *ptr;

    ptr = (char *)malloc(size);
    scanf("%c", &buf);
    for (;buf <= '9' && buf >= '0';)
    {
        ptr = (char *)realloc(ptr, size + 1);
        ptr[size - 1] = buf;
        ptr[size++] = '\0';
        scanf("%c", &buf);
    }
    return (ptr);
}

char *add_num(char *num1, char *num2)
{
    int tens = 0, units = 0;
    int short_len, long_len;
    char *short_num, *long_num;
    char buf[2] = {0};
    char *res;

    short_len = strlen(num1) <= strlen(num2) ? strlen(num1) : strlen(num2);
    long_len = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    short_num = strlen(num1) <= strlen(num2) ? num1 : num2;
    long_num = strlen(num1) > strlen(num2) ? num1 : num2;

    for (;short_len > 0;short_len--)
    {
        units = (tens + short_num[short_len - 1] + long_num[long_len - 1] - '0' - '0') % 10;
        tens = (tens + short_num[short_len - 1] + long_num[long_len - 1] - '0' - '0') / 10;
        long_num[long_len - 1] = units + '0';
        long_len--;
    }
    for (;long_len > 0;long_len--)
    {
        units = (tens + long_num[long_len - 1] - '0') % 10;
        tens = (tens + long_num[long_len - 1] - '0') / 10;
        long_num[long_len - 1] = units + '0';
    }
    if (tens != 0)
    {
        buf[0] = tens + '0';
        res = (char *)malloc(strlen(long_num) + 2);
        res = strcat(res, buf);
        res = strcat(res, long_num);
    }
    else
        res = long_num;
    return res;
}

int main()
{
    char *num1, *num2;
    char *sum;

    num1 = get_num();
    num2 = get_num();
    cout<<add_num(num1, num2);
    return 0;
}