#pragma once
#include"Camp.h"
#include<vector>
using namespace std;
class fila
{
protected:
	long long index;
	vector<camp*>*Cvector;
	vector<camp*>::iterator it;
public:
	fila(long long i) : index(i) {
		Cvector = new vector<camp*>;
		it = Cvector->begin();
	}
	~fila() {
		for (camp* a : *Cvector)
			delete a;
		delete Cvector;
	}
	void setIndex(long long i) { index = i; }
	long long getindex() { return index; }

	void upIterator()
	{
		it = Cvector->begin();
	}
	void push_back(camp *c)
	{
		Cvector->push_back(c);
	}
	void insertar(camp* a, long long pos)
	{
		upIterator();
		Cvector->erase(it + pos);
	}
	void borrar(long long pos)
	{
		upIterator();
		Cvector->erase(it + pos);
	}
	void borrar(long long first, long long last) {
		upIterator();
		Cvector->erase(it + first, it + last);
	}

	camp* at(long long pos) {
		return Cvector->at(pos);
	}
	camp**atpoint(long long pos) {
		return &Cvector->at(pos);
	}
	void PrintF() {
		cout << " " << index << "\t";
		for (long long i = 0; i < Cvector->size(); i++) {
			Cvector->at(i)->PrintC();
		}
	}

};