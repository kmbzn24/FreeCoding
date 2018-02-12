#include <stdio.h>
int power(int n, int a) {
    int result = 1;
    for (int i = 0; i < a; i++) {
        result *= n;
    }
    return result;
}
int han(int n) {
    int a = 0;
    for (int i = 1; i <= 4; i++) {
        if ((power(10, i - 1) <= n) && (n < power(10, i))) {
            a = i;
            break;
        }
        a = 1;
    }
    if (a < 3) {
        return 1;
    }
    else if (a == 4) {
        return 0;
    }
    else {
        int arr[a];
        for (int i = 0; i < 3; i++) {
            arr[i] = ((n % power(10, i + 1)) / power(10, i));
        }
        if (arr[2] - arr[1] == arr[1] - arr[0]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int n, result = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        result += han(i);
    }
    printf("%d", result);
    return 0;
}
