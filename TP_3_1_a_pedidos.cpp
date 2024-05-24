/*
  1.a Una aplicación para un restaurante que tiene: primer plato, plato principal y poste, 
  toma pedidos de los mozos. Estos envían la comanda codificada por numero para cada plato.
  El cocinero recibe el pedido en formato de texto con el nro de mesa, nombre mozo, fecha,
   hora, primer plato, plato principal y poste. 
   Se pide desarrollar una APP que pida la comanda y muestre por pantalla la Info solicitada.
*/

#include <iostream>
#include <string>
using namespace std;

// al poner =1 al primer elemento, cuando se usa un menu directamente es
// la opcion la elegida. 
enum PrimerPlato { ANTIPASTO=1, MAYONESA_DE_AVE, EMPANADITAS, SOPA };  // opciones de primer plato
enum PlatoPrincipal { BIFE_DE_CHORIZO=1, ENSALADA_CESAR, FIDEOS_CON_SALSA, MILANESA_NAPOLITANA }; // opciones de plato principal
enum Postre { VIGILANTE=1, HELADO, BUDIN_DE_PAN }; // opciones de postre
enum Mozos { JUAN=1, CARLOS, JOSE };

struct Comanda {                                      // estructura para la comanda
    int numeroMesa;
    Mozos nombreMozo;
    unsigned short int fecha;
    unsigned short int hora;
    PrimerPlato primerPlato;
    PlatoPrincipal platoPrincipal;
    Postre postre;
};

string getNombreMozo(Mozos nomMozo);
string getNombrePrimerPlato(PrimerPlato plato);
string getNombrePlatoPrincipal(PlatoPrincipal plato);
string getNombrePostre(Postre postre);
Comanda tomarPedido();
void imprimirPedido(Comanda pedido);
void pauseConsole();
void clearConsole();

int main() {
    clearConsole();
    Comanda pedidoGlob;
    cout << "===================================================\n";
    cout << "\nBienvenido al sistema de pedidos del restaurante.\n";
    cout << "Por favor ingrese los datos del pedido a continuacion=\n";
    pedidoGlob = tomarPedido();

    int menu=0;    
    clearConsole();
    do {
    cout << "\n1- Imprimir Pedido por Pantalla\n";
    cout << "2- Volver a realizar el pedido\n";
    cout << "0- Salir\n";
    cin.ignore();
    cin >> menu;
    switch(menu) {
        case 1: imprimirPedido(pedidoGlob); cout << endl;break;;
        case 2: pedidoGlob = tomarPedido();
        case 0: cout << "Gracias por usar el sistema de pedidos del restaurante.\n"; break;
      
        default: cout << "\nOpción inválida. Por favor, ingrese una opción valida.\n"; break;
    }
          
    } while (menu != 0);
        
    return 0;
}

string getNombreMozo(Mozos nomMozo) {
    switch (nomMozo) {
        case JUAN: return "Juan";
        case CARLOS: return "Carlos";
        case JOSE: return "José";
        default: return "Desconocido";
    }
}

string getNombrePrimerPlato(PrimerPlato plato) {
    switch (plato) {
        case ANTIPASTO: return "Antipasto";
        case MAYONESA_DE_AVE: return "Mayonesa de ave";
        case EMPANADITAS: return "Empanaditas";
        case SOPA: return "Sopa";
        default: return "Desconocido";
    }
}

string getNombrePlatoPrincipal(PlatoPrincipal plato) {
    switch (plato) {
        case BIFE_DE_CHORIZO: return "Bife de chorizo";
        case ENSALADA_CESAR: return "Ensalada César";
        case FIDEOS_CON_SALSA: return "Fideos con salsa";
        case MILANESA_NAPOLITANA: return "Milanesa napolitana";
        default: return "Desconocido";
    }
}

string getNombrePostre(Postre postre) {
    switch (postre) {
        case VIGILANTE: return "Vigilante";
        case HELADO: return "Helado";
        case BUDIN_DE_PAN: return "Budín de pan";
        default: return "Desconocido";
    }
}

