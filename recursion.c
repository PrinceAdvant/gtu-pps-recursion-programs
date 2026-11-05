/* GTU PPS practice: 6 classic recursion programs with a self-test.
   Own practice code, not copied from a GTU paper. Build: gcc -Wall -o recursion recursion.c */
#include <stdio.h>

long factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }
int fibonacci(int n) { return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2); }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long power(int base, int exp) { return exp == 0 ? 1 : base * power(base, exp - 1); }
int sum_digits(int n) { return n == 0 ? 0 : n % 10 + sum_digits(n / 10); }
int reverse_num(int n, int acc) { return n == 0 ? acc : reverse_num(n / 10, acc * 10 + n % 10); }

int main(void) {
    int fails = 0;
#define CHECK(x, want) do { long got = (x); if (got != (want)) { printf("FAIL %s = %ld, want %ld\n", #x, got, (long)(want)); fails++; } } while (0)
    CHECK(factorial(5), 120);  CHECK(factorial(0), 1);
    CHECK(fibonacci(10), 55);  CHECK(fibonacci(1), 1);
    CHECK(gcd(48, 18), 6);     CHECK(gcd(17, 5), 1);
    CHECK(power(2, 10), 1024); CHECK(power(7, 0), 1);
    CHECK(sum_digits(12345), 15);
    CHECK(reverse_num(1234, 0), 4321);
    printf("First 10 Fibonacci terms:");
    for (int i = 0; i < 10; i++) printf(" %d", fibonacci(i));
    printf("\n%s\n", fails ? "Some checks failed" : "All checks passed");
    return fails != 0;
}
