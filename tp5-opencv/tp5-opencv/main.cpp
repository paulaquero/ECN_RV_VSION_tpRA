// tp5-opencv.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <aruco/aruco.h>

using namespace std;
using namespace cv;
using namespace aruco;

int main(int argc, char** argv)
{
    // creation d'un detecteur de marqueurs
    MarkerDetector myDetector;

    // lecture d'une image
	Mat myImage;
    //myImage = imread(argv[1], IMREAD_COLOR);

	// declaration de l'objet VideoCapture 
	VideoCapture cap(0);

	// creation d'une fenetre pour afficher les images
	namedWindow("ArUco", WINDOW_AUTOSIZE);

	// Lecture des images
	int key = 0;
	string nameWindow = "ArUco";
	while (key != 27 && key != 113 && cap.isOpened()) {
		cap.read(myImage);

		// liste de marqueurs : sera remplie par ArUco
		// detect markers and for each one, draw info
		// and its boundaries in the image
		for (auto m : myDetector.detect(myImage)) {
			cout << m << endl;
			m.draw(myImage);
		}

		imshow(nameWindow, myImage);

		key = waitKey(50);
	}
	destroyWindow(nameWindow);

    return 0;
}

