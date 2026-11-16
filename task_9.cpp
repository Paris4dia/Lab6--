#include <iostream>
#include <pthread.h>
using namespace std;

int sum = 0;

void* calculateSum(void*) {
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, calculateSum, NULL);

    if (!pthread_equal(pthread_self(), thread)) {
        pthread_join(thread, NULL);
    }

    cout << "Сума: " << sum << endl;
    return 0;
}
