#include <stdio.h>

int main() {
    int n; // 금액 
    int a, b, c; // 각 물건의 수량(900원,750원,200원)
    int found = 0; // 조건을 만족하는 경우가 있는지 확인하는 변수

    // 금액 입력
    scanf("%d", &n); 

    // 중첩 반복문을 통해 가능한 모든 조합 탐색
    // a(900원)는 최소 1개부터 n/900개까지 가능
    for (a = 1; a * 900 < n; a++) {
        // b(750원)는 최소 2개(짝수 조건)부터 n/750개까지 가능
        for (b = 2; (a * 900) + (b * 750) < n; b += 2) {
            
            int rem = n - (a * 900 + b * 750);
            
            // 남은 금액이 C(200원)로 나누어 떨어지는지 확인
            if (rem > 0 && rem % 200 == 0) {
                c = rem / 200;

                // C 상품 수량 조건 확인: (c < a) or (c < b)
                if (c < a || c < b) {
                    printf("%d %d %d\n", a, b, c);
                    found = 1;
                }
            }
        }
    }

    // 만족하는 조합이 하나도 없을 경우
    if (found == 0) {
        printf("none\n");
    }

    return 0;
}
