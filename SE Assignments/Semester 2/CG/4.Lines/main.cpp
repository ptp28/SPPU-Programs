#include "lines.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lines w;
    w.show();

    return a.exec();
}
