#include "hoist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hoist w;
    w.show();

    return a.exec();
}
