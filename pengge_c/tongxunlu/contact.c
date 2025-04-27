#include "contact.h"

// memset
// void * memset ( void * ptr, int value, size_t num );
void Initcon(Contact* con) {
    con->count = 0;
    memset(con->data, 0, sizeof(con->data));
}