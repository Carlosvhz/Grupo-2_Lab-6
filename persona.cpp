#include "persona.h"

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

    return 0;
}

persona* persona::operator*(persona& p){
    return 0;
}
