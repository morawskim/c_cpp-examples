#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char* argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "opencv_facedetection image.jpg");
        exit(EXIT_FAILURE);
    }

    Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (img.empty()) {
        fprintf(stderr, "Cant load image '%s'", argv[1]);
        exit(EXIT_FAILURE);
    }

    CascadeClassifier haar_cascade;
    if (!haar_cascade.load("/usr/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml")) {
        fprintf(stderr, "Cant load haar cascade (/usr/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml)");
        exit(EXIT_FAILURE);
    }

    vector< Rect_<int> > faces;
    haar_cascade.detectMultiScale(img, faces);

    Scalar red = CV_RGB(255,0,0);

    for(int i = 0; i < faces.size(); i++) {
        Rect face_i = faces[i];
        printf("Face at [%d, %d] width %d and height %d\n", face_i.x, face_i.y, face_i.width, face_i.height);
        fflush(stdout);

        rectangle(img, face_i, red, 1);
    }
    imwrite("facedetection.jpg", img);

    namedWindow("Faces", WINDOW_AUTOSIZE);
    imshow("Faces", img);
    waitKey(0);

    return 0;
}