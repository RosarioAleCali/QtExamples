#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadXmlButton_clicked()
{
    QXmlStreamReader xml;

    QString fileName = QFileDialog::getOpenFileName(this, "Open XML", ".", "Xml files (*.xml)");
    QFile file(fileName);
    if (!file.open((QFile::ReadOnly | QFile::Text)))
        qDebug() << "Error loading XML file.";
    xml.setDevice(&file);

    while (!xml.atEnd())
    {
        if (xml.isStartElement())
        {
            QString name = xml.name().toString();

            if (name == "object")
            {
                qDebug() << "[Object]======================";

                for (int i = 0; i < xml.attributes().size(); i++)
                {
                    qDebug() << xml.attributes().at(i).name() << xml.attributes().at(i).value();
                }

            }

            if (name == "name" || name == "position" || name == "rotation" || name == "scale")
            {
                QString text = xml.readElementText();
                qDebug() << name << text;
            }
        }

        if (xml.isEndElement())
        {
            QString name = xml.name().toString();

            if (name == "object")
            {
                qDebug() << "==============================";
            }
        }

        xml.readNext();
    }

    if (xml.hasError())
    {
        qDebug() << "Error loading XML: " << xml.errorString();
    }
}

void MainWindow::on_saveXmlButton_clicked()
{
    QXmlStreamWriter xml;

    QString fileName = QFileDialog::getSaveFileName(this, "Save XML", ".", "Xml files (*.xml)");
    QFile file(fileName);
    if (!file.open((QFile::WriteOnly | QFile::Text)))
        qDebug() << "Error saving XML file.";
    xml.setDevice(&file);

    xml.setAutoFormatting(true);
    xml.writeStartDocument();

    xml.writeStartElement("contact");
    xml.writeAttribute("category", "Friend");
    xml.writeTextElement("name", "Alex Cali");
    xml.writeTextElement("age", "20");
    xml.writeTextElement("address", "114B, 2nd Floor, Toronto");
    xml.writeTextElement("phone", "091-820-9734");
    xml.writeEndElement();

    xml.writeStartElement("contact");
    xml.writeAttribute("category", "Friend");
    xml.writeTextElement("name", "Sal Cali");
    xml.writeTextElement("age", "40");
    xml.writeTextElement("address", "116B, 2nd Floor, Toronto");
    xml.writeTextElement("phone", "091-820-1845");
    xml.writeEndElement();

    xml.writeEndDocument();
}
