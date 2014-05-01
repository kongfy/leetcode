#include <cstdio>

class Solution
{
public:
    double pow(double x, int n)
    {
        if (0 == n) {
            return 1.0;
        }
        
        if (1 == n) {
            return x;
        }

        if (-1 == n) {
            return 1.0 / x;
        }

        int half = n / 2;
        int reminder = n % 2;

        double temp = pow(x, half);
        temp *= temp;
        if (reminder != 0) {
            temp *= pow(x, reminder);
        }

        return temp;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    printf("%f\n", solution.pow(8.84372, -5));
    
    return 0;
}

