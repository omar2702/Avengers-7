#pragma once
#include "columna.h"
#include <map>

typedef map<string, Columna*>colmap;

class Fila {
protected:
	long long indice;
	colmap* cols;

public:
	Fila(long long idx) : indice(idx) { cols = new colmap; }

	void añadir_Col(Columna* c) {
		(*cols)[c->get_nombre()] = c;
	}

	string getData(string name) {
		return cols->at(name)->get_data(indice);
	}

	colmap* getColmap() {
		return cols;
	}
};