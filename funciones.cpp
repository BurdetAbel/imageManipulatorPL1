//
// Created by abelb on 26/10/2024.
//

#include "funciones.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/core.hpp>
#include <filesystem>
#include <opencv2/imgproc.hpp>

// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::string, std::cout, std::endl, std::cerr;
using std::cin;
using std::cout;
using std::endl;
using namespace cv;
namespace fs = std::filesystem;  // Alias para el espacio de nombres

Mat Funciones::convertirImagenAGrises(Mat colorgris) {


    Mat gray_img; // Guarda variable gris
    cvtColor(colorgris, gray_img, COLOR_BGR2GRAY); // Funcion cambia a gris

    return gray_img; // Devuelve imagen convertida en gris
}


Mat Funciones::rotarImagen(Mat rotarimg) {

    int grados;
    Mat rotate_img; // Guarda variable rotar

    while (true) {
        cout << " Rotacion imagen " << endl;
        cout << "-------------------------" << endl;
        cout << "* Introduzca tipo de rotacion  (90°, 180°, 270°, 360°): "; cin >> grados;

        if ((grados!=90)&&(grados!=180)&&(grados!=270)&&(grados!=360)) {

            cout << "\n El grado " << grados << " no corresponde a ninguna opcion posible." << endl;


        } else {
            break;

        }

    }

    if(grados == 90) {
        rotate(rotarimg, rotate_img, ROTATE_90_CLOCKWISE);
    } else if(grados == 180) {
        rotate(rotarimg, rotate_img, ROTATE_180);
    } else if(grados == 270) {
        rotate(rotarimg, rotate_img, ROTATE_90_COUNTERCLOCKWISE);
    } else if  (grados == 360) {
        rotate_img = rotarimg;
    } else {
        cout<<"!! La opcion elegida no es valida !!" <<endl;
    }

    return rotate_img;
}



Mat Funciones::escalarImagen(Mat escalarimg) {

    int width, height, opcescalado;
    double coeficiente;
    Mat resize_img;


    while (true) {
        cout << " \n---------------------" << endl;
        cout << "*** Tipo de Escalado: " << endl;
        cout << " ---------------------" << endl;

        cout << "*** OPCION 1: Dimensiones (width x height) " << endl;
        cout << "*** OPCION 2: Coeficiente (n %) " << endl;

        cout << "\nIntroduzca el metodo de escalado a realizar: " << endl;

        cin >> opcescalado;

        if ((opcescalado!=1)&&(opcescalado!=2)){
            cout << "\n**** La opcion introducida no es correcta." << endl;
        } else {
            break;
        }
    }

    if (opcescalado == 1) {
        while (true) {
            cout << " ------------------------------------------" << endl;
            cout << "*** Dimensiones en pixeles(ej: 400x300): " << endl;
            cout << "\n* Introduzca el ancho de la imagen (horizontalmente): "; cin >> width;
            cout << "* Introduzca el alto de la imagen (verticalmente): "; cin >> height;

            if ((width < 0 )||(height < 0)){
                cout << "\n**** La dimension introducida no es correcta." << endl;

            } else {
                break;
            }
        }
        resize(escalarimg, resize_img, Size(width, height), 0, 0, INTER_NEAREST);

    } else if (opcescalado == 2) {
        while (true) {
            cout << " ------------------------" << endl;
            cout << "*** Coeficiente de escalado (ej: 21.9 [%]): " << endl;
            cin >> coeficiente;

            if (coeficiente < 0 ){
                cout << "\n**** La dimension introducida no es correcta." << endl;
            } else {
                break;
            }
        }

        /*
        int width = escalarimg.cols;

        coeficiente = (coeficiente/100);
        width = width*coeficiente;
        height *= height*coeficiente;
        */

        // Calcular el nuevo tamaño basado en el coeficiente
        coeficiente /= 100.0;
        width = static_cast<int>(escalarimg.cols * coeficiente);
        height = static_cast<int>(escalarimg.rows * coeficiente);

        resize(escalarimg, resize_img, Size(width, height),0,0 , INTER_LINEAR);

    }

    return resize_img;
}


Mat Funciones::desenfocarImagen(Mat desenfocImg) {

    int width1, height1;
    Mat blurred_img;


    while (true) {
        cout << " ------------------------" << endl;
        cout << "*** Cambios en la intensidad de los pixeles (ej: 50x50): " << endl;
        cout << "*** NOTA *** : Cuanto mayor sean los gradientes --> imagen mas desenfocada" << endl;

        cout << "* Introduzca gradientes (horizontalmente): "; cin >> width1;
        cout << "* Introduzca gradientes (verticalmente): "; cin >> height1;

        if ((width1 < 0 )||(height1 < 0)){
            cout << "\n**** Los gradientes introducidos son incorrectos." << endl;

        } else {
            break;

        }

    }

    GaussianBlur(desenfocImg, blurred_img, Size(width1, height1), 0);

    return blurred_img;
}



