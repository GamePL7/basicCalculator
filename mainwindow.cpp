#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QMessageBox>
#include <math.h>
#include <QDebug>

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

void MainWindow::ustaw(int l)
{
    if(znak=="")
    a+=l;
    else
    b+=l;
}

int MainWindow::wynik()
{
    l1=a;
    l2=b;
    if(znak=="+")
    w=l1+l2;
    else
     if(znak=="-")
      w=l1-l2;
    else
      if(znak=="*")
          w=l1*l2;
    else
       if(znak=="/"){
           if(l2!=0){
               w=l1/l2;
           }
           else{
                ui->plainTextEdit->setPlainText("");
                QMessageBox::StandardButton odp = QMessageBox::warning(this,"Ostrzeżenie", "Nie dziel przez zero!", QMessageBox::Ok);
                return 0;
           }

       }
    return w;
}

void MainWindow::wypisz()
{

        w = wynik();
        ui->plainTextEdit->setPlainText(QString::number(w));
        znak="";
//    }
}

void MainWindow::on_actionWyczysc_triggered()
{
    ui->plainTextEdit->setPlainText("");
    a=0;
    b=0;
}

void MainWindow::on_actionZakoncz_triggered()
{
    QMessageBox::StandardButton odp;

    odp = QMessageBox::warning(this,"Ostrzeżenie", "Czy na pewno zamknąć program?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if(odp == QMessageBox::Yes) {
        QApplication::exit();

    }
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->plainTextEdit->setPlainText("");
    a=0;
    b=0;
}

void MainWindow::on_pushButton_15_clicked()
{
    if(znak==""){
        a =  (ui->plainTextEdit->toPlainText()).toInt();
        ui->plainTextEdit->setPlainText("");
        znak="*";
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    if(znak==""){
        a =  (ui->plainTextEdit->toPlainText()).toInt();
        ui->plainTextEdit->setPlainText("");
        znak="/";
    }
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"7");
    ustaw(7);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"8");
    ustaw(8);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"9");
    ustaw(9);
}

void MainWindow::on_pushButton_18_clicked()
{
    if(znak==""){
        a =  (ui->plainTextEdit->toPlainText()).toInt();
        ui->plainTextEdit->setPlainText("");
        znak="+";
    }
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"4");
    ustaw(4);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"5");
    ustaw(5);
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"6");
    ustaw(6);
}

void MainWindow::on_pushButton_22_clicked()
{
    if(znak==""){
        a =  (ui->plainTextEdit->toPlainText()).toInt();
        ui->plainTextEdit->setPlainText("");
        znak="-";
    }
}

void MainWindow::on_pushButton_29_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"1");
    ustaw(1);
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"2");
    ustaw(2);
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"3");
    ustaw(3);
}

void MainWindow::on_pushButton_26_clicked()
{
    if (znak==""){}
    else{
        b =  (ui->plainTextEdit->toPlainText()).toInt();
        wypisz();
    }
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"0");
    ustaw(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    a = (ui->plainTextEdit->toPlainText().toInt());
    a *= a;
    if(a!=NULL){
        ui->plainTextEdit->setPlainText(QString::number(a));
        znak="";
        b=NULL;
        qDebug() << a;
    }
}

void MainWindow::on_pushButton_clicked()
{
    a = sqrt(ui->plainTextEdit->toPlainText().toInt());
    if(a!=NULL){
        ui->plainTextEdit->setPlainText(QString::number(a));
        znak="";
        b=NULL;
        qDebug() << a;
    }
}
void MainWindow::keyPressEvent(QKeyEvent* ke)
{
    qDebug()<<ke->key();
    switch(ke->key()){
    case 16777220 ... 16777221:
        on_pushButton_26_clicked();
        break;
    case 42:
        on_pushButton_15_clicked();
        break;
    case 47:
        on_pushButton_16_clicked();
        break;
    case 43:
        on_pushButton_18_clicked();
        break;
    case 45:
        on_pushButton_22_clicked();
        break;
    case 49:
        on_pushButton_29_clicked();
        break;
    case 50:
        on_pushButton_27_clicked();
        break;
    case 51:
        on_pushButton_28_clicked();
        break;
    case 52:
        on_pushButton_25_clicked();
        break;
    case 53:
        on_pushButton_23_clicked();
        break;
    case 54:
        on_pushButton_24_clicked();
        break;
    case 55:
        on_pushButton_21_clicked();
        break;
    case 56:
        on_pushButton_19_clicked();
        break;
    case 57:
        on_pushButton_20_clicked();
        break;
    }
}
