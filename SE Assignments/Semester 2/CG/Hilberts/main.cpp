#include "hilbs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hilbs w;
    w.show();

    return a.exec();
}
