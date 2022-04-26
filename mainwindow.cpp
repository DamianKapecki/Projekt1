#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QMessageBox>
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

std::vector <float> Kon1;
std::vector <float> Kon2;
std::vector <float> pojemnosc;
std::vector <float> napiecie;
std::vector <float> pom;
std::vector <float> QQ;
std::vector <float> inna1;
std::vector <float> imp;
std::vector <float> inne;

class Myclass{
public:
    void Kondensator1()
    {
        Kon1.insert(Kon1.begin()+5,((Kon1[1]*Kon1[2])/Kon1[3])*Kon1[0]);
        Kon1.insert(Kon1.begin()+6,(1/(Kon1[4]*6.28*Kon1[5])));

    }
    void Kondensator2()
    {

        Kon2.insert(Kon2.begin()+4,(Kon2[1]/Kon2[2]*Kon2[0]));
        Kon2.insert(Kon2.begin()+5,(1/(Kon2[3]*6.28*Kon2[4])));

    }

    void pojrow()
        {
            pojemnosc.insert(pojemnosc.begin()+6,0);

            for (int i=0;i<6; i++){
                if(pojemnosc[i]>0){
                    pojemnosc.insert(pojemnosc.begin()+6,pojemnosc[6]+pojemnosc[i]);
                }
            }

        }
   void impszereg()
   {
       imp.insert(imp.begin()+3,0);

       for (int i=0;i<3; i++){
           if(imp[i]>0){
               imp.insert(imp.begin()+3,imp[3]+imp[i]);
           }
       }
   }
   void improw()
   {
       inne.insert(inne.begin(),0);
              for(int i=0; i<3;i++){
                  if(imp[i]>0){
                    inne.insert(inne.begin(),inne[0]+1/imp[i]);
                  }
              }
             inne.insert(inne.begin()+1,1/inne[0]);
   }

   void reset()
   {
       Kon2.insert(Kon2.begin(),(0));
        Kon2.insert(Kon2.begin()+1,(0));
         Kon2.insert(Kon2.begin()+2,(0));
          Kon2.insert(Kon2.begin()+3,(0));
           Kon2.insert(Kon2.begin()+4,(0));
            Kon2.insert(Kon2.begin()+5,(0));
            Kon2.insert(Kon2.begin()+6,(0));
   };



        void naprow()
        {
            for (int i=0; i<6; i++){
                if(napiecie[i]>0){
                if(napiecie[i]<napiecie[6]){
                    napiecie.insert(napiecie.begin()+6,napiecie[i]);
                }
                }
            }
        }

        void pojszer()
        {
            pom.insert(pom.begin(),0);
                   for(int i=0; i<6;i++){
                       if(pojemnosc[i]>0){
                         pom.insert(pom.begin(),pom[0]+1/pojemnosc[i]);
                       }
                   }
                  pom.insert(pom.begin()+1,1/pom[0]);
        }

        void napszer(){
            for (int i=0; i<6; i++){
                QQ.insert(QQ.begin()+i, pojemnosc[i]*napiecie[i]);
            }

                   pom.insert(pom.begin()+2,0);
                   for(int i=0;i<6;i++){
                       if(QQ[i]>pom[2]){
                           pom.insert(pom.begin()+2,QQ[i]);
                       }
                   }

            for (int i=0; i<6;i++){
                inna1.insert(inna1.begin()+i, pom[2]/pojemnosc[i]);
            }

                   pom.insert(pom.begin()+3,0);
                   for(int i=0; i<6; i++){
                       if(pojemnosc[i]>0){
                           pom.insert(pom.begin()+3,pom[3]+inna1[i]);
                       }
                   }
        }

};


void MainWindow::on_Reset_clicked()
{
    ui->P1->setText("0");
    ui->P2->setText("0");
    ui->P3->setText("0");
    ui->P4->setText("0");
    ui->P5->setText("0");
    ui->P6->setText("0");
    ui->N1->setText("0");
    ui->N2->setText("0");
    ui->N3->setText("0");
    ui->N4->setText("0");
    ui->N5->setText("0");
    ui->N6->setText("0");

}


