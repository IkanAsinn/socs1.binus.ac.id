#include <stdio.h>
#include <string.h>

struct Data {
    char accNum[5];
    char name[50];
    int age;
    double balance;
};

int contains(Data* arr, int low, int high, char* target) {
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (strcmp(arr[mid].accNum, target) < 0)
            low = mid + 1;

        else if (strcmp(arr[mid].accNum, target) > 0)
            high = mid - 1;

        else
        {
            ans = mid;
            break;
        }
    }

    return ans;
}

int main() {

    int n;
    scanf ("%d", &n); getchar();
    
    Data data[n];

    for (int i = 0; i < n; i++)
    {
        scanf ("%[^,],%[^,],%d,%lf", data[i].accNum, data[i].name, &data[i].age, &data[i].balance);
        getchar();
    }

    int tc;
    scanf("%d", &tc); getchar();

    for (int q = 1; q <= tc; q++)
    {
        char target[5];
        scanf ("%s", target); getchar();

        int pos = contains(data, 0, n - 1, target);

        if (pos == -1)
            puts("-1");

        else
            printf ("%s %d %.2lf\n", data[pos].name, data[pos].age, data[pos].balance);
    }

    return 0;
}

/*
5
ANGE,Andrew Garfield,18,110933.25
HAIS,SpectraVgeist,18,25000.00
NERA,Frankie,16,999999999.99
TION,Dorothy White,22,0.00
VVVV,Michael J,17,100000.00
3
NERA
JOLY
VVVV
*/