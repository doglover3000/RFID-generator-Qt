#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <Qfile>
#include <QTextStream>
#include <iostream>
#include <array>
#include <ctime>
#include <bitset>
#include <locale>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <iomanip>
#include <QtCore5Compat/QTextCodec>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
 Q_OBJECT
public:
 MainWindow(QWidget *parent = nullptr);
 ~MainWindow();
private slots:
 void on_pushButton_clicked();
private:
 Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H