#include <iostream>
#include <pthread.h>
using namespace std;
void* func1(void*) {
    cout << "Потік 1 привіт!" << endl;
    return NULL;
}
void* func2(void*) {
    cout << "Потік 2 привіт!" << endl;
    return NULL;
}
int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
