#pragma once

#include <sstream>
#include <fstream>
#include"DataFrame.h"
#include<iostream>

using namespace std;

class Driver {

public:
	vector<DataFrame*>vector_DF;
public:
	Driver() {}
	~Driver() {}
	DataFrame* getDF(long long idx) {
		return vector_DF.at(idx);
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
		vector_DF.push_back(auxD);
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

		DataFrame* nDF = new DataFrame(this->vector_DF[idx]);
		for (long long i = 0; i < this->vector_DF[idx]->counter_Fil; i++) {
			if (compare(nc1, op1, val1, this->vector_DF[idx]->atF(i)) && compare(nc2, op2, val2, this->vector_DF[idx]->atF(i))) {
				nDF->añadir_Fila(this->vector_DF[idx]->atF(i));
			}
		}
		return nDF;
	}

	void index(string col_nombre)
	{

	}

	void merge(vector<Fila*> &vec, long long inicio, long long fin, string nombreColumna) {
		long long length = (fin - inicio) + 1;
		vector<Fila*> aux(length);
		long long mid = (fin + inicio) / 2;
		long long i = inicio;
		long long j = mid + 1;
		for (long long k = 0; i <= mid || j <= fin; k++) {
			if (i > mid || j <= fin && vec[j]->getData(nombreColumna) < vec[i]->getData(nombreColumna)) {
				aux[k] = vec[j];
				j++;
			}
			else {
				aux[k] = vec[i];
				i++;
			}
		}
		for (long long k = 0; k < length; k++) {
			vec[inicio + k] = aux[k];
		}
	}

	void sort(vector<Fila*> &vec, int i, int f, string nombreColumna) {
		if (i < f) {
			int mid = (f + i) / 2;
			sort(vec, i, mid, nombreColumna);
			sort(vec, mid + 1, f, nombreColumna);
			merge(vec, i, f, nombreColumna);
		}
	}

	void mergesort(vector<Fila*> &vec, string nombreColumna) {
		sort(vec, 0, vec.size() - 1, nombreColumna);
	}


	DataFrame* OrdenarMerge(string nombreColumna, long long id) {
		DataFrame* nDF = new DataFrame(this->vector_DF[id]);
		for (long long i = 1; i < nDF->FilaSize(); i++) {
			mergesort(nDF->vector_Filas, nombreColumna);
		}
		return nDF;
	}


	DataFrame* seleccionar(long long idx, vector<string> numero_col) {
		DataFrame* numero_DF = new DataFrame("seleccionar_" + this->vector_DF[idx]->ID);
		for (long long i = 0; i < this->vector_DF.at(idx)->ColumnaSize(); i++) {
			if (numero_col[i] == this->vector_DF[idx]->atC(i)->get_nombre()) {
				numero_DF->añadir_columna(this->vector_DF[idx]->atC(i));
			}
}
		vector<Fila*> numero_F;
		for (long long i = 0; i < this->vector_DF[idx]->FilaSize(); i++) {
			for (long long j = 0; j < numero_DF->ColumnaSize(); j++) {
				numero_DF->añadir_Fila(this->vector_DF[idx]->atF(j));
			}
		}
		return numero_DF;
	}
};