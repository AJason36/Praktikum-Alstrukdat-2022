#include "stack.c"
#include <stdio.h>

int main(){
    Stack s1, s2, sTotal;
    char c1, c2;
    boolean sisa;
    int var1, var2, var;

    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&sTotal);

    do{
        scanf("%c", &c1);
        if (c1!='#'){
            Push(&s1, (int)(c1-48));
        }
    } while (c1 != '#');

    do{
        scanf("%c", &c2);
        if (c2!='#'){
            Push(&s2, (int)(c2-48));
        }
    } while (c2 != '#');

    sisa = false;
    printf("%d %d\n", IsEmpty(s1), IsEmpty(s2));
    while (!IsEmpty(s1) && !IsEmpty(s2)){
        Pop(&s1, &var1);
        Pop(&s2, &var2);

        if (sisa==false){
            if ((var1+var2)/10 == 1){
                sisa = true;
            }else{
                sisa = false;
            }
            Push(&sTotal, (var1 + var2) % 10);
        }else{
            if ((var1+var2+1)/10 == 1){
                sisa = true;
            }else{
                sisa = false;
            }
            Push(&sTotal, (var1 + var2+1) % 10);
        }
        
    }

    while (!IsEmpty(s1)){
        Pop(&s1, &var1);
        if (sisa){
            Push(&sTotal, (var1+1) % 10);
            if ((var1+1)/10 == 1){
                sisa = true;
                Push(&sTotal, 1);
            }else{
                sisa = false;
            }
        }else{
            Push(&sTotal, (var1));
        }
    }

    while (!IsEmpty(s2)){
        Pop(&s2, &var2);
        if (sisa){
            Push(&sTotal, (var2+1) % 10);
            if ((var2+1)/10 == 1){
                sisa = true;
                Push(&sTotal, 1);
            }else{
                sisa = false;
            }
        }else{
            Push(&sTotal, (var2));
        }
    }

    while(!IsEmpty(sTotal)){
        Pop(&sTotal, &var);
        printf("%c", (char)(var+48));
    }
    return 0;
}