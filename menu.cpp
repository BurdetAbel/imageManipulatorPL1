//
// Created by abelb on 24/10/2024.
//

#include "menu.h"
#include "funciones.h"
#include "pila.h"

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

    string image_path,img_catalogo;
    Mat img, gray, rotat,escala, desenfc, contrast, recorte, border,invert, sharp, img2;
    Pila imgGris, imgRotada, imgEscala, imgDesenfc, imgContrast, imgRecorte, imgBorder, imgInvert, imgSharp;

    do{
        cout << " ---------------------------" << endl;
        cout << "  Menu para editar imagenes" << endl;
        cout << " ---------------------------" << endl;

        cout << "\n1. Modificar una imagen especifica" << endl;
        cout << "2. Modificar varias imagenes" << endl;
        cout << "3. Modificar todas las imagenes" << endl;
        cout << "4. Modificar solamente las imagenes impares"<< endl;
        cout << "5. Modificar solamente las imagenes pares"<< endl;
        cout << "6. Mostrar Imagenes (Collage)"<< endl; // Collage con las fotos originales
        cout << "7. Mostrar imagen/s editadas"<< endl; // Collage con las fotos editadas
        cout << "8. Mostrar catalogo IMAGENES"<< endl; // Imagenes con su nombre
        cout << "0. Salir "<< endl;


        cout << "\nIntroduzca su opcion: ";
        cin >> opcionTipo;



        switch (opcionTipo) {
            case 1:

                int img_especifica;
                while (true) {
                    cout << "Selecciona modificar una imagen especifica (entre 1 y 25)." << endl;
                    cin >> img_especifica;

                    if ((img_especifica < 1)||(img_especifica > 25 )) {
                        cout << "\nEl numero " << img_especifica << " no corresponde a ninguna imagen." << endl;
                    }else {
                        cout << "\nEl numero " << img_especifica << " corresponde a imagen." << endl;
                        break;
                    }
                }

                image_path = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/" + std::to_string(img_especifica) + ".jpg";
                img = imread(image_path, IMREAD_COLOR);


            // Apilando Pilas
                imgGris.apilar(img);
                imgRotada.apilar(img);
                imgEscala.apilar(img);
                imgDesenfc.apilar(img);
                imgContrast.apilar(img);
                imgRecorte.apilar(img);
                imgBorder.apilar(img);
                imgInvert.apilar(img);
                imgSharp.apilar(img);



                // No hay que enseñar imagen. Hay que guardar variable imagen en una pila

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
            case 8:

                img_catalogo = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/catalogoImagen.jpg";

                cout << "Has seleccionado mostrar catalogo de todas las imagenes." << endl;
                img2 = imread(img_catalogo, IMREAD_COLOR);
                resize(img2, img2, Size((1200), (628)), 0, 0, INTER_NEAREST); //1200x628 tamaño collage final

                namedWindow("Catalogo", WINDOW_NORMAL);
                imshow("Catalogo", img2);
                setWindowProperty("Catalogo", WND_PROP_TOPMOST, 1); // Mantener la ventana siempre encima
            //  moveWindow("Catalogo", 1400, 600);
                waitKey(1); // Permite actualizar la ventana sin detener el programa principal

                break;

            case 0:
                break;


            default:
                cout << "Opcion no valida." << endl;

        }

        if ((opcionTipo == 1)||(opcionTipo == 2)||(opcionTipo == 3)||(opcionTipo == 4)||(opcionTipo == 5)){
            cout << "\n---------------------" << endl;
            cout << " Seleccione edicion:" << endl;
            cout << "---------------------" << endl;

            cout << "\n1. Rotar (90, 180, 270, 360)" << endl;
            cout << "2. Filtro Escala de grises" << endl;
            cout << "3. Desenfocar" << endl;
            cout << "4. Modificar Brillo/Contraste"<< endl;
            cout << "5. Escalar"<< endl;
            cout << "6. Recortar"<< endl;
            cout << "7. Marcos/Bordes"<< endl;
            cout << "8. Invertir"<< endl;
            cout << "9. Nitidez" << endl;
            cout << "0. Salir "<< endl;

            cout << "\nIntroduzca su opcion: ";
            cin >> opcionEdicion;

            switch (opcionEdicion) {
                case 1:
                    // Rotar imagen
                    rotat = Funciones::rotarImagen(imgRotada.desapilar());
                    imshow("Imagen rotada", rotat);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas

                    break;

                case 2:
                    // Filtrar imagen a escala de grises
                    gray = Funciones::convertirImagenAGrises(imgGris.desapilar());
                    imshow("Imagen gris", gray);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas

                    break;

                case 3:
                    // Desenfocar Imagen
                    desenfc = Funciones::desenfocarImagen(imgDesenfc.desapilar());
                    imshow("Imagen desenfocada", desenfc);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas

                    break;

                case 4:
                    // Contraste y brillo Imagen
                    contrast = Funciones::cambiarBrilloContrasteImagen(imgContrast.desapilar());
                    imshow("Imagen - Brillo / Contraste", contrast);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas

                    break;

                case 5:
                    // Escalar imagen
                    escala = Funciones::escalarImagen(imgEscala.desapilar());
                    imshow("Imagen escalada", escala);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas

                    break;

                case 6:
                    // Escalar imagen
                    recorte = Funciones::recortarImagen(imgRecorte.desapilar());
                    imshow("Imagen recortada", recorte);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas
                    break;

                case 7:
                    // Añadir Borde imagen
                    border = Funciones::anadirBordes(imgBorder.desapilar());
                    imshow("Imagen con Borde - Marco", border);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas

                    break;
                case 8:
                    // Invertir imagen
                    invert = Funciones::invertirImg(imgInvert.desapilar());
                    imshow("Imagen invertida", invert);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas
                    break;

                case 9:
                    // Nitidez imagen
                    sharp = Funciones::anadirNitidez(imgSharp.desapilar());
                    imshow("Nitidez imagen", sharp);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas
                    break;

                default:
                    cout << "Opcion no valida." << endl;
            }
        }

    } while (opcionTipo != 0);

    cout << "Cerrando programa..." << endl;

}
