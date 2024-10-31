//
// Created by abelb on 24/10/2024.
//

#include "menu.h"
#include "funciones.h"
#include "pila.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <queue>
#include <iostream>
#include <list>
#include <stack>
#include <filesystem>

using std::string, std::cout, std::endl, std::cerr;
using std::cout; using std::cin; using std::endl;
const int minimum = 0, maximum = 10;
namespace fs = std::filesystem;
using namespace cv;

void modificarImagen(int tipo);
void aplicarEdicion(int edicion);

void mostrarMenu() {

    /// VARIABLES ///
    int cantidad, opcionTipo, opcionEdicion, img_especifica, opcion;
    string image_path,img_catalogo, formato, output_path;
    Mat img, imgEditada, collage1, collage2;
    std::list<int> imagenes_cant; // Lista para almacenar iamgenes seleccionadas
    std::stack<Mat> pilaImagenesOriginales; //Pila para almacenar las imágenes originales
    stack<Mat> pilaImagenesEditadas; // Pila para almacenar las imágenes editadas junto con las no editadas
    std::queue<int> colaImagenes; // Cola para almacenar las imágenes seleccionadas
    String folderPath = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/";

//---------------------------------------------------------------------------------------------------------------------------------------

    cout << "   ::::::::::::::::::::::::::::::::::::::::::::::    ::::::::::::::::::    :::::::::::::::::::::::::::" << endl;
    cout << "   :::::::     MANIPULADOR DE IMAGENES     ::::::    :::::   __   :::::    ::::::  BIENVENIDO!  ::::::" << endl;
    cout << "   ::::::::::::::::::::::::::::::::::::::::::::::    :::    |__|    :::    :::::::::::::::::::::::::::" << endl;
    cout << "   :::: ABEL BURDET ::::::: CRISTIAN JIMENEZ ::::    :::   __||__   :::    ::::: Tenga paciencia :::::" << endl;
    cout << "   ::::: X9844318L ::::::::::: 51495888S ::::::::    :::::  _||_  :::::    :::: mientras carga... ::::" << endl;
    cout << "   ::::::::::::::::::::::::::::::::::::::::::::::    ::::::::::::::::::    :::::::::::::::::::::::::::" << endl;

    cout << "\n******** Iniciando..." << endl;

//---------------------------------------------------------------------------------------------------------------------------------------

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

    // Mostrar COLLAGE al iniciar
    collage2 = Funciones::createCollageEdit(pilaImagenesOriginales);
    Funciones::mostrarImagen2(collage2, "Collage original");

//---------------------------------------------------------------------------------------------------------------------------------------

    do {
        cout << " --------------------------------                   ::  ::  ::  ::  ::  ::  ::  ::  ::" << endl;
        cout << " ::  Menu para editar imagenes ::                     ::  ::  ::  ::  ::  ::  ::  ::  " << endl;
        cout << " --------------------------------                   ::  ::  ::  ::  ::  ::  ::  ::  ::" << endl;

        cout << "\n   :::::::       1. Modificar una imagen especifica" << endl;
        cout << "   :: O ::       2. Modificar varias imagenes" << endl;
        cout << "   :: P ::       3. Modificar todas las imagenes" << endl;
        cout << "   :: C ::       4. Modificar solamente las imagenes Impares"<< endl;
        cout << "   :: I ::       5. Modificar solamente las imagenes Pares"<< endl;
        cout << "   :: O ::       6. Mostrar Imagenes ORIGINALES (Collage)"<< endl; // Collage con las fotos originales
        cout << "   :: N ::       7. Mostrar Imagenes EDITADAS (Collage)" << endl; // Collage con las fotos editadas
        cout << "   :: E ::       8. Mostrar CATALOGO imagenes"<< endl; // Imagenes con su nombre (mismo orden y posicion que en collage)
        cout << "   :: S ::       9. Guardar >>> COLLAGE IMAGENES EDITADAS"<< endl; // Imagenes con su nombre
        cout << "   :::::::       0. Salir ::::::: [EXIT] :::::::"<< endl;
        cout << " ----------------------------------------------------------------" << endl;


        cout << "\n>>>>> Introduzca su opcion: ";
        cin >> opcionTipo;

//---------------------------------------------------------------------------------------------------------------------------------------

        switch (opcionTipo) {
            case 1: // Modificar una sola imagen especifica
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
            break;

            case 2: // Modificar varias imagenes
                cout << "Has seleccionado modificar varias imagenes." << endl;

            cout << ">>>>> Cuantas imagenes quieres editar?: ";
            cin >> cantidad;

            imagenes_cant.clear(); // Limpiar la lista antes de usarla

            for (int i = 0; i < cantidad; ++i) { // Llenar la lista con el número de imágenes
                int numeroImagen;
                do {
                    cout << ">>>>> Ingresa el numero de la imagen " << i + 1 << " (1 - 25): ";
                    cin >> numeroImagen;
                    if (numeroImagen < 1 || numeroImagen > 25) {
                        cout << "!!!! Numero fuera de rango. Intente de nuevo." << endl;
                    }
                } while (numeroImagen < 1 || numeroImagen > 25);

                imagenes_cant.push_back(numeroImagen); // Agregar el nombre de imagen a la lista
            }

            // Mostrar las imágenes seleccionadas
            cout << "\nLas imagenes seleccionadas son:" << endl;
            for (int numeroImagen : imagenes_cant) {
                cout << "Imagen numero: " << numeroImagen << endl;
            }

            break;

            case 3: // Modificar todas las imágenes (1 a 25)
                cout << "Has seleccionado modificar TODAS las imagenes." << endl;
                imagenes_cant.clear();
                for (int i = 1; i <= 25; ++i) {
                    imagenes_cant.push_back(i);
                }

            break;
            case 4: // Modificar solo las imágenes impares

                cout << "Has seleccionado modificar las imágenes IMPARES." << endl;
                imagenes_cant.clear();
                for (int i = 1; i <= 25; i += 2) {
                    imagenes_cant.push_back(i);
                }

            break;
            case 5: // Modificar solo las imágenes pares

                cout << "Has seleccionado modificar las imagenes PARES." << endl;
                imagenes_cant.clear();
                for (int i = 2; i <= 25; i += 2) {
                    imagenes_cant.push_back(i);
                }

            break;

            case 6:// Mostrar el collage Original

                cout << "Has seleccionado mostrar todas las imagenes originales (COLLAGE)." << endl;
                collage2 = Funciones::createCollageEdit(pilaImagenesOriginales);
                Funciones::mostrarImagen2(collage2, "Collage original");
            break;

            case 7: // Mostrar el collage Modificado

                cout << "Has seleccionado mostrar las imagenes modificadas." << endl;
                collage1 = Funciones::createCollageEdit(pilaImagenesEditadas);
                Funciones::mostrarImagen2(collage1, "Collage modificado");
            break;
            case 8: // Mostrar catalogo con imagenes nombradas

                img_catalogo = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/catalogoImagen.jpg"; // Ruta catalogo
                cout << "Has seleccionado mostrar CATALOGO de todas las imagenes." << endl;
                Funciones::mostrarImagen(img_catalogo, 1462, 946);

            break;

            case 9: // Guardar collage imagenes editadas
            collage1 = Funciones::createCollageEdit(pilaImagenesEditadas); // Collage con imagenes editadas

            // Directorio de salida
            output_path =  "C:/Users/abelb/CLionProjects/imageManipulatorPL1/outputs/";

            // Preguntar al usuario el formato de salida
            cout << ">>>>> Seleccione el formato en que desea guardar el collage: " << endl;
            cout << "1. .jpg" << endl;
            cout << "2. .png" << endl;
            cout << "3. .bmp" << endl;
            cout << "4. .tiff" << endl;

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
                cout << "---------------------------------------------------------------------------------------------" << endl;
                cout << "::::::::::::::::::::::::::::::::     ::     ___      ::      :::::::::::::::::::::::::::::::::" << endl;
                cout << ":::   Cerrando programa...   :::           |^_^|             :::::::::   ADIOS!!   ::::::::::" << endl;
                cout << "::::::::::::::::::::::::::::::::     ::              ::      :::::::::::::::::::::::::::::::::" << endl;
                cout << "---------------------------------------------------------------------------------------------" << endl;

            break;

            default:
                cout << "Opcion no valida  -->  Introduzca otra opcion" << endl;

        }

//---------------------------------------------------------------------------------------------------------------------------------------

        if ((opcionTipo == 1)||(opcionTipo == 2)||(opcionTipo == 3)||(opcionTipo == 4)||(opcionTipo == 5)){
            cout << "\n---------------------------                 ::  ::  ::  ::  ::  ::  ::  ::  ::" << endl;
            cout << "  :: Seleccione edicion ::                    ::  ::  ::  ::  ::  ::  ::  ::  " << endl;
            cout << "---------------------------                 ::  ::  ::  ::  ::  ::  ::  ::  ::" << endl;

            cout << "\n   :::::::       1. Rotar --> (90, 180, 270, 360) [grados]" << endl;
            cout << "   :: O ::       2. Filtro Escala de grises" << endl;
            cout << "   :: P ::       3. Desenfocar" << endl;
            cout << "   :: C ::       4. Modificar Brillo/Contraste"<< endl;
            cout << "   :: I ::       5. Escalar"<< endl;
            cout << "   :: O ::       6. Recortar"<< endl;
            cout << "   :: N ::       7. Marcos/Bordes"<< endl;
            cout << "   :: E ::       8. Invertir"<< endl;
            cout << "   :: S ::       9. Nitidez" << endl;
            cout << "   :::::::       0. Salir ::::::: [EXIT] :::::::" << endl;
            cout << "-------------------------------------------------------------" << endl;

            cout << "\n>>>> Introduzca su opcion: ";
            cin >> opcionEdicion;

//---------------------------------------------------------------------------------------------------------------------------------------
// Pedir variables desde el menu para no repetir al ser varias imagenes

            // Variables funcion rotar
            int grados;
            if (opcionEdicion == 1) {
                cout << "-----------------" << endl;
                cout << " Rotacion imagen " << endl;
                cout << "-----------------" << endl;
                cout << "* Introduzca tipo de rotacion (90, 180, 270, 360): ";
                cin >> grados;
                if (grados != 90 && grados != 180 && grados != 270 && grados != 360) {
                    cout << "Grado no válido. Usando 360 (sin rotación)." << endl;
                    grados = 360;
                }
            }

            // Variables funcion desenfocar
            int width1, height1;
            if (opcionEdicion == 3) {
                while (true) {
                    cout << " ------------------" << endl;
                    cout << " DESENFOCAR IMAGEN" << endl;
                    cout << " ------------------" << endl;
                    cout << "*** Cambios en la intensidad de los pixeles (ej: 81x73): " << endl;
                    cout << "*** NOTA *** : Cuanto mayor sean los gradientes --> imagen mas desenfocada" << endl;
                    cout << "*** NOTA *** Los gradientes deben ser impares y positivos:  " << endl;

                    cout << "* Introduzca gradientes (horizontalmente): "; cin >> width1;
                    cout << "* Introduzca gradientes (verticalmente): "; cin >> height1;

                    if ((width1 < 0 )||(height1 < 0)||(width1 % 2 == 0 )||(height1 % 2 == 0)){
                        cout << "\n**** Los gradientes introducidos son incorrectos." << endl;

                    } else {
                        break;
                    }
                }
            }

            // Variables funcion modificar Contraste y brillo
            double alpha; int beta;
            if (opcionEdicion == 4) {
                cout << "----------------------------" << endl;
                cout << " CAMBIAR CONTRASTE / BRILLO " << endl;
                cout << "----------------------------" << endl;
                cout << "* Ingresa el valor alfa para el contraste [1.0-3.0]: "; cin >> alpha;
                cout << "* Ingresa el valor alfa para el brillo [0-100]: ";    cin >> beta;

            }

            // Variables funcion recortar
            int pos1, pos2, exten1, exten2;
            if (opcionEdicion == 6) {
                while (true) {
                    cout << " --------------" << endl;
                    cout << " CORTAR IMAGEN " << endl;
                    cout << " --------------" << endl;
                    cout << "*** Parametros: (x1,y1) = posicion, (x2, y2) = extension (ej: 50,50,200,200) : " << endl;
                    cout << "*** EJ -- AYUDA*** : La imagen comienza en la posicion (50, 50) de la imagen" << endl;
                    cout << "Se extiende 200 pix. hacia la derecha y 200 pix. hacia abajo" << endl;
                    cout << "Se forma una imagen de 200 x 200 pixeles" << endl;

                    cout << "****** NOTA: Siguiendo el ejemplo comenzaras aprox. desde el centro de la imagen a recortar";
                    cout << "\n* Introduzca posicion x1 (inicial) (Ej: 1700): "; cin >> pos1;
                    cout << "* Introduzca posicion y1 (inicial) (Ej: 980): "; cin >> pos2;
                    cout << "* Introduzca anchura extension x2 (300): "; cin >> exten1;
                    cout << "* Introduzca altura extension y2: (200)"; cin >> exten2;

                    if ((pos1 < 0 )||(pos2 < 0)||(exten1 < 0 )||(exten2 < 0)){
                        cout << "\n**** Los valores introducidos son incorrectos." << endl;
                    } else {
                        break;
                    }
                }
            }

            // Variables funcion anadir Marcos/Bordes
            int borderThickness;
            if (opcionEdicion == 7) {
                while (true) {
                    cout << " ----------------------" << endl;
                    cout << " BORDES - MARCO IMAGEN " << endl;
                    cout << " ----------------------" << endl;
                    cout << ">>>>> Introduzca el grosor del borde [pixeles] (Ej: 20): ";
                    cin >> borderThickness;

                    if (borderThickness < 0){
                        cout << "\n****  Los valores introducidos son incorrectos." << endl;
                        cout << "\n****  No es posible añadir un borde de: " << borderThickness<< " pixeles. " << endl;
                    } else {
                        break;
                    }
                }
            }

            // Variables funcion invertir imagen
            int value1;
            if (opcionEdicion == 8) {
                while (true) {
                    cout << " \n ----------------" << endl;
                    cout << "  Invertir Imagen" << endl;
                    cout << " ----------------" << endl;

                    cout << "* Inversion (Vertical / Horizontal): " << endl;
                    cout << "\nOPCION 1: Vertical " << endl;
                    cout << "OPCION 2: Horizontal " << endl;
                    cout << "Introduzca el tipo de inversion a realizar: " << endl;
                    cin >> value1;

                    if ((value1 != 1)&&(value1!= 2)){
                        cout << "\n****  El valor " << value1 << " no es una  opcion posible." << endl;

                    } else {
                        break;
                    }
                }
            }

            // Variables funcion nitidez
            int value;
            if (opcionEdicion == 9) {
                cout << " \n ----------------" << endl;
                cout << "  NITIDEZ IMAGEN" << endl;
                cout << " ----------------" << endl;
                cout << "* Introduzca el grado de nitidez (Ej: 5): ";
                cout << "***AYUDA*** : Cuanto mayor grado de nitidez --> Imagen mas nitida " << endl;
                cin >> value;
            }

//---------------------------------------------------------------------------------------------------------------------------------------

            // Iterar sobre todas las imágenes seleccionadas para aplicar la edición
            // Bucle for para lista imagenes seleccionadas para editar

            for (int numeroImagen:imagenes_cant) {
                colaImagenes.push(numeroImagen);
            }

            // Aplicar la edicion a cada imagen en la cola
            while (!colaImagenes.empty()) {
                int numeroImagen = colaImagenes.front();
                colaImagenes.pop();

                string image_path = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/"+ std::to_string(numeroImagen) +".jpg";
                img = imread(image_path, IMREAD_COLOR);


                if (img.empty()) {
                    cout << "No se pudo cargar la imagen " << numeroImagen << endl;
                    continue;
                }

//---------------------------------------------------------------------------------------------------------------------------------------


                switch (opcionEdicion) {
                    case 1: // Rotar imagen
                        imgEditada = Funciones::rotarImagen(img, grados);
                    break;

                    case 2: // Filtrar imagen a escala de grises
                        imgEditada = Funciones::convertirImagenAGrises(img);
                    break;

                    case 3: // Desenfocar Imagen
                        imgEditada = Funciones::desenfocarImagen(img, width1,height1);
                    break;

                    case 4: // Contraste y brillo Imagen
                        imgEditada = Funciones::cambiarBrilloContrasteImagen(img, alpha, beta);
                    break;

                    case 5: // Escalar imagen
                        imgEditada = Funciones::escalarImagen(img);
                    break;

                    case 6: // Recortar imagen

                        imgEditada = Funciones::recortarImagen(img, pos1, pos2, exten1, exten2);
                    break;

                    case 7: // Añadir Borde imagen

                        imgEditada = Funciones::anadirBordes(img, borderThickness);
                    break;

                    case 8: // Invertir imagen

                        imgEditada = Funciones::invertirImg(img, value1);
                    break;

                    case 9: // Nitidez imagen

                        imgEditada = Funciones::anadirNitidez(img, value);
                    break;

                    default:
                        cout << "!!!! Opcion no valida  -->  Introduzca otra opcion" << endl;
                    continue;
                }
                if (opcionEdicion != 5) {
                    resize(imgEditada, imgEditada, Size(1200, 628));
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


                if (opcionTipo == 1) { // Mostrar la imagen editada (Solo si es una imagen)
                    imshow("Imagen Editada", imgEditada);
                    waitKey(0); // Esperar una tecla para cerrar las ventanas
                }
            }
        }
    }while (opcionTipo != 0);
}
