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
#include <sys/stat.h>
#include <iostream>
#include <list>
#include <stack>
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

    string image_path,img_catalogo, formato, output_path;
    Mat ejemplomat;
    Mat img, gray, rotat,escala, desenfc, contrast, recorte, border,invert, sharp, img2;
    Pila ejemplo, imgGris, imgRotada, imgEscala, imgDesenfc, imgContrast, imgRecorte, imgBorder, imgInvert, imgSharp;
    Mat collage2, collage1;
    int cantidad;
    std::list<int> imagenes_cant;
    std::stack<Mat> pilaImagenesOriginales; //Pila para almacenar las imágenes originales
    stack<Mat> pilaImagenesEditadas; // Pila para almacenar las imágenes editadas junto con las no editadas
    Pila pilaRotada, pilaGris, pilaDesenfocada, pilaBrilloContraste, pilaEscalada, pilaRecortada, pilaBordes, pilaInvertida, pilaNitidez;

    String folderPath = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/";
//---------------------------------------------------------------------------------------------------------------------------------------

    cout << "     ::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "     :::::::     MANIPULADOR DE IMAGENES     ::::::" << endl;
    cout << "     ::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "     :::: ABEL BURDET ::::::: CRISTIAN JIMENEZ ::::" << endl;
    cout << "     ::::: X9844318L :::::::::: 51495888S :::::::::" << endl;
    cout << "     ::::::::::::::::::::::::::::::::::::::::::::::" << endl;

    cout << "\n******** Iniciando..." << endl;


    // Inicializar la pila con imágenes originales
    for (int i = 1; i <= 25; ++i) {
        string image_path = folderPath + to_string(i) +".jpg";
        Mat img = imread(image_path, IMREAD_COLOR);
        if (!img.empty()) {
            pilaImagenesEditadas.push(img); // Apilar cada imagen original
        }
    }

    // Cargar las imágenes de 1 a 25
    for (int i = 1; i <= 25; ++i) {
        std::string imagePath = folderPath + std::to_string(i) + ".jpg"; // Asumiendo que las imágenes están numeradas del 1 al 25

        Mat img = imread(imagePath, IMREAD_COLOR);
        if (img.empty()) {
            std::cout << "No se pudo cargar la imagen " << i << " desde " << imagePath << std::endl;
            continue; // Si la imagen no se carga, continuar con la siguiente
        }

        // Agregar la imagen cargada a la pila
        pilaImagenesOriginales.push(img);
    }
