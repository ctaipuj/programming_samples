#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; // Para no poner CV en todas las lineas
using namespace std; // std


int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        cout<<"usage: DisplayImage.out <Image_Path>\n"; //Incluir los argumentos al momento de abrir la pagina
        return -1;
    }

    Mat image; // Matriz donde se almacenan los datos de la foto
    Mat gray_image; //Matriz donde se guarda la imagen en blanco y negro
    image = imread( argv[1],1);//imread("result3",CV_LOAD_IMAGE_GRAYSCALE) para cargar la foto en escala de grises.
    cvtColor( image, gray_image, CV_BGR2GRAY ); //Funcion que transforma a blanco y negro

    if ( !image.data )
    {
        printf("No image data \n"); // si la imagen tiene datos muestre si no no.
        return -1;
    }
        
    cout<<"La imagen tiene "<<image.rows<<" filas y "<<image.cols<<" columnas"<<endl; //mostrar el tamaño de la imagen 
    cout<<"La imagen se cargo mostrando "<<image.channels()<<" canal(es)."<<endl; //mostrar los canales de la imagen 
    namedWindow("Original", WINDOW_NORMAL );
    
    imshow("Original", image);
    
    Mat result; // nueva matriz para almacenar datos 
    flip(image,result,1); // valores positivas giran horizontalmente
    namedWindow("Girada Horizontal",WINDOW_NORMAL);
    putText(result,"Texto de prueba",Point(700,800),FONT_HERSHEY_PLAIN,12.0,Scalar(255,255,255),3); // Poner texto en foto, putText(imagen, texto, punto del texto, fuente, escala, color, grosor)
    imshow("Girada Horizontal",result);
    
    Mat result2;
    flip(image,result2,0); // valores de 0 giran verticalmente la imagen
    namedWindow("Girada Vertical",WINDOW_NORMAL);
    circle(result2,Point(700,700),500,0,15); //Introducir un circulo en una imagen (Imagen, punto, radio, color, grosor)
    imshow("Girada Vertical",result2);
    
    Mat result3;
    flip(image,result3,-1); // valores negativos giran en los dos sentidos al tiempo
    namedWindow("Girada Horizontal & Vertical",WINDOW_NORMAL);
    imshow("Girada Horizontal & Vertical",result3);
    
    namedWindow("Black & White",WINDOW_NORMAL);
    imshow("Black & White",gray_image);
    
   // imwrite("B18Modified.JPEG",result3); // Save results
    
    waitKey(0); //Espera que la persona presione una tecla

    return 0;
}
