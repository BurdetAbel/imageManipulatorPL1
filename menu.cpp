//
// Created by abelb on 24/10/2024.
//

#include "menu.h"


#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // Para la función cvtColor
#include <iostream>
#include <filesystem>

using std::string, std::cout, std::endl, std::cerr;
using std::cout; using std::cin; using std::endl;
const int minimum = 0, maximum = 10;
namespace fs = std::filesystem;  // Alias para el espacio de nombres
using namespace cv;

void modificarImagen(int tipo);
void aplicarEdicion(int edicion);

void mostrarMenu() {

    int opcionTipo, opcionEdicion, img_especifica, img_seleccionada;

    string image_path;
    Mat img;

    do{
        cout << "Seleccione la cantidad de imagenes a editar:" << endl;

        cout << "1. Modificar una imagen especifica" << endl;
        cout << "2. Modificar varias imagenes" << endl; //Se puede quitar
        cout << "3. Modificar todas las imagenes" << endl;
        cout << "4. Modificar solamente las imagenes impares"<< endl;
        cout << "5. Modificar solamente las imagenes pares"<< endl;
        cout << "6. Mostrar Imagenes (Collage)"<< endl;
        cout << "7. Mostrar imagen/s editadas"<< endl;
        cout << "8. Salir "<< endl;

        cout << "\nIntroduzca su opcion: ";
        cin >> opcionTipo;



        switch (opcionTipo) {
            case 1:
                cout << "Selecciona modificar una imagen especifica (entre 1 y 25)." << endl;
                cin >> img_especifica;

                if ((img_especifica < 1)||(img_especifica > 25 ))
                    cout << "\n El numero " << img_especifica << " no corresponde a ninguna imagen." << endl;
                else
                    int img_selccionada = img_especifica;
                    image_path = "C:/Users/abelb/Downloads/displayImage (1)/displayImage/images8k/" + std::to_string(img_especifica) + ".jpg";
                    img = imread(image_path, IMREAD_COLOR);

                    imshow("Original Image", img);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas


            break;

            case 2:
                cout << "Has seleccionado modificar varias imagenes." << endl;

                /*
                int cantidad;
                cout << "¿Cuantas imagenes quieres editar?: ";
                cin >> cantidad;

                // Crear un vector del tamaño de la cantidad seleccionada
                std::vector<int>imagenes_cant(cantidad);

                for (int i = 0; i < cantidad; ++i) {
                    int numeroImagen;
                    do {
                        cout << "Ingresa el numero de la imagen " << i + 1 << " (1 - 25): ";
                        cin >> numeroImagen;
                        if (numeroImagen < 1 || numeroImagen > 25) {
                            cout << "Numero fuera de rango. Intente de nuevo." << endl;
                        }
                    } while (numeroImagen < 1 || numeroImagen > 25);

                    // Asignar el número de la imagen al vector
                    imagenes_cant[i] = numeroImagen;
                }

                // Mostrar las imágenes seleccionadas
                cout << "\nLas imagenes seleccionadas son:" << endl;
                for (int i = 0; i < cantidad; ++i) {
                    cout << "Imagen numero: " << imagenes_cant[i] << endl;
            }
            */
                break;

            case 3:
                cout << "Has seleccionado modificar todas las imágenes." << endl;

                break;
            case 4:
                cout << "Has seleccionado modificar las imágenes impares." << endl;

                break;
            case 5:
                cout << "Has seleccionado modificar las imágenes pares." << endl;

                break;

            case 6:
                cout << "Has seleccionado mostrar todas las imágenes." << endl;
                break;

            case 7:
                cout << "Has seleccionado mostra las imágenes modificadas." << endl;
                break;

            default:
                cout << "Opción no valida." << endl;


        }

        cout << "Seleccione edicion:" << endl;

        cout << "1. Rotar (90, 180, 270, 360)" << endl;
        cout << "2. Filtro Escala de grises" << endl;
        cout << "3. Desenfocar" << endl;
        cout << "4. Modificar Brillo/Contraste"<< endl;
        cout << "5. Escalar"<< endl;
        cout << "6. Recortar"<< endl;
        cout << "7. Añadir Marcos/Bordes"<< endl;
        cout << "8. Salir "<< endl;

        cout << "\nIntroduzca su opcion: ";
        cin >> opcionEdicion;

        switch (opcionEdicion) {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            default:
                cout << "Opción no valida." << endl;
        }
    }while (opcionTipo != 8);
}