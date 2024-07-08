#include <iostream>
using namespace std;
void quicksort(int* a, int l, int r)
{
    int i = l;
    int j = r;
    int mid = a[(l + r + 1) / 2];

    while (i <= j)
    {
        while (a[i] < mid)
        {
            i++;
        }
        while (a[j] > mid)
        {
            j--;
        }
        if (i <= j) {
            if (a[i] > a[j]) {
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quicksort(a, i, r);
    }
    if (l < j)
    {
        quicksort(a, l, j);
    }
}


int main() {
    int n, k;
    cin >> n >> k;

    int chairs[n];
    for (int i = 0; i < n; i++) {
        cin >> chairs[i];
    }

    quicksort(chairs,0, n-1);

    int l = 0;
    int r = chairs[n - 1] - chairs[0];

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int count = k - 1;
        int prev = chairs[0];

        for (int i = 1; i < n; i++) {
            if (chairs[i] - prev >= mid) {
                prev = chairs[i];
                count--;
            }

            if (count == 0) {
                break;
            }
        }

        if (count > 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << r << endl;

    return 0;
}
