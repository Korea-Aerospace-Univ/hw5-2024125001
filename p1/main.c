#include <stdio.h>

int main() {
    int n; // 금액 
    int a, b, c; // 각 물건의 수량(900원, 750원, 200원)
    int found = 0; // 조건을 만족하는 경우가 있는지 확인하는 변수

    // 금액 입력
    if (scanf("%d", &n) != 1) return 0; 

    // 1. a 상품 반복 (최소 1개)
    for (a = 1; a * 900 < n; a++) {
        // 2. b 상품 반복 (최소 2개, 짝수)
        for (b = 2; (a * 900) + (b * 750) < n; b += 2) {
            // 3. c 상품 반복 (최소 1개)
            for (c = 1; (a * 900) + (b * 750) + (c * 200) <= n; c++) {
                // 조건 1: 잔돈 x
                if ((a * 900) + (b * 750) + (c * 200) == n) {
                    
                    // 조건 2: C < A or c < B
                    if (c < a || c < b) {
                        printf("%d %d %d\n", a, b, c);
                        found = 1;
                    }
                }
            }
        }
    }

    // 만족하는 조합이 하나도 없으면 
    if (found == 0) {
        printf("none\n");
    }

    return 0;
}
