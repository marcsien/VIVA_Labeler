#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QProcess>
#include <QDebug>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dir = qApp->applicationDirPath();
    dir.append("/files");
    directory = QDir(dir);
    alltxt = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);
    setWindowTitle("LABELER");
    QVBoxLayout* containerLayout = new QVBoxLayout();
    widget = new QListWidget;
    widget->addItems(alltxt);

    for(int i = 0; i < widget->count(); ++i)
    {
        item = widget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

    QObject::connect(widget, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(highlightChecked(QListWidgetItem*)));
    containerLayout->addWidget(widget);
    ui->scrollAreaWidgetContents->setLayout(containerLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    for (int i = 0;i<seltxt.size();i++)
    {
        QString temp = QString(dir);
        temp.append("/");
        temp.append(seltxt.at(i));

        for (int var = 0; var < ui->spinBox->value(); ++var)
        {
            QString name = "C:\\jj.txt >> lpt1:";
            QString exe = QString("print %1 >> lpt1:").arg(temp);
            //qDebug() << exe;
            exe.replace("/","\\",Qt::CaseSensitive);
            //qDebug() << exe;
            QProcess::execute(exe);
        }
    }

}

void MainWindow::highlightChecked(QListWidgetItem *item)
{
    QString obiekcik = item->text();
    if (!seltxt.contains(obiekcik))
    {
        seltxt.append(item->text());
    }
    else
    {
        seltxt.removeOne(obiekcik);
    }
}
