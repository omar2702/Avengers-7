#pragma once
#include"Columna.h"
#include"Fila.h"

class DataFrame
{
private:
	vector<Columna*>vector_columnas;
	vector<Fila*>vector_Filas;
	string ID;
public:
	
	long long numeros_col = 0;
	long long counter_col = 0;
	long long counter_Fil = 0;

	DataFrame(string i) : ID(i){}
	DataFrame(colmap* Cm) {
		numeros_col = Cm->size();
		counter_col = Cm->begin()->second->size();
		for (auto it = Cm->begin(); it != Cm->end(); ++it) {
			añadir_columna((*it).second);
		}
		for (long long i = 0; i < counter_col; i++) {
			Fila* auxF = new Fila(i);
			for (long long j = 0; j < numeros_col; j++) {
				auxF->añadir_Col(this->atC(j));
			}
			this->añadir_Fila(auxF);
		}
	}
	DataFrame() {}
	void añadir_columna(Columna* Col) {
		vector_columnas.push_back(Col);
	}
	void añadir_Fila(Fila* Fil) {
		vector_Filas.push_back(Fil);
	}
	Columna* atC(long long id) { return vector_columnas.at(id); }
	Fila* atF(long long id) { return vector_Filas.at(id); }

	void PrintD() {
		for (long long i = 0; i < vector_columnas.size(); i++) {
			cout << vector_columnas[i]->get_nombre() << "\t";
		}
		cout << endl;
		for (long long i = 0; i < vector_Filas.size(); i++) {
			for (long long j = 0; j < vector_columnas.size(); j++) {
				cout << vector_Filas[i]->getData(vector_columnas[j]->get_nombre()) << "\t";
			}
			cout << endl;
		}
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

	
};