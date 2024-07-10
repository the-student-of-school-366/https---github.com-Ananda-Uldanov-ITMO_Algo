#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int finx, finy, finz;
    cin >> finx >> finy >> finz;
    int arr[finx + 1][finy + 1][finz + 1];
    int n = finx * finy * finz - 2;
    for (int i = 0; i <= finx; i++)
    {
        for (int j = 0; j <= finy; j++)
        {
            for (int z = 0; z <= finz; z++)
            {
                arr[i][j][z] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y, z, s, tmp;
        cin >> x >> y >> z >> s;
        arr[x][y][z] = s;
    }
    for (int x = 1; x <= finx; x++)
    {
        for (int y = 1; y <= finy; y++)
        {
            for (int z = 1; z < finz; z++)
            {
                int tmp, m;
                tmp = max(arr[x - 1][y][z], arr[x][y - 1][z]);
                m = max(tmp, arr[x][y][z - 1]);
                arr[x][y][z] = m + arr[x][y][z];
            }
        }
    }
    int tmp = max(arr[finx - 1][finy][finz], arr[finx][finy - 1][finz]);

    arr[finx][finy][finz] = max(tmp, arr[finx][finy][finz - 1]);
    cout << arr[finx][finy][finz];
}