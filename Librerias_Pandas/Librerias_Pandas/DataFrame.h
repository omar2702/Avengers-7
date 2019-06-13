#pragma once
#include"columna.h"
#include"Fila.h"

class dataframe {
private:
	vector<fila*>*Fvector;
	vector<fila*>::iterator it;
	vector<columna*>*COvector;
	vector<columna*>::iterator it2;
public:
	dataframe() {
		Fvector = new vector<fila*>;
		it = Fvector->begin();
		COvector = new vector<columna*>;
		it2 = COvector->begin();
	}
	~dataframe() {
		for (fila* f : *Fvector)
			delete f;
		for (columna* c : *COvector)
			delete c;
		delete Fvector, COvector;
	}
	void Upiterator() { it = Fvector->begin(); }
	void push_back(fila *f) {
		Fvector->push_back(f);
	}
	void insertar(fila *f, long long pos)
	{
		Upiterator();
		Fvector->insert(it + pos, f);
	}
	void borrar(long long pos) {
		Upiterator();
		Fvector->erase(it + pos);
	}
	void borrar(long long first, long long last)
	{
		Upiterator();
		Fvector->erase(it + first, it + last);
	}
	fila *at(long long pos) { return Fvector->at(pos); }

	///////Columna///////
	void UpiteratorCO() { it2 = COvector->begin(); }
	void push_backCO(columna *c) {
		COvector->push_back(c);
	}
	void insertatCO(columna *c, long long pos) {
		UpiteratorCO();
		COvector->insert(it2 + pos, c);
	}
	void borrarCO(long long pos)
	{
		UpiteratorCO();
		COvector->erase(it2 + pos);
	}
	void borrarCO(long long first, long long last)
	{
		UpiteratorCO();
		COvector->erase(it2 + first, it2 + last);
	}
	columna* atCO(long long pos) { return COvector->at(pos); }

	void PrintD() {
		for (long long i = 0; i < Fvector->size(); i++) {
			Fvector->at(i)->PrintF();
		}
	}
};


