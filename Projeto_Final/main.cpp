#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // Inicializa a comunicação com a porta serial
        serialPort = new QSerialPort(this);

        // Defina a porta serial que você está usando (ajuste conforme necessário)
        serialPort->setPortName("COM3");
        serialPort->setBaudRate(QSerialPort::Baud9600);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        if (serialPort->open(QIODevice::ReadWrite)) {
            qDebug() << "Porta serial aberta!";
        } else {
            qDebug() << "Erro ao abrir a porta serial:" << serialPort->errorString();
        }


        connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::lerDadosSerial);

        // Configurar o banco de dados SQLite
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("meu_banco.db");
        if (!db.open()) {
            qDebug() << "Erro ao abrir banco de dados:" << db.lastError().text();
        }
        query = new QSqlQuery(db);

        // Criar a tabela de usuários no banco de dados, caso não exista
        query->exec("CREATE TABLE IF NOT EXISTS usuarios (id INTEGER PRIMARY KEY AUTOINCREMENT, nome TEXT NOT NULL, nivel TEXT NOT NULL)");

        // Configuração da interface gráfica
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        QLabel *label = new QLabel("Esperando dados do Arduino...", this);
        layout->addWidget(label);

        setCentralWidget(centralWidget);
    }

private slots:
    void lerDadosSerial() {
        QByteArray dados = serialPort->readAll();
        QString dadosStr = QString::fromStdString(dados.toStdString());


        QStringList partes = dadosStr.split(",");
        if (partes.size() == 2) {
            QString nome = partes[0].trimmed();
            QString nivel = partes[1].trimmed();


            query->prepare("INSERT INTO usuarios (nome, nivel) VALUES (:nome, :nivel)");
            query->bindValue(":nome", nome);
            query->bindValue(":nivel", nivel);

            if (!query->exec()) {
                qDebug() << "Erro ao inserir dados no banco:" << query->lastError().text();
            } else {
                qDebug() << "Dados inseridos com sucesso!";
            }
        }
    }

private:
    QSerialPort *serialPort;   // Ponteiro para o objeto QSerialPort
    QSqlDatabase db;           // Banco de dados SQLite
    QSqlQuery *query;          // Objeto para executar as queries SQL
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
