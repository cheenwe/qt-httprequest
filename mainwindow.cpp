#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qtnetwork/QNetworkReply>
#include <QMessageBox>

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


void MainWindow::on_pushButton_clicked() {
    // trigger the request - see the examples in the following sections

    QString url_str = "http://0.0.0.0:5003/api/v1/users/";

    HttpRequestInput input(url_str, "GET");

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}

void MainWindow::on_pushButton_2_clicked() {
    // trigger the request - see the examples in the following sections

    QString url_str = "http://0.0.0.0:5003/api/v1/users/";

    HttpRequestInput input(url_str, "POST");
    input.add_var("username", "demo1");
    input.add_var("password", "123123123");
    input.add_file("file", "/Users/chenwei/a.ico", NULL, "image/png");


    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}


void MainWindow::on_pushButton_3_clicked() {
    // trigger the request - see the examples in the following sections

    QString url_str = "http://0.0.0.0:5003/api/v1/users/";

    HttpRequestInput input(url_str, "PUT");
    input.add_var("username", "demo1");
    input.add_var("password", "123123123");

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}


void MainWindow::on_pushButton_4_clicked() {
    // trigger the request - see the examples in the following sections

    QString url_str = "http://0.0.0.0:5003/api/v1/users/";

    HttpRequestInput input(url_str, "DELETE");

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}

void MainWindow::on_pushButton_5_clicked() {
    // trigger the request - see the examples in the following sections

    QString url_str = "http://0.0.0.0:5003/api/v1/users/";

    HttpRequestInput input(url_str, "HEAD");


    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}




void MainWindow::handle_result(HttpRequestWorker *worker) {
    QString msg;

    if (worker->error_type == QNetworkReply::NoError) {
        // communication was successful
        msg = "Success - Response: " + worker->response;
    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str;
    }

    QMessageBox::information(this, "", msg);
}
