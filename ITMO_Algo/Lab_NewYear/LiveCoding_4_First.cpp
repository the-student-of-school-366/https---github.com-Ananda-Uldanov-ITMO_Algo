#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    
    vector<int> p(n, 0);

    for (int i = 1; i < n; i++) {
        for (int j = z[i] - 1; j >= 0; j--) {
            if (p[i + j] > 0) {
                break;
            } else {
                p[i + j] = j + 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }

}
