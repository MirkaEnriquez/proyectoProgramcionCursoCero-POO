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


int main(){

    string nombres[24];
    int horarios[24];
    int tipodemesa[24];
    int opcion = 0;

    bool activa[20];

    int n = 0;

    int mesas2 = 5, mesas4 = 4, mesas6 = 3;

    int ocupadas2_16 = 0, ocupadas4_16 = 0, ocupadas6_16 = 0;
    int ocupadas2_21 = 0, ocupadas4_21 = 0, ocupadas6_21 = 0;


    do
    {
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

       if (opcion < 1 || opcion > 6)
       {
        cout << "Opcion invalida. Por favor vuelva a intentar: " << endl;
        cin >> opcion;
       } else if (opcion == 1)
       {
            registrarReserva(nombres, horarios, tipodemesa, activa, n, ocupadas2_16,
                 ocupadas4_16, ocupadas6_16, ocupadas2_21, ocupadas4_21, ocupadas6_21);
       }
       

       




    } while (opcion != 6);
    





}


void registrarReserva(string nombres[], int horarios[], int tipodemesa[], bool activa[], int &n,
                      int &ocupadas2_18, int &ocupadas4_18, int &ocupadas6_18,
                      int &ocupadas2_20, int &ocupadas4_20, int &ocupadas6_20)
    {
       
        cout << "Ingrese el nombre: " << endl;
        cin >> nombres[n];

        cout << "Eliga el horario: " << endl;
        cout << "1.- 16:00" << endl;
        cout << "2.- 21:00" << endl;
        cin >> horarios[n];

        while(horarios[n] != 1 && horarios[n] != 2){
            cout << "Opcion invalida. Por favor vuelva a intentar: ";
            cin >> horarios[n];

        cout << "Tipo de mesa (Para 2, 4 o 6 personas): ";
        cin >> tipodemesa[n];

        while (tipodemesa[n] != 2 && tipodemesa[n] !=4 && tipodemesa[n] !=6)
        {
            cout << "Opcion invalida. Por favor vuelva a intentar: ";
            cin >> tipodemesa[n];
        }
        
}







     }
            