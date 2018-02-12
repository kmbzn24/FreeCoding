#include <stdio.h>
#include <math.h>
int main() {
    int n; //입력 횟수
    double result = 1; //최종 결과
    scanf("%d", &n); //n값을 입력받습니다.
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &b[i], &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = a[i] - b[i] + 1; j <= a[i]; j++) {
            result *= j;
            result /= j + b[i] - a[i];
        }
        printf("%.0lf\n", round(result));
        result = 1;
    }
    return 0;
}
