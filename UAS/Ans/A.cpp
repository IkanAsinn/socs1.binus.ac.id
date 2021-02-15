#include <stdio.h>

struct Data {
    int id;
    char name[50];
    double inch;
    double foot;
    double cm;
};

void merge(Data* arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    Data arrLeft[leftSize], arrRight[rightSize];

    for (int i = 0; i < leftSize; i++)
        arrLeft[i] = arr[left + i];
    
    for (int i = 0; i < rightSize; i++)
        arrRight[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize)
    {
        if (arrLeft[i].cm < arrRight[j].cm)
            arr[k++] = arrLeft[i++];
        else if(arrLeft[i].cm > arrRight[j].cm)
            arr[k++] = arrRight[j++];
        else
        {
            if (arrLeft[i].id > arrRight[j].id)
                arr[k++] = arrLeft[i++];
            else
                arr[k++] = arrRight[j++];
        }
    }

    while (i < leftSize)
        arr[k++] = arrLeft[i++];
    while (j < rightSize)
        arr[k++] = arrRight[j++];
}

void mergeSort(Data* arr, int left, int right) {
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int last(Data* arr, int left, int right, double target) {
    int idx = -1;

    while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid].cm <= target)
            {
                idx = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
    return idx;
}

int main() {

    int n;
    scanf ("%d", &n); getchar();

    Data data[n];

    for (int i = 0; i < n; i++)
    {
        scanf ("%d,%[^,],%lf %lf", &data[i].id, data[i].name, &data[i].foot, &data[i].inch);
        getchar();
        data[i].cm = (data[i].foot * 12 * 2.54) + (data[i].inch * 2.54);
    }

    mergeSort(data, 0, n - 1);

    int tc;
    scanf("%d", &tc); getchar();

    for (int q = 1; q <= tc; q++)
    {
        double target;
        scanf ("%lf", &target);
        int start = last(data, 0, n - 1, target);
        printf("Q%d:\n", q);

        if (start == -1)
            puts("-1");

        else
        {
            for (int i = start; i >= 0; i--)
                printf ("%d %s %.2lf\n", data[i].id, data[i].name, data[i].cm);
        }
    }

    return 0;
}

/*
5
1,John Doe,4 6
2,Anonymous,5 4
3,Vohu Manah,6 1
4,Dora Hariwini,5 4
5,Kyo,6 7
3
165
130
200
*/