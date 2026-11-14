#include <bits/stdc++.h>
using namespace std;
int tinhgiaithua(int n) {
    if (n == 0 || n == 1) return 1;
    return n * tinhgiaithua(n - 1);
}
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    cout << "Giai thua cua " << n << " la: " << tinhgiaithua(n) << endl;
    cout << "So fibonacci thu " << n << " la: " << fibonacci(n) << endl;
    return 0;
}