void MainWindow::on_pushButton_clicked()
{
    Kon1.insert(Kon1.begin(),ui->Kon1_1->text().toFloat());
    Kon1.insert(Kon1.begin()+1,ui->Kon1_2->text().toFloat());
    Kon1.insert(Kon1.begin()+2,ui->Kon1_3->text().toFloat());
    Kon1.insert(Kon1.begin()+3,ui->Kon1_4->text().toFloat());
    Kon1.insert(Kon1.begin()+4,ui->ff1->text().toFloat());
    Myclass P1;
    P1.Kondensator1();
    QString wynik1;

    wynik1.setNum(Kon1[5]);
    ui->label_26->setText(wynik1+'C');
    QString wynik11;
    wynik11.setNum(Kon1[6]);
    ui->imp1->setText('Z'+wynik11);


    QFile file;
           file.setFileName("raport.txt");
           if (!file.open(QFile::WriteOnly | QIODevice::Append)) {
               QMessageBox::warning(this, "Ostrzeżenie", "Plik nie został otworzony");
           }
           QTextStream out(&file);
           out << "Kondensator1";
           out << ",";
           out << Kon1[5];
           out << ",";

           out << Kon1[6];
           out <<",";

           file.flush();
           file.close();




}


void MainWindow::on_pushButton_3_clicked()
{
    Myclass P1;
    P1.reset();
    Kon2.insert(Kon2.begin(),ui->Kon2_1->text().toFloat());
    Kon2.insert(Kon2.begin()+1,ui->Kon2_2->text().toFloat());
    Kon2.insert(Kon2.begin()+2,ui->Kon2_3->text().toFloat());
    Kon2.insert(Kon2.begin()+3,ui->ff2->text().toFloat());

    P1.Kondensator2();
    QString wynik2;
    wynik2.setNum(Kon2[4]);
    ui->label_27->setText(wynik2+'C');
    QString wynik22;
    wynik22.setNum(Kon2[5]);
    ui->imp2->setText('Z'+wynik22);
    QFile file;
           file.setFileName("raport.txt");
           if (!file.open(QFile::WriteOnly | QIODevice::Append)) {
               QMessageBox::warning(this, "Ostrzeżenie", "Plik nie został otworzony");
           }
           QTextStream out(&file);
           out << "Kondensator2";
           out << ",";
           out << Kon2[4];
           out << ",";

           out << Kon2[5];
           out <<",";

           file.flush();
           file.close();
}


void MainWindow::on_pushButton_4_clicked()
{
    Myclass P1;
    P1.reset();
    Kon2.insert(Kon2.begin(),ui->Kon3_1->text().toFloat());
    Kon2.insert(Kon2.begin()+1,ui->Kon3_2->text().toFloat());
    Kon2.insert(Kon2.begin()+2,ui->Kon3_3->text().toFloat());
    Kon2.insert(Kon2.begin()+3,ui->ff3->text().toFloat());


    P1.Kondensator2();
    QString wynik2;
    wynik2.setNum(Kon2[4]);
    ui->label_28->setText(wynik2+'C');
    QString wynik22;
    wynik22.setNum(Kon2[5]);
    ui->imp3->setText('Z'+wynik22);
    QFile file;
           file.setFileName("raport.txt");
           if (!file.open(QFile::WriteOnly | QIODevice::Append)) {
               QMessageBox::warning(this, "Ostrzeżenie", "Plik nie został otworzony");
           }
           QTextStream out(&file);
           out << "Kondensator3";
           out << ",";
           out << Kon2[4];
           out << ",";

           out << Kon2[5];
           out <<",";

           file.flush();
           file.close();
}


void MainWindow::on_pushButton_5_clicked()
{
    Myclass P1;
    P1.reset();
    Kon2.insert(Kon2.begin(),ui->Kon4_1->text().toFloat());
    Kon2.insert(Kon2.begin()+1,ui->Kon4_2->text().toFloat());
    Kon2.insert(Kon2.begin()+2,ui->Kon4_3->text().toFloat());
    Kon2.insert(Kon2.begin()+3,ui->ff4->text().toFloat());


    P1.Kondensator2();
    QString wynik2;
    wynik2.setNum(Kon2[4]);
    ui->label_29->setText(wynik2+'C');
    QString wynik22;
    wynik22.setNum(Kon2[5]);
    ui->imp4->setText('Z'+wynik22);
    QFile file;
           file.setFileName("raport.txt");
           if (!file.open(QFile::WriteOnly | QIODevice::Append)) {
               QMessageBox::warning(this, "Ostrzeżenie", "Plik nie został otworzony");
           }
           QTextStream out(&file);
           out << "Kondensator3";
           out << ",";
           out << Kon2[4];
           out << ",";

           out << Kon2[5];
           out <<",";

           file.flush();
           file.close();
}


