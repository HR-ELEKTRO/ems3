#ifndef _HR_BroJZ_buffer_
#define _HR_BroJZ_buffer_

#include <stdbool.h>

// interface for buffers with int's

typedef struct buffer_tag *buffer;

// create a new buffer
// returns NULL on failure
buffer new_buffer(void);

// delete a buffer pointed to by pb
void delete_buffer(buffer *pb);

// put value i in buffer b if buffer b is not full
// returns true on success or false otherways
bool buffer_put(buffer b, int i);

// get value from buffer b and writes it to *p if buffer b not empty
// returns true on success or false otherways
bool buffer_get(buffer b, int *p);

// returns true when buffer b is full or false otherways
bool buffer_is_full(buffer b);

// returns true when buffer b is empty or false otherways
bool buffer_is_empty(buffer b);

#endif