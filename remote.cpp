#include <iostream>
int abs(int n) {
    if (n < 0) {
        return (-1) * n;
    }
    else {
        return n;
    }
}
int main() {
    int n, m, result = 0;
    std::cin >> n;
    std::cin >> m;
    while (n != m) {
        int min = 40;
        int plus = 0;
        if (min > abs(n + 10 - m)) {
            min = abs(n + 10 - m);
            plus = 10;
        }
        if (min > abs(n + 5 - m)) {
            min = abs(n + 5 - m);
            plus = 5;
        }
        if (min > abs(n + 1 - m)) {
            min = abs(n + 1 - m);
            plus = 1;
        }
        if (min > abs(n - 10 - m)) {
            min = abs(n - 10 - m);
            plus = -10;
        }
        if (min > abs(n - 5 - m)) {
            min = abs(n - 5 - m);
            plus = -5;
        }
        if (min > abs(n - 1 - m)) {
            min = abs(n - 1 - m);
            plus = -1;
        }
        result++;
        n += plus;
    }
    std::cout << result;
    return 0;
}