Comanda tomarPedido() {
    Comanda pedido;
   
    int opcion;
    cout << "Ingrese el número de mesa: ";
    cin >> pedido.numeroMesa;
    clearConsole();

    
    cout << "Ingrese el nombre del mozo: \n";
    cout << "1. Juan\n2. Carlos\n3. Jóse\n";
    cin >> opcion;
    while (opcion < 1 || opcion > 3) {
        cout << "\nOpción inválida. Por favor, ingrese una opcion valida para el nombre del mozo: ";
        cin >> opcion;
    }
    //pedido.nombreMozo = static_cast<Mozos>(opcion);
    pedido.nombreMozo = Mozos(opcion);
    clearConsole();

    cout << "Ingrese la fecha (Solo el dia): ";
    cin >> pedido.fecha;
    while (!((pedido.fecha <= 31) && (pedido.fecha >= 1 ))) {
        cout << "\nFecha inválida. Por favor, ingrese la fecha (Solo el dia): ";
        cin >> pedido.fecha;
    }
    clearConsole();

    cout << "Ingrese la hora (Solo la hora): ";
    cin >> pedido.hora;
        while (!((pedido.hora <= 23) && (pedido.fecha >= 0 ))) {
        cout << "\nHora inválida. Por favor, ingrese la hora (Solo la hora): ";
        cin >> pedido.hora;
    }
    clearConsole();

    cout << "\nElija el primer plato:\n";
    cout << "1. Antipasto\n2. Mayonesa de ave\n3. Empanaditas\n4. Sopa\n";
    cin >> opcion;
    while (opcion < 1 || opcion > 4) {
        cout << "\nOpción inválida. Por favor, ingrese una opcion del Menu: ";
        cin >> opcion;
    }
    //pedido.primerPlato = static_cast<PrimerPlato>(opcion);
    pedido.primerPlato = PrimerPlato(opcion);
    clearConsole();

    cout << "\nElija el plato principal:\n";
    cout << "1. Bife de chorizo\n2. Ensalada César\n3. Fideos con salsa\n4. Milanesa napolitana\n";
    cin >> opcion;
    while (opcion < 1 || opcion > 4) {
        cout << "\nOpción inválida. Por favor, ingrese una opcion del Menu: ";
        cin >> opcion;
    }   
    //pedido.platoPrincipal = static_cast<PlatoPrincipal>(opcion);
    pedido.platoPrincipal = PlatoPrincipal(opcion);
    clearConsole();

    cout << "\nElija el postre:\n";
    cout << "1. Vigilante\n2. Helado\n3. Budín de pan\n";
    cin >> opcion;
    while (opcion < 1 || opcion > 3) {
        cout << "\nOpción inválida. Por favor, ingrese una opcion del Menu: ";
        cin >> opcion;
    }   
    //pedido.postre = static_cast<Postre>(opcion);
    pedido.postre = Postre(opcion);
    clearConsole();

    return pedido;   
}

void imprimirPedido(Comanda pedido) {
    clearConsole();
    cout << "===================================================\n";
    cout << "\nPedido:\n";
    cout << "Mesa: " << pedido.numeroMesa << "\n";
    cout << "Mozo: " << getNombreMozo(pedido.nombreMozo) << "\n";
    cout << "Fecha: " << pedido.fecha << "\n";
    cout << "Hora: " << pedido.hora << "\n";
    cout << "Primer plato: " << getNombrePrimerPlato(pedido.primerPlato) << "\n";
    cout << "Plato principal: " << getNombrePlatoPrincipal(pedido.platoPrincipal) << "\n";
    cout << "Postre: " << getNombrePostre(pedido.postre) << "\n";
    cout << "===================================================\n";
}


void pauseConsole() {
    std::cin.get();
}

void clearConsole() {
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN64)
        system("cls");
    #endif
}