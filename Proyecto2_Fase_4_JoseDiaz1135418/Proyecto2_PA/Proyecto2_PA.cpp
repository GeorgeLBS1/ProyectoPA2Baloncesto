#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
#define NOM_ARCHIVO  "Entrada.txt"
#define MAX_CHARS  100
#define MAX_LINEA  1024

//Estructura del jugador para almacenar los datos
class PERSONA {
public:
	string Codigo_nombre;
	string Conferencia;
	string Equipo;
	string Posicion;
	int potencia;
	string habilidad;
	float altura;
	int puntos_anotados;
	int balones_robados;
	int rebotes;
	int tapones;
	int votacion;
	bool Latiene;
	bool bloqueado;
};

struct Jugador {
	char Codigo_nombre[MAX_CHARS];
	char Conferencia[MAX_CHARS];
	char Equipo[MAX_CHARS];
	char Posicion[MAX_CHARS];
	int potencia;
	char habilidad[MAX_CHARS];
	float altura;
	int puntos_anotados;
	int balones_robados;
	int rebotes;
	int tapones;
	int votacion;	
};

//Creacion del nodo
class Nodo
{
public:
	string Codigo_nombre;
	string Conferencia;
	string Equipo;
	string Posicion;
	int potencia;
	string habilidad;
	float altura;
	int puntos_anotados;
	int balones_robados;
	int rebotes;
	int tapones;
	int votacion;
	Nodo *izquierdo;
	Nodo *derecho;
public:
	Nodo(char* Codigo, char* Confe, char* Equi, char* posi, int poten, char* habil, float altu, int robados, int anotados, int rebot, int tapo, int vot ) {
		
		Codigo_nombre = Codigo;
		Conferencia = Confe;
		Equipo = Equi;
		Posicion = posi;
		potencia = poten;
		habilidad = habil;
		altura = altu;
		puntos_anotados = anotados;
		balones_robados = robados;
		rebotes = rebot;
		tapones = tapo;
		votacion = vot;
		izquierdo = NULL;
		derecho = NULL;
	};

	~Nodo() {};
};
PERSONA Basquetbolista[1000];
//Creacion del arbol
class ArbolBB
{
public:
	Nodo *raiz;

public:
	ArbolBB() {
		raiz = NULL;
	};

	void Insertar(char* Codigo, char* Confe, char* Equi, char* posi, int poten, char* habil, float altu, int anotados, int robados, int rebot, int tapo, int vot) {
		Nodo *nuevo = new Nodo(Codigo, Confe, Equi, posi, poten, habil, altu, anotados, robados, rebot, tapo, vot);

		if (raiz == NULL) { //Verifico que no exista nodo raíz
			raiz = nuevo;
		}
		else
		{
			if (nuevo->potencia > raiz->potencia) {
				InsertarAux(nuevo, raiz, true);
			}
			else if (nuevo->potencia < raiz->potencia) {
				InsertarAux(nuevo, raiz, false);
			}
		}
	};

private:
	void InsertarAux(Nodo *nuevo, Nodo *padre, bool esDerecho) {
		if (esDerecho) {
			if (padre->derecho == NULL) { // Insertar acá
				padre->derecho = nuevo;
			}
			else
			{
				if (nuevo->potencia > padre->derecho->potencia)
				{
					InsertarAux(nuevo, padre->derecho, true);
				}
				else if (nuevo->potencia < padre->derecho->potencia) {
					InsertarAux(nuevo, padre->derecho, false);
				}
			}
		}
		else
		{
			if (padre->izquierdo == NULL) {
				padre->izquierdo = nuevo;
			}
			else
			{
				if (nuevo->potencia > padre->izquierdo->potencia)
				{
					InsertarAux(nuevo, padre->izquierdo, true);
				}
				else if (nuevo->potencia < padre->izquierdo->potencia) {
					InsertarAux(nuevo, padre->izquierdo, false);
				}
			}
		}
	}


};

