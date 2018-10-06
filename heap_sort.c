#include <stdio.h>
/*
TITLE : HEAP_SORT
PROGRAMMER : BYUNG JUN KIM
DATE : 2018.01.05
*/
int heapify(int arr[], int k, int n) {
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int bigger;
	if (right <= n) { //자식 요소가 두 개인 경우 체크
		if (arr[left] < arr[right]) {
			bigger = right;
		}
		else {
			bigger = left;
		}
	}
	else if (left == n) { //자식 요소가 한 개인 경우 체크
		bigger = left;
	}
	else { //자식 요소가 없는 경우
		return;
	}
	if (arr[k] < arr[bigger]) { //교환
		int change;
		change = arr[k];
		arr[k] = arr[bigger];
		arr[bigger] = change;
		heapify(arr, bigger, n); //재귀적 호출
	}
}
void build_heap(int arr[], int n) {
	for (int i = n / 2; i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void heap_sort(int arr[], int n) {
	build_heap(arr, n); //전체적인 구조를 만들어 준다
	for (int i = n; i > 0; i--) {
		int change; //첫번째 요소와 마지막 요소를 교환하는 과정
		change = arr[0];
		arr[0] = arr[i];
		arr[i] = change;
		heapify(arr, 0, i - 1);
	}
}
int main(void) {
	int arr[] = { 11, 7, 1, 4, 9, 2, 12, 6, 3, 8, 10, 5 }; //주어진 배열
	int length = sizeof(arr) / 4; //배열의 길이
	heap_sort(arr, length - 1); //정렬
	for (int i = 0; i < length; i++) { //정렬된 배열을 출력
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	return 0;
}
