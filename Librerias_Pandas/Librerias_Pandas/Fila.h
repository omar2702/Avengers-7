#pragma once
#include<map>
#include <string>
#include "Columna.h"
#include <vector>
#include<iostream>

using namespace std;

class Fila {
private:

	long long Indice = 0;
	string datoString;
	long long datoLong;
	double datoDouble;
	bool datoBool;
	//////////////////////////////////////
	ColumnaString	*ColString; 
	ColumnaLong		*ColLong;
	ColumnaDouble	*ColDouble;
	ColumnaBool		*ColBool;

	//typedef map<string, Col*> colmap;

	//Fila(map<string>, Col*>* cols): cols(cols){}

	/*void getData(string name) {
	return (*cols)[name][idx];
	}*/

	/*Fila(int ind, string str, double doub, long long lon, bool boo, ColumnaString *colS, ColumnaLong *colL,
		ColumnaDouble *colD, ColumnaBool *colB) : indice(ind), datoString(str), datoLong(lon), datoDouble(doub), datoBool(boo),
		ColString(colS), ColLong(colL), ColDouble(colD), ColBool(colB) {}*/

public:
	Fila(int ind) : Indice(ind) {
		datoString = "";
		datoLong = NULL;
		datoDouble = NULL;
		datoBool = NULL;
		ColString = nullptr;
		ColLong = nullptr;
		ColDouble = nullptr;
		ColBool = nullptr;
	}

	Fila(int ind, ColumnaString* CS, ColumnaLong* CL, ColumnaDouble* CD, ColumnaBool* CB) {
		setPunteroString(CS);
        setPunteroLong(CL);
		setPunteroDouble(CD);
		setPunteroBool(CB);
		AsignarDatos();
	}
	~Fila() {
		delete ColString;
		delete ColLong;
		delete ColDouble;
		delete ColBool;
	}
	void AsignarDatos() {
		if (ColString != nullptr)
			datoString = ColString->getDato(this->Indice);
		if (ColLong != nullptr)
			datoLong = ColLong->getDato(this->Indice);
		if (ColDouble != nullptr)
			datoDouble = ColDouble->getDato(this->Indice);
		if (ColBool != nullptr)
			datoBool = ColBool->getDato(this->Indice);
	}

	long long getIndice() { return this->Indice; }
	string getString() { return this->datoString; }
	long long getLong() { return this->datoLong; }
	double getDouble() { return this->datoDouble; }
	bool getBool() { return this->datoBool; }
	void setString(string S) { this->datoString = S; }
	void setLong(long long L) { this->datoLong = L; }
	void setDouble(double D) { this->datoDouble = D; }
	void setBool(bool B) { this->datoBool = B; }
	void setPunteroString(ColumnaString* CS) {this->ColString = CS;}
	void setPunteroLong(ColumnaLong* CL) {	this->ColLong = CL;}
	void setPunteroDouble(ColumnaDouble* CD) {this->ColDouble = CD;}
	void setPunteroBool(ColumnaBool* CB) {	this->ColBool = CB;}
	
	void mostrar() {  //Se eiminara mas adelante, al hacer un lambda en main.cpp
		cout << "| " << datoString << " |\t" << "| " << datoLong << " |\t" << "| " << datoDouble << " |\t" << "| " << datoBool << " |" << endl;
	}
	

};