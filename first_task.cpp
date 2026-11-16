#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    cout<<"Це перше завдання"<<"\n";
    fork();
    sleep(30);
    return 0;
}
