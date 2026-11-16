#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    pid_t pid = fork();
    if(pid == 0) cout<<"дочірній процес"<<" "<<getpid()<<"\n";
    else if (pid > 0) cout<<"батьківський процес"<<" "<<pid<<"\n";
    else if (pid == -1) cout<<"виникла помилка"<<"\n";
    sleep (5);
    return 0;

}
