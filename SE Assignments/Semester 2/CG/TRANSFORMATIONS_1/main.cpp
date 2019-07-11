#include "transform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    transform w;
    w.show();

    return a.exec();
}
