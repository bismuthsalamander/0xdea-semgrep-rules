#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool test1(int a, int b) {
    if (a == b) {
        return false;
    }
    a *= 2;
    if (a == b) {
        return false;
    }
    b += 1;
    //ok: raptor-typos
    bool double_plus_one = a == b;
    bool result = double_plus_one;
    a *= 3;
    //ok: raptor-typos
    result &= a == b;
    //ok: raptor-typos
    result &= test2(a, b, a == b);
    //ok: raptor-typos
    return a == b || double_plus_one;
}

bool test2(int a, int b, bool c) {
    return a + b > 10 || (c && a * b > 15);
}