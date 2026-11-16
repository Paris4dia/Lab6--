#include <iostream>
#include <pthread.h>
using namespace std;

int a, b;
int sum, product;

void* add(void*) {
    sum = a + b;
    pthread_exit(NULL);
}
void* multiply(void*) {
    product = a * b;
    pthread_exit(NULL);
}
int main() {
    cout<<"Введіть два числа: ";
    cin>>a>>b;

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, add, NULL);
    pthread_create(&thread2, NULL, multiply, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout << "Сума: " << sum << endl;
    cout << "Добуток: " << product << endl;

    if (sum > product)
        cout << "Сума більша за добуток";
    else if (sum < product)
        cout << "Сума менша за добуток";
    else
        cout << "Сума дорівнює добутку";

    return 0;
}
