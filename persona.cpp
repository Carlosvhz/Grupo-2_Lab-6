#include "persona.h"

persona::persona(){

}

persona::persona(string pnombre,char pgenero,int colorCabello,int colorOjos,int colorPiel,bool pfertilidad){
  nombre = pnombre;
  genero = pgenero;
  color_cabello = colorCabello;
  color_ojos = colorOjos;
  color_piel = colorPiel;
  fertilidad = pfertilidad;
}

string persona::getNombre(){
  return nombre;
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

string getGenes(){
  return genes;
}
//Operadores sobrecargados

persona* persona::operator+(persona& p){
    return 0;
}

persona* persona::operator*(persona& p){
    return 0;
}
