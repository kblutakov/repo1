//============================================================================
// Name        : funcio34.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// modified for github
// testing branch
#include <iostream>
#define MAX 10
using namespace std;

struct client{
	string DNI;
	string nom;
	double sou;
	bool empty;
};

void reset(client taula[MAX]);
int  menu();
int trobar_empty(client taula[MAX]);
void consulta(client taula[MAX]);
int validar(string dni, client taula[MAX]);
void alta(string dni, client taula[MAX], int posicio);
void baixa(client taula[MAX], int posicio);
void consulta(client taula[MAX]);
void modificacio(client taula[MAX], int posicio);
void mostrarcli(client cli);


int main() {
	int opcio;
	client taula_clients[MAX];
	reset(taula_clients);
	int empty, posicio_dni;
	string dni;


	do
	{
				switch(opcio=menu()){
				case 1:
					empty=trobar_empty(taula_clients);
					cout << "posicio a inserir " << empty << endl;
					if(empty!=-1){
						cout << "Entra el DNI del client: " << endl;
						cin >> dni;
						posicio_dni=validar(dni, taula_clients);
						if(posicio_dni==-1){
							alta(dni, taula_clients, empty);				//alta
						}else{
							cout << "Error. Aquest DNI esta registrat."<< endl;
						}
					}else{
						cout << "Error. La taula esta plena."<< endl;
					}
					break;

				case 2:
					cout << "Entra el DNI del client: "<< endl;
					cin >> dni;
					posicio_dni=validar(dni, taula_clients);
					if(posicio_dni != -1){
						cout << "segur que vol donar de baixa (s/n): " << endl;
						mostrarcli(taula_clients[posicio_dni]);
						baixa(taula_clients, posicio_dni);
					}else{
						cout << "Error. Aquest DNI no esta registrat."<< endl;
					}
					break;

				case 3:
					cout << "Entra el DNI del client: "<< endl;
					cin >> dni;
					posicio_dni=validar(dni, taula_clients);
					if(posicio_dni != -1){
						cout << "DNI trobat. Pots fer modificacio: "<<endl;
						modificacio(taula_clients, posicio_dni);
					}else{
						cout << "Error. Aquest DNI no esta registrat."<< endl;
					}

					break;

				case 4:
					consulta(taula_clients);

					break;

				case 5:
						cout << "bye bye";
					break;

				default:

					break;

				}

	}while(opcio!=5);

	return 0;
}

void reset(client taula[MAX]){
	for(int i=0; i< MAX; i++){
		taula[i].empty=true;
	}
}

int menu(){
	int choice;
	do{
		cout << "Tria opcio:" << endl;
		cout << "1. Fer alta" << endl;
		cout << "2. Fer baixa" << endl;
		cout << "3. Fer modificacio" << endl;
		cout << "4. Fer consulta a la taula" << endl;
		cout << "5. Sortir" << endl;
		cin >> choice;

	}while(choice<1 and choice>5);
	return choice;
}
int trobar_empty(client taula[MAX]){

	int trobat=false;
	int i=0;
	while(!trobat and i<MAX){
		if(taula[i].empty==true)
			trobat=true;
		else
			i++;
	}
	if(trobat)
		return i;
	else
		return -1;

}
int validar(string dni, client taula[MAX]){
	bool trobat=false;
	int i=0;

	while(!trobat and i<MAX){
		if(taula[i].DNI==dni)  //if(taula[i].DNI==dni)
			trobat=true;
		else
			i++;
	}
	if(trobat)
		return i;
	else
		return -1;
}
void alta(string dni, client taula[MAX], int posicio){

	string nom;

	taula[posicio].DNI=dni;

	cout << "Entra el nom del client: " << endl;
	cin >> taula[posicio].nom;


	cout << "Entra el sou del client: " << endl;
	cin >> taula[posicio].sou;


	taula[posicio].empty=false;
}
void baixa(client taula[MAX], int posicio){
	taula[posicio].empty=true;
}

void mostrarcli(client cli)
{
				cout << "DNI: " << cli.DNI;
				cout << "		Nom: " << cli.nom;
				cout << "		Sou: " << cli.sou;
				cout << endl;
}

void consulta(client taula[MAX]){
	int i=0;
	for(i=0; i<MAX; i++){
		if(taula[i].empty==false){
			mostrarcli(taula[i]);
		}
	}
}

void modificacio(client taula[MAX], int posicio){
	string nom,dni;
	double sou;
	cout << "Entra el DNI del client: " << endl;
	cin >> dni;
	taula[posicio].DNI=dni;
	cout << "Entra el nom del client: " << endl;
	cin >> nom;
	taula[posicio].nom=nom;
	cout << "Entra el sou del client: " << endl;
	cin >> sou;
	taula[posicio].sou=sou;
	taula[posicio].empty=false;
}






