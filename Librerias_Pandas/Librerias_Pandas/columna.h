#pragma once
#include <string>
#include <vector>
using namespace std;

class Columna {
protected:
	string nombre_columna;
	string tipo_De_Columna = "undefined";
	
	vector<bool>*dBool = nullptr;
	vector<string>*dString = nullptr;
	vector<double>*dDouble = nullptr;
	vector<long long>*dLong_Long = nullptr;

	long long Indice;
	bool definir = 0;
public:
	Columna(string nombre, long long Index) : nombre_columna(nombre), Indice(Index) {}
	Columna(){}

	string get_nombre() { return nombre_columna;}
	void set_nombre(string nombre) { nombre_columna = nombre; }

	long long size() {
		if (tipo_De_Columna == "bool") return dBool->size();
		else if (tipo_De_Columna == "string") return dString->size();
		else if (tipo_De_Columna == "double") return dDouble->size();
		else if (tipo_De_Columna == "long") return dLong_Long->size();
	}
	string checkType(string e) {
		if (e == "true" || e == "false" || e == "1" || e == "0")
			return "bool";
		else if (e[0] >= 65 && e[0] <= 122) return "string";
		else if (e[0] >= 48 && e[0] <= 57) {
			if ((double)stoll(e) != stod(e)) return "double";
			else if ((double)stoll(e) == stod(e)) return "long";
		}
		else return "unknown";
	}
	void agregar(string Data) {
		if (definir == 0) {
			tipo_De_Columna = checkType(Data);
			if (tipo_De_Columna == "bool") dBool = new vector<bool>;
			else if (tipo_De_Columna == "string") dString = new vector<string>;
			else if (tipo_De_Columna == "double") dDouble = new vector<double>;
			else if (tipo_De_Columna == "long") dLong_Long = new vector<long long>;
			definir = 1;
		}
		if (tipo_De_Columna == "bool") {
			if (Data == "false" || Data == "0") dBool->push_back(false);
			else if (Data == "true" || Data == "1") dBool->push_back(true);
		}
		else if (tipo_De_Columna == "string") dString->push_back(Data);
		else if (tipo_De_Columna == "double") dDouble->push_back(stod(Data));
		else if (tipo_De_Columna == "long") dLong_Long->push_back(stoll(Data));
	}
		string get_data(long long I) {
			if (tipo_De_Columna == "bool") return to_string(dBool->at(I));
			else if (tipo_De_Columna == "string") return dString->at(I);
			else if (tipo_De_Columna == "long") return to_string(dLong_Long->at(I));
			else if (tipo_De_Columna == "double") return to_string(dDouble->at(I));
	}
};



