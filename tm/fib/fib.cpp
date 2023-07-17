#include "fib.h"

int doFibExpensive(int n) {
    if (n < 2) {
        return n;
    } else {
        return doFibExpensive(n - 1) + doFibExpensive(n - 2);
    }
}
