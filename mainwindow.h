#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    void on_actionNew_triggered();

    void on_actionopen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionREdo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_Notepad_triggered();

    void on_actionPaste_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionAdd_Background_Color_triggered();

    void on_actionBackGround_Color_Text_triggered();

    void on_actionPrint_triggered();

    void on_pushButton_2_clicked();

    void on_actionnext_triggered();

    void on_actionClear_Text_triggered();

private:
    Ui::MainWindow *ui;
    QString filepath;
    //secondWindow *myNewWindow;

};
#endif // MAINWINDOW_H
