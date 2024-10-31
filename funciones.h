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
#include <stack>

using std::string, std::cout, std::endl, std::cerr;
using namespace cv;
namespace fs = std::filesystem;  // Alias para el espacio de nombres

class Funciones {

    private:

    public:
        static Mat convertirImagenAGrises(Mat colorgris);
        static Mat rotarImagen(Mat rotarimg, int grados);
        static Mat escalarImagen(Mat escalarimg);
        static Mat desenfocarImagen(Mat desenfocImg, int width1, int height1);
        static Mat cambiarBrilloContrasteImagen(Mat contrastImg, double alpha,int beta);
        static Mat recortarImagen(Mat recortimg, int pos1,int pos2, int exten1, int exten2);
        static Mat anadirBordes(Mat bordimg, int borderThickness);
        static Mat invertirImg(Mat inverted, int value1);
        static Mat anadirNitidez(Mat sharped, int value);
        static Mat createCollage(int gridRows, int gridCols, int collageWidth, int collageHeight, string folderPath);
        static void mostrarImagen(string name_vent, int width, int height);
        static Mat createCollageEdit(std::stack<Mat> pilaImagenes);
        static void guardarImagen(Mat collage, string output_path, string formato);
        static void mostrarImagen2(Mat imagen,string name_vent);
};



#endif //FUNCIONES_H
