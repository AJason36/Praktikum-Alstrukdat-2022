#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.h"
#include "charmachine.h"

int main () {
    Stack S;
    CreateStack(&S);
    START();
    boolean valid = true;
    int val;
    int count[5];
    for (int i = 0; i < 5; i++) {
        count[i] = 0;
    }
    int max = 0;
    
    while (!EOP) {
        boolean isKurung = false;
        if (currentChar == '[') {
            isKurung = true;
            push(&S, 0);
        } else if (currentChar == '(') {
            isKurung = true;
            push(&S, 1);
        } else if (currentChar == '|') {
            isKurung = true;
            if (isEmpty(S)) {
                push(&S, 2);
            } else {
                pop(&S, &val);
                if (val != 2) {
                    push(&S, val);
                    push(&S, 2);
                } else {
                    count[2]++;
                }
            }
        } else if (currentChar == '{') {
            isKurung = true;
            push(&S, 3);
        } else if (currentChar == '<') {
            isKurung = true;
            push(&S, 4);
        } else if (currentChar == ']') {
            isKurung = true;
            if (!isEmpty(S)) {
                pop(&S, &val);
                if (val != 0) {
                    valid = false;
                    push(&S, val);
                }
                count[0]++;
            } else {
                valid = false;
            }
        } else if (currentChar == ')') {
            isKurung = true;
            if (!isEmpty(S)) {
                pop(&S, &val);
                if (val != 1) {
                    valid = false;
                    push(&S, val);
                }
                count[1]++;
            } else {
                valid = false;
            }
        }  else if (currentChar == '}') {
            isKurung = true;
            if (!isEmpty(S)) {
                pop(&S, &val);
                if (val != 3) {
                    valid = false;
                    push(&S, val);
                }
                count[3]++;
            } else {
                valid = false;
            }
        } else if (currentChar == '>') {
            isKurung = true;
            if (!isEmpty(S)) {
                pop(&S, &val);
                if (val != 4) {
                    valid = false;
                    push(&S, val);
                }
                count[4]++;
            } else {
                valid = false;
            }
        }
        if (isKurung) {
            DisplayStack(S);
            printf("\n");
        }
        if (length(S) > max) {
            max = length(S);
        }
        ADV();
    }
    if (valid && isEmpty(S)) {
        printf("kurung valid\n");
        printf("[%d] (%d) |%d| {%d} <%d>\n", count[0], count[1], count[2], count[3], count[4]);
        printf("MAX %d\n", max);
    } else {
        printf("kurung tidak valid\n");
    }
    return 0;
}