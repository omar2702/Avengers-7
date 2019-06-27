#include <iostream>
#include <locale.h>
#include <conio.h>
#include "Archivo.h"
#include <map>
using namespace std;
using namespace System;
Driver d1;
long long idxDF = -1;

void importar_F() {
	string filename;
	cout << "\tIngrese el nombre del archivo a importar: ";
	cin >> filename;
	while (!d1.findFile(filename)) {
		cout << endl;  cout << "\tError! Ingrese un nombre de archivo existente: ";
		cin >> filename;
	}
	cout << endl;
	d1.addFile(filename), idxDF++;
	d1.getDF(idxDF)->printD(), cout << endl;
}
void logo() {
	cout << "\tTRABAJO FINAL ALGORITMOS Y ESTRUCUTRA DE DATOS\n";
}

void mostrar() {
	cout << "Introduzca el indice del dataframe a mostrar: ";
	cout << endl; d1.printvDF(), cout << endl, cout << endl;
	cin >> idxDF;
	d1.getDF(idxDF - 1)->printD(), cout << endl;
}
void indexar() {
	string nombreColumna;
	cout << "Introduzca el indice del dataframe a indexar: ";
	cout << endl, d1.printvDF(), cout << endl;
	cin >> idxDF, cout << endl;
	cout << "Introduzca el nombre de la columna del dataframe a indexar: ", cout << endl, cout << endl;
	cin >> nombreColumna, cout << endl;
	d1.index(idxDF - 1, nombreColumna);
	cout << "Indexado exitoso! La altura del arbol generado es: ";
	cout << d1.vDF[idxDF - 1]->getMapTree()[nombreColumna]->Height(), cout << endl, cout << endl;
}
void ordenar() {
	string nombreColumna;
	cout << "Introduzca el indice del dataframe a ordenar: ";
	cout << endl, d1.printvDF(), cout << endl;
	cin >> idxDF, cout << endl;
	cout << "Introduzca el nombre de la columna del dataframe a ordenar: ", cout << endl, cout << endl;
	cin >> nombreColumna, cout << endl;
	d1.vDF.push_back(d1.mergesort(idxDF - 1, nombreColumna)), idxDF++;
	cout << "Ordenamiento exitoso! Imprimiendo el nuevo dataframe generado: ";
	d1.vDF[d1.vDF.size() - 1]->printD(), cout << endl, cout << endl;
}
void seleccionar() {
	vector<string>nCols;
	string col;
	cout << "Introduzca el indice del dataframe a seleccionar: ";
	cout << endl, d1.printvDF(), cout << endl;
	cin >> idxDF, cout << endl;
	cout << "Ingrese el numero de columnas a seleccionar: ", cout << endl;
	int numero;
	cin >> numero;
	for (int i = 0; i < numero; i++) {
		cout << endl, cout << "Nombre de la columna " << i + 1 << ": ";
		cin >> col;
		nCols.push_back(col);
	}
	cout << endl, d1.vDF.push_back(d1.select(idxDF - 1, nCols)), idxDF++;
	d1.vDF[d1.vDF.size() - 1]->printD(), cout << endl, cout << endl;
}
void filtrar() {
	string nc1, op1, val1, nc2 = "", op2 = "", val2 = "";
	int dos = 0;
	cout << "Introduzca el indice del dataframe a filtrar: ";
	cout << endl, d1.printvDF(), cout << endl;
	cin >> idxDF, cout << endl;
	cout << "Ingrese el numero de columnas a filtrar: ", cout << endl;
	cin >> dos;
	cout << "Ingrese el nombre de la columna " << dos - 1 << " a filtrar: ", cout << endl;
	cin >> nc1, cout << endl;
	cout << "Ingrese la operacion " << dos - 1 << " para filtrar: ", cout << endl;
	cin >> op1, cout << endl;
	cout << "Ingrese el valor de la operacion " << dos - 1 << " para filtrar: ", cout << endl;
	cin >> val1, cout << endl;
	if (dos == 2) {
		cout << "Ingrese el nombre de la columna " << dos << " a filtrar: ", cout << endl;
		cin >> nc2, cout << endl;
		cout << "Ingrese la operacion " << dos << " para filtrar: ", cout << endl;
		cin >> op2, cout << endl;
		cout << "Ingrese el valor de la operacion " << dos << " para filtrar: ", cout << endl;
		cin >> val2, cout << endl;
	}
	d1.vDF.push_back(d1.filter(idxDF - 1, nc1, op1, val1, nc2, op2, val2));
	d1.vDF[d1.vDF.size() - 1]->printD(), cout << endl, cout << endl;
}
void exportar_F() {
	string nombreDF;
	cout << "Introduzca el indice del dataframe a exportar: ";
	cout << endl, d1.printvDF(), cout << endl;
	cin >> idxDF, cout << endl;
	cout << "Ingrese el nombre del archivo a exportar: ", cout << endl;
	cin >> nombreDF;
	d1.exportFile(d1.vDF[idxDF - 1], nombreDF);
}
void opciones() {
	cout << "\tOpciones:", cout << endl, cout << endl;
	cout << "\t1. Importar archivo", cout << endl;
	cout << "\t2. Mostrar Dataframe", cout << endl;
	cout << "\t3. Indexar Dataframe", cout << endl;
	cout << "\t4. Ordenar Dataframe", cout << endl;
	cout << "\t5. Seleccionar Elementos", cout << endl;
	cout << "\t6. Filtrar datos", cout << endl;
	cout << "\t7. Exportar Dataframe", cout << endl;
	cout << "\t8. Salir del programa", cout << endl, cout << endl;
}
void menu() {
	string opcion;
	while (opcion != "8") {
		opciones();
		do {
			cin >> opcion;
		} while (opcion[0] < 48 || opcion[0] > 57);
		Console::Clear();
		switch (opcion[0])
		{
		case '1':
			importar_F();
			break;
		case '2':
			mostrar();
			break;
		case '3':
			indexar();
			break;
		case '4':
			ordenar();
			break;
		case '5':
			seleccionar();
			break;
		case '6':
			filtrar();
			break;
		case '7':
			exportar_F();
			break;
		default:
			break;
		}
	}
}

void main() {
	menu();
}