#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (char i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int arr[m];
        for (char j = 0; j < m; j++) {
            scanf("%d", &arr[j]);
        }
        for (char j = 1; j < m; j++) {
                arr[0] += arr[j];
        }
        printf("%d\n", arr[0]);
    }
    return 0;
}
