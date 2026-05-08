class Solution {
public:
    double myPow(double a, int b) {
        long long exp = b;
    if (exp < 0) {
        a = 1 / a;
        exp = -exp;
    }

    double result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= a;
        a *= a;
        exp /= 2;
    }
    return result;

    }
};
