#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFontDialog>
#include<QFont>
#include<QColorDialog>
#include<QColor>
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

        //toolbar->addAction(openNewWindowAction);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

    filepath="";//setting to empty string when clicked it will reset path.
    ui->textEdit->setText("");//clearing the text edit
}


void MainWindow::on_actionopen_triggered()
{

    QString file_name= QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(file_name);
    filepath=file_name;
    if(!file.open(QFile::ReadOnly | QFile :: Text))
    {
        QMessageBox::warning(this,"...","File Not Open");
        return;
    }

    QTextStream in(&file);
    QString text= in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{

    QFile file(filepath);
    if(!file.open(QFile::WriteOnly | QFile :: Text))
    {
        QMessageBox::warning(this,"...","File Not Open");
        return;
    }

    QTextStream out(&file);
    QString text= ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{

    QString file_name= QFileDialog::getSaveFileName(this,"Save the File");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile :: Text))
    {
        QMessageBox::warning(this,"...","File Not Open");
        return;
    }

    QTextStream out(&file);
    QString text= ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionREdo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{

    QString aboutText;
    aboutText = "Authur : Awais Raza \n";
    aboutText+="Created on: 3/05/2024\n";
    aboutText+="First Application\n";
    aboutText+="Personal Notepad\n";
    QMessageBox::about(this,"about notepad",aboutText);
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this) ;
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else {
        return;
    }

}


void MainWindow::on_actionColor_triggered()
{
    QColor color= QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }

//    else{
//        return;
//    }
}


void MainWindow::on_actionAdd_Background_Color_triggered()
{
    QColor color= QColorDialog::getColor(Qt::white,this,"Choose Background Color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
}


void MainWindow::on_actionBackGround_Color_Text_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Background Color ");
    QPalette palette;
    palette.setColor(QPalette::Base,color);
    if(color.isValid())
    ui->textEdit->setPalette(palette);
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Desired Printer Name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected ) return;
    ui->textEdit->print(&printer);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->statusbar->adjustSize();
}


void MainWindow::on_actionnext_triggered()
{
    ui->textEdit->fontUnderline();
    //connect(openNewWindowAction, SIGNAL(triggered()), this, SLOT(openNewWindow()));
}


void MainWindow::on_actionClear_Text_triggered()
{
     ui->textEdit->clear();
}

