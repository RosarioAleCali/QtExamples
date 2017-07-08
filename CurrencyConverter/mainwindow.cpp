#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList currencies;
    currencies.push_back("EUR");
    currencies.push_back("USD");
    currencies.push_back("CAD");
    currencies.push_back("MYR");
    currencies.push_back("GBP");

    ui->fromCurrency->insertItems(0, currencies);
    ui->toCurrency->insertItems(0, currencies);

    QValidator *inputRange = new QDoubleValidator(this);
    ui->fromInput->setValidator(inputRange);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertButton_clicked()
{
    if(ui->fromInput->text() != "")
    {
        ui->convertButton->setEnabled(false);
        QString from = ui->fromCurrency->currentText();
        QString to = ui->toCurrency->currentText();
        targetCurrency = to;
        QString url = "http://api.fixer.io/latest?base=" + from + "&symbols=" + to;
        QNetworkRequest request = QNetworkRequest(QUrl(url));
        manager->get(request);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Please insert a value.");
    }
}

void MainWindow::finished(QNetworkReply *reply)
{
    QByteArray response = reply->readAll();
    qDebug() << response;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
    QJsonObject jsonObj = jsonResponse.object();
    QJsonObject jsonObj2 = jsonObj.value("rates").toObject();
    double rate = jsonObj2.value(targetCurrency).toDouble();
    if(rate == 0)
        rate = 1;
    double amount = ui->fromInput->text().toDouble();
    double result = amount * rate;
    ui->toInput->setText(QString::number(result));
    ui->convertButton->setEnabled(true);
}
