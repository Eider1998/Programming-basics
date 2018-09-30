#include<stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
    int a[N], i;

    for(i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, N - 1);

    for(i = 0; i < N; i++)
    {
        printf("%d%c", a[i], i == N - 1?'\n':' ');
    }
    return 0;
}

void quicksort(int a[], int low, int high)
{
    int middle;

    if(low >= high)
    {
        return ;
    }
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for( ; ; )
    {
        while(low < high && part_element <= a[high])
        {
            high--;
        }
        if(low >= high)
        {
            break;
        }
        a[low++] = a[high];
        while(low < high && part_element >= a[low])
        {
            low++;
        }
        if(low >= high)
        {
            break;
        }
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}
