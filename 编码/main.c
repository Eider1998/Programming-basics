#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[10000];
    int i, n, a[10000], k;

    while(gets(str))
    {
        memset(a, 0, sizeof(a));
        n = strlen(str);
        for(i = 0; i < n; i++)
        {
            for(k = i + 1; str[k] == str[i]; k++)
            {
                a[i]++;
            }
            if(a[i] + 1 > 1)
            {
                printf("%d", a[i] + 1);
            }
            printf("%c", str[i]);
            i = k - 1;
        }
        printf("\n");
    }
    return 0;
}
