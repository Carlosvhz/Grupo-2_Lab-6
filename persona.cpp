#include "persona.h"
#include <cstdlib>
#include <iostream>

using namespace std;

persona::persona(){

}

persona::persona(string pnombre,char pgenero,int colorCabello,int colorOjos,int colorPiel,bool pfertilidad,string go
                  ,string gp, string gpl){
  nombre = pnombre;
  genero = pgenero;
  color_cabello = colorCabello;
  color_ojos = colorOjos;
  color_piel = colorPiel;
  fertilidad = pfertilidad;
  genOjo = go;
  genPelo = gp;
  genPiel = gpl;
}

string persona::getNombre(){
  return nombre;
}

string persona::getGenOjo(){
  return genOjo;
}

string persona::getGenPelo(){
  return genPelo;
}

string persona::getGenPiel(){
  return genPiel;
}

char persona::getGenero(){
  return genero;
}

int persona::getColorCabello(){
  return color_cabello;
}

int persona::getColorOjos(){
  return color_ojos;
}

int persona::getColorPiel(){
  return color_piel;
}

bool persona::getFertilidad(){
  return fertilidad;
}

//Operadores sobrecargados

persona* persona::operator+(persona& p){

  string nombre;
  int tipo;
  persona* hijo;
  string ojo = calcular(this->genOjo,p.getGenOjo());
  string pelo = calcular(this->genPelo,p.getGenPelo());
  string piel= calcular(this->genPiel,p.getGenPiel());
  int pelohijo,pielhijo,ojohijo;
  //Comparar cabello
  if(ojo[0]=='A'||ojo[1]=='A')
  {
      ojohijo=2;
  }else{
    tipo = 1 + rand()%100;
    if(tipo%2==0){
      ojohijo = 1;
    }else{
      ojohijo = 3;
    }
  }
  cout<<" "<<endl;
  if(piel[0]=='A'||piel[1]=='A')
  {
          pielhijo=2;
  }else{
    tipo = 1 + rand()%100;
    if(tipo%2==0){
      pielhijo = 1;
    }else{
      pielhijo = 3;
    }
  }
  cout<<" "<<endl;
  if(pelo[0]=='A'||pelo[1]=='A')
  {
    pelohijo=1;
  }else{
    tipo = 1 + rand()%100;
    if(tipo%2==0){
      pelohijo = 2;
    }else{
      pelohijo = 3;
    }
  }
  char genero;
  tipo = 1 + rand()%100;
    if(tipo%2==0){
      genero = 'F';
    }else{
      genero = 'M';
    } 
  cout<<"- Ingrese el nombre de su bendicion: ";
  cin>>nombre;
  hijo = new persona(nombre,genero,pelohijo,ojohijo,pielhijo,true,ojo,pelo,piel);
}

persona* persona::operator*(persona& p){
    return 0;
}
string persona:: calcular(string genpadre, string genmadre){
  string matrizgenes[2][2];
  string temp;
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      temp = genpadre[i];
      temp+= genmadre[j];
      matrizgenes[i][j]= temp;

    }
  }
  string genfinal="";
  int contador=-1;
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      string temporal =matrizgenes[i][j];
      int cont=0;

      for (int k = 0; k < 2; ++k)
      {
        for (int l = 0; l < 2; ++l)
        {
            
            if (temporal == matrizgenes[k][l]&&(i!=k)&&(l!=j))
            {
              cont++;
            }
        }
      }if (cont>contador)
      {
        genfinal= temporal;
      }
    }
  }
}