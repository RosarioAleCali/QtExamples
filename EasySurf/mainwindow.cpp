#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webview = new QWebEngineView;
    ui->horizontalLayout_2->addWidget(webview);

    // webview->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, false);
    // webview->page()->settings()->setAttribute(QWebEngineSettings::AutoLoadImages, false);
    // QString fontFamily = webview->page()->settings()->fontFamily(QWebEngineSettings::SerifFont);
    QString fontFamily = webview->page()->settings()->fontFamily(QWebEngineSettings::SansSerifFont);
    int fontSize = webview->page()->settings()->fontSize(QWebEngineSettings::MinimumFontSize);
    QFont myFont = QFont(fontFamily, fontSize);
    webview->page()->settings()->setFontFamily(QWebEngineSettings::StandardFont, myFont.family());

    QFile file("://tux.png");
    if(file.open(QFile::ReadOnly))
    {
        QByteArray data = file.readAll();
        webview->page()->setContent(data, "image/png");
    }
    else
    {
        qDebug() << "File cannot be opened.";
    }

    connect(webview, SIGNAL(loadProgress(int)), SLOT(loading(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadUrl()
{
    QUrl url = QUrl(ui->address->text());
    url.setScheme("http");
    webview->page()->load(url);
}

void MainWindow::startLoading()
{
    ui->progressBar->show();
}

void MainWindow::loading(int progress)
{
    ui->progressBar->setValue(progress);
}

void MainWindow::loaded(bool ok)
{
    ui->progressBar->hide();
}

void MainWindow::on_backButton_clicked()
{
    webview->back();
}

void MainWindow::on_forwardButton_clicked()
{
    webview->forward();
}

void MainWindow::on_goButton_clicked()
{
    loadUrl();
}

void MainWindow::on_address_returnPressed()
{
    loadUrl();
}

void MainWindow::on_loadHTMLButton_clicked()
{
    webview->setHtml(ui->source->toPlainText());
}
