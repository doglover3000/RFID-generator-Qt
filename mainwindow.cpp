#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
 : QMainWindow(parent)
 , ui(new Ui::MainWindow)
{
 ui->setupUi(this);
}
MainWindow::~MainWindow()
{
 delete ui;
}
void MainWindow::on_pushButton_clicked()
{
 const char letters[] = "!\"#$%'()*=,-
./0123456789:;<?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^
_`abcdefjhijklmnopqrstuvwxyz{|}~АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯаб
вгдеёжзийклмнопрстуфхцчшщъыьэюя";
 srand((unsigned)time(NULL));
 int row_legth = ui->line_rows->text().toInt();
 int string_length = 15;
 unsigned char** matrixChar;
 matrixChar = new unsigned char*[row_legth];
 for (int i = 0; i < row_legth; i++) {
 matrixChar[i] = new unsigned char[string_length];
 }
 for (int i = 0; i < row_legth; i++) {
 for (int j = 0; j < string_length; j++) {
 int random_number = rand() % ARRAY_SIZE(letters);
 //std::cout << random_number << " ";
 char result = letters[random_number-1];
 //std::cout << result << " ";
 matrixChar[i][j] = result;
 }
 //std::cout << "\n";
 }
 for (int i = 0; i < row_legth; ++i) {
 for (int j = 0; j < string_length; ++j) {
 std::cout << matrixChar[i][j];
 }
 for (int j = 0; j < string_length; ++j) {
 std::cout << " " << std::hex << (unsigned int)matrixChar[i][j];
 }
 std::cout << "\n";
 }
 std::ofstream outFile("D:\\out.txt");
 int counter = 1;
 for (int i = 0; i < row_legth; ++i) {
 for (int j = 0; j < string_length; ++j) {
 outFile << std::setw(1) <<matrixChar[i][j];
 switch(counter)
 {
 case 1:
 case 3:
 case 5:
 case 10:
 case 15:
 outFile << " ";
 break;
 }
 counter++;
 }
 counter = 1;
 outFile << "\t";
 for (int j = 0; j < string_length; ++j) {
 outFile << " " << std::hex << (unsigned int)matrixChar[i][j];
 }
 outFile << "\n";
 }
 outFile.close();
 QFile file("D:\\out.txt");
 if(!file.open(QIODevice::ReadOnly))
 ui->textBrowser->setText("Не удалось открыть файл");
 QTextStream in(&file);
 ui->textBrowser->setText(in.readAll());
}
