#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QDir>

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
    void highlightChecked(QListWidgetItem* item);



private:
    Ui::MainWindow *ui;
    QString dir;
    QString prtfile = nullptr;
    QStringList alltxt;
    QStringList seltxt;
    QListWidget* widget;
    QListWidgetItem* item = nullptr;
    QDir directory;

};
#endif // MAINWINDOW_H
