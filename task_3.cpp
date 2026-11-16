#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[] = {(char*)"ls", (char*)"-l", NULL};
        execve("/bin/ls", args, NULL);
    }
    sleep(2);
    return 0;
}
