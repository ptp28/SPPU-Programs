#include "objects.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Objects w;
    w.show();

    return a.exec();
}
