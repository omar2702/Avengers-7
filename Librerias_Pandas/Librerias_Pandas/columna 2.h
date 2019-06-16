#pragma once

#include <string>

#include <vector>

using namespace std;



class Columna2 {

protected:

	string tipoDeDato;

public:

	Columna2(string tipo) : tipoDeDato(tipo) {}



	string getTipo() { return tipoDeDato; }			//Devuelve el "nombre" de la columna  El nombre de una columna indica que tipo de datos contiene

	void setTipo(string t) { this->tipoDeDato = t; } //Cambia el "nombre" de la columna

	~Columna2() {}

};



class ColumnaString : public Columna2 {

private:

	vector<string>* datosString;

public:

	ColumnaString() : Columna2("String") {

		datosString = new vector<string>;

		//Agregando 2 "palabras" aleatorias con propósitos de prueba

		agregar("asdf");



	}



	~ColumnaString() {

		delete datosString;

	}



	void agregar(string s) {

		datosString->push_back(s);

	}



	string getDato(int indice) {

		return datosString->at(indice);

	}

};



class ColumnaLong : public Columna2 {

private:

	vector<long long>* datosLong;

public:

	ColumnaLong() :Columna2("Long") {

		datosLong = new vector<long long>;

		agregar(rand() % 1000000); //Agregando 2 long longs aleatorios con propósitos de prueba

		agregar(rand() % 1000000);

	}



	~ColumnaLong() {



		delete datosLong;

	}



	void agregar(long long l) {

		datosLong->push_back(l);

	}



	long getDato(int indice) {

		return datosLong->at(indice);

	}

};



class ColumnaDouble : public Columna2 {

private:

	vector<double>* datosDouble;

public:

	ColumnaDouble() : Columna2("Double") {

		datosDouble = new vector<double>;

		agregar((rand() % 100000) + rand() % 11 / 10);  //Agregando 2 doubles aleatorios con propósitos de prueba

		agregar((rand() % 100000) + rand() % 11 / 10);

	}



	~ColumnaDouble() {



		delete datosDouble;

	}



	void agregar(double d) {

		datosDouble->push_back(d);

	}



	double getDato(int indice) {

		return datosDouble->at(indice);

	}

};



class ColumnaBool : public Columna2 {

private:

	vector<bool>* datosBool;

public:

	ColumnaBool() : Columna2("Bool") {

		datosBool = new vector<bool>;

		agregar(rand() % 2);

	}



	~ColumnaBool() {

		delete datosBool;

	}



	void agregar(bool b) {

		datosBool->push_back(b);

	}



	bool getDato(int indice) {

		return datosBool->at(indice);

	}

};