#include "ring_buffer.h"
#include <stdio.h>
#include <stdlib.h>


static int is_buffer_empty(ring_buffer *rb)
{
    if((rb->head == -1)&&(rb->tail == -1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
static int is_buffer_full(ring_buffer *rb)
{
    if((rb->head == 0)&&(rb->tail == rb->max_length - 1))
    {
        return 1;
    }
    else if((rb->tail + 1)%(rb->max_length) == rb->head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int init_ring_buffer(ring_buffer *rb, int max_len)
{
    rb->buffer = calloc(max_len, sizeof(float));
    rb->head = -1;
    rb->tail = -1;
    rb->max_length = max_len;

    return 0;
}

int free_ring_buffer(ring_buffer *rb)
{
    free(rb);
    return 0;
}

int push_data(ring_buffer *rb, float data)
{
    if(is_buffer_empty(rb))
    {
        rb->head = 0;
        rb->tail = 0;
        rb->buffer[rb->tail] = data;
    }
    else
    {
        rb->tail = (rb->tail + 1)%(rb->max_length);
        if(rb->tail == rb->head)
        {
            rb->head = (rb->head + 1)%(rb->max_length);
            rb->buffer[rb->tail] = data;
        }
        else
        {
            rb->buffer[rb->tail] = data;
        }
    }
    return 0;
}

int pop_data(ring_buffer *rb, float *data)
{
    if(is_buffer_empty(rb))
    {
        return -1;
    }
    else if(rb->head == rb->tail)
    {
        *data = rb->buffer[rb->tail];
        rb->head = -1;
        rb->tail = -1;
        return 0;
    }
    else
    {
        *data = rb->buffer[rb->tail];
        rb->tail = rb->tail - 1;
        if(rb->tail < 0)
        {
            rb->tail = rb->max_length - 1;
        }
        return 0;
    }
}

int peek_data(ring_buffer *rb, float *data)
{
    if(is_buffer_empty(rb))
    {
        return -1;
    }
    else
    {
        *data = rb->buffer[rb->tail];
        return 0; 
    }
}

void print_buffer(ring_buffer *rb)
{
    printf("\n\nPrinting the ring buffer:\n");
    printf("---------------------------\n");
    printf("Buffer: ");
    for(int i=0; i<rb->max_length; i++)
    {
        printf("%f\t", rb->buffer[i]);
    }
    printf("\n");
    printf("Head: %d\n Tail: %d", rb->head, rb->tail);
}