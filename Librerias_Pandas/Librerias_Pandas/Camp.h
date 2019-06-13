#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;
class camp {
protected:
	string type;
	string dataS;
	double dataD;
	long long dataL;
	bool dataB;
public:
	camp(string d) {
		string t = checkType(d);
		type = t;
		if (t == "string") dataS = d, dataD = 0.0, dataL = 0, dataB = NULL;
		else if (t == "double") dataS = "empty=D", dataD = stof(d), dataL = NULL, dataB = NULL;
		else if (t == "long") dataS = "empty=L", dataD = NULL, dataL = stoll(d), dataB = NULL;
		else if (t == "unknown") dataS = d, dataD = NULL, dataL = NULL, dataB = NULL;
		else if (t == "bool") {
			dataD = NULL, dataL = NULL;
			if (d == "true")
				dataB = true;
			else
				dataB = false;
		}
		else dataS = "error", dataD = NULL, dataL = NULL;
	}
	~camp() {}

	string checkType(string d) {
		if (d[0] >= 65 && d[0] <= 122) return "string";
		else if (d == "true" || d == "false") return "bool";
		else if (d[0] >= 48 && d[0] <= 57) {
			if ((double)stoll(d) != stod(d)) return "double";
			else if ((double)stoll(d) == stod(d)) return "long";
		}
		else return "unknown";
	}

	void setType(string t) { type = t; }
	void setData(string d) {
		string t = checkType(d);
		type = t;
		if (t == "string") dataS = d, dataD = 0.0, dataL = 0;
		else if (t == "double") dataS = "empty=D", dataD = stof(d), dataL = NULL;
		else if (t == "long") dataS = "empty=L", dataD = NULL, dataL = stoll(d);
		else if (t == "bool") {
			dataS = d, dataD = NULL, dataL = NULL;
			if (d == "true")
				dataB = true;
			else
				dataB = false;
		}
		else if (t == "unknown") dataS = d, dataD = NULL, dataL = NULL;
		else dataS = "error", dataD = NULL, dataL = NULL;
	}
	string getType() { return type; }
	string getDataS() { return dataS; }
	double getDataD() { return dataD; }
	long long getDataL() { return dataL; }
	bool getDataB() { return dataB; }

	void PrintC() {
		cout << "|\t" << type << "\t";
		if (type == "string" || type == "unknown" || type == "error") cout << dataS;
		else if (type == "double") cout << dataD;
		else if (type == "long")cout << dataL;
		else if (type == "bool")
			if (dataB)
				cout << "True";
			else
				cout << "False";
		cout << "\t|";
	}
};

//Por si no entiendes una funcion o codigo:  :D

//stof:
//Analiza la cadena interpretando su contenido como un número de punto flotante, que se devuelve como un valor de tipo float.