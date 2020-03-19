
#ifndef Slot_h
#define Slot_h

#include "Person.h"

typedef int Key; // 주민등록번호
typedef Person * Value;


typedef struct _slot
{
    Key key;
    Value val;
} Slot;



#endif /* Slot_h */