//---------------------------------------------------------------------------------------------------------------------------------------

    do {
        cout << " --------------------------------" << endl;
        cout << " ::  Menu para editar imagenes ::" << endl;
        cout << " --------------------------------" << endl;

        cout << "\n1. Modificar una imagen especifica" << endl;
        cout << "2. Modificar varias imagenes" << endl;
        cout << "3. Modificar todas las imagenes" << endl;
        cout << "4. Modificar solamente las imagenes Impares"<< endl;
        cout << "5. Modificar solamente las imagenes Pares"<< endl;
        cout << "6. Mostrar Imagenes ORIGINALES (Collage)"<< endl; // Collage con las fotos originales
        cout << "7. Mostrar Imagenes EDITADAS (Collage)" << endl; // Collage con las fotos editadas
        cout << "8. Mostrar catalogo IMAGENES"<< endl; // Imagenes con su nombre (mismo orden y posicion que en collage)
        cout << "9. Guardar >>> COLLAGE IMAGENES EDITADAS"<< endl; // Imagenes con su nombre
        cout << "0. Salir ::::::: [EXIT] :::::::"<< endl;
        cout << " --------------------------------" << endl;


        cout << "\n>>>>> Introduzca su opcion: ";
        cin >> opcionTipo;



        switch (opcionTipo) {
            case 1:


            while (true) {
                cout << ">>>>> Selecciona modificar una imagen especifica [entre 1 y 25]: " << endl;
                cin >> img_especifica;

                if ((img_especifica < 1)||(img_especifica > 25 )) {
                    cout << "\n!!ERROR!! --> El numero " << img_especifica << " no corresponde a imagen." << endl;

                }else {

                    imagenes_cant.clear();
                    imagenes_cant.push_back(img_especifica);
                    break;
                }
            }
            /*
                            image_path = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/" + std::to_string(img_especifica) + ".jpg";
                            img = imread(image_path, IMREAD_COLOR);

            */

            // Apilando imagenes
            //ejemplo.apilar(img);



            // No hay que enseñar imagen. Hay que guardar variable imagen en una pila

            break;

            case 2:
                cout << "Has seleccionado modificar varias imagenes." << endl;

            cout << ">>>>> Cuantas imagenes quieres editar?: ";
            cin >> cantidad;

            // Limpiar la lista antes de usarla
            imagenes_cant.clear();


            // Llenar la lista con el número de imágenes
            for (int i = 0; i < cantidad; ++i) {
                int numeroImagen;
                do {
                    cout << ">>>>> Ingresa el numero de la imagen " << i + 1 << " (1 - 25): ";
                    cin >> numeroImagen;
                    if (numeroImagen < 1 || numeroImagen > 25) {
                        cout << "!!!! Numero fuera de rango. Intente de nuevo." << endl;
                    }
                } while (numeroImagen < 1 || numeroImagen > 25);

                // Agregar el número de imagen a la lista
                imagenes_cant.push_back(numeroImagen);
            }

            // Mostrar las imágenes seleccionadas
            cout << "\nLas imagenes seleccionadas son:" << endl;
            for (int numeroImagen : imagenes_cant) {
                cout << "Imagen numero: " << numeroImagen << endl;
            }

            break;

            case 3:
                cout << "Has seleccionado modificar todas las imágenes." << endl;
                // Modificar todas las imágenes (1 a 25)
                imagenes_cant.clear();
                for (int i = 1; i <= 25; ++i) {
                    imagenes_cant.push_back(i);
                }

            break;
            case 4:
                cout << "Has seleccionado modificar las imágenes impares." << endl;
                // Modificar solo las imágenes impares
                imagenes_cant.clear();
                for (int i = 1; i <= 25; i += 2) {
                    imagenes_cant.push_back(i);
                }

            break;
            case 5:
                cout << "Has seleccionado modificar las imágenes pares." << endl;
                // Modificar solo las imágenes pares
                imagenes_cant.clear();
                for (int i = 2; i <= 25; i += 2) {
                    imagenes_cant.push_back(i);
                }

            break;

            case 6:
                cout << "Has seleccionado mostrar todas las imagenes originales (COLLAGE)." << endl;

            ////////COLLAGE
/*
            collage = Funciones::createCollage(5, 5, 1200, 645, "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/");
            //imwrite("collage.jpg", collage); // Guardar el collage
            imshow("Collage", collage);
            setWindowProperty("Collage", WND_PROP_TOPMOST, 1); // Mantener la ventana siempre encima

            waitKey(0);
*/
            cout << "Has seleccionado mostrar las imagenes originales." << endl;
            // Mostrar el collage
            collage2 = Funciones::createCollageEdit(pilaImagenesOriginales);
            imshow("Collage de imagenes originales", collage2);
            waitKey(0); // Esperar hasta que el usuario cierre la ventana
            break;

            case 7:
                cout << "Has seleccionado mostrar las imagenes modificadas." << endl;
                // Mostrar el collage
                collage1 = Funciones::createCollageEdit(pilaImagenesEditadas);
                imshow("Collage de imagenes editadas", collage1);
                waitKey(0); // Esperar hasta que el usuario cierre la ventana
            break;
            case 8:

                img_catalogo = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/catalogoImagen.jpg";

            cout << "Has seleccionado mostrar catalogo de todas las imagenes." << endl;
            Funciones::mostrarImagen(img_catalogo, 1462, 946);

            break;

            case 9:
            collage1 = Funciones::createCollageEdit(pilaImagenesEditadas); // Collage con imagenes editadas

            // Directorio de salida
            output_path =  "C:/Users/abelb/CLionProjects/imageManipulatorPL1/outputs/";

            // Preguntar al usuario el formato de salida
            cout << ">>>>> Seleccione el formato en que desea guardar el collage: " << endl;
            cout << "1. .jpg" << endl;
            cout << "2. .png" << endl;
            cout << "3. .bmp" << endl;
            cout << "4. .tiff" << endl;
            int opcion;
            cin >> opcion;

            // Formatos de guardado
            switch (opcion) {
                case 1: formato = ".jpg"; break;
                case 2: formato = ".png"; break;
                case 3: formato = ".bmp"; break;
                case 4: formato = ".tiff"; break;
                default:
                    cout << "Opción no válida. Guardando como .jpg por defecto." << endl;
                formato = ".jpg";
                break;
            }

            // Llamada a la función para guardar el collage
            Funciones::guardarImagen(collage1, output_path, formato);
                break;

            case 0:
                break;


            default:
                cout << "Opcion no valida. Introduzca otra opcion" << endl;

        }

        if ((opcionTipo == 1)||(opcionTipo == 2)||(opcionTipo == 3)||(opcionTipo == 4)||(opcionTipo == 5)){
            cout << "\n------------------------" << endl;
            cout << "  :: Seleccione edicion ::" << endl;
            cout << "------------------------" << endl;

            cout << "\n1. Rotar --> (90, 180, 270, 360) [grados]" << endl;
            cout << "2. Filtro Escala de grises" << endl;
            cout << "3. Desenfocar" << endl;
            cout << "4. Modificar Brillo/Contraste"<< endl;
            cout << "5. Escalar"<< endl;
            cout << "6. Recortar"<< endl;
            cout << "7. Marcos/Bordes"<< endl;
            cout << "8. Invertir"<< endl;
            cout << "9. Nitidez" << endl;
            cout << "0. Salir ::::::: [EXIT] :::::::" << endl;
            cout << "------------------------" << endl;

            cout << "\n>>>> Introduzca su opcion: ";
            cin >> opcionEdicion;

//---------------------------------------------------------------------------------------------------------------------------------------

            // Iterar sobre todas las imágenes seleccionadas para aplicar la edición
            // Bucle for para lista imagenes seleccionadas para editar
            for (int numeroImagen:imagenes_cant) {
                string image_path = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/"+ std::to_string(numeroImagen) +".jpg";
                Mat img = imread(image_path, IMREAD_COLOR);

                if (img.empty()) {
                    cout << "No se pudo cargar la imagen " << numeroImagen << endl;
                    continue;
                }

                Mat imgEditada;

                switch (opcionEdicion) {
                    case 1: // Rotar imagen

                            //rotat = Funciones::rotarImagen(imgRotada.desapilar());
                        imgEditada = Funciones::rotarImagen(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                    //imshow("Imagen rotada", rotat);

                    break;

                    case 2: // Filtrar imagen a escala de grises

                        //ejemplomat = ejemplo.desapilar();
                    //gray = Funciones::convertirImagenAGrises(ejemplomat);
                        imgEditada = Funciones::convertirImagenAGrises(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                    //imshow("Imagen gris", gray);

                    //imgGris.apilar(gray);
                    break;

                    case 3: // Desenfocar Imagen

                        imgEditada = Funciones::desenfocarImagen(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                            //desenfc = Funciones::desenfocarImagen(imgDesenfc.desapilar());
                    //imshow("Imagen desenfocada", desenfc);
                    break;

                    case 4: // Contraste y brillo Imagen

                        imgEditada = Funciones::cambiarBrilloContrasteImagen(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                            //contrast = Funciones::cambiarBrilloContrasteImagen(imgContrast.desapilar());
                    //imshow("Imagen - Brillo / Contraste", contrast);
                    break;

                    case 5: // Escalar imagen

                        imgEditada = Funciones::escalarImagen(img);
                            //escala = Funciones::escalarImagen(imgEscala.desapilar());
                    //imshow("Imagen escalada", escala);
                    break;

                    case 6: // Recortar imagen

                        imgEditada = Funciones::recortarImagen(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                            //recorte = Funciones::recortarImagen(imgRecorte.desapilar());
                    //imshow("Imagen recortada", recorte);
                    break;

                    case 7: // Añadir Borde imagen

                        imgEditada = Funciones::anadirBordes(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                            //border = Funciones::anadirBordes(imgBorder.desapilar());
                    //imshow("Imagen con Borde - Marco", border);
                    break;

                    case 8: // Invertir imagen

                        imgEditada = Funciones::invertirImg(img);
                        resize(imgEditada, imgEditada, Size(1200, 628));
                            //invert = Funciones::invertirImg(imgInvert.desapilar());
                    //imshow("Imagen invertida", invert);
                    break;

                    case 9: // Nitidez imagen

                        imgEditada = Funciones::anadirNitidez(img);
                        resize(imgEditada, imgEditada, Size(1200, 645));
                            //sharp = Funciones::anadirNitidez(imgSharp.desapilar());
                    //imshow("Nitidez imagen", sharp);
                    break;

                    default:
                        cout << "Opcion no valida. Introduzca otra opcion" << endl;
                    break;

                }
//---------------------------------------------------------------------------------------------------------------------------------------

                // Reemplazar la imagen original en la pila por la imagen editada
                stack<Mat> pilaTemp;
                while (!pilaImagenesEditadas.empty()) {
                    Mat tempImg = pilaImagenesEditadas.top();
                    pilaImagenesEditadas.pop();

                    // Reemplaza la imagen editada
                    if (pilaImagenesEditadas.size() + 1 == numeroImagen) {
                        pilaTemp.push(imgEditada);
                    } else {
                        pilaTemp.push(tempImg);
                    }
                }

                // Reconstruir la pila con las imágenes originales y editadas
                while (!pilaTemp.empty()) {
                    pilaImagenesEditadas.push(pilaTemp.top());
                    pilaTemp.pop();
                }


                if ((opcionTipo == 1)||(opcionTipo == 2)) { // Mostrar la imagen editada (Solo si es una o varias imagenes)
                    imshow("Imagen Editada", imgEditada);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas
                }

//---------------------------------------------------------------------------------------------------------------------------------------

            }

        }

    }while (opcionTipo != 0);
    cout << "::::::::::::::::::::::::::::::::" << endl;
    cout << ":::   Cerrando programa...   :::" << endl;
    cout << "::::::::::::::::::::::::::::::::" << endl;
}
