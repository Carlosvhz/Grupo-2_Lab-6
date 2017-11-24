#include <iostream>
#include <vector>
#include "persona.h"

using namespace std;
int menu();
persona* agregar();
vector<persona*> eliminar(vector<persona*>);

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
		cout<<"3. Salir"<<endl;
		cin>>resp;
	} while (resp <0&&resp>3);
	return resp;
}


persona* agregar(){
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
		genero = true;
	}else{
		genero =false;
	}
	persona* person = new persona(nombre,genero,cabello,ojo,piel,fertil);
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
