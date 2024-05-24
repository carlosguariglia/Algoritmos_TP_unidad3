/*
    c. Un Verdulería nos pide que armemos el pedido para el mayorista para lo cual
    deberemos pedir al usuario el código proveedor, razón social, fecha de solicitud
     y fecha de entrega. Las frutas estarán enumeradas (tomar solo 6 a modo de
      ejemplo), mostrando los datos x pantalla.
        
*/

#include <iostream>
#include <string>
using namespace std;
enum frutas { NARANJA=1, BANANA, MANZANA, KIWI, MELON, SANDIA};   // enumeracion de frutas, se puso =1 para que el primer elemento sea 1 en lugar de 0

void TomarPedido(int &codproveedor, int &razonsocial, string &fechasol, string &fechaentrega, frutas &pedido); // procedimiento para tomar pedido se usa & para que sea por referencia
void MostrarPedido(int codproveedor, int razonsocial, string fechasol, string fechaentrega, frutas pedido); // procedimiento para mostrar pedido
string GetnombreFruta(frutas fruta);
void pauseConsole();
void clearConsole();

int main() {
    int codproveedor=-1;
    int razonsocial;
    string fechasol;
    string fechaentrega;
    frutas pedido;
    int menu;
    clearConsole();
    do {
        cout << "\nMenu de opciones Verduleria San Jose\n";
        cout << "1- Ingresar Pedido para el mayorista\n";
        cout << "2- Mostrar Pedido para el mayorista\n";
        cout << "0- Salir\n";
        cin >> menu;
        switch (menu) {
            case 1: TomarPedido(codproveedor, razonsocial, fechasol, fechaentrega, pedido); break;
            case 2: MostrarPedido(codproveedor, razonsocial, fechasol, fechaentrega, pedido); break;
            case 0: break;
            default: cout << "Opcion Invalida.\n";
        }
    } while (menu != 0);

    cout << "Gracias por usar nuestro servicio de pedidos\n";
    return 0;
}

void TomarPedido(int &codproveedor, int &razonsocial, string &fechasol, string &fechaentrega, frutas &pedido)
{
    clearConsole();
    int fruta;
    cout << "Ingrese el codigo del proveedor:\n";
    cin >> codproveedor;
    clearConsole();
    cout << "Ingrese la razon social:\n";
    cin >> razonsocial;
    cin.ignore();
    clearConsole();
    cout << "Ingrese la fecha de solicitud:\n";
    getline(cin, fechasol);
    clearConsole();
    cout << "Ingrese la fecha de entrega:\n";
    getline(cin, fechaentrega);
    clearConsole();
    do {
        cout << "Ingrese la fruta pedida\n";
        cout << "1- Naranja				4- Kiwi\n";
        cout << "2- Banana				5- Melon\n";
        cout << "3- Manzana             6- Sandia\n";
        cin >> fruta;
        if (fruta<1 || fruta >6)
            cout << "Ingrese una opcion valida\n";
    } while (!((fruta>=1) && (fruta<=6)));

    pedido = frutas(fruta); //  para pasar el valor de fruta a pedido siendo la opcion un int porque es un enumerado
                            // entonces se pone:  la variable tipo enumerado = enumerado(variable int) donde int es la variable del menu
                            // pedido=static_cast<frutas>(fruta);
    clearConsole();
}   

void MostrarPedido(int codproveedor, int razonsocial, string fechasol, string fechaentrega, frutas pedido) {
    clearConsole();
    if (codproveedor!=-1) { 
        cout << "El proveedor es: " << codproveedor << endl;
        cout << "La razon social es: " << razonsocial << endl;
        cout << "La fecha de solicitud es: " << fechasol << endl;
        cout << "La fecha de entrega es: " << fechaentrega << endl;
        cout << "La fruta pedida es: " << GetnombreFruta(pedido) << endl;
        cout << endl;
    }
    else cout << "Aun no se ha hecho ningun pedido.\n";
}

string GetnombreFruta(frutas fruta) {
    switch (fruta) {
        case NARANJA: return "Naranja";
        case BANANA: return "Banana";
        case MANZANA: return "Manzana";
        case KIWI: return "Kiwi";
        case MELON: return "Melon";
        case SANDIA: return "Sandia";
        default: return "";
    }
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
