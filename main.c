#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


char keys[] = "X^1234567890XXXXqwertzuiopXXXXasdfghjklXXXXXyxcvbnmXXXXXX XXXXXXXXXXXXXXXX";
unsigned char barcode[100] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

int buf_index = 0;

void INThandler() {
    exit(0);
}

int main(int argc, char *argv[])
{
    // init barcode
    memset(barcode, 1, sizeof(barcode));
    buf_index = 0;

    //char devname[] = "/dev/input/by-id/usb-Belon.cn_2.4G_Wireless_Device_Belon_Smart-event-kbd";
    //int device = open(devname, O_RDONLY);
    int device = open(argv[1], O_RDONLY);

    struct input_event ev;

    signal(SIGINT, INThandler);

    while(1)
    {
        read(device,&ev, sizeof(ev));
        if(ev.type == 1 && ev.value == 1) {
            if(ev.code == 28) {
                printf("%s\n", barcode);
                fflush(stdout);
                memset(barcode, 1, sizeof(barcode));
                buf_index = 0;
            } else {
                barcode[buf_index] = keys[ev.code];
                buf_index++;
            }
        }
    }
}
