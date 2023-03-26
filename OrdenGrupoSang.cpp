/*
Escriba un programa que permite ordenar un registro con la siguiente estructura:
Nombres, Apellidos, Edad, Grupo Sanguíneo (A, B, O, AB). El orden se realiza por
edad en orden ascendente, si resultan iguales se considera el Grupo Sanguíneo en
orden descendente.
*/

#include <iostream>
#include <string.h>
using namespace std;
typedef char Cadena[20];

struct Datos{
	Cadena Nombre;
	Cadena ApellidoP;
	Cadena ApellidoM;
	int edad;
	Cadena GS;
};

void ImpReg(Datos A[], int n){
	for(int i=0; i<n; i++){
		cout << i+1 << "." << endl;
		cout << A[i].Nombre << " " << A[i].ApellidoP << " " << A[i].ApellidoM << endl;
		cout << "Edad: "<< A[i].edad << endl;
		cout << "Grupo Sanguíneo: "<< A[i].GS << endl << endl;
	}
}

int main(){
	setlocale( LC_ALL, "" );
	
	int n;
	cout << "Ingrese la cantidad de registros: "; cin >> n;
	Datos Reg[n];
	for(int i=1; i<=n; i++){
		cout << i << "." << endl;
		cout << "Nombre: "; cin >> Reg[i-1].Nombre;
		cout << "Apellido P: "; cin >> Reg[i-1].ApellidoP;
		cout << "Apellido M: "; cin >> Reg[i-1].ApellidoM;
		cout << "Edad: "; cin >> Reg[i-1].edad;
		cout << "Grupo Sanguíneo: "; cin >> Reg[i-1].GS;
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(Reg[i].edad*10-strcmp(Reg[i].GS, Reg[j].GS) > Reg[j].edad*10){
				Datos Aux=Reg[i];
				Reg[i]=Reg[j];
				Reg[j]=Aux;
			}
		}
	}
	
	cout << "Datos ordenados: " << endl;
	ImpReg(Reg, n);
	
	return 0;
}
