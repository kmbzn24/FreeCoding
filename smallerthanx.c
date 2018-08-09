//X보다 작은 수를 순서대로 출력하는 코드입니다.
#include <stdio.h>
int main(void) {
	int n, x;
	scanf("%d %d", &n, &x);
	int array[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	for (int i = 0; i < n; i++) {
		if (array[i] < x) {
			printf("%d ", array[i]);
		}
	}
	return 0;
}
