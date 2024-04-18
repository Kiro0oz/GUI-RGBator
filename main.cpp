/*
FCAI – Structured Programming – 2024 - Assignment 3 - Winged Dragon Competition
-------------------------------------------------------------------------------
Author: Aly Elnokrashy => [merge, neon, flip, detect image]
        Kirolos Adel  => [grayscale, black&white, brightness, infrared, skew, oldTv]
        Mohamed Walid => [invert, rotate,  sunlight, oil, frame, resize, purple, Emposs, swirl, blur, crop]

IDs & Sections: Aly Elnokrashy => 20230239, S17
                Kirolos Adel => 2023295, S1
                Mohamed Walid => 20230585, S1
*/

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
