#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

class MyArray
{
public:
    MyArray()
    {
        arr = NULL;
        arr_size = -1;
    }
    ~MyArray()
    {
        if (arr != NULL)
            free(arr); // if you use "malloc" to allocate memory
                       // or you can use c++ style: "delete" corresponding to "new"
        arr_size = -1;
    }
    void new_arr(int n);
    void segment_move(int a, int b, int k);
    void segment_reverse(int a, int b);
    void print();

private:
    // private variable only used by public function
    // means, a.arr is error, a is MyArr
    int *arr;
    int arr_size;
};

void MyArray::new_arr(int n)
{
    if (arr != NULL)
        free(arr);
    arr_size = n;
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i ++)
        arr[i] = i + 1;
}

void MyArray::segment_move(int a, int b, int k)
{
    int start, end, pos;
    for (int i = 0; i < arr_size; i ++)
    {
        if (arr[i] == a) start = i;
        if (arr[i] == b) end   = i;
        if (arr[i] == k) pos   = i;
    }
    int *tmp_arr = (int *)malloc(arr_size * sizeof(int));
    int j = 0;
    for (int i = 0; i < start; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = end + 1; i <= pos; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = start; i <= end; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = pos + 1; i < arr_size; i ++, j ++)
        tmp_arr[j] = arr[i];

    free(arr);
    arr = tmp_arr;
}

void MyArray::segment_reverse(int a, int b)
{
    int start, end;
    for (int i = 0; i < arr_size; i ++)
    {
        if (arr[i] == a) start = i;
        if (arr[i] == b) end   = i;
    }

    int temp;
    for (int i = 0; i < (end - start + 1) / 2; i++ )
    {
        temp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

void MyArray::print()
{
    printf("%d", arr[0]);
    for (int i = 1; i < arr_size; i ++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main()
{

    int t;
    int n, m;
    int a, b, k;
    scanf("%d", &t);
    while (t --)
    {
        MyArray m_arr;
        scanf("%d %d", &n, &m);
        m_arr.new_arr(n);
        while ( m -- )
        {
            char type[10];
            scanf("%s", type);
            if (type[0] == 'm')
            {
                scanf("%d %d %d", &a, &b, &k);
                m_arr.segment_move(a, b, k);
            } else {
                scanf("%d %d", &a, &b);
                m_arr.segment_reverse(a, b);
            }
        }
        m_arr.print();
    }
    return 0;
}

