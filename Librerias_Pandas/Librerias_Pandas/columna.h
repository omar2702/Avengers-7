#pragma once
#include<vector>
#include"Camp.h"
class columna {
protected:
	string name;
	vector<camp**>*Cvector;
	vector<camp**>::iterator it;
public:
	columna(string s) : name(s)
	{
		Cvector = new vector<camp**>;
		it = Cvector->begin();
	}
	~columna() {
		for (camp** a : *Cvector)
			delete a;
		delete Cvector;
	}
	void setname(string s) { name = s; }
	string getname() { return name; }

	void upIterator()
	{
		it = Cvector->begin();
	}
	void push_back(camp *c)
	{
		Cvector->push_back(&c);
	}
	void insertar(camp* a, long long pos)
	{
		upIterator();
		Cvector->insert(it + pos, &a);
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
		return (*Cvector->at(pos));
	}
	void PrintC() {
		cout << " " << name << "\t";
		for (long long i = 0; i < Cvector->size(); i++) {
			(*Cvector->at(i))->PrintC();
		}
		cout << endl;
	}
};

