#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main() {
    cout << "Батьківський процес почався" << endl;
    pid_t pid = fork();
    if (pid == 0) {
        cout << "Дочірній процес виконується..." << endl;
        sleep(2);
        cout << "Дочірній процес закінчився" << endl;
        return 0;
    } else {
        wait(NULL);
        cout << "Батьківський процес завершився" << endl;
    }
    return 0;
}
