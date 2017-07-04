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

void MainWindow::on_loadButton_clicked()
{
    QDomDocument xml;

    QString fileName = QFileDialog::getOpenFileName(this, "Open Xml", ".", "Xml files (*.xml)");
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Error Loading XML File.";
    if (!xml.setContent(&file))
    {
        qDebug() << "Error setting content.";
        file.close();
        return;
    }
    file.close();

    QDomElement element = xml.documentElement();
    QDomNode node = element.firstChild();

    while (!node.isNull())
    {
        QDomElement nodeElement = node.toElement();
        if (!nodeElement.isNull())
        {
            if (nodeElement.tagName() == "object")
            {
                qDebug() << "[Object]======================";

                QDomNode childNode = nodeElement.firstChild();

                while (!childNode.isNull())
                {
                    QDomElement childNodeElement = childNode.toElement();

                    QString name = childNodeElement.tagName();
                    if (name == "name" || name == "position" || name == "rotation" || name == "scale")
                    {
                        QString text = childNodeElement.text();
                        qDebug() << name << text;
                    }

                    childNode = childNode.nextSibling();
                }
            }

            qDebug() << "==============================";
        }

        node = node.nextSibling();
    }
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Xml", ".", "Xml files (*.xml)");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Error Saving XML File.";
        file.close();
        return;
    }

    QDomDocument xml("contact");

    // Alex Cali
    QDomElement root = xml.createElement("contact");
    root.setAttribute("category", "Family");
    xml.appendChild(root);

    QDomElement tagName = xml.createElement("name");
    root.appendChild(tagName);
    QDomText textName = xml.createTextNode("Alex Cali");
    tagName.appendChild(textName);

    QDomElement tagAge = xml.createElement("age");
    root.appendChild(tagAge);
    QDomText textAge = xml.createTextNode("20");
    tagAge.appendChild(textAge);

    QDomElement tagAddress = xml.createElement("address");
    root.appendChild(tagAddress);
    QDomText textAddress = xml.createTextNode("85 Lorne Av., Toronto");
    tagAddress.appendChild(textAddress);

    QDomElement tagPhone = xml.createElement("phone");
    root.appendChild(tagPhone);
    QDomText textPhone = xml.createTextNode("905-457-9817");
    tagPhone.appendChild(textPhone);

    // Sal Cali
    QDomElement root2 = xml.createElement("contact");
    root2.setAttribute("category", "Family");
    xml.appendChild(root2);

    QDomElement tagName2 = xml.createElement("name");
    root2.appendChild(tagName2);
    QDomText textName2 = xml.createTextNode("Sal Cali");
    tagName2.appendChild(textName2);

    QDomElement tagAge2 = xml.createElement("age");
    root2.appendChild(tagAge2);
    QDomText textAge2 = xml.createTextNode("25");
    tagAge2.appendChild(textAge2);

    QDomElement tagAddress2 = xml.createElement("address");
    root2.appendChild(tagAddress2);
    QDomText textAddress2 = xml.createTextNode("85 Lorne Av., Montreal");
    tagAddress2.appendChild(textAddress2);

    QDomElement tagPhone2 = xml.createElement("phone");
    root2.appendChild(tagPhone2);
    QDomText textPhone2 = xml.createTextNode("905-457-5217");
    tagPhone2.appendChild(textPhone2);

    // Save to File
    QTextStream output(&file);
    output << xml.toString();

    file.close();
}
