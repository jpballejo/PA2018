/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 02:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include<list>
#include <string>
#include<sstream>
#include <random>
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Socio.h"
#include "DtSocio.h"
#include "Inscripcion.h"
#include "eTurno.h"
#include "DtClase.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"
#include "Fecha.h"
using namespace std;

int const MAX_SOCIOS = 10, MAX_CLASES = 10;
int CantSocios = 0;
int CantClases = 0;
int Cant = 0;

Socio* arreglo_socios[MAX_SOCIOS];
Clase* arreglo_clases[MAX_CLASES];

/*
 * 
 */
void infoSocio();
void datosSocio ();
void mostrarClaseS();
void mostrarSocios();
void agregarSocio(string,string);
bool existeSocio(string);
void agregarInscripcion(string, int, Fecha*);
void pedirDatosClase();
void agregarClase(DtClase&);
bool existeClase(int);
void inscribirSocio();
void mostrarInscripciones();
void borrarSocio();
Socio* existeSociop(string);
Clase* existeClasep(int);
void borrarInscripcion(string, int);
DtSocio** obtenerInfoSociosPorClase(int,int&);
DtClase& obtenerClase(int);
//Clase* tipoClase(DtClase& clase);

int main(int argc, char** argv) {
    
    for (int i = 0; i < MAX_SOCIOS; i++)
        arreglo_socios[i] = NULL;

    for (int j = 0; j < MAX_CLASES; j++)
        arreglo_clases[j] = NULL;

    int idClase;
   
    string ci;
    int opcionMenu;
    do {
        cout << "\n1- Agregar socio\n2- Agregar clase\n3- Inscribir a clase\n4- Borrar Inscripcion\n5- obtenerInfoSociosPorClase\n6- Obtener Clase\n0- Salir\n";
        cin>>opcionMenu;
        switch (opcionMenu) {
            case 1:
             datosSocio ();
                break;
            case 2:
               pedirDatosClase();
                break;
            case 3:
                inscribirSocio();
                break;
            case 4:
                borrarSocio();
                break;
            case 5:
                infoSocio();
                break;
            case 6:
                mostrarClaseS ();
                break;
            
            case 0:
                break;
            default:
                cout << "\nOpción incorrecta. Por favor intente nuevamente.\n";
                break;
        }
    } while (opcionMenu != 0);


    return 0;
    
}

void infoSocio(){
DtSocio** arreglo_dtSocio;
int idClase=0;

try{
        cout << "ID Clase: ";
        cin>>idClase;
        Clase * cla= existeClasep(idClase);
        arreglo_dtSocio=obtenerInfoSociosPorClase(idClase,CantSocios);
        for (int i = 0; i <= CantSocios; i++) {
            cout << "Nombre: " + arreglo_dtSocio[i]->getNombre() + "\n";
            cout << "Cedula: " + arreglo_dtSocio[i]->getCi() + "\n";
        }

    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }

}
void borrarSocio(){
    string ci="";
    int idClase;
try{               
         
                
                cout << "CI Socio: ";
                cin>>ci;
                cout << "ID Clase:";
                cin >> idClase;
                borrarInscripcion(ci, idClase);
          
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }    
}

void mostrarClaseS (){
   DtClase* clase;
   int idClase=0;
   try{
       
       cout << "Ingrese el ID de Clase: ";
        cin>>idClase;


        clase = &obtenerClase(idClase);

        if (DtSpinning* cla = dynamic_cast <DtSpinning *>(clase))
            cout<<cla;
        if (DtEntrenamiento* cla = dynamic_cast <DtEntrenamiento *>(clase))
                cout<<cla;
   
          
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }           
}
DtClase& obtenerClase(int idClase) {

        if(existeClase(idClase)!=true)
            throw std::invalid_argument("No existe la clase");
    Clase* clase = NULL;
    DtClase* resultado = NULL;


    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {

            clase = arreglo_clases[i];

            Entrenamiento* entrenamiento = dynamic_cast<Entrenamiento*> (clase);

            if (entrenamiento != NULL) {
                resultado = new DtEntrenamiento(entrenamiento->getId(), entrenamiento->getNombre(), entrenamiento->getTurno(), entrenamiento->getEnRambla());
                return* resultado;

            } else {

                Spinning* spinning = dynamic_cast<Spinning*> (clase);

                if (spinning != NULL) {
                    resultado = new DtSpinning(spinning->getId(), spinning->getNombre(), spinning->getTurno(), spinning->getCantBicicletas());
                    return* resultado;
                }

            }

            throw invalid_argument("La clase no existe");

        }

    }
}
Fecha* armarFecha() {
    int dia = 0;
    int mes = 0;
    int anio = 0;
    cout << "Ingrese la fecha: \n";
    cout << "Ingrese dia: \n";
    cin>>dia;
    if (dia < 1 && dia > 31){
        throw invalid_argument("El dia no es correcto");}
    cout << "Ingrese el mes: \n";
    cin>>mes;
    if(mes<1 && mes >12)
        throw invalid_argument("El mes no es correcto");
    cout << "Ingrese el año: \n";
    cin>>anio;
    if (anio<1900 && anio>2018)
        throw invalid_argument("Ell año no es correcto");
    Fecha * fech = new Fecha(dia, mes, anio);

    return fech;

}

