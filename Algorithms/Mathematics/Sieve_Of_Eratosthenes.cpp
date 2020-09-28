#include <iostream>
#include <cstring>

using namespace std;

// Sieve of Erathosthenes
void SieveOfErathosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int k = 2; k <= n; k++) {
        if (prime[k])
            cout << k << " ";
    }
}

int main() {
    int n = 30;
    SieveOfErathosthenes(30);
    return 0;
}