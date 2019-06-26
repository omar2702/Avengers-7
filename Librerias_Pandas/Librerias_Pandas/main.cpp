#include <iostream>
#include <conio.h>
#include"Driver.h"
#include<vector>
#include <ctime>

using namespace std;

void menu()
{
	cout << "[1] Cargar archivo\n"
		<< "[2] Guardar DataFrame\n"
		<< "[3] Listar DataFrames\n"
		<< "[4] Crear DataFrame\n"
		<< "[5] Mostrar DataFrame\n"
		<< "[0] SALIR!\n"
		<< "\n-- Ingrese una opción [0..5]: ";
}

void cargarDF(vector<DataFrame*>& dfs) {
	string name;
	cout << "Nombre del archivo: ";
	cin.get();
	getline(cin, name);
	//TODO cargar archivo
	//dfs.push_back(cargarDeArchivo(name));
	dfs.push_back(new DataFrame());
}
void guardarDF(vector<DataFrame*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleccione un DF [1.." << dfs.size() << "] ";
		cin >> i; --i;
	} while (i < 0 | i >= dfs.size());
	cout << "Nombre del archivo: "; getline(cin, name);
	cin.get();
	getline(cin, name);
	//TODO guardar dataframe en archivo
	// guardarDF(dfs[i], name);
}
void listarDFs(vector<DataFrame*>& dfs) {
	int i = 0;
	for (auto df : dfs)
	{
		cout << ++i << "]\n"; // TODO imprimir alguna otra informacion del DF
	}
}
DataFrame* seleccionar(DataFrame* df) {
	vector<string> cols;
	string col;
	do
	{
		cout << "Ingrese columna: ";
		cin.get();
		getline(cin, col);
		if (col != "") cols.push_back(col);
	} while (col != "");
	if (cols.size() > 0)
	{
		//return df.seleccionar(cols);
	}
	return nullptr;
}
DataFrame* filtrar(DataFrame* df) {}
DataFrame* ordenar(DataFrame* df) {}
void crearDF(vector<DataFrame*>& dfs) {
	int i;
	string name;
	do
	{
		cout << "Seleccione un DF [1.." << dfs.size() << "]: ";
		cin >> i; --i;
	} while (i < 0 || i >= dfs.size());
	char op;
	do
	{
		cout << "[1] Seleccionar\n"
			<< "[2] Filtrar\n"
			<< "[3] Ordenar\n"
			<< "[0] Cancelar\n"
			<< "\n-- Ingrese una opción [0..3]: ";
		cin >> op;
		DataFrame* nuevo;
		switch (op)
		{
		case '1': nuevo = seleccionar(dfs[i]); break;
		case '2': nuevo = filtrar(dfs[i]); break;
		case '3': nuevo = ordenar(dfs[i]); break;
		}
		if (nuevo != nullptr)
		{
			dfs.push_back(nuevo);
		}
	} while (op != 0);


}
void mostrarDF(vector<DataFrame*>& dfs) {}


int main()
{
	char op;
	vector<DataFrame*> dfs;
	do
	{
		menu();
		cin >> op;
		switch (op)
		{
		case 0: cout << "Bye Bye!"; break;
		case 1: cargarDF(dfs); break;
		case 2: guardarDF(dfs); break;
		case 3: listarDFs(dfs); break;
		case 4: crearDF(dfs); break;
		case 5: mostrarDF(dfs); break;
		}
	} while (op != 0);
}