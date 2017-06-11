#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef struct ring_buffer_float
{
    float *buffer;
    int head;
    int tail;
    int max_length;
}ring_buffer;

int init_ring_buffer(ring_buffer *rb, int max_len);
int free_ring_buffer(ring_buffer *rb);
int push_data(ring_buffer *rb, float data);
int pop_data(ring_buffer *rb, float *data);
int peek_data(ring_buffer *rb, float *data);
void print_buffer(ring_buffer *rb);

#endif