#include <stdio.h>
void DFS(int n, int m, int v) {
    int arr[n][n]; //정사각형 형태의 2차원 배열을 만들어 준다.
    int stack[n]; //스택을 만들어 준다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //2차원 배열의 값을 전부 0으로 초기화
            arr[i][j] = 0;
        }
        //스택의 값을 전부 0으로 초기화
        stack[i] = 0;
    }
    stack[0] = v; //스택에 시작점을 넣어 준다.
    for (int i = 0; i < m; i++) { //간선의 데이터를 입력받아 정점 간의 관계를 2차원 배열에 저장
        int f, t;
        scanf("%d %d", &f, &t);
        //양방향이므로 2번씩 해준다.
        arr[f - 1][t - 1] = 1;
        arr[t - 1][f - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        //destack
        int st;
        if (stack[0] == 0) {
            st = stack[0];
        }
        else {
            for (int k = n - 1; k >= 0; k--) {
                if (stack[k] != 0) {
                    st = stack[k];
                    stack[k] = 0;
                    break;
                }
            }
        }
        printf("%d ", st); //destack된 st값을 출력한다.
        //destack
        for (int j = n - 1; j >= 0; j--) {
            if (arr[st - 1][j] == 1) {
                //stack
                if (stack[0] == 0) {
                    stack[0] = j + 1; //스택이 비었을 경우 맨 앞쪽에 저장
                }
                else {
                    //스택이 비어있지 않을 경우 요소를 적절한 위치에 저장
                    for (int k = n - 1; k >= 0; k--) {
                        if (stack[k] != 0) {
                            stack[k + 1] = j + 1;
                            break; //저장 후 반복문을 빠져나온다.
                        }
                    }
                }
                //enstack
                for (int k = 0; k < n; k++) {
                    arr[k][st - 1] = 0; //enstack 작업이 끝난 후 표시를 해 준다.
                }
            }
        }
    }
}
int main (void) {
    int n, m, v;
    //n : 점의 개수, m : 간선의 개수, v : 시작점
    scanf("%d %d %d", &n, &m, &v);
    DFS(n, m, v);
}
