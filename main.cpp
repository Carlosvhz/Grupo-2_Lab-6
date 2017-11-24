#include <iostream>
#include <vector>
#include "persona.h"

using namespace std;

int menu();
persona* agregar();
vector<persona*> eliminar(vector<persona*>);
void simulacion(vector<persona*>);

int main(){
	vector <persona*> lista;
	int opcion =-1;
	do
	{
		opcion=menu();
		if (opcion==1)
		{
			persona* person = agregar();
			lista.push_back(person);
		}else if (opcion==2)
		{
			lista= eliminar(lista);
		}else if (opcion==3)
		{
			 simulacion(lista);
		}else if(opcion==4){
			cout<<"Hasta la vista"<<endl;
		}
	} while (opcion!=3);
  return 0;
}

int menu(){
	int resp =-1;
	do
	{
		cout<<"1. Agregar Personas"<<endl;
		cout<<"2. Eliminar"<<endl;
		cout<<"3. Simulacion"<<endl;
		cout<<"4. salir"<<endl;
		cin>>resp;
	} while (resp <0&&resp>4);
	return resp;
}

void simulacion(vector<persona*> lista){
	if(lista.size()>1){
		int opcion, p=0,m=0;
		persona* padre;
		persona* madre;
		cout<<"___ Simulacion __"<<endl;
		for (int i = 0; i < lista.size(); ++i)
		{
			persona* person = lista.at(i);
			cout<<i<<" "<<person->getNombre()<<endl;
		}
		cout<<"1. Con proteccion"<<endl
		<<"2. Sin proteccion"<<endl
		<<"Ingrese la opcion: ";
		cin>>opcion;
		while(opcion<0||opcion>2){
			cout<<"Ingrese de nuevo: ";
			cin>>opcion;
		}
		cout<<"Ingrese el numero de persona del padre: ";
		cin>>p;
		cout<<"Ingrese el numero de persona de la mandre: ";
		cin>>m;
		while(p<0||p>lista.size()-1  || m<0||m>lista.size()-1){
			cout<<"Ingrese de nuevo los numeros...";
			cout<<"Ingrese el numero de persona del padre: ";
			cin>>p;
			cout<<"Ingrese el numero de persona de la madre: ";
			cin>>m;
		}
		cout<<"p"<<endl;
		cout<<lista.at(p)->getNombre() <<endl;
		cout<<lista.at(m)->getNombre();
		while(padre->getGenero()==madre->getGenero()){
			cout<<"No puede haber reproduccion entre personas del mismo sexo";
			cout<<"Ingrese de nuevo el numero de persona del padre: ";
			cin>>p;
			cout<<"Ingrese el numero de persona de la mandre: ";
			cin>>m;
			while(p<0||p>lista.size()-1||m<0||m>lista.size()-1){
				cout<<"Ingrese de nuevo los numeros...";
				cout<<"Ingrese el numero de persona del padre: ";
				cin>>p;
				cout<<"Ingrese el numero de persona de la mandre: ";
				cin>>m;
			}
			padre = lista.at(p);
			madre = lista.at(m);
		}
		persona* hijo;
		switch(opcion){
			case 1:{
				if(!padre->getFertilidad()||!madre->getFertilidad()){
					cout<<"Alguno de los dos individuos es infertil, no hubo embarazo alguno";
				}else{
					hijo = (*padre)+(*madre);
					if(hijo==0){
						cout<<"No hubo embarazo";
					}else{
						cout<<"Tuviste una bendicion!"<<endl;
					}
				}
			}
				break;
			case 2:{
				if(!padre->getFertilidad()||!madre->getFertilidad()){
					cout<<"Alguno de los dos individuos es infertil, no hubo embarazo alguno";
				}else{
					hijo = (*padre)+(*madre);
					cout<<"Tuviste una bendicion!"<<endl;
				}
			}
			break;
		}
	}else{
		cout<<"No hay suficientes personas para el coito "<<endl;
	}
}

persona* agregar(){
	string genojos, genpelo, genpiel;
	int cabello,ojo,piel;
	char genero;
	bool fertil;
	string nombre;
	cout<<"------Creacion de persona---"<<endl;
	int resp=-1;
	cout<<"Ingrese el nombre de la persona"<<endl;
	cin>>nombre;
	do
	{
		cout<<"Ingrese el numero del color de cabello"<<endl;
		cout<<"1. Negro"<<endl;
		cout<<"2. Cafe"<<endl;
		cout<<"3. Rubio"<<endl;
		cin>>resp;
	} while (resp<1&&resp>3);
	if(resp==1){
		genpelo = "AA";
	}else{
		genpelo = "aa";
	}
	cabello = resp;
	resp=-1;
	do
	{
		cout<<"Ingrese el numero del color de ojos"<<endl;
		cout<<"1. Azul"<<endl;
		cout<<"2. Negro"<<endl;
		cout<<"3. Cafe"<<endl;
		cin>>resp;
	} while (resp<1&&resp>3);
	if(resp==2){
		genojos = "AA";
	}else{
		genojos = "aa";
	}
	ojo = resp;
	resp=-1;
	do
	{
		cout<<"Ingrese el numero del piel"<<endl;
		cout<<"1. Blanco"<<endl;
		cout<<"2. Negro"<<endl;
		cout<<"3. Trigueño"<<endl;
		cin>>resp;
	} while (resp<1&&resp>3);
	if(resp==2){
		genpiel = "AA";
	}else{
		genpiel = "aa";
	}
	piel= resp;
	resp=-1;
	do
	{
		cout<<"Ingrese el numero de sexo"<<endl;
		cout<<"1. Masculino"<<endl;
		cout<<"2. Femenino"<<endl;
		cin>>resp;
	} while (resp<1&&resp>2);
	if (resp ==1)
	{
		genero='M';
	}else{
		genero='F';
	}
	resp=-1;
	do
	{
		cout<<"Fertil"<<endl;
		cout<<"1. si"<<endl;
		cout<<"2. no"<<endl;
		cin>>resp;
	} while (resp<1&&resp>2);
	if (resp==1)
	{
		fertil = true;
	}else{
		fertil =false;
	}
	persona* person = new persona(nombre,genero,cabello,ojo,piel,fertil,genojos,genpelo,genpiel);
	return person;
}
vector<persona*> eliminar(vector<persona*>lista){
	if (lista.size()>0)
	{
		int posicion= -1;
		cout<<"Ingrese el index de la posicion a eliminar desde 0 hasta "<<lista.size()-1<<endl;
		for (int i = 0; i < lista.size(); ++i)
		{
			persona* person = lista.at(i);
			cout<<i<<" "<<person->getNombre()<<endl;
		}
		do
		{
			cout<<"Ingrese la posicion a eliminar"<<endl;
			cin>>posicion;
		} while (posicion<0&&posicion>=lista.size());
		lista.erase(lista.begin()+posicion);
		return lista;
	}else{
		cout<<"La lista esta vacia"<<endl;
		return lista;
	}
}