void MainWindow::on_pushButton_9_clicked()
{
    pojemnosc.insert(pojemnosc.begin(),ui->P1->text().toFloat());
      pojemnosc.insert(pojemnosc.begin()+1,ui->P2->text().toFloat());
      pojemnosc.insert(pojemnosc.begin()+2,ui->P3->text().toFloat());
       pojemnosc.insert(pojemnosc.begin()+3,ui->P4->text().toFloat());
       pojemnosc.insert(pojemnosc.begin()+4,ui->P5->text().toFloat());
       pojemnosc.insert(pojemnosc.begin()+5,ui->P6->text().toFloat());
       napiecie.insert(napiecie.begin(),ui->N1->text().toFloat());
       napiecie.insert(napiecie.begin()+1,ui->N2->text().toFloat());
       napiecie.insert(napiecie.begin()+2,ui->N3->text().toFloat());
       napiecie.insert(napiecie.begin()+3,ui->N4->text().toFloat());
       napiecie.insert(napiecie.begin()+4,ui->N5->text().toFloat());
       napiecie.insert(napiecie.begin()+5,ui->N6->text().toFloat());
       imp.insert(imp.begin(),ui->impdane1->text().toFloat());
       imp.insert(imp.begin()+1,ui->impdane2->text().toFloat());
       imp.insert(imp.begin()+2,ui->impdane3->text().toFloat());

       QString opcja =ui->comboBox_8->currentText();
       if(opcja=="Równoległe"){

           Myclass P1;
                 P1.pojrow();


                 QString pojrow1;
                 pojrow1.setNum(pojemnosc[6]);

                 ui->wynik1->setText(pojrow1);

                  P1.naprow();
                  P1.improw();

                  QString napp1;
                  napp1.setNum(napiecie[6]);
                  ui->wynik2->setText(napp1);
                  QString impp1;
                  impp1.setNum(inne[1]);
                  ui->impwynik->setText(impp1);
                  QFile file;
                         file.setFileName("raport.txt");
                         if (!file.open(QFile::WriteOnly | QIODevice::Append)) {
                             QMessageBox::warning(this, "Ostrzeżenie", "Plik nie został otworzony");
                         }
                         QTextStream out(&file);
                         out << "Rownolegle";
                         out << ",";
                         out << "Pojemnosc";
                         out << ",";
                         out << pojemnosc[6];
                         out << ",";
                         out << "Napiecie";
                         out << ",";
                         out << napiecie[6];
                         out << ",";
                         out << "Impedancja";
                         out << ",";
                         out << inne[1];
                         out << ",";



                         file.flush();
                         file.close();
       }
       if(opcja=="Szeregowe"){
              Myclass P1;
              P1.pojszer();

              QString pojszer1;
              pojszer1.setNum(pom[1]);
              ui->wynik1->setText(pojszer1);
              P1.napszer();

              QString naprzeb1;
              naprzeb1.setNum(pom[3]);
              ui->wynik2->setText(naprzeb1);

              P1.impszereg();
              QString impp2;
              impp2.setNum(imp[3]);
              ui->impwynik->setText(impp2);
              QFile file;
                     file.setFileName("raport.txt");
                     if (!file.open(QFile::WriteOnly | QIODevice::Append)) {
                         QMessageBox::warning(this, "Ostrzeżenie", "Plik nie został otworzony");
                     }
                     QTextStream out(&file);
                     out << "Szeregowe";
                     out << ",";
                     out << "Pojemnosc";
                     out << ",";
                     out << pom[1];
                     out << ",";
                     out << "Napiecie";
                     out << ",";
                     out << pom[3];
                     out << ",";
                     out << "Impedancja";
                     out << ",";
                     out << imp[4];
                     out << ",";



                     file.flush();
                     file.close();
}

}



