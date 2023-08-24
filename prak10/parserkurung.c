// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 8 November 2022
// Topik Praktikum: List berkait stack queue 
// Deskripsi: realisasi list berkait queue

#include "stacklinked.c"
#include "charmachine.c"
#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
	Stack s;
	int var1;
	CreateStack(&s);
	START();
	int arrCount[5];
	int i = 0, maxCount=0;
	while(i<5){
		arrCount[i] = 0;
		i++;
	}
	int tegak = 0;
	boolean kurung, valid = true;
	while (!EOP)
	{
		kurung = false;
		var1 = 0;
		if (currentChar == '<')
		{
			kurung = true;
			push(&s,4);
		}else if (currentChar == '{')
		{
			kurung = true;
			push(&s,3);
			
		}else if (currentChar == '|')
		{
			kurung = true;
			if(isEmpty(s)){
                push(&s,2);
                arrCount[2]++;
            } else if (TOP(s) == 2){
                pop(&s, &var1);
            } else {
                push(&s,2);
                arrCount[2]++;
            }
			tegak++;
		}
		else if (currentChar == '(')
		{
			kurung = true;
			push(&s,1);
		}else if (currentChar == '[')
		{
			kurung = true;
			push(&s,0);
		}
		else if (currentChar == '>')
		{
			kurung = true;
			if(!isEmpty(s)){
				pop(&s, &var1);
				if(var1!=4){
					valid = false;
					push(&s, var1);
				}
				arrCount[4]++;
			}else{
				valid = false;
			}
		}
		else if (currentChar == '}')
		{
			kurung = true;
			if(!isEmpty(s)){
				pop(&s, &var1);
				if(var1!=3){
					valid = false;
					push(&s, var1);
				}
				arrCount[3]++;
			}else{
				valid = false;
			}
		}
		else if (currentChar == ')')
		{
			kurung = true;
			if(!isEmpty(s)){
				pop(&s, &var1);
				if(var1!=1){
					valid = false;
					push(&s, var1);
				}
				arrCount[1]++;
			}else{
				valid = false;
			}
		}
		else if (currentChar == ']')
		{
			kurung = true;
			if(!isEmpty(s)){
				pop(&s, &var1);
				if(var1!=0){
					valid = false;
					push(&s, var1);
				}
				arrCount[0]++;
			}else{
				valid = false;
			}
		}

		if(kurung){
			DisplayStack(s);
			printf("\n");
		}
		if(length(s)>maxCount){
			maxCount = length(s);
		}
		
		ADV();
	}
	if(tegak%2==1){
        valid = false;
    }
	if(!valid || !isEmpty(s)){
		printf("kurung tidak valid\n");
		
	}else {
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n",arrCount[0],arrCount[1],arrCount[2],arrCount[3],arrCount[4]);
		printf("MAX %d\n", maxCount);
	}
	return 0;
}