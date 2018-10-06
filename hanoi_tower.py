def ht(n, fro, sto, to) :
    if (n == 1) : #개수가 1일 경우
        print(str(fro) + " " + str(to));
    else :
        ht(n - 1, fro, to, sto);
        print(str(fro) + " " + str(to));
        ht(n - 1, sto, fro, to);
n = int(input());
power = 1;
for i in range(0, n) :
    power *= 2;
print(str(power - 1)); #총 이동횟수를 출력합니다.
if (n <= 20) :
    ht(n, 1, 2, 3);
