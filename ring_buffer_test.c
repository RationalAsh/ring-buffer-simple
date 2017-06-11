#include <stdio.h>
#include <stdlib.h>
#include "ring_buffer.h"

int main(int argc, char **argv)
{
    ring_buffer rb;
    float num;
    int ret;
    init_ring_buffer(&rb, 10);
    print_buffer(&rb);
    push_data(&rb, 1.5);
    push_data(&rb, 3.141);
    for(float i=0.0; i<20; i++)
    {
        push_data(&rb, i);
        print_buffer(&rb);
    }
    for(float i=0.0; i<20; i++)
    {
        ret = pop_data(&rb, &num);
        print_buffer(&rb);
        printf("Popped: %f", num);
        if(ret == -1)
        {
            printf("Buffer is empty!\n");
        }
    }
    print_buffer(&rb);
    printf("Hello world!\n");
    return 0;
}