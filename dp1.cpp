#include <stdio.h>
int ans(int n, int k) {
    int arr[n + 1][n + k + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + k + 1; j++) {
            if (j <= 0 || j >= i) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
            }
        }
    }
    return arr[n][k];
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", ans(n, k));
    return 0;
}
