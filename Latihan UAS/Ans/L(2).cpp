#include <stdio.h>

bool contains(long long* arr, long long low, long long high, long long key) {
    bool ans = false;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long midVal = arr[mid];

        if (midVal < key)
            low = mid + 1;

        else if (midVal > key)
            high = mid - 1;

        else if (midVal == key)
        {
            ans = true;
            break;
        }
    }

    return ans;
}

long long first(long long* arr, long long low, long long high, long long key) {
    long long ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low + 1) / 2;
        long long midVal = arr[mid];

        if (midVal < key)
            low = mid + 1;

        else if (midVal > key)
            high = mid - 1;

        else if (midVal == key) {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

long long greatestlesser(long long* arr, long long low, long long high, long long key) {
    long long ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low + 1) / 2;
        long long midVal = arr[mid];

        if (midVal < key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (midVal > key)
            high = mid - 1;

        else if (midVal == key)
            high = mid - 1;

    }

    return ans;
}

long long last(long long* arr, long long low, long long high, long long key) {
    long long ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low + 1) / 2;
        long long midVal = arr[mid];

        if (midVal < key)
            low = mid + 1;

        else if (midVal > key)
            high = mid - 1;

        else if (midVal == key) {
            ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}

long long leastgreater(long long* arr, long long low, long long high, long long key) {
    long long ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low + 1) / 2;
        long long midVal = arr[mid];

        if (midVal < key)
            low = mid + 1;

        else if (midVal > key)
        {
            ans = mid;
            high = mid - 1;
        }

        else if (midVal == key)
            low = mid + 1;

    }

    return ans;
}

void merge(long long* arr, long long left, long long mid, long long right) {
    long long leftSize = mid - left + 1;
    long long rightSize = right - mid;
    long long arrlefteft[leftSize], arrrightight[rightSize];

    for (long long i = 0; i < leftSize; i++)
        arrlefteft[i] = arr[left + i];

    for (long long i = 0; i < rightSize; i++)
        arrrightight[i] = arr[mid + i + 1];

    long long i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize)
    {
        if (arrlefteft[i] < arrrightight[j])
            arr[k++] = arrlefteft[i++];
        else
            arr[k++] = arrrightight[j++];
    }

    while (i < leftSize)
        arr[k++] = arrlefteft[i++];
    while (j < rightSize)
        arr[k++] = arrrightight[j++];
}

void mergeSort(long long* arr, long long left, long long right) {
    if (left < right)
    {
        long long mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {

    int tc;
    scanf("%d", &tc); getchar();
    for (int q = 1; q <= tc; q++)
    {
        int n;
        scanf ("%d", &n);
        long long arr[n], total = 0;
        for (int i = 0; i < n; i++)
        {
            scanf ("%lld", &arr[i]);
            total += arr[i];
        }
        mergeSort(arr, 0, n - 1);
        long long max = arr[n - 1], min = arr[0];
        
        int query;
        scanf ("%d", &query);
        printf("Case #%d:\n", q);
        for (int w = 1; w <= query; w++)
        {
            long long left, right;
            scanf ("%lld %lld", &left, &right);
            long long start = (contains(arr, 0, n - 1, left)) ? first(arr, 0, n - 1, left) : leastgreater(arr, 0, n - 1, left);
            long long end = (contains(arr, 0, n - 1, right)) ? last(arr, 0, n - 1, right) : greatestlesser(arr, 0, n - 1, right);
            long long res = 0;

            if (left > max || right < min)
                start = end = -1;

            else if (left < min)
                start = 0;
                
            else if (right > max)
                end = n - 1;

            if (start == -1 && end == -1)
                puts("0");

            else if (start == 0 && end == n - 1)
                printf ("%lld\n", total);

            else
            {
                while (start <= end)
                {
                    if (start == end)
                        res += arr[start];
                    else
                        res += arr[start] + arr[end];
                    start++;
                    end--;
                }
                printf ("%lld\n", res);

            }
        }
    }

    return 0;
}