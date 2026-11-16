#include <iostream>
#include <pthread.h>
using namespace std;

pthread_t id1, id2;

void* firstThread(void*) {
    id1 = pthread_self();
    pthread_exit(NULL);
}

void* secondThread(void*) {
    id2 = pthread_self();
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, firstThread, NULL);
    pthread_create(&thread2, NULL, secondThread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    if (pthread_equal(id1, id2))
        cout << "Ідентифікатори однакові";
    else
        cout << "Ідентифікатори різні";

    return 0;
}
