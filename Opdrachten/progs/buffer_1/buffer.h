#ifndef _HR_BroJZ_buffer_
#define _HR_BroJZ_buffer_

#include <stdbool.h>

// interface for a buffer with int's

// put value i in buffer if buffer is not full
// returns true on success or false otherways
extern bool buffer_put(int i);

// get value from buffer and writes it to *p if buffer not empty
// returns true on success or false otherways
extern bool buffer_get(int *p);

// returns true when buffer is full or false otherways
extern bool buffer_is_full(void);

// returns true when buffer is empty or false otherways
extern bool buffer_is_empty(void);

#endif