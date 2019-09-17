#include <bits/stdc++.h>
using namespace std;
const int m = 100;
int d = 0 , minn , c;
int ans[m] , out[m];
void find(int a , int b , int x) {
    if (d >= c || x >= minn) {
        return;  
    }
    if (b % a == 0) {
        b /= a;
        if (b < x || b >= minn) {
            return;
        }
        ans[d] = b;
        minn = b;
        memcpy(out , ans , (d + 1) * sizeof(int));
        return;
    } else {
        if (d >= c - 1) {
            return;
        }
        while (a * x <= b && x < minn) {
            x++;
        }
        while (x < minn) {
            if (a * x >= b * (c - d)) {
                break;
            }
            ans[d] = x;
            d++;
            find(a * x - b , b * x , x + 1);
            d--;
            x++;
        }
    }
    return;
}
int main() {
    int a , b;
    cin >> a >> b;
    minn = 1000000;
    for (c = 1;c <= m;c++) {
        find(a , b , 1);
        if(minn < 1000000) {
            break;
        }
    }
    for (int k = 0;k < c - 1;k++) {
        cout << out[k];
    }
    cout << out[c - 1];
    return 0;
}
