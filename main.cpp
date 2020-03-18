#include <QList>
#include <QWidget>
#include <QApplication>
#include <QDebug>

#include <iostream>
using namespace std;
void funcTest(QList<QWidget *> test){
    qDebug() <<"Infunc"<< test.first();
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QList<QWidget *> test;
    QWidget *l = new QWidget();
    test.append(l);
    funcTest(test);
    qDebug() << "outFunc" << test.first();
    return a.exec();
}
