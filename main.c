#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


char keys[] = "X^1234567890XXXXqwertzuiopXXXXasdfghjklXXXXXyxcvbnmXXXXXX XXXXXXXXXXXXXXXX";

void signal_handler() {
    exit(0);
}

int main(int argc, char *argv[])
{
    int device = open(argv[1], O_RDONLY);
    struct input_event ev;

    signal(SIGINT, signal_handler);
    signal(SIGPIPE, signal_handler);
    signal(SIGHUP, signal_handler);
    signal(SIGQUIT, signal_handler);
    signal(SIGTERM, signal_handler);

    while(1)
    {
        read(device,&ev, sizeof(ev));
        if(ev.type == 1 && ev.value == 1) {
            if(ev.code == 28) {
                printf("\n");
                fflush(stdout);
            } else {
                printf("%c", keys[ev.code]);
            }
        }
    }
}