bool existeClase(int id) {

    for (int a = 0; a < CantClases; a++) {
        if (arreglo_clases[a]!=NULL && arreglo_clases[a]->getId() == id)
            return true;
    }
    return false;
}

void inscribirSocio() {
    int codClase=0;
    string ciS;
    try{
        cout << "Incribir Socio a clase\n";
        cout << "Ingrese la cedula:\n";
        cin>>ciS;
        cout << "Ingrese el codigo de la clase:\n";
        cin>>codClase;
        
            
            agregarInscripcion(ciS, codClase, armarFecha());
        
          
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void agregarInscripcion(string ci, int codC, Fecha* fecha) {
    
      if (existeSocio(ci) == false && existeClase(codC) == false) 
          throw invalid_argument("No existe el socio o la clase");
        Socio* soc = existeSociop(ci);
        Clase* clas = existeClasep(codC);
        if (!clas->socioEnClase(ci)) {
            Inscripcion * ins = new Inscripcion(soc, fecha);
            clas->setInscripcion(ins);
        Cant++;
        } else {
            throw std::invalid_argument("El socio ya esta inscripto a la clase.");
        }
    
}

void mostrarInscripciones() {

    int idClase;

    cout << "ID Clase: ";
    cin>>idClase;

    Clase* clase = NULL;

    for (int i = 0; i < CantClases; i++)
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {
            clase = arreglo_clases[i];
            break;
        }

    if (clase == NULL) {
        throw invalid_argument("la clase no existe");
    }

    Inscripcion** inscripciones = clase->getInscripcion();

    Entrenamiento* entrenamiento = dynamic_cast<Entrenamiento*> (clase);

    int cupos = 0;

    if (entrenamiento != NULL) {
        cupos = entrenamiento->cupo();
    } else {
        Spinning* spinning = dynamic_cast<Spinning*> (clase);

        cupos = spinning->cupo();
    }

    for (int i = 0; i < cupos; i++) {
        if (inscripciones[i] != NULL) {
            cout << "SOCIO: " + inscripciones[i]->getSocio()->getNombre() + "\n";
        }
    }

}

void borrarInscripcion(string ciSocio, int idClase) {

    Clase* clase = NULL;
    


                if ((existeClase(idClase))!=true && (existeSocio(ciSocio)!=true))
                    throw std::invalid_argument("El socio o la clase no existen"); 
  /*  for (int i = 0; i < CantSocios; i++)
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(ciSocio) == 0) {
            socio = arreglo_socios[i];
         
            break;
        }

    if (socio == NULL) {
        throw invalid_argument("El socio no existe");
    }


    

    if (clase == NULL) {
        throw invalid_argument("la clase no existe");
    }
*/  
                
                for (int i = 0; i < CantClases; i++)
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {
            clase = arreglo_clases[i];
            break;
        }
                Inscripcion** inscripciones = clase->getInscripcion();

                if(inscripciones==NULL)throw invalid_argument("La inscripcion no existe");
                delete inscripciones;
}

void pedirDatosClase() {
    int id=0, optT=0, op=0,cantBici=0;;
    string nombre=" ";  
    Turno t;
try{    
    
        cout << "\nIngrese ID de la clase\n";
        cin>>id;
        cout << "\nIngrese nombre de la clase\n";
        cin>>nombre;        
        cout << "\nIngrese turno de la clase:\n1- Manana\n2- Tarde\n3- Noche\n";
        cin>>optT;
        switch (optT) {
            case 1:
                t = Turno::Manana;
                break;
            case 2:
                t = Turno::Tarde;
                break;
            case 3:
                t = Turno::Noche;
                break;
            default:
                break;
        }
        cout << "\nQue tipo de clase desea crear?\n1- Spinning\n2- Entrenamiento\n";
        cin>>op;
    if(op==1){cout<<"Ingrese la cantidad de bicicletas: "<<endl;
        cin>>cantBici;
        if (existeClase(id))throw std::invalid_argument("El ID de la clase ya existe");
        
        DtSpinning * DtSpin = new DtSpinning(id,nombre,t,cantBici);
        agregarClase(*DtSpin);//y esto es necesario porque no es por referencia es por el coso 
    }
    if(op==2){cout << "El entrenamiento es en rambla?\n1- Si\n2- No\n";
    cin>>op;
    if(op==1){
        if (existeClase(id))throw std::invalid_argument("El ID de la clase ya existe");
        
        DtEntrenamiento * DtEntre = new DtEntrenamiento(id,nombre,t,true);
    agregarClase(*DtEntre);
    }
    if(op==2){DtEntrenamiento * DtEntre = new DtEntrenamiento(id,nombre,t,false);
    agregarClase(*DtEntre);}
           
    }
                
              
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void agregarClase(DtClase& clase) {
//sabelo estoy re loco
    //aca empieza el coso este primero casteo el spinning ameo, si es creo un
    //obj spinning y despues lo agrego al arreglo clase ya tu sabe
    try{
    DtSpinning * DtSpin = dynamic_cast<DtSpinning*>(&clase);//y precisa esto & porque no es por referencia
    //es por parametros
    if (DtSpin){Spinning* Spin = new Spinning(DtSpin->getId(),DtSpin->getNombre(),DtSpin->getTurno(),DtSpin->getCantBicicletas());
    if(CantClases>= MAX_CLASES)throw std::invalid_argument("Tope de clase");
    else{arreglo_clases[CantClases]=Spin; CantClases++;}

                }
// y bueno aca casteamos el entrenamiento y creo la clase entrenamiento y desoues lo agrego al arrego calses
    DtEntrenamiento* DtEntre = dynamic_cast<DtEntrenamiento*>(&clase);

    if (DtEntre){Entrenamiento* Entre = new Entrenamiento(DtEntre->getId(),DtEntre->getNombre(),DtEntre->getTurno(),DtEntre->getEnRambla());
    if(CantClases>= MAX_CLASES)throw std::invalid_argument("Tope de clase");
    else{arreglo_clases[CantClases]=Entre; CantClases++;}}
                  
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }        
//por ultimo en los dos if incremento el cantClase variable grobal cosa 
    //Jp estuvo aqui...
}//entendi heeee.......

void datosSocio (){
 string ci, nombre;
try { 
        cout << "\nIngrese el número de Cédula del nuevo socio\n";
        cin>>ci;
        cout << "\nIngrese el nombre del nuevo socio\n";
        cin>>nombre;                       
        agregarSocio(ci,nombre);    
           
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
 
 



}

void agregarSocio(string ci, string nombre) {
    
    if (existeSocio(ci))throw std::invalid_argument("Ya existe el socio ingresado");
    
            Socio* s = new Socio(ci, nombre);
            if (CantSocios >= MAX_SOCIOS)throw std::invalid_argument("Tope de socios");
            else{arreglo_socios[CantSocios]=s;
            CantSocios++;}
    }
     


Socio* existeSociop(string cedula) {
    for (int i = 0; i < CantSocios; i++) {
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(cedula) == 0)
            return arreglo_socios[i];
    }
    return NULL;

}

Clase* existeClasep(int cod) {
    Clase* clase = NULL;
    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == cod) {

            clase = dynamic_cast<Entrenamiento*> (arreglo_clases[i]);
            if (clase != NULL) {
                return clase;
            } else {
                clase = dynamic_cast<Spinning*> (arreglo_clases[i]);
                return clase;
            }
            //return arreglo_clases[i];
        }
    }
    return NULL;
}

bool existeSocio(string CI) {

    for (int i = 0; i < CantSocios; i++) {
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(CI) == 0) {
            return true;
        }
    }
    return false;
}


DtSocio** obtenerInfoSociosPorClase(int idClase, int& cantSocios) {
   
       DtSocio ** arreglo_soc = new DtSocio*[cantSocios]();
       Clase* clase = existeClasep(idClase);
       if(clase!=NULL){
            int tam=0;
            for (int i=0;i<=MAX_SOCIOS;i++){
                   if(clase->socioEnClase(arreglo_socios[i]->getCI())==true){
                            DtSocio * aux =new DtSocio(arreglo_socios[i]->getCI(),arreglo_socios[i]->getNombre());
                            arreglo_soc[tam]= aux;tam++;}                                                       }
          }
   // DtSocio** arreglo_soc = new DtSocio*[cantSocios]();
             
  return arreglo_soc; 
     
  
        }
