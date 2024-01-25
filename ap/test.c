#include <stdio.h>

// SWAP 매크로 정의
#define SWAP(type, a, b) do { \
    type temp = a; \
    a = b; \
    b = temp; \
} while(0)

int main() {
    // int 형 변수 교환
    int intA = 5, intB = 10;
    SWAP(int, intA, intB);
    printf("After swapping integers: A=%d, B=%d\n", intA, intB);

    // double 형 변수 교환
    double doubleA = 3.14, doubleB = 2.71;
    SWAP(double, doubleA, doubleB);
    printf("After swapping doubles: A=%f, B=%f\n", doubleA, doubleB);

    // 사용자가 정의한 타입에 대해서도 동작
    struct Point {
        int x;
        int y;
    };
    struct Point pointA = {1, 2};
    struct Point pointB = {3, 4};
    SWAP(struct Point, pointA, pointB);
    printf("After swapping points: A=(%d, %d), B=(%d, %d)\n", pointA.x, pointA.y, pointB.x, pointB.y);

    return 0;
}
