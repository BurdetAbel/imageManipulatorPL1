//
// Created by abelb on 26/10/2024.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // Para la función cvtColor
#include <iostream>
#include <filesystem>

using std::string, std::cout, std::endl, std::cerr;
using namespace cv;
namespace fs = std::filesystem;  // Alias para el espacio de nombres

class Funciones {

    private:

    public:
        static Mat convertirImagenAGrises(Mat colorgris);
        static Mat rotarImagen(Mat rotarimg);
        static Mat escalarImagen(Mat escalarimg);
        static Mat desenfocarImagen(Mat desenfocImg);
        static Mat cambiarBrilloContrasteImagen(Mat contrastImg);
        static Mat recortarImagen(Mat recortimg);
        static Mat anadirBordes(Mat bordimg);
        static Mat invertirImg(Mat inverted);
        static Mat anadirNitidez(Mat sharped);
        //static Mat posicion(Mat ventana, string name_vent, int pos1, int pos2);



};



#endif //FUNCIONES_H
