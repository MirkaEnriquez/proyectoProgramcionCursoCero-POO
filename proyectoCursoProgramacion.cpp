/*
PROYECTO:

Autor: Mirka Enriquez
Fecha: 22-03-2026

E/P/S
 Entrada:
    nombre del cliente
    horario en el que reserva
        1. 16:00
        2. 21:00
    tipo de mesa reservada 
        para 2 personas
        para 4 personas
        para 6 personas
 Proceso:
    mostrar el menú
    registro de la reserva
        guardar nombre, hora y tipo de mesa
        aumentar el contador de las mesas
        rechazar si ya esta lleno
    mostrar reservas:
        recorrer el arreglo
        mostrar el arreglo
    buscar reserva
        recorrer el arreglo de los nombres
        comparar si coincide con alguno registrado
    cancelar reserva
        buscar la reserva 
        desactivar la reserva
        disminuir el contador
    ver disponibilidad 
        calcular las mesas disponibles segun el horario 
    repetir hasta que el usuario decida salir
 Salida:
    mensaje con la confirmacion de la reserva
    mensaje avisando que no hay disponibilidad
    mensaje con las reservas realizadas
    mensaje indicando si se encontro la reserva
    mensaje indicando que la reserva no se ha encontrado
    mensaje confirmando la cancelacion de la reserva
    mensaje con el numero de mesas y el horario en el que se encuetran disponibles

*/
#include <iostream>
using namespace std;

void registrarReserva(string nombres[], int horarios[], int tipodemesa[], bool activa[], int &n,
    int &ocupadas2_18, int &ocupadas4_18, int &ocupadas6_18, int &ocupadas2_20, int &ocupadas4_20, int &ocupadas6_20);
void mostrarReservas(string nombres[], int horarios[], int tipodemesa[], bool activa[], int n);
void buscarReserva(string nombres[], bool activa[], int n);



int main(){

    string nombres[24];
    int horarios[24];
    int tipodemesa[24];
    int opcion = 0;

    bool activa[24];

    int n = 0;

    int mesas2 = 5, mesas4 = 4, mesas6 = 3;

    int ocupadas2_16 = 0, ocupadas4_16 = 0, ocupadas6_16 = 0;
    int ocupadas2_21 = 0, ocupadas4_21 = 0, ocupadas6_21 = 0;


    do
    {
        //Mostrar el menú
       cout << "========================================= " << endl;
       cout << " BIENVENIDO AL REGISTRO DE RESERVACIONES " << endl;
       cout << "========================================= " << endl;

       cout << " Menu de opciones" << endl;
       cout << " 1.- Registro de la reserva " << endl;
       cout << " 2.- Mostrar reservas " << endl;
       cout << " 3.- Buscar reserva " << endl;
       cout << " 4.- Cancelar reserva " << endl;
       cout << " 5.- Revisar disponibilidad" << endl;
       cout << " 6.- Salir " << endl;
       cin >> opcion;

       //Validar que opcion este dentro del rango de valores del menú
       if (opcion < 1 || opcion > 6)
       {
            cout << "Opcion invalida. Por favor vuelva a intentar: " << endl;
            cin >> opcion;
       } else if (opcion == 1) //Llamo a la funcion que registra la reserva
       {
            registrarReserva(nombres, horarios, tipodemesa, activa, n, ocupadas2_16,
                 ocupadas4_16, ocupadas6_16, ocupadas2_21, ocupadas4_21, ocupadas6_21);
       } else if (opcion == 2)//Llamo a la funcion que muestra las reservas
       {
            mostrarReservas(nombres, horarios, tipodemesa,activa, n);
       } else if (opcion == 3) //Llamo a la funcion que busca las reservas
       {
            buscarReserva(nombres, activa, n);
       }
       



    } while (opcion != 6);
    





}

//ARREGLO PARA REGISTRAR RESERVA
void registrarReserva(string nombres[], int horarios[], int tipodemesa[], bool activa[], int &n,
    int &ocupadas2_16, int &ocupadas4_16, int &ocupadas6_16, int &ocupadas2_21, int &ocupadas4_21, int &ocupadas6_21)
    {
       //Ingresar el nombre
        cout << "Ingrese el nombre: " << endl;
        cin >> nombres[n];

        //Elegir horario
        cout << "Eliga el horario: " << endl;
        cout << "1.- 16:00" << endl;
        cout << "2.- 21:00" << endl;
        cin >> horarios[n];

        //Validar horario
        while(horarios[n] != 1 && horarios[n] != 2){
            cout << "Opcion invalida. Por favor vuelva a intentar: ";
            cin >> horarios[n];
            }

        //Elegir el tipo de mesa 
        cout << "Tipo de mesa (Para 2, 4 o 6 personas): ";
        cin >> tipodemesa[n];

        //Validar el tipo de mesa
        while (tipodemesa[n] != 2 && tipodemesa[n] !=4 && tipodemesa[n] !=6)
        {
            cout << "Opcion invalida. Por favor vuelva a intentar: ";
            cin >> tipodemesa[n];
        }


        //Revisar  disponibilidad
        bool disponible = false;

        if(horarios[n] == 1){ // 16:00
            if(tipodemesa[n] == 2 && ocupadas2_16 < 5){
                ocupadas2_16++; 
                disponible = true;
            }
            else if(tipodemesa[n] == 4 && ocupadas4_16 < 4){
                ocupadas4_16++;
                disponible = true;
            }
            else if(tipodemesa[n] == 6 && ocupadas6_16 < 3){
                ocupadas6_16++; 
                disponible = true;
            }
        }
        else{ // 21:00
            if(tipodemesa[n] == 2 && ocupadas2_21 < 5){
                ocupadas2_21++; 
                disponible = true;
            }
            else if(tipodemesa[n] == 4 && ocupadas4_21 < 4){
                ocupadas4_21++; 
                disponible = true;
            }
            else if(tipodemesa[n] == 6 && ocupadas6_21 < 3){
                ocupadas6_21++; 
                disponible = true;
            }
        }

        //Mostrar disponibilidad y aumentar el contador si es posible
        if(disponible == true){
            activa[n] = true;
            n++;
            cout << "Reserva registrada exitosamente" << endl;
        }
        else{
            cout << "No hay disponibilidad para completar la reserva" << endl;
        }        
     }

//ARREGLO PARA MOSTRAR RESERVA

void mostrarReservas(string nombres[], int horarios[], int tipodemesa[], bool activa[], int n)
{
    for(int i = 0; i < n; i++){
        if(activa[i] == true){
            cout << "Reservacion a nombre de " << nombres[i] << " - ";

            if(horarios[i] == 1)
                {cout << "16:00";
              }  
            else
                {cout << "21:00";
              }
            cout << " - Mesa para " << tipodemesa[i] << endl;
        }
    }
}

//ARREGLO PARA BUSCAR RESERVA

void buscarReserva(string nombres[], bool activa[], int n)
{
    string buscar;
    cout << "Ingrese el nombre a buscar: ";
    cin >> buscar;

    for(int i = 0; i < n; i++){
        if(nombres[i] == buscar && activa[i]){
            cout << "Reserva encontrada." << endl;
            return; //Investigue y esto aydua a que salga de la funcion y no imprima reserva no encontrada incluso cuando si la existe una 
        }
    }

    cout << "Reserva no encontrada." << endl;
}
            