Mat Funciones::cambiarBrilloContrasteImagen(Mat contrastImg) {

    double alpha = 1.0; // Simple contrast control
    int beta = 0;       //Simple brightness control

    Mat contrasted_img = Mat::zeros( contrastImg.size(), contrastImg.type() );
    /// Initialize values
    cout << " Cambiar Contraste / Brillo " << endl;
    cout << "--------------------------" << endl;
    cout << "* Ingresa el valor alfa para el contraste [1.0-3.0]: "; cin >> alpha;
    cout << "* Ingresa el valor alfa para el brillo [0-100]: ";    cin >> beta;

    for( int y = 0; y < contrastImg.rows; y++ ) {
        for( int x = 0; x < contrastImg.cols; x++ ) {
            for( int c = 0; c < contrastImg.channels(); c++ ) {
                contrasted_img.at<Vec3b>(y,x)[c] =
                  saturate_cast<uchar>( alpha*contrastImg.at<Vec3b>(y,x)[c] + beta );
            }
        }
    }
    return contrasted_img;

}


Mat Funciones::recortarImagen(Mat recortimg) {




    int pos1, pos2, exten1, exten2;


    while (true) {
        cout << " Cortar Imagen " << endl;
        cout << " --------------" << endl;
        cout << "*** Parametros: (x1,y1) = posicion, (x2, y2) = extension (ej: 50,50,200,200) : " << endl;
        cout << "*** EJ -- AYUDA*** : La imagen comienza en la posicion (50, 50) de la imagen" << endl;
        cout << "Se extiende 200 pix. hacia la derecha y 200 pix. hacia abajo" << endl;
        cout << "Se forma una imagen de 200 x 200 pixeles" << endl;


        cout << "* Introduzca posicion x1 (inicial): "; cin >> pos1;
        cout << "* Introduzca posicion y1 (inicial): "; cin >> pos2;
        cout << "* Introduzca anchura extension x2: "; cin >> exten1;
        cout << "* Introduzca altura extension y2: "; cin >> exten2;

        if ((pos1 < 0 )||(pos2 < 0)||(exten1 < 0 )||(exten2 < 0)){
            cout << "\n**** Los valores introducidos son incorrectos." << endl;

        } else {
            break;

        }

    }
    Rect roi(pos1,pos2,exten1,exten2);
    Mat crop_img = recortimg(roi);

    return crop_img;
}

Mat Funciones::anadirBordes(Mat bordimg) {

    int borderThickness;
    Scalar borderColor(0,0,0);

    while (true) {
        cout << " Bordes - Marco a Imagen " << endl;
        cout << " -----------------------" << endl;

        cout << "* Introduzca el grosor del borde [pixeles] (Ej: 20): ";
        cin >> borderThickness;

        if (borderThickness < 0){
            cout << "\n****  Los valores introducidos son incorrectos." << endl;
            cout << "\n****  No es posible añadir un borde de: " << borderThickness<< " pixeles. " << endl;


        } else {
            break;
        }
    }


    // Add borders to the image using the copyMakeBorder function

    Mat imageWithBorders;
    copyMakeBorder(bordimg, imageWithBorders,
                   borderThickness, borderThickness, // Thickness of the top and bottom borders
                   borderThickness, borderThickness, // Thickness of the left and right borders
                   BORDER_CONSTANT, borderColor);

    return imageWithBorders;


}

Mat Funciones::anadirNitidez(Mat sharped) {

    Mat sharpImage;
    int value;

    cout << " \n ----------------" << endl;
    cout << "  Nitidez Imagen" << endl;
    cout << " ----------------" << endl;

    cout << "* Introduzca el grado de nitidez (Ej: 5): ";
    cout << "***AYUDA*** : Cuanto mayor grado de nitidez --> Imagen mas nitida " << endl;
    cin >> value;

    // Define a kernel for sharpness
    Mat kernel = (Mat_<float>(3, 3) <<
                  0, -1, 0,
                 -1,  value, -1,
                  0, -1, 0);
    // Apply convolution with the kernel to enhance the image
    filter2D(sharped, sharpImage, -1, kernel);

    return sharpImage;
}

Mat Funciones::invertirImg(Mat inverted) {

    Mat invertedImage;
    int value1;

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

    value1 -=1;

    flip(inverted, invertedImage,value1);
    return invertedImage;
}

/*

Mat Funciones::posicion(Mat ventana, string name_vent, int pos1, int pos2) {

    Mat img_reducidd;
    //Esta funcion se encarga de reducir y posicionar la imagen
    ventana = imread(name_vent, IMREAD_COLOR);
    resize(ventana, img_reducidd, Size((1200), (628)), 0, 0, INTER_NEAREST); //1200x628 tamaño collage final

    namedWindow(name_vent, WINDOW_NORMAL);
    imshow(name_vent, img_reducidd);
    setWindowProperty(name_vent, WND_PROP_TOPMOST, 1); // Mantener la ventana siempre encima
    //  moveWindow("Catalogo", 1400, 600);
    waitKey(1); // Permite actualizar la ventana sin detener el programa principal

}
*/