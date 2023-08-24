#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.c"
#include "charmachine.c"
#include "boolean.h"

boolean isMember (int x, Queue q) {
    boolean found = false;
    Address p = ADDR_HEAD(q);
    while (p != NULL && !found) {
        if (INFO(p) == x) {
            found = true;
        } else {
            p = NEXT(p);
        }
    }
    return found;
}

int main () {
    Queue butak, mhs, nomhs;
    CreateQueue(&butak);
    CreateQueue(&mhs);
    CreateQueue(&nomhs);

    START();
    int i = 1;
    while (currentChar != ',') {
        if (currentChar == 'B') {
            enqueue(&mhs, 0);
        } else if (currentChar == 'K'){
            enqueue(&mhs, 1);
        }
        enqueue(&nomhs, i++);
        ADV();
    }
    ADV();
    while (!EOP) {
        if (currentChar == 'B') {
            enqueue(&butak, 0);
        } else if (currentChar == 'K') {
            enqueue(&butak, 1);
        }
        ADV();
    }
    
    boolean valid = true;
    int butakval, mhsval, nomhsval;
    while (!isEmpty(butak) && valid) {
        dequeue(&butak, &butakval);
        if (!isMember(butakval, mhs)) {
            valid = false;
        } else {
            dequeue(&nomhs, &nomhsval);
            dequeue(&mhs, &mhsval);
            while (mhsval != butakval) {
                enqueue(&nomhs, nomhsval);
                enqueue(&mhs, mhsval);
                dequeue(&nomhs, &nomhsval);
                dequeue(&mhs, &mhsval);
            }
            if (butakval == 0) {
                printf("%d -> bulat\n", nomhsval);
            } else {
                printf("%d -> kotak\n", nomhsval);
            }
        }
        if (!valid) {
            enqueue(&butak, butakval);
        }
    }
    printf("%d\n", length(mhs));

    return 0;
}