#include "cursos.h"
using namespace std;
void cursos::cursoselegir()
{
	fstream file;
	cout<<"\n-------------------------------------------------Ingreso de Curso -------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa curso           : ";
	cin>>curso;
	cout<<"\t\t\tIngresa codigo       : ";
	cin>>codigo;
	file.open("Datoscurso.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< curso <<std::left<<std::setw(15)<< codigo << "\n";
	file.close();

}
