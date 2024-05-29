#ifndef INGRESOUSUARIO_H
#define INGRESOUSUARIO_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class IngresoUsuario
{
    public:
        void iniciarSesion();
		string menuUsuario(string nombreUsuario);
		void registroUsuario();
		void imprimirUsuario(string nombreUsuario);
		void borrarUsuario(string nombreUsuario);
		void modificarUsuario(string nombreUsuario);
		void buscarUsuario(string nombreUsuario);

    protected:

    private:
        string nombre, contrasena;
};

#endif // INGRESOUSUARIO_H
