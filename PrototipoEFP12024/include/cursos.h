#ifndef CURSOS_H
#define CURSOS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menugeneral.h"
#include "ingresousuario.h"

class cursos
{
    public:
        void cursoselegir();

    protected:

    private:
         string codigo;
        string curso;
};

#endif // CURSOS_H
