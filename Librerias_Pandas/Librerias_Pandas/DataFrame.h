#pragma once
#include"Columna.h"
#include"Fila.h"

class DataFrame
{
private:
	long long numero_filas = 0;
	long long numero_columnas = 0;//preguntar al profe
public:
	vector<Fila*>* Filas;
	vector <Columna*>*Columnas;
	DataFrame()
	{
		Filas = new vector<Fila*>;
		Columnas = new vector<Columna*>;
		agregar_Columna_Bool();
		agregar_Columna_double();
		agregar_Columna_long();
		agregar_Columna_String();
	}

	//DF* select(vector<string> colNames) { //Retorna un DataFrame. Para escoger de las columnas totales que se tienen cuáles se quieren seleccionar. Puede ser en cualquier orden
	//	colmap* nCols = new colmap();
	//	for (auto cn : colNames) {
	//		nCols[cn] = cols[cn];
	//	}
	//	DF* nuevoDF(nCols);
	//	nuevoDF->rows = this->rows;
	//}

	/*DF* filter(string numcol1, string op1, string val1, string numcol2="", string op2="", string val2=""){       ////FILTREAR

		colmap* nCols = new colmap();

		*nCols = this->Columnas;

		vector<Fila*> nFilas;

		for (auto r : this->Filas) {
			if (compare(numCol1, op1, val1, r) && compare(numcol2, opc2, val2, r))
				nFilas.push_back(r);
		}
	}*/

	/*void index(string colname) {

		AVLTree<Fila*, string>* t = new AVLTree<Row* r, string>([=](Row* r){ return r->getdata(colname) });

		for (auto row : this->rows) {
			t->Add(row);
		}
		trees[colname] = t; //mapa de árboles
	}*/

	
	/*DF* sort(string colname) {            ////Ordenar////
		colmap* nCols = new colmap();
		*nCols = this->Columnas;
		DF* nDF=nDF(nCols);
		nDF->rows = this->rows;
		quicksort<Fila*, string>(nDF->rows, [=](Fila* r) {return r->getdata(colname); })
	}*/

	void agregar_Fila()
	{
		/*long long I = 0;
		Filas* aux = new Filas(I);

		Filas->push_back(aux);

		for (long long i = 0; i < numero_columnas; i++) {

			if (Columnas->at(i)->getTipo() == "String")

				aux->setPunteroString((ColumnaString*)Columnas->at(i));

			if (Columnas->at(i)->getTipo() == "Long")

				aux->setPunteroLong((ColumnaLong*)Columnas->at(i));

			if (Columnas->at(i)->getTipo() == "Double")

				aux->setPunteroDouble((ColumnaDouble*)Columnas->at(i));

			if (Columnas->at(i)->getTipo() == "Bool")

				aux->setPunteroBool((ColumnaBool*)Columnas->at(i));

		}

		aux->AsignarDatos();

		numero_filas++;

		I++;*/
	}

	void agregar_Columna_String()
	{
		Columnas->push_back(new ColumnaString());
		numero_columnas++;
	}
	void agregar_Columna_Bool()
	{
		Columnas->push_back(new ColumnaBool());
	}
	void agregar_Columna_double()
	{
		Columnas->push_back(new ColumnaDouble());
	}
	void agregar_Columna_long()
	{
		Columnas->push_back(new ColumnaLong());
	}
	void mostrar() { 

		cout << "String \t Long \t Double \t Bool" << endl; //Falta hacer que se alineen bien los nombres de las columnas

		for (long long i = 0; i < numero_filas; i++) {

			Filas->at(i)->mostrar();

		}

	}
};