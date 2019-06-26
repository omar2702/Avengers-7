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

	DataFrame* filter(long long idx, string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {

		colmap* nCols = new colmap();
		for (long long i = 0; i < vDF.at(idx)->counter_Fil; i++) {
			nCols = this->getDF(idx)->atF(i)->getColmap();
		}
		vector<Fila*>nFils;
		DataFrame* nDF = new DataFrame(nCols);
	}

};
