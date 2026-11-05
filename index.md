---
title: GTU PPS recursion programs in C
---

GTU Hero's PPS guide puts functions and recursion in the list of topics to practise. Recursion dekh ke darr lagta hai, but every program here is just two lines of thinking: a base case, and a smaller version of the same problem.

| Function | Base case | Recursive step |
|---|---|---|
| `factorial(n)` | n <= 1 gives 1 | n x factorial(n - 1) |
| `fibonacci(n)` | n < 2 gives n | fib(n - 1) + fib(n - 2) |
| `gcd(a, b)` | b == 0 gives a | gcd(b, a % b) (Euclid) |
| `power(b, e)` | e == 0 gives 1 | b x power(b, e - 1) |
| `sum_digits(n)` | n == 0 gives 0 | n % 10 + sum_digits(n / 10) |
| `reverse_num(n, acc)` | n == 0 gives acc | reverse_num(n / 10, acc x 10 + n % 10) |

## Build and test

```
gcc -Wall -o recursion recursion.c && ./recursion
```

Prints the first 10 Fibonacci terms and `All checks passed` (tested with gcc). These are my own practice programs, not copied from a GTU paper or solution.

## Exam tips

- Write the base case first. No base case means infinite recursion and a crash.
- Draw the call stack for a small input, like factorial(3). Examiner ko logic dikhna chahiye.
- Plain recursive Fibonacci is slow for big n because it recomputes the same terms. Saying this in one line shows you understand it.

Old PPS papers and the full practice list: [GTU Hero PPS previous year paper guide](https://gtuhero.com/blogs/gtu-pps-previous-year-paper) (GTU Hero is my project).