void Simulacion1(int Personas_enLosArboles)
{
	int acciones_rival = 0;
	int QuienLaTiene;
	int AleatorioParaElPase;
	int AleatorioDrible;
	int AleatorioTiro;
	int RandomTapon;
	int RandomRobar;
	int RandomSaltar;
	bool posesion = true;
	int puntajeX = 0;
	int puntajeY = 0;
	int Tu[3];
	int Rival[3];
	//Selecciona los jugadores para el partido de forma aleatoria y aqui se verifica que no puede ser el mismo jugador por equipo
	do
	{
		for (int i = 0; i < 3; i++)
		{
			Tu[i] = rand() % Personas_enLosArboles + 0;
			Rival[i] = rand() % Personas_enLosArboles + 0;
		}
	} while (Tu[0] == Tu[1] || Tu[0] == Tu[2] || Tu[1] == Tu[2] || Tu[0] == Rival[0] || Tu[1] == Rival[0] || Tu[2] == Rival[0] || Tu[0] == Rival[1] || Tu[0] == Rival[2] || Rival[0] == Rival[1] || Rival[0] == Rival[2] || Rival[2] == Rival[1]);

	cout << "Tu equipo esta conformado por: \n";
	for (int i = 0; i < 3; i++)
	{
		cout << Basquetbolista[Tu[i]].Codigo_nombre << "\n";
	}
	cout << "\nEl equipo rival esta conformado por: \n";
	for (int i = 0; i < 3; i++)
	{
		cout << Basquetbolista[Rival[i]].Codigo_nombre << "\n";
	}
	cout << "Que gane el mejor!!!!\n";
	system("PAUSE");
	system("cls");
	Basquetbolista[Tu[0]].Latiene = true;
	//aqui comienza la simulacion
	//Ofensiva
	string SioNo;
	Guardar:
	cout << "Deseas agregar los resultados de la simulacion a la estadistica general? (Si/No) \n";
	cin >> SioNo;
	if (SioNo == "Si" || SioNo == "si" || SioNo == "SI")
	{
		while ((puntajeX < 21 || puntajeY < 21));
		{
			while (posesion == true)
			{
				cout << "Tu: " << puntajeX << "\n";
				cout << "Rival: " << puntajeY << "\n";

				cout << "Jugada ofensiva, tienes el balon \n";

				int Seleccion;
				//verificar quien tiene el balon
				for (QuienLaTiene = 0; QuienLaTiene < 3; QuienLaTiene++)
				{
					if (Basquetbolista[Tu[QuienLaTiene]].Latiene == true)
					{
						cout << Basquetbolista[Tu[QuienLaTiene]].Codigo_nombre << " Tiene el balon \n Que quieres hacer? \n1. Pasar\n2. Driblar\n3. Tirar\n ";
					}
				}

				cin >> Seleccion;
				int GeneralOpcion = 1;
				string Aeste;
				switch (Seleccion)
				{

				case 1:

					cout << "Pasar a: \n";

					//solo imprime a quienes tiene disponible para pasar
					for (int i = 0; i < 3; i++)
					{
						if (Basquetbolista[Tu[i]].Latiene == false)
						{
							cout << GeneralOpcion << ") " << Basquetbolista[Tu[i]].Codigo_nombre << "(escriba el nombre del jugador) \n";
							GeneralOpcion++;
						}
					}
					//Le quitamos la posicion a el que la tenia antes
					for (int i = 0; i < 3; i++)
					{
						Basquetbolista[Tu[i]].Latiene = false;
					}
					//Lee a quien se la quiere pasar
					cin.ignore();
					getline(cin, Aeste);
					for (int i = 0; i < 3; i++)
					{
						if (Aeste == Basquetbolista[Tu[i]].Codigo_nombre)
						{
							AleatorioParaElPase = rand() % 10 + 0;
							if (AleatorioParaElPase >= 3)
							{
								cout << "Pase Completado \n";
								Basquetbolista[Tu[i]].Latiene = true;
								Basquetbolista[Tu[i]].rebotes += 1;
								system("PAUSE");
								system("cls");
								posesion = true;
							}
							else
							{
								cout << "Pase fallido \n";
								Basquetbolista[Tu[i]].Latiene = false;
								system("PAUSE");
								system("cls");
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
							}
						}
					}
					break;
				case 2:
					//driblar terminado ya :)
					for (int i = 0; i < 3; i++)
					{
						if (Basquetbolista[Tu[i]].Latiene == true)
						{
							AleatorioDrible = rand() % 10 + 1;
							if (AleatorioDrible <= 5)
							{
								Basquetbolista[Tu[i]].Latiene = false;
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;

								cout << "Drible fallido, perdio la pelota\n";
								system("PAUSE");
								system("cls");
							}
							else
							{
								Basquetbolista[Tu[i]].Latiene = true;
								posesion = true;
								cout << "Drible completado\n";
								system("PAUSE");
								system("cls");

							}
						}
					}

					break;
				case 3:
					for (int i = 0; i < 3; i++)
					{
						//verifica que el jugador tenga el balon
						if (Basquetbolista[Tu[i]].Latiene == true)
						{
							if (Basquetbolista[Tu[i]].potencia > 90)
							{
								AleatorioTiro = rand() % 10 + 5;
								if (AleatorioTiro == 10)
								{
									cout << "Encesto un triple \n";
									puntajeX += 3;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									Basquetbolista[Tu[i]].puntos_anotados += 3;
									system("PAUSE");
									system("cls");
								}
								else if (AleatorioTiro > 5 && AleatorioTiro < 10)
								{
									cout << "Encesto un doble \n";
									puntajeX += 2;
									Basquetbolista[Tu[i]].puntos_anotados += 2;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else
								{
									cout << "Fallo el tiro \n";
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								Basquetbolista[Tu[i]].Latiene = false;
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
							}
							else
							{
								AleatorioTiro = rand() % 10 + 1;
								if (AleatorioTiro == 10)
								{
									cout << "Encesto un triple \n";
									puntajeX += 3;
									Basquetbolista[Tu[i]].puntos_anotados += 3;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else if (AleatorioTiro > 5 && AleatorioTiro < 10)
								{
									cout << "Encesto un doble \n";
									puntajeX += 2;
									Basquetbolista[Tu[i]].puntos_anotados += 2;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else
								{
									cout << "Fallo el tiro \n";
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								Basquetbolista[Tu[i]].Latiene = false;
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
							}

						}
					}

					break;
				default:
					cout << "Opcion invalida \n";
					system("PAUSE");
					system("cls");
					break;
				}


			}
			while (posesion == false)
			{
				cout << "Tu: " << puntajeX << "\n";
				cout << "Rival: " << puntajeY << "\n";
				cout << "Jugada Defensiva \n";
				for (QuienLaTiene = 0; QuienLaTiene < 3; QuienLaTiene++)
				{
					if (Basquetbolista[Rival[QuienLaTiene]].Latiene == true)
					{
						cout << Basquetbolista[Rival[QuienLaTiene]].Codigo_nombre << " Tiene el balon \n Que quieres hacer? \n1. Tapar\n2. Robar\n3. Saltar\n ";
					}
				}
				int Seleccion;
				cin >> Seleccion;
				int GeneralOpcion = 1;
				string Aeste;
				switch (Seleccion)
				{

				case 1:
					RandomTapon = rand() % 10 + 1;
					if (RandomTapon > 5)
					{
						cout << "Tapo con exito, recuperan el balon \n";
						Basquetbolista[Tu[0]].tapones += 1;
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						system("PAUSE");
						system("cls");
					}
					else
					{
						cout << "No logro completar la tapada \n";
						posesion = false;
						acciones_rival += 1;
						if (acciones_rival % 3 == 0)
						{
							puntajeY += 2;
						}
						system("PAUSE");
						system("cls");
					}
					break;
				case 2:
					RandomRobar = rand() % 10 + 1;
					if (RandomRobar > 5)
					{
						cout << "Robo con exito, recuperan el balon \n";
						posesion = true;
						Basquetbolista[Tu[0]].balones_robados += 1;
						Basquetbolista[Tu[0]].Latiene = true;
						system("PAUSE");
						system("cls");
					}
					else
					{
						cout << "No logro robar \n";
						posesion = false;
						acciones_rival += 1;
						if (acciones_rival % 3 == 0)
						{
							puntajeY += 2;
						}
						system("PAUSE");
						system("cls");
					}
					break;
				case 3:
					RandomSaltar = rand() % 10 + 1;
					if (RandomSaltar > 5)
					{
						cout << "Salto con exito, recuperan el balon \n";
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						system("PAUSE");
						system("cls");
					}
					else
					{
						cout << "No logro saltar, encesta el rival \n";
						puntajeY += 2;
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						acciones_rival += 1;
						system("PAUSE");
						system("cls");

					}

					break;
				default:
					cout << "Opcion incorrecta \n";
					system("PAUSE");
					system("cls");
					break;
				}



			}
			
		}
		cout << "Simulacion terminada, resultado del encuentro: \n";
		cout << "Tu: " << puntajeX << "\n";
		cout << "Rival: " << puntajeY << "\n";
		system("PAUSE");
		system("cls");
	}
	else if (SioNo == "No" || SioNo == "no" || SioNo == "NO")
	{
		while ((puntajeX < 21 || puntajeY < 21))
		{
			while (posesion == true )
			{
				cout << "Tu: " << puntajeX << "\n";
				cout << "Rival: " << puntajeY << "\n";

				cout << "Jugada ofensiva, tienes el balon \n";

				int Seleccion;
				//verificar quien tiene el balon
				for (QuienLaTiene = 0; QuienLaTiene < 3; QuienLaTiene++)
				{
					if (Basquetbolista[Tu[QuienLaTiene]].Latiene == true)
					{
						cout << Basquetbolista[Tu[QuienLaTiene]].Codigo_nombre << " Tiene el balon \n Que quieres hacer? \n1. Pasar\n2. Driblar\n3. Tirar\n ";
					}
				}

				cin >> Seleccion;
				int GeneralOpcion = 1;
				string Aeste;
				switch (Seleccion)
				{

				case 1:

					cout << "Pasar a: \n";

					//solo imprime a quienes tiene disponible para pasar
					for (int i = 0; i < 3; i++)
					{
						if (Basquetbolista[Tu[i]].Latiene == false)
						{
							cout << GeneralOpcion << ") " << Basquetbolista[Tu[i]].Codigo_nombre << "(escriba el nombre del jugador) \n";
							GeneralOpcion++;
						}
					}
					//Le quitamos la posicion a el que la tenia antes
					for (int i = 0; i < 3; i++)
					{
						Basquetbolista[Tu[i]].Latiene = false;
					}
					//Lee a quien se la quiere pasar
					cin.ignore();
					getline(cin, Aeste);
					for (int i = 0; i < 3; i++)
					{
						if (Aeste == Basquetbolista[Tu[i]].Codigo_nombre)
						{
							AleatorioParaElPase = rand() % 10 + 0;
							if (AleatorioParaElPase >= 3)
							{
								cout << "Pase Completado \n";
								Basquetbolista[Tu[i]].Latiene = true;
								system("PAUSE");
								system("cls");
								posesion = true;
							}
							else
							{
								cout << "Pase fallido \n";
								Basquetbolista[Tu[i]].Latiene = false;
								system("PAUSE");
								system("cls");
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
							}
						}
					}
					break;
				case 2:
					//driblar terminado ya :)
					for (int i = 0; i < 3; i++)
					{
						if (Basquetbolista[Tu[i]].Latiene == true)
						{
							AleatorioDrible = rand() % 10 + 1;
							if (AleatorioDrible <= 5)
							{
								Basquetbolista[Tu[i]].Latiene = false;
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
								cout << "Drible fallido, perdio la pelota\n";
								system("PAUSE");
								system("cls");
							}
							else
							{
								Basquetbolista[Tu[i]].Latiene = true;
								posesion = true;
								cout << "Drible completado\n";
								system("PAUSE");
								system("cls");

							}
						}
					}

					break;
				case 3:
					for (int i = 0; i < 3; i++)
					{
						//verifica que el jugador tenga el balon
						if (Basquetbolista[Tu[i]].Latiene == true)
						{
							if (Basquetbolista[Tu[i]].potencia > 90)
							{
								AleatorioTiro = rand() % 10 + 5;
								if (AleatorioTiro == 10)
								{
									cout << "Encesto un triple \n";
									puntajeX += 3;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else if (AleatorioTiro > 5 && AleatorioTiro < 10)
								{
									cout << "Encesto un doble \n";
									puntajeX += 2;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else
								{
									cout << "Fallo el tiro \n";
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								Basquetbolista[Tu[i]].Latiene = false;
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
							}
							else
							{
								AleatorioTiro = rand() % 10 + 1;
								if (AleatorioTiro == 10)
								{
									cout << "Encesto un triple \n";
									puntajeX += 3;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else if (AleatorioTiro > 5 && AleatorioTiro < 10)
								{
									cout << "Encesto un doble \n";
									puntajeX += 2;
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								else
								{
									cout << "Fallo el tiro \n";
									cout << "Tu: " << puntajeX << " Rival: " << puntajeY << "\n";
									system("PAUSE");
									system("cls");
								}
								Basquetbolista[Tu[i]].Latiene = false;
								posesion = false;
								Basquetbolista[Rival[i]].Latiene = true;
							}

						}
					}

					break;
				default:
					cout << "Opcion invalida \n";
					system("PAUSE");
					system("cls");
					break;
				}


			}
			while (posesion == false)
			{
				cout << "Tu: " << puntajeX << "\n";
				cout << "Rival: " << puntajeY << "\n";
				cout << "Jugada Defensiva \n";
				for (QuienLaTiene = 0; QuienLaTiene < 3; QuienLaTiene++)
				{
					if (Basquetbolista[Rival[QuienLaTiene]].Latiene == true)
					{
						cout << Basquetbolista[Rival[QuienLaTiene]].Codigo_nombre << " Tiene el balon \n Que quieres hacer? \n1. Tapar\n2. Robar\n3. Saltar\n ";
					}
				}
				int Seleccion;
				cin >> Seleccion;
				int GeneralOpcion = 1;
				string Aeste;
				switch (Seleccion)
				{

				case 1:
					RandomTapon = rand() % 10 + 1;
					if (RandomTapon > 5)
					{
						cout << "Tapo con exito, recuperan el balon \n";
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						system("PAUSE");
						system("cls");
					}
					else
					{
						cout << "No logro completar la tapada \n";
						posesion = false;
						acciones_rival += 1;
						if (acciones_rival % 3 == 0)
						{
							puntajeY += 2;
						}
						system("PAUSE");
						system("cls");
					}
					break;
				case 2:
					RandomRobar = rand() % 10 + 1;
					if (RandomRobar > 5)
					{
						cout << "Robo con exito, recuperan el balon \n";
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						system("PAUSE");
						system("cls");
					}
					else
					{
						cout << "No logro robar \n";
						posesion = false;
						acciones_rival += 1;
						if (acciones_rival % 3 == 0)
						{
							puntajeY += 2;
						}
						system("PAUSE");
						system("cls");
					}
					break;
				case 3:
					RandomSaltar = rand() % 10 + 1;
					if (RandomSaltar > 5)
					{
						cout << "Salto con exito, recuperan el balon \n";
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						system("PAUSE");
						system("cls");
					}
					else
					{
						cout << "No logro saltar, encesta el rival \n";
						puntajeY += 2;
						posesion = true;
						Basquetbolista[Tu[0]].Latiene = true;
						acciones_rival += 1;
						system("PAUSE");
						system("cls");

					}

					break;
				default:
					cout << "Opcion incorrecta \n";
					system("PAUSE");
					system("cls");
					break;
				}



			}
			if (puntajeX > 21 || puntajeY > 21)
			{
				break;
			}
		}
		cout << "Simulacion terminada, resultado del encuentro: \n";
		cout << "Tu: " << puntajeX << "\n";
		cout << "Rival: " << puntajeY << "\n";
		system("PAUSE");
		system("cls");
	}
	else
	{
		goto Guardar;
	}	
}

void Simulacion2(int jugadores)
{
	int Elejido, cantidadTiros;
	int random;
	double estadistica;
	int Fallidos = 0, acertados = 0;
	cout << "Escriba el numero del jugador que quiere seleccionar\n";
	for (int i = 0; i < jugadores; i++)
	{
		cout << i << ". " << Basquetbolista[i].Codigo_nombre << "\n";
	}
	cin >> Elejido;
	system("cls");
	cout << "Cuantos tiros quieres hacer? \n";
	cin >> cantidadTiros;
	for (int i = 0; i < cantidadTiros; i++)
	{
		if (Basquetbolista[Elejido].potencia >= 90)
		{
			random = rand() % 20 + 5;
		}
		if (Basquetbolista[Elejido].potencia >=70 && Basquetbolista[Elejido].potencia < 90)
		{
			random = rand() % 10 + 5;
		}
		if (Basquetbolista[Elejido].potencia < 70)
		{
			random = rand() % 10 + 1;
		}
		if (random > 6)
		{
			cout << "Acertado\n";
			acertados += 1;
		}
		if (random <= 6)
		{
			cout << "Fallo \n";
			Fallidos += 1;
			
		}
		cout << "Tiro: " << i+1 << " finalizado \n";
		system("PAUSE");
		system("cls");
	}
	cout << "Resultados de: " << Basquetbolista[Elejido].Codigo_nombre<<" En tiros libres haciendo: "<<cantidadTiros<< "\n";
	cout << "Tiros acertados: " << acertados << "\n";
	cout << "Tiros Fallados: " << Fallidos << "\n";
	estadistica = (1.0*acertados / cantidadTiros)*100.0;
	cout << "Estadistica de tiros: " << estadistica << "% \n";
	system("PAUSE");
	system("cls");
	

}

//EL MAIN 
int main(void)
{
	int contador = 0;
	
	string Consultados[1000];
	string split = "- ";
	int contadorGeneral = 0;
	//Creacion de los arboles
	ArbolBB *ArbolPivote = new ArbolBB();
	ArbolBB *ArbolBase = new ArbolBB();
	ArbolBB *ArbolAlero = new ArbolBB();
	cout << "NBA Lectura de archivo Proyecto #2 Fase #2 \n\n";
	cout << "                       ..ee$$$$$ee..                              \n";
	cout << "                   .e$*""    $    ""*$e.                          \n";
	cout << "                 z$''*.      $         $$c                        \n";
	cout << "               z$''   *.     $      .P  ^$c                       \n";
	cout << "              d""      *     $      z"     "b                     \n";
	cout << "             $''       b     $     4 %      ^$                    \n";
	cout << "            d%         *     $     P         '$                   \n";
	cout << "           .$          'F    $    J''         $r                  \n";
	cout << "           4L           b    $    $           J$                  \n";
	cout << "           $F$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                  \n";
	cout << "           4F          4F    $    4r          4P                  \n";
	cout << "           ^$          $     $     b          $%                  \n";
	cout << "            3L        .F     $     'r        JP                   \n";
	cout << "             *c       $      $      3.      z$                    \n";
	cout << "              *b    J''      $       3r    dP                     \n";
	cout << "               ^$c  z%       $        'c z$                       \n";
	cout << "                  *$L        $	      .d$'                       \n";
	cout << "                     *$ee..$    ..ze$P                            \n";
	cout << "                         ""*******""					           \n";

	system("PAUSE");
	system("cls");
	FILE *in;
	char linea[MAX_LINEA];
	struct Jugador player;

	/* (determinar si ocurre un error) */
	if ((in = fopen(NOM_ARCHIVO, "rt")) == NULL) {
		perror(NOM_ARCHIVO);
		return EXIT_FAILURE;
	}
	/* Leemos y procesamos cada linea del archivo */
	while (fgets(linea, MAX_LINEA, in) != NULL) {
		
		if (sscanf(linea, "%[^-]- %[^-]- %[^-]- %[^-]- %d- %[^-]- %f- %d- %d- %d- %d- %d-",player.Codigo_nombre, player.Conferencia, player.Equipo, player.Posicion, &player.potencia, player.habilidad, &player.altura, &player.puntos_anotados, &player.balones_robados, &player.rebotes, &player.tapones, &player.votacion) == 12) {
			if (player.Posicion[0] == 'A')
			{
				//Insercion de datos en EL arbol
				ArbolAlero->Insertar(player.Codigo_nombre, player.Conferencia, player.Equipo, player.Posicion, player.potencia, player.habilidad, player.altura, player.puntos_anotados, player.balones_robados, player.rebotes, player.tapones, player.votacion);
			}
			if (player.Posicion[0] == 'P')
			{
				//Insercion de datos en EL arbol
				ArbolPivote->Insertar(player.Codigo_nombre, player.Conferencia, player.Equipo, player.Posicion, player.potencia, player.habilidad, player.altura, player.puntos_anotados, player.balones_robados, player.rebotes, player.tapones, player.votacion);
			}
			if (player.Posicion[0] == 'B')
			{
				//Insercion de datos en EL arbol
				ArbolBase->Insertar(player.Codigo_nombre, player.Conferencia, player.Equipo, player.Posicion, player.potencia, player.habilidad, player.altura, player.puntos_anotados, player.balones_robados, player.rebotes, player.tapones, player.votacion);
			}
			Basquetbolista[contador].Codigo_nombre = player.Codigo_nombre;
			Basquetbolista[contador].Conferencia = player.Conferencia;
			Basquetbolista[contador].Equipo = player.Equipo;
			Basquetbolista[contador].Posicion = player.Posicion;
			Basquetbolista[contador].potencia = player.potencia;
			Basquetbolista[contador].habilidad = player.habilidad;
			Basquetbolista[contador].altura = player.altura;
			Basquetbolista[contador].puntos_anotados = player.puntos_anotados;
			Basquetbolista[contador].balones_robados = player.balones_robados;
			Basquetbolista[contador].rebotes = player.rebotes;
			Basquetbolista[contador].tapones = player.tapones;
			Basquetbolista[contador].votacion = player.votacion;
			Basquetbolista[contador].Latiene = false;
			Basquetbolista[contador].bloqueado = false;
			contador++;
			
		}
		else
			puts("Linea no valida");
	}
	fclose(in);
	
	//Termina lectura de archivo

	int opt = 0;

	do
	{
		cout << "Seleccione su opcion: " << endl;
		cout << "1. Estadisticas por jugador" << endl;
		cout << "2. Estadisticas por equipo" << endl;
		cout << "3. Generar archivo de estadisticas" << endl;
		cout << "4. Simulacion caso 1" << endl;
		cout << "5. Simulacion caso 2" << endl;
		cout << "6. Sancionar/Quitar sancion" << endl;
		cout << "0. Salir" << endl;
		cin >> opt;

		switch (opt)
		{
		case 0: {
			cout << "Adios..." << endl;
		}break;

		case 1: {
			cout << "Ingrese el Nombre del jugador a buscar: " << endl;
			string name;
			cin.ignore();
			getline(cin, name);
			system("cls");
			for (int i = 0; i < 1000; i++)
			{
				if (name == Basquetbolista[i].Codigo_nombre)
				{
					cout <<"Nombre: " <<Basquetbolista[i].Codigo_nombre<<"\n";
					cout<<"Conferencia: " <<Basquetbolista[i].Conferencia<<"\n";
					cout <<"Equipo: "<< Basquetbolista[i].Equipo<<"\n";
					cout<<"posicion: "<<Basquetbolista[i].Posicion<<"\n";
					printf(" Potencia: \"%d\"\n", Basquetbolista[i].potencia);
					cout<<"Habilidad: "<<Basquetbolista[i].habilidad<<"\n";
					printf("Altura(m): \"%f\"\n", Basquetbolista[i].altura);
					printf("Puntos anotados: \"%d\"\n", Basquetbolista[i].puntos_anotados);
					printf("Robados: \"%d\"\n", Basquetbolista[i].balones_robados);
					printf("Rebotes: \"%d\"\n", Basquetbolista[i].rebotes);
					printf("Tapones: \"%d\"\n", Basquetbolista[i].tapones);
					printf("Votos: \"%d\"\n\n\n", Basquetbolista[i].votacion);
					Consultados[contadorGeneral] = Basquetbolista[i].Codigo_nombre + split + Basquetbolista[i].Conferencia + split + Basquetbolista[i].Equipo + split + Basquetbolista[i].Posicion + split + std::to_string(Basquetbolista[i].potencia) + split + Basquetbolista[i].habilidad + split + std::to_string(Basquetbolista[i].altura) + split + std::to_string(Basquetbolista[i].puntos_anotados) + split + std::to_string(Basquetbolista[i].balones_robados) + split + std::to_string(Basquetbolista[i].rebotes) + split + std::to_string(Basquetbolista[i].tapones) + split + std::to_string(Basquetbolista[i].votacion);

				}
			}
			system("PAUSE");
			system("cls");
		}break;

		case 2: {
			cout << "Ingrese el Nombre del Equipo a buscar: " << endl;
			string equipo;
			cin.ignore();
			getline(cin, equipo);
			system("cls");
			for (int i = 0; i < 1000; i++)
			{
				if (equipo == Basquetbolista[i].Equipo)
				{
					cout << "Nombre: " << Basquetbolista[i].Codigo_nombre << "\n";
					cout << "Conferencia: " << Basquetbolista[i].Conferencia << "\n";
					cout << "Equipo: " << Basquetbolista[i].Equipo << "\n";
					cout << "posicion: " << Basquetbolista[i].Posicion << "\n";
					printf(" Potencia: \"%d\"\n", Basquetbolista[i].potencia);
					cout << "Habilidad: " << Basquetbolista[i].habilidad << "\n";
					printf("Altura(m): \"%f\"\n", Basquetbolista[i].altura);
					printf("Puntos anotados: \"%d\"\n", Basquetbolista[i].puntos_anotados);
					printf("Robados: \"%d\"\n", Basquetbolista[i].balones_robados);
					printf("Rebotes: \"%d\"\n", Basquetbolista[i].rebotes);
					printf("Tapones: \"%d\"\n", Basquetbolista[i].tapones);
					printf("Votos: \"%d\"\n\n\n", Basquetbolista[i].votacion);
					Consultados[contadorGeneral] = Basquetbolista[i].Codigo_nombre + split + Basquetbolista[i].Conferencia + split + Basquetbolista[i].Equipo + split + Basquetbolista[i].Posicion + split + std::to_string(Basquetbolista[i].potencia) + split + Basquetbolista[i].habilidad + split + std::to_string(Basquetbolista[i].altura) + split + std::to_string(Basquetbolista[i].puntos_anotados) + split + std::to_string(Basquetbolista[i].balones_robados) + split + std::to_string(Basquetbolista[i].rebotes) + split + std::to_string(Basquetbolista[i].tapones) + split + std::to_string(Basquetbolista[i].votacion);

				}
			}
			system("PAUSE");
			system("cls");
						
		}break;

		case 3: {
			system("cls");
			cout << "Generando archivo con tus consultas realizadas :) \n";
			ofstream ofs("Consultas.txt");
			
			for (int i = 0; i < 1000; i++)
			{
				ofs << "Nombre: " << Basquetbolista[i].Codigo_nombre << "\n";
				ofs << "Conferencia: " << Basquetbolista[i].Conferencia << "\n";
				ofs << "Equipo: " << Basquetbolista[i].Equipo << "\n";
				ofs << "posicion: " << Basquetbolista[i].Posicion << "\n";
				ofs << "Potencia: " << Basquetbolista[i].potencia << "\n";
				ofs << "Habilidad: " << Basquetbolista[i].habilidad << "\n";
				ofs << "Altura(m): " << Basquetbolista[i].altura << "\n";
				ofs << "Puntos anotados: " << Basquetbolista[i].puntos_anotados << "\n";
				ofs << "Robados: " << Basquetbolista[i].balones_robados << "\n";
				ofs << "Rebotes: " << Basquetbolista[i].rebotes << "\n";
				ofs << "Tapones: " << Basquetbolista[i].tapones << "\n";
				ofs << "Votos: " << Basquetbolista[i].votacion << "\n\n";
				if ((Basquetbolista[i].altura < 1) ||(Basquetbolista[i].potencia) < 1 )
				{
					break;
				}
			}
			cout << "Archivo creado con exito!!! \n";
			system("PAUSE");
			system("cls");
			ofs.close();

		}break;

		case 4: {
			system("cls");
			Simulacion1(contador);
			cout << "Simulacion terminada \n";
			system("PAUSE");
			system("cls");
		}break;

		case 5: {
			system("cls");
			Simulacion2(contador);
			cout << "Simulacion terminada \n";
			
		}break;
		case 6: {
			system("cls");
			string seleccionPrincipal;
			int Elejido;
			cout << "1. Sancionar \n2.Quitar Sancion \n";
			cin >> seleccionPrincipal;
			if (seleccionPrincipal == "1")
			{
				cout << "Escriba el numero del jugador que quiere sancionar\n";
				for (int i = 0; i < contador; i++)
				{
					if (Basquetbolista[i].bloqueado == false)
					{
						cout << i << ". " << Basquetbolista[i].Codigo_nombre << "\n";
					}
				}
				cin >> Elejido;
				Basquetbolista[Elejido].bloqueado = true;
				cout << "Se sanciono a: " << Basquetbolista[Elejido].Codigo_nombre << "\n";
			}
			if (seleccionPrincipal == "2")
			{
				string x;
				cout << "Escriba el Nombre del jugador al que quiere quitar la sancion\n";
				for (int i = 0; i < contador; i++)
				{
					if (Basquetbolista[i].bloqueado == true)
					{
						cout << Basquetbolista[i].Codigo_nombre << "\n";
					}
				}
				cin.ignore();
				getline(cin, x);
				for (int i = 0; i < contador; i++)
				{
					if (x == Basquetbolista[i].Codigo_nombre)
					{
						Basquetbolista[i].bloqueado = false;
						cout << "Se quito la sancion a: " << Basquetbolista[i].Codigo_nombre << "\n";
					}
				}
				
			}
			else 
			{
				cout << "Opcion invalida, regresando al menu principal \n";				
			}


			
			system("PAUSE");
			system("cls");


		}break;
		default:
			cout << "Opción no válida" << endl;
			break;
		}

	} while (opt != 0);
	return EXIT_SUCCESS;
}


