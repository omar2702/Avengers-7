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
		if (nc1 == "") return 1;
		else if (op == "mayor") return mayor(r->getData(nc1), value);
		else if (op == "menor") return menor(r->getData(nc1), value);
		else if (op == "igual") return igual(r->getData(nc1), value);
		else if (op == "incia")return inicia(r->getData(nc1), value);
		else if (op == "finaliza") return finaliza(r->getData(nc1), value);
		else if (op == "contenido") return contenido(r->getData(nc1), value);
		else if (op == "nocontenido") return noContenido(r->getData(nc1), value);
	}

	bool mayor(string v1, string v2) {
		if (v1[0] >= 48 && v1[0] <= 57) {
			if (stod(v1) > stod(v2)) return 1;
			else return 0;
		}
		if (v1 > v2) return 1;
		return 0;
	}
	bool menor(string v1, string v2) {
		if (v1[0] >= 48 && v1[0] <= 57) {
			if (stod(v1) < stod(v2)) return 1;
			else return 0;
		}
		if (v1 < v2) return 1;
		return 0;
	}
	bool igual(string v1, string v2) {
		if (v1 == v2) return 1;
		return 0;
	}
	bool inicia(string v1, string v2) {
		for (long long i = 0; i < v2.size(); i++) {
			if (v1[i] != v2[i]) return 0;
			return 1;
		}
	}
	bool finaliza(string v1, string v2) {
		if (v1[v1.size() - 1] == v2[0]) return 1;
		return 0;
	}
	bool contenido(string v1, string v2) {
		for (long long i = 0; i < v1.size(); i++) {
			if (v1[i] == v2[0]) return 1;
		}
		return 0;
	}
	bool noContenido(string v1, string v2) {
		for (long long i = 0; i < v1.size(); i++) {
			if (v1[i] == v2[0]) return 0;
		}
		return 1;
	}

	DataFrame* filter(long long idx, string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {

		DataFrame* nDF = new DataFrame(/*this->vDF[idx]*/);
		for (long long i = 0; i < this->vDF[idx]->counter_Fil; i++) {
			if (compare(nc1, op1, val1, this->vDF[idx]->atF(i)) && compare(nc2, op2, val2, this->vDF[idx]->atF(i))) {
				nDF->añadir_Fila(this->vDF[idx]->atF(i));
			}
		}
		return nDF;
	}

	void index(string col_nombre)
	{

	}

	/*DataFrame* seleccionar(long long idx, vector<string> numero_col) {
		DataFrame* numero_DF = new DataFrame("seleccionar_" + this->vDF[idx]->id);
		for (long long i = 0; i < this->vDF.at(idx)->ColumnaSize(); i++) {
			if (numero_col[i] == this->vDF[idx]->atC(i)->get_nombre()) {
				numero_DF->añadir_columna(this->vDF[idx]->atC(i));
			}
}
		vector<Fila*> numero_F;
		for (long long i = 0; i < this->vDF[idx]->FilaSize(); i++) {
			for (long long j = 0; j < numero_DF->ColumnaSize(); j++) {
				numero_DF->añadir_Fila(this->vDF[idx]->atF(j));
			}
		}
		return numero_DF;
	}*/
	DataFrame* sort(string col_nombre) {

	}

	/* DF filter(string numcol1, string op1, string val1, string numcol2 = "", string op2 = "", string val2 = "") {       ////FILTREAR
		colmap* nCols = new colmap();
		*nCols = this->Columnas;
		vector<Fila*> nFilas;
		for (auto r : this->Filas) {
			if (compare(numCol1, op1, val1, r) && compare(numcol2, opc2, val2, r))
				nFilas.push_back(r);
		}
	}*/
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