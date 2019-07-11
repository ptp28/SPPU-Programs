#include "cohen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cohen w;
    w.show();

    return a.exec();
}
