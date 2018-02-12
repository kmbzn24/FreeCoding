#include <stdio.h>
int a = 0, b = 0;
int reday(int month) {
    if (month == 1) {
        return 0;
    }
    else if (month == 2) {
        return 31;
    }
    else if (month == 3) {
        return 28 + reday(month - 1);
    }
    else if ((month == 4) || (month == 6) || (month == 8) || (month == 9) || (month == 11)) {
        return 31 + reday(month - 1);
    }
    else {
        return 30 + reday(month - 1);
    }
}
void pwd(int m) {
    int n = m % 7;
    if (n == 0) {
        printf("MON");
    }
    else if (n == 1) {
        printf("TUE");
    }
    else if (n == 2) {
        printf("WED");
    }
    else if (n == 3) {
        printf("THU");
    }
    else if (n == 4) {
        printf("FRI");
    }
    else if (n == 5) {
        printf("SAT");
    }
    else if (n == 6) {
        printf("SUN");
    }
}
int main() {
    int m, d;
    scanf("%d %d", &m, &d);
    pwd(reday(m) + d - 1);
    return 0;
}
