#include <stdio.h>
void BFS(int n, int m, int v) {
    int arr[n][n]; //정사각형 형태의 2차원 배열을 만들어 준다.
    int queue[n]; //큐를 만들어 준다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //2차원 배열의 값을 전부 0으로 초기화
            arr[i][j] = 0;
        }
        //큐의 값을 전부 0으로 초기화
        queue[i] = 0;
    }
    queue[0] = v; //큐에 시작점을 넣어 준다.
    for (int i = 0; i < m; i++) { //간선의 데이터를 입력받아 정점 간의 관계를 2차원 배열에 저장
        int f, t;
        scanf("%d %d", &f, &t);
        //양방향이므로 2번씩 해준다.
        arr[f - 1][t - 1] = 1;
        arr[t - 1][f - 1] = 1;
    }
    for (int i = 0; i < n; i++) { //dequeue 작업을 총 n회 반복
        //dequeue
        int q = queue[0]; //맨 앞의 값을 미리 빼 놓는다.
        for (int j = 0; j < n; j++) {
            queue[j] = queue[j + 1]; //큐에 있는 값들을 한칸씩 앞으로 옮긴다.
        }
        queue[n - 1] = 0; //큐 맨 뒤의 값을 0으로 초기화한다.
        printf("%d ", q); //dequeue된 q값을 출력한다.
        //dequeue
        for (int j = 0; j < n; j++) {
            if (arr[q - 1][j] == 1) {
                //enqueue
                if (queue[0] == 0) {
                    queue[0] = j + 1; //큐가 비었을 경우 맨 앞쪽에 저장
                }
                else {
                    //큐가 비어있지 않을 경우 요소를 적절한 위치에 저장
                    for (int k = n - 1; k >= 0; k--) {
                        if (queue[k] != 0) {
                            queue[k + 1] = j + 1;
                            break; //저장 후 반복문을 빠져나온다.
                        }
                    }
                }
                //enqueue
                for (int k = 0; k < n; k++) {
                    arr[k][q - 1] = 0; //enqueue 작업이 끝난 후 표시를 해 준다.
                }
            }
        }
    }
}
int main (void) {
    int n, m, v;
    //n : 점의 개수, m : 간선의 개수, v : 시작점
    scanf("%d %d %d", &n, &m, &v);
    BFS(n, m, v);
}
