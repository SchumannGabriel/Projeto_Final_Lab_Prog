#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Janela principal
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Main Window");

    // Criando o QStackedWidget para gerenciar as páginas
    QStackedWidget *stackedWidget = new QStackedWidget;

    // Página inicial com os botões
    QWidget *paginaInicial = new QWidget;
    QVBoxLayout *layoutInicial = new QVBoxLayout(paginaInicial);

    QPushButton *botao_controle = new QPushButton("Controle");
    QPushButton *botao_cadastro = new QPushButton("Cadastro");
    QPushButton *botao_config = new QPushButton("Configuração");

    layoutInicial->addWidget(botao_controle);
    layoutInicial->addWidget(botao_cadastro);
    layoutInicial->addWidget(botao_config);

    // Páginas de Controle, Cadastro e Configuração com botão "Voltar"
    QWidget *paginaControle = new QWidget;
    QVBoxLayout *layoutControle = new QVBoxLayout(paginaControle);
    QLabel *labelControle = new QLabel("Página de Controle");
    QPushButton *botaoVoltarControle = new QPushButton("Voltar");
    layoutControle->addWidget(labelControle);
    layoutControle->addWidget(botaoVoltarControle);

    QWidget *paginaCadastro = new QWidget;
    QVBoxLayout *layoutCadastro = new QVBoxLayout(paginaCadastro);
    QLabel *labelCadastro = new QLabel("Página de Cadastro");
    QPushButton *botaoVoltarCadastro = new QPushButton("Voltar");
    layoutCadastro->addWidget(labelCadastro);
    layoutCadastro->addWidget(botaoVoltarCadastro);

    QWidget *paginaConfig = new QWidget;
    QVBoxLayout *layoutConfig = new QVBoxLayout(paginaConfig);
    QLabel *labelConfig = new QLabel("Página de Configuração");
    QPushButton *botaoVoltarConfig = new QPushButton("Voltar");
    layoutConfig->addWidget(labelConfig);
    layoutConfig->addWidget(botaoVoltarConfig);

    // Adicionando as páginas ao QStackedWidget
    stackedWidget->addWidget(paginaInicial);   // Página 0
    stackedWidget->addWidget(paginaControle);  // Página 1
    stackedWidget->addWidget(paginaCadastro);  // Página 2
    stackedWidget->addWidget(paginaConfig);    // Página 3

    // Configurando a página inicial como a página exibida
    mainWindow.setCentralWidget(stackedWidget);

    // Conectando os botões para mudar entre as páginas
    QObject::connect(botao_controle, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(1); // Página de Controle
    });
    QObject::connect(botao_cadastro, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(2); // Página de Cadastro
    });
    QObject::connect(botao_config, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(3); // Página de Configuração
    });

    // Conectando os botões "Voltar" para retornar à página inicial
    QObject::connect(botaoVoltarControle, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(0); // Página Inicial
    });
    QObject::connect(botaoVoltarCadastro, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(0); // Página Inicial
    });
    QObject::connect(botaoVoltarConfig, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(0); // Página Inicial
    });

    mainWindow.resize(400, 300);
    mainWindow.show();

    return a.exec();
}
