#include "estudiante.h"

Menus regresarMenuE;
string Estudiante::menuEmpleadosPlanilla(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    Estudiante menu;
    int choice;
    bool repetir = true;
    char x;
	do
    {
	system("cls");

	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Hola " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
	cout<<"\t\t\t |   Bienvenido al Menu de estudiante  |"<<endl;
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Datos de Estudiante "<<endl;
	cout<<"\t\t\t 2. Buscar Estudiante"<<endl;
	cout<<"\t\t\t 3. Modificar Datos de Estudiante"<<endl;
	cout<<"\t\t\t 4. Elimidar Estudiante"<<endl;
	cout<<"\t\t\t 5. Imprimir Datos de Estudiante"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        system("cls");
        do
    	{
    		menu.insertarEmpleado(userName);
    		cout<<"\n\t\t\t Agregar Otro Estudiante (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');

		break;
	case 2:
	    system("cls");
		menu.buscarEmpleado(userName);

		break;
	case 3:
	    system("cls");
		menu.modificarEmpleado(userName);

		break;
	case 4:
	    system("cls");
		menu.borrarEmpleado(userName);

		break;
    case 5:
		system("cls");
		menu.imprimirEmpleados(userName);

		break;
	case 6:
	    system("cls");
		regresarMenuE.menuCatalogos(userName);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(repetir);
}

void Estudiante::insertarEmpleado(string nombreUsuario)
{
    string userName = nombreUsuario;
	fstream file;
	cout<<"\n-------------------------------------------------Ingreso de Estudiantes -------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa carne de Estudiante           : ";
	cin>>idEmpleado;
	cout<<"\t\t\tIngresa Nombre del Estudiante       : ";
	cin>>nombreEmpleado;
	cout<<"\t\t\tIngresa Apellido del Estudiante     : ";
	cin>>apellidoEmpleado;
	cout<<"\t\t\tIngresa Direccion del Estudiante   : ";
	cin>>direccionEmpleado;
	cout<<"\t\t\tIngresa Telefono del Estudiante     : ";
	cin>>telefonoEmpleado;
	file.open("DatosEstudiantes.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< idEmpleado <<std::left<<std::setw(15)<< nombreEmpleado <<std::left<<std::setw(15)<< apellidoEmpleado <<std::left<<std::setw(15)<< dpiEmpleado <<std::left<<std::setw(15)<< direccionEmpleado <<std::left<<std::setw(15)<< telefonoEmpleado << "\n";
	file.close();

}

void Estudiante::buscarEmpleado(string nombreUsuario)
{
    string userName = nombreUsuario;
    fstream file;
	int found=0;
	file.open("DatosEstudiantes.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Estudiante Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Estudiante Buscado------------------------"<<endl;
		cout<<"\nIngrese carne del estudiante que quiere buscar: ";
		cin>>participant_id;
		file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		while(!file.eof())
		{
			if(participant_id==idEmpleado)
			{
				cout<<"\n\n\t\t\t carne Estudiante        : "<<idEmpleado<<endl;
                cout<<"\n\n\t\t\t Nombre Estudiante    : "<<nombreEmpleado<<endl;
                cout<<"\t\t\t Apellido Estudiante      : "<<apellidoEmpleado<<endl;
                cout<<"\t\t\t Direccion Estudiante     : "<<direccionEmpleado<<endl;
                cout<<"\t\t\t Telefono Estudiante      : "<<telefonoEmpleado<<endl;
				found++;
			}
			file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Estudiante no encontrada...";
		}
		file.close();
	}

}

void Estudiante::modificarEmpleado(string nombreUsuario)
{
string userName = nombreUsuario;
    fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Estudiante-------------------------"<<endl;
	file.open("DatosEstudiantes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese carne de estudiante que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		while(!file.eof())
		{
			if(participant_id!=idEmpleado)
			{
			 file1 <<std::left<<std::setw(15)<< idEmpleado <<std::left<<std::setw(15)<< nombreEmpleado <<std::left<<std::setw(15)<< apellidoEmpleado <<std::left<<std::setw(15)<< dpiEmpleado <<std::left<<std::setw(15)<< direccionEmpleado <<std::left<<std::setw(15)<< telefonoEmpleado << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa carne Estudiante            : ";
                cin>>idEmpleado;
                cout<<"\t\t\tIngresa Nombre del Estudiante        : ";
                cin>>nombreEmpleado;
                cout<<"\t\t\tIngresa Apellido del Estudiante      : ";
                cin>>apellidoEmpleado;
                cout<<"\t\t\tIngresa Direccion del Estudiante     : ";
                cin>>direccionEmpleado;
                cout<<"\t\t\tIngresa Telefono del Estudiante     : ";
                cin>>telefonoEmpleado;
				file1 <<std::left<<std::setw(15)<< idEmpleado <<std::left<<std::setw(15)<< nombreEmpleado <<std::left<<std::setw(15)<< apellidoEmpleado <<std::left<<std::setw(15)<< dpiEmpleado <<std::left<<std::setw(15)<< direccionEmpleado <<std::left<<std::setw(15)<< telefonoEmpleado << "\n";
				found++;
			}
			file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;

		}
		file1.close();
		file.close();
		remove("DatosEstudiantes.txt");
		rename("Record.txt","DatosEstudiantes.txt");
	}

}

void Estudiante::borrarEmpleado(string nombreUsuario)
{
string userName = nombreUsuario;
    fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Baja (Borrado) del Estudiante-------------------------"<<endl;
	file.open("DatosEstudiantes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el carne del estudiante que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		while(!file.eof())
		{
			if(participant_id!= idEmpleado)
			{
				file1 <<std::left<<std::setw(15)<< idEmpleado <<std::left<<std::setw(15)<< nombreEmpleado <<std::left<<std::setw(15)<< apellidoEmpleado <<std::left<<std::setw(15)<< dpiEmpleado <<std::left<<std::setw(15)<< direccionEmpleado <<std::left<<std::setw(15)<< telefonoEmpleado << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("DatoEstudiantes.txt");
		rename("Record.txt","EmpleadoPlanilla.txt");
	}

}

void Estudiante::imprimirEmpleados(string nombreUsuario)
{
string userName = nombreUsuario;


   fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Informe de Estudiante -------------------------"<<endl;
	file.open("DatosEstudiantes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Carne Estudiante           : "<<idEmpleado<<endl;
			cout<<"\t\t\t Nombre Estudiante      : "<<nombreEmpleado<<endl;
			cout<<"\t\t\t Apellido Estudiante    : "<<apellidoEmpleado<<endl;
			cout<<"\t\t\t Direccion Estudiante   : "<<direccionEmpleado<<endl;
			cout<<"\t\t\t Telefono Estudiante    : "<<telefonoEmpleado<<endl;
        file >> idEmpleado >> nombreEmpleado >> apellidoEmpleado >> dpiEmpleado >> direccionEmpleado >> telefonoEmpleado;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();

}


