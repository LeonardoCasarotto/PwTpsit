#include <QApplication>
#include <QPushButton>
#include "MainWindow.h"

/*int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget widget;
    Ui_MainWindow ui;
    ui.setupUi(&widget);

    widget.show();
    return app.exec();
}