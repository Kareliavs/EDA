#include "arbin.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
using namespace std;


void printMenu(){

    cout<<"\t\tMENU"<<endl;
    cout<<"1.Insertar"<<endl;
    cout<<"2.Recorrer"<<endl;
    cout<<"3.Eliminar"<<endl;
    cout<<"4.Buscar"<<endl;
    cout<<"5.Imprimir"<<endl;
    cout<<"6.Convertir"<<endl;
    cout<<"7.Salir"<<endl;
    cout<<endl<<"\tOPCION: ";
}

void printSubMenu(){
    system("clear");
    cout<<endl<<"1.Imprimir en pre-orden"<<endl;
    cout<<"2.Imprimir en in-orden"<<endl;
    cout<<"3.Imprimir en post-orden"<<endl;
    cout<<endl<<"\tOPCION: ";
}

int main(int argc, char* argv[]){

    Arbin *arbin = new Arbin();
    Nodo *q;
    int nu = 0;
    int aux = 0;
    char opcion[1];
    bool salir = false;

    do{

    printMenu();
    fflush(stdin);
    cin >> opcion;

    switch(atoi(opcion)){
        case 1:
            system("clear");
            cout<<endl<<"Cuantos valores desea ingresar";
            cin>>nu;
            for(int i=0;i<nu;++i)
            {
                cout<<endl<<"Ingrese un valor entero: ";
                fflush(stdin);
                cin>>aux;
                q = new Nodo(aux);
                arbin->Crear(q);
            }

        break;

        case 2:
            system("clear");
            printSubMenu();
            fflush(stdin);
            cin>>aux;
            arbin->Recorridos(aux);
            cout<<endl<<endl;
        break;

        case 3:
            system("clear");
            cout<<endl<<"Ingrese valor a eliminar: ";
            fflush(stdin);
            cin>>aux;
            arbin->Eliminar(aux);
        break;

        case 4:
            system("clear");
            cout<<endl<<"Ingrese valor a buscar: ";
            //fflush(stdin);
            cin>>aux;
            arbin->Buscar(aux);
        break;

        case 5:
            cout<<endl<<"Imprimiendo"<<endl;
            arbin->Imprimir();
        break;

        case 6:
             cout<<endl<<"Antes"<<endl;
            arbin->Imprimir();
            cout<<endl<<"Convertido"<<endl;

            arbin->Convertir();
            arbin->Imprimir();
        break;

        case 7:
            system("clear");
            cout<<"Cerrando aplicacion...";
            salir = true;
            break;

        default:
            system("clear");
            cout<<endl<<"\tOpcion invalida!"<<endl;
        break;
    }

    }while(salir != true);


    return 0;
}
