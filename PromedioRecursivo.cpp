/*
Escriba un programa que permita obtener el valor promedio de los elementos de un
arreglo de valores enteros de forma recursiva.
*/
#include <iostream>
using namespace std;

float Promedio(int A[], int n, float n2){
	if(n-1==0) return A[n-1]/n2;
	else return A[n-1]/n2 + Promedio(A, n-1,n2);
}

int main(){
	int n;
	cout << "# de elementos del arreglo: "; cin >> n;
	int El[n];
	for(int i=0; i<n; i++){
		cout << i+1 << ".- "; cin >> El[i];
	}
	cout << "El promedio es: " << Promedio(El, n, n);
	return 0;
}
