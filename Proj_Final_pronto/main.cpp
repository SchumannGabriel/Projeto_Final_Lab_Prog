#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QComboBox>
#include <QPalette>
#include <QFont>

void adicionarUsuario(QTableWidget *tabelaCadastro) {
    bool ok;
    QString nome = QInputDialog::getText(nullptr, "Adicionar Usuário",
                                         "Digite o nome do usuário:", QLineEdit::Normal, "", &ok);
    if (!ok || nome.isEmpty()) return;

    QString nivel = QInputDialog::getItem(nullptr, "Adicionar Usuário",
                                          "Selecione o nível de acesso:",
                                          {"Administrador", "Usuário"}, 0, false, &ok);
    if (!ok) return;

    QString uid = QInputDialog::getText(nullptr, "Adicionar Usuário",
                                        "Digite o UID do cartão:", QLineEdit::Normal, "", &ok);
    if (!ok || uid.isEmpty()) return;

    int row = tabelaCadastro->rowCount();
    tabelaCadastro->insertRow(row);
    tabelaCadastro->setItem(row, 0, new QTableWidgetItem(nome));
    tabelaCadastro->setItem(row, 1, new QTableWidgetItem(nivel));
    tabelaCadastro->setItem(row, 2, new QTableWidgetItem(uid));

    QMessageBox::information(nullptr, "Usuário Adicionado", "Usuário adicionado com sucesso!");
}

void excluirUsuario(QTableWidget *tabelaCadastro) {
    int row = tabelaCadastro->currentRow();
    if (row < 0) {
        QMessageBox::warning(nullptr, "Erro", "Por favor, selecione um usuário para excluir.");
        return;
    }

    tabelaCadastro->removeRow(row);
    QMessageBox::information(nullptr, "Usuário Excluído", "Usuário excluído com sucesso!");
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Janela principal
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Sistema de Controle");

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

    // Página de Controle
    QWidget *paginaControle = new QWidget;
    QVBoxLayout *layoutControle = new QVBoxLayout(paginaControle);

    QLabel *labelControle = new QLabel("Histórico de Acessos");
    QTableWidget *tabelaControle = new QTableWidget(0, 4); // 0 linhas, 4 colunas
    QStringList cabecalhosControle = {"Nome do Usuário", "UID do Cartão", "Horário", "Nível de Acesso"};
    tabelaControle->setHorizontalHeaderLabels(cabecalhosControle);
    tabelaControle->horizontalHeader()->setStretchLastSection(true);
    tabelaControle->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QPushButton *botaoVoltarControle = new QPushButton("Voltar");
    layoutControle->addWidget(labelControle);
    layoutControle->addWidget(tabelaControle);
    layoutControle->addWidget(botaoVoltarControle);

    // Página de Configuração
    QWidget *paginaConfig = new QWidget;
    QVBoxLayout *layoutConfig = new QVBoxLayout(paginaConfig);

    QLabel *labelConfig = new QLabel("Configurações");
    QPushButton *botaoIdioma = new QPushButton("Alterar Idioma");
    QPushButton *botaoVoltarConfig = new QPushButton("Voltar");

    // Personalizando os botões
    botaoIdioma->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; font-size: 16px; border-radius: 5px;");
    botaoVoltarConfig->setStyleSheet("background-color: #f44336; color: white; padding: 10px; font-size: 16px; border-radius: 5px;");

    // Personalizando o layout da página de configurações
    layoutConfig->setSpacing(20);
    layoutConfig->addWidget(labelConfig);
    layoutConfig->addWidget(botaoIdioma);
    layoutConfig->addWidget(botaoVoltarConfig);

    // Configuração de fontes e cores
    QFont font("Arial", 14);
    labelConfig->setFont(font);
    labelConfig->setStyleSheet("color: #333333;");
    paginaConfig->setStyleSheet("background-color: #f0f0f0;");

    // Página de Cadastro (com gerenciamento de usuários)
    QWidget *paginaCadastro = new QWidget;
    QVBoxLayout *layoutCadastro = new QVBoxLayout(paginaCadastro);

    QLabel *labelCadastro = new QLabel("Cadastro de Usuários");
    QTableWidget *tabelaCadastro = new QTableWidget(0, 3); // 0 linhas, 3 colunas
    QStringList cabecalhosCadastro = {"Nome do Usuário", "Nível de Acesso", "UID do Cartão"};
    tabelaCadastro->setHorizontalHeaderLabels(cabecalhosCadastro);
    tabelaCadastro->horizontalHeader()->setStretchLastSection(true);
    tabelaCadastro->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QPushButton *botaoAddUsuario = new QPushButton("Adicionar Usuário");
    QPushButton *botaoExcluirUsuario = new QPushButton("Excluir Usuário");
    QPushButton *botaoVoltarCadastro = new QPushButton("Voltar");

    // Estilizando os botões de Cadastro
    botaoAddUsuario->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; font-size: 16px; border-radius: 5px;");
    botaoExcluirUsuario->setStyleSheet("background-color: #ff9800; color: white; padding: 10px; font-size: 16px; border-radius: 5px;");
    botaoVoltarCadastro->setStyleSheet("background-color: #f44336; color: white; padding: 10px; font-size: 16px; border-radius: 5px;");

    layoutCadastro->addWidget(labelCadastro);
    layoutCadastro->addWidget(tabelaCadastro);
    layoutCadastro->addWidget(botaoAddUsuario);
    layoutCadastro->addWidget(botaoExcluirUsuario);
    layoutCadastro->addWidget(botaoVoltarCadastro);

    // Página Inicial (Estilo de Botões)
    botao_controle->setStyleSheet("background-color: #4CAF50; color: white; padding: 15px; font-size: 18px; border-radius: 5px;");
    botao_cadastro->setStyleSheet("background-color: #2196F3; color: white; padding: 15px; font-size: 18px; border-radius: 5px;");
    botao_config->setStyleSheet("background-color: #ff9800; color: white; padding: 15px; font-size: 18px; border-radius: 5px;");

    // Adicionando as páginas ao QStackedWidget
    stackedWidget->addWidget(paginaInicial);    // Página 0
    stackedWidget->addWidget(paginaControle);   // Página 1
    stackedWidget->addWidget(paginaCadastro);   // Página 2
    stackedWidget->addWidget(paginaConfig);     // Página 3

    // Conexões dos botões
    QObject::connect(botao_controle, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(1); // Página de Controle
    });
    QObject::connect(botao_cadastro, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(2); // Página de Cadastro
    });
    QObject::connect(botao_config, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(3); // Página de Configuração
    });

    QObject::connect(botaoVoltarControle, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(0); // Página Inicial
    });
    QObject::connect(botaoVoltarCadastro, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(0); // Página Inicial
    });
    QObject::connect(botaoVoltarConfig, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentIndex(0); // Página Inicial
    });
    QObject::connect(botaoAddUsuario, &QPushButton::clicked, [=]() {
        adicionarUsuario(tabelaCadastro);
    });
    QObject::connect(botaoExcluirUsuario, &QPushButton::clicked, [=]() {
        excluirUsuario(tabelaCadastro);
    });

    mainWindow.setCentralWidget(stackedWidget);
    mainWindow.resize(600, 400);
    mainWindow.show();

    return a.exec();
}
