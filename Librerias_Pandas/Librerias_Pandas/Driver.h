#pragma once

#include <sstream>
#include <fstream>
#include"DataFrame.h"
#include<iostream>

using namespace std;

class Driver {

public:
	vector<DataFrame*>vDF;
public:
	Driver() {}
	~Driver() {}
	DataFrame* getDF(long long idx) {
		return vDF.at(idx);
	}

	int addFile(string filename) {
		DataFrame* auxD = new DataFrame(filename);
		ifstream f(filename);
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir\n";

			return 0;
		}

		while (getline(f, line, '\n')) {
			stringstream ss(line);
			if (auxD->numeros_col == 0) {
				while (getline(ss, num, ',')) {
					Columna* auxCo = new Columna(num.c_str(), auxD->numeros_col);
					auxD->añadir_columna(auxCo);
					auxD->numeros_col++;
				}
			}

			else {
				Fila* auxF = new Fila(auxD->counter_Fil);
				while (getline(ss, num, ',')) {
					auxD->atC(auxD->counter_col)->agregar(num.c_str());
					auxF->añadir_Col(auxD->atC(auxD->counter_col));
					auxD->counter_col++;
				}
				auxD->añadir_Fila(auxF);
				auxD->counter_Fil++;
			}
			auxD->counter_col = 0;
		}
		vDF.push_back(auxD);
		f.close();
	}

	bool compare(string nc1, string op, string value, Fila*  r)
	{
		if (op == ">") return r->getData(nc1) > value;
		else if (op == "<") return r->getData(nc1) < value;
		else if (op == "=") return r->getData(nc1) == value;
		else if (op == "<=")return r->getData(nc1) <= value;
		else if (op == ">=") return r->getData(nc1) >= value;
		else if (op == "inciacon") {
			if (r->getData(nc1).find(value) == 0) {
				return true;
			}
		}
		else if (op == "finzalizacon") {
			if (r->getData(nc1).find(value) == r->getData(nc1).size() - 1) {
				return true;
			}
		}
		else if (op == "contains") {
			if (r->getData(nc1).find(value) >= 0) {
				return true;
			}
		}
		else if (op == "nocontains") {
			if (r->getData(nc1).find(value) < 0) {
				return true;
			}
		}
	}

	DataFrame* filter(long long idx, string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {

		colmap* nCols = new colmap();
		*nCols = this->compare;
		vector<Fila*>nFils;
		DataFrame* nDF = new DataFrame(nCols);
	}

	DataFrame* seleccionar() {

	}

	//////////////////////////////////////
	/* DF filter(string numcol1, string op1, string val1, string numcol2 = "", string op2 = "", string val2 = "") {       ////FILTREAR
		colmap* nCols = new colmap();
		*nCols = this->Columnas;
		vector<Fila*> nFilas;
		for (auto r : this->Filas) {
			if (compare(numCol1, op1, val1, r) && compare(numcol2, opc2, val2, r))
				nFilas.push_back(r);
		}
	}*/
		//////////////////////////////////////
		DataFrame * select(long long col_nombres) {
		colmap* ncols = new colmap();
	}

	//DF* select(vector<string> colNames) { 
	//Retorna un DataFrame. Para escoger de las columnas totales que se tienen cuáles se quieren seleccionar. Puede ser en cualquier orden
	//	colmap* nCols = new colmap();
	//	for (auto cn : colNames) {
	//		nCols[cn] = cols[cn];
	//	}
	//	DF* nuevoDF(nCols);
	//	nuevoDF->rows = this->rows;
	//}

	/*void index(string colname) {
	AVLTree<Fila*, string>* t = new AVLTree<Row* r, string>([=](Row* r){ return r->getdata(colname) });
	for (auto row : this->rows) {
	t->Add(row);
	}
	trees[colname] = t; //mapa de árboles
	}*/


	/* DF sort(string colname) {            ////Ordenar////
		colmap* nCols = new colmap();
		*nCols = this->Columnas;
		DF* nDF = nDF(nCols);
		nDF->rows = this->rows;
		quicksort<Fila*, string>(nDF->rows, [=](Fila* r) {return r->getdata(colname); })
	}*/


};