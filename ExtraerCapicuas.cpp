/*
Un número capicúa es aquel que se lee igual de izquierda a derecha que de derecha
a izquierda (por ejemplo, 2992, 91019). Escriba un programa que, dada una línea de
texto, que contiene datos enteros imprima aquellos números que sean capicúas.
Ejemplo:
Entrada: “El año 2021 no es una capicua, 1991 y 2002 lo fueron y tendremos que esperar 90 años para el próximo capicúa”
Salida: 1991, 2002
*/

#include <iostream>
#include <string.h>
typedef char Cadena1[201];
typedef char Cadena2[21];
using namespace std;

string InvCad(Cadena2 Cad){
	string res1;
	Cadena2 res;
	int n=strlen(Cad);
	for(int i=0; i<strlen(Cad); i++){
		res[n-i-1]=Cad[i];
	}
	res[n]='\0';
	res1=res;
	return res1;
}

bool CompNum(Cadena2 Cad){
	for(int i=0; i<strlen(Cad); i++){
		if(!('0' <= Cad[i] and Cad[i] <= '9')) return false;
	}
	return true;
}

struct Nodo{
	Cadena2 Pal;
	Nodo *sig;
};

void CreaNodo(Nodo *&p, Cadena2 palabra){
	if(p==NULL){
		p = new Nodo;
		strcpy(p->Pal, palabra);
		p->sig=NULL;
	}
	else CreaNodo(p->sig, palabra);
}

void RecorreNodo(Nodo *p){
	if(p!=NULL){
		string a = p->Pal;
		if(CompNum(p->Pal) and InvCad(p->Pal)==a) cout << p->Pal << endl;
		RecorreNodo(p->sig);
	}
}

void EnlistarPal(Nodo *&p, Cadena1 text){
	p=NULL;
	int l=strlen(text), i=0, cont=0;
	Cadena2 pal;
	while(i<l){
		while(i<l and text[i]==' '){
			i++;
		}
		if(i<l){
			strcpy(pal, "");
			int j=0;
			while(i<l and text[i]!=' '){
				pal[j]=text[i];
				i++;
				j++;
			}
			pal[j]='\0';
			CreaNodo(p, pal);
		}
	}
}

int main(){
	setlocale( LC_ALL, "" );
	Nodo *ListaPal;
	Cadena1 text;
	cout << "Ingrese el texto:" << endl;
	fflush(stdin);
	gets(text);
	EnlistarPal(ListaPal, text);
	cout << "Números capicúas en el texto:" << endl;
	RecorreNodo(ListaPal);
	return 0;
}
