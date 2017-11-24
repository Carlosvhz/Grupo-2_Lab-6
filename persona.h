#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class persona{
  private:
    string nombre;
    char genero;
    int color_cabello;
    int color_ojos;
    int color_piel;
    bool fertilidad;

  public:
    string getNombre();
    char getGenero();
    int getColorCabello();
    int getColorOjos();
    int getColorPiel();
    bool getFertilidad();
    //Sobrecargado
    persona* operator+(persona&);
    persona* operator*(persona&);
    //Constructor
    persona(string,char,int,int,int,bool);
    persona();
};

#endif
