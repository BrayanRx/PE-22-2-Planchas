/*
Escriba una función que ordene un arreglo que contiene las edades de los alumnos
del curso POO (10 alumnos), en forma decreciente, usando punteros.
*/
#include <iostream>
#include <string.h>
using namespace std;
typedef char Cadena[20];


int main(){
	int Edades[10];
	for(int i=0; i<10; i++){
		cout << i+1 << ":" << endl;
		cout << "Edad: "; cin >> Edades[i];
	}
	int *pq=Edades + 10 - 1;
	for(int i=0; i<10; i++){
		for(int *p=Edades; p<pq; p++){
			if(*p < *(p+1)){
				int aux = *p;
				*p=*(p+1);
				*(p+1)=aux;
			}
		}	
	}
	for(int i=0; i<10; i++){
		cout << Edades[i] << endl;
	}
	return 0;
}
