#include <iostream>

long long sumOfGoodNumbers(long long n) {
    long long sum = 0;

    for (long long x = n; x >= 1; ) {
        // For the current x, find the largest k such that floor(n / k) == x
        long long k_min = n / (x + 1) + 1; // smallest k that yields floor(n / k) == x
        long long k_max = n / x;           // largest k that yields floor(n / k) == x

        // Add x for each valid k in this range, or equivalently x * (k_max - k_min + 1)
        sum += x;

        // Move to the next lower unique value of x
        x = n / (k_max + 1);
    }

    return sum;
}

int main() {
    long long n;
    std::cout << "Enter a number n: ";
    std::cin >> n;

    long long result = sumOfGoodNumbers(n);
    std::cout << "Sum of all good numbers: " << result << std::endl;

    return 0;
}
