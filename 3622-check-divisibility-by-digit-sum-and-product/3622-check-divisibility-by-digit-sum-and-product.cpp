class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int pro = 1;

        while (n > 0) {
            int digit = n % 10;

            sum += digit;
            pro *= digit;

            n /= 10;
        }

        return original % (sum + pro) == 0;
    }
};