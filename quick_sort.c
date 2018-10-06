#include <stdio.h>
/*
PROGRAMMER : BYUNG JUN KIM
DATE : 2017.12.30 (SAT)
TIME : 3:11 AM ~ 4:39 AM (1 hour 28 minutes)
*/
int partition(int arr[], int p, int r) {
	int j = p - 1;
	for (int i = p; i < r; i++) {
		if (arr[i] <= arr[r]) {
			//3구역과 2구역 맨 처음 요소를 교환하는 과정
			int change = arr[i];
			arr[i] = arr[j + 1];
			arr[j + 1] = change;
			j++; //1구역 요소의 개수가 증가
		}
	}
	//기준원소를 제 위치로 이동
	for (int i = r; i > j + 1; i--) {
		int change = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = change;
	}
	return (j + 1); //q값 반환
} 
void quick_sort(int arr[], int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r); //기준 원소의 위치값을 q에 저장
		quick_sort(arr, p, q - 1); //1구역 원소 정렬
		quick_sort(arr, q + 1, r); //2구역 원소 정렬
	}
}
int main(void) {
	int arr[] = { 7, 1, 4, 2, 6, 3, 8, 5 }; //주어진 배열
	int length = sizeof(arr) / 4; //배열의 길이
	quick_sort(arr, 0, length - 1); //정렬
	//퀵정렬된 배열을 출력
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
