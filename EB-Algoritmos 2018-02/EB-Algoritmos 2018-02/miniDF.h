#pragma once
//#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;

class columna {
	vector<int> elementos;
public:
	columna() {}

	void añadirE(int a) {
		elementos.push_back(a);
	}
	int getE(int f) {
		return elementos[f];
	}
};

class fila {
	vector<columna*> columnas;
	int indice;
public:
	fila(int a, vector<columna*> f) : indice(a), columnas(f) {}
	int getElem(int nom) {
		return columnas[nom]->getE(indice);
	}

	int getIndx() {
		return indice;
	}
	void mostrarF() {
		for (int i = 0; i < columnas.size(); i++) {
			cout << columnas[i]->getE(indice) << " ";
		}
		cout << endl;
	}
	static void simEl(fila*& a) {
		a->indice = -1;
	}
};

class miniDF {
	vector<fila*> Filas;
	vector<columna*> Col;
public:
	miniDF(int a, int b) {
		for (int i = 0; i < a; i++) {
			Col.push_back(new columna());
		}
	}
	void añadirFila(vector<int> we) {
		for (int i = 0; i < we.size(); i++) {
			Col[i]->añadirE(we[i]);
		}
		fila* a = new fila(Filas.size(), Col);
		Filas.push_back(a);
	}
	void act(int a, int b) {
		AVL<fila*, int>* arb = new AVL<fila*, int>([=](fila* r) {
			return r->getElem(a);
		});

		for (int i = 0; i < Filas.size(); i++) {
			if (Filas[i]->getIndx() != -1)
				arb->add(Filas[i]);
		}
		//arb->ord();
		vector<fila*> wi = arb->Busc(b);
		//cout << wi.size() << endl;
		for (auto& we : wi) {
			//we->mostrarF();
			fila::simEl(we);
		}
		delete arb;
	}

	void mostrar() {
		for (int i = 0; i < Filas.size(); i++) {
			if (Filas[i]->getIndx() != -1) {
				for (int j = 0; j < Col.size(); j++) {
					cout << Filas[i]->getElem(j) << " ";
				}
				cout << endl;
			}
		}
	}

};
