// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 20 Oktober 2022
// Topik Praktikum: stack
// Deskripsi: realisasi bigint

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "boolean.h"

int lenStack(Stack s){
	if (IsEmpty(s)){
		return 0;
	}else{
		int count=0;
		infotype temp;
		while (!IsEmpty(s)){
			Pop(&s,&temp);
			count++;
		}
		return count;
	}
}

boolean checkVal(char c1[100], char c2[100]){
	// Stack s1temp,s2temp;
	// int val1, val2, a1,a2;
	// CreateEmpty(&s1temp);
	// CreateEmpty(&s2temp);
	if (strlen(c1)== strlen(c2)){
		int i = 0;
		while (i < strlen(c1))
		{
			if (c1[i] < c2[i])
			{
				return false;
			}else if (c2[i]<c1[i]){
				return true;
			}
			i++;
		}
	}else if(strlen(c1)< strlen(c2)){
		return false;
	}else{
		return true;
	}
	return true;
}
boolean sameChar(char c1[100], char c2[100]){
	int i = 0;
	if (strlen(c1)!= strlen(c2)){
		return false;
	}
	while (i < strlen(c1)){
		if (c1[i]!=c2[i]){
			return false;
		}
		i++;
	}
	return true;
}
int main(){
	Stack s1,s2, s1temp,s2temp, sMin;
	int var1, var2,varMin, len1, len2;
	int i=0;
	char c1[100],c2[100], cMin;
	boolean krg, cek=true;
	CreateEmpty(&s1);
	CreateEmpty(&s2);
	CreateEmpty(&sMin);

	// long long int a1, a2;
	// scanf("%lld", &a1);
	// scanf("%lld", &a2);
	// printf("%lld\n", a1 - a2);
	// return 0;
	scanf("%s", c1);
	scanf("%s", c2);
	i = 0;
	while (c1[i] != '\0'){
		Push(&s1,(int)c1[i]-48);
		i++;
	}
	i = 0;
	while (c2[i] != '\0'){
		Push(&s2,(int)c2[i]-48);
		i++;
	}
	if (sameChar(c1,c2)){
		printf("0\n");
	}else{
		krg = false;
		len1 = lenStack(s1);
		len2 = lenStack(s2);
		if (!checkVal(c1, c2))
		{
			cek=false;
			while(!IsEmpty(s1) && !IsEmpty(s2)){
				Pop(&s1, &var1);
				Pop(&s2, &var2);
				if (krg){
					if (var2-1<var1){
						Push(&sMin, 10+var2-var1-1);
						krg = true;
					}else{
						Push(&sMin, var2-var1-1);
						krg = false;
					}
				}else{
					if (var2<var1){
						Push(&sMin, 10+var2-var1);
						krg = true;
					}else{
						Push(&sMin, var2-var1);
						krg = false;
					}
				}
			}
			while(!IsEmpty(s2)){
				Pop(&s2, &var2);
				if (krg){
					if (var2-1<0){
						Push(&sMin, 10+var2-1);
						krg = true;
					}else{
						Push(&sMin, var2-1);
						krg = false;
					}
				}else{
					Push(&sMin, var2);
				}
			}
		}
		else
		{
			while(!IsEmpty(s1) && !IsEmpty(s2)){
				Pop(&s1, &var1);
				Pop(&s2, &var2);
				if (krg){
					if (var1-1<var2){
						Push(&sMin, 10+var1-var2-1);
						krg = true;
					}else{
						Push(&sMin, var1-var2-1);
						krg = false;
					}
				}else{
					if (var1<var2){
						Push(&sMin, 10+var1-var2);
						krg = true;
					}else{
						Push(&sMin, var1-var2);
						krg = false;
					}
				}
			}
			while(!IsEmpty(s1)){
				Pop(&s1, &var1);
				if (krg){
					if (var1-1<0){
						Push(&sMin, 10+var1-1);
						krg = true;
					}else{
						Push(&sMin, var1-1);
						krg = false;
					}
				}else{
					Push(&sMin, var1);
				}
			}
			while(!IsEmpty(s2)){
				Pop(&s2, &var2);
				if (krg){
					if (var2-1<0){
						Push(&sMin, 10+var2-1);
						krg = true;
					}else{
						Push(&sMin, var2-1);
						krg = false;
					}
				}else{
					Push(&sMin, var2);
				}
			}
		}
		if (krg || len1<len2 ||!cek){
			printf("-");
		}
		while (!IsEmpty(sMin)){
			Pop(&sMin, &varMin);
			if (varMin!=0){
				Push(&sMin, varMin);
				break;
			}
		}
		while (!IsEmpty(sMin)){
			Pop(&sMin, &varMin);
			printf("%c", (char)varMin+48);
		}
		printf("\n");
	}
	return 0;
}

