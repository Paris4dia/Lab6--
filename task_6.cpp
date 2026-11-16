#include <iostream>
#include <pthread.h>
using namespace std;
struct Nums { int a; int b; };

void* sum_func(void* arg) {
    Nums* n = (Nums*)arg;
    cout << "Сума: " << n->a + n->b << endl;
    return NULL;
}
void* mul_func(void* arg) {
    Nums* n = (Nums*)arg;
    cout << "Добуток: " << n->a * n->b << endl;
    return NULL;
}
int main() {
    Nums n = {3, 4};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, sum_func, &n);
    pthread_create(&t2, NULL, mul_func, &n);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
