#include <iostream>
#include <vector>
using namespace std;

int compute_hash(vector<int> const &s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int c : s) {
        hash_value = (hash_value + c * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
    }

    int q;
    cin >> q;

    if ((sum == matrix[0][0] * n * m) and (matrix[0][0] == matrix[n - 1][m - 1])) {
        for (int i = 0; i < q; ++i)
            cout << "YES" << endl;
        return 0;
    }

    for (int p = 0; p < q; ++p) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x3 >> y3;
        cin >> x2 >> y2 >> x4 >> y4;

        --x1;
        --y1;
        --x2;
        --y2;
        --x3;
        --y3;
        --x4;
        --y4;

        int size1 = x3 - x1;
        int size2 = y3 - y1;

        if (size1 != x4 - x2 || size2 != y4 - y2) {
            cout << "NO" << endl;
            continue;
        }

        bool flag = true;
        for (int i = 0; i <= size1; ++i) {
            for (int j = 0; j <= size2; ++j) {
                if (matrix[x1 + i][y1 + j] != matrix[x2 + i][y2 + j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
