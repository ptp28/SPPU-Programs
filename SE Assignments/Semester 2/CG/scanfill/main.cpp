#include "mypoly.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mypoly w;
    w.show();
    return a.exec();
}
