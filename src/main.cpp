#include <QApplication>
#include "FamilyTreeWidget.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FamilyTreeWidget widget;
    widget.show();

    return app.exec();
}

#include "main.moc"
