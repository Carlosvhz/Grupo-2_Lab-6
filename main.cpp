#include <iostream>
#include <vector>
#include "persona"

	
using namespace std;

//int menu();



int main(){
	int opcion =-1;
	do
	{
		//opcion= menu();
		if (opcion==1)
		{
			
		}else if (opcion==2)
		{
			
		}else if (opcion==3)
		{
			cout<<"Hasta la vista"<<endl;
		}
	} while (opcion!=3);
  return 0;
}

int menu(){
	int resp !=-1;
	do
	{
		cout<<"1. Agregar Personas"<<endl;	
		cout<<"2. Eliminar"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>resp;
	} while (resp <0||resp>3);
	return resp;
}