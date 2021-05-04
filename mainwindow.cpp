#include "mainwindow.h"
#include "login.h"
#include "exceptions.h"

#include <QtWidgets>
#include <QtSql>

/* class constructor */
MainWindow::MainWindow(QWidget *pOwner) : inherited(pOwner), m_database()
{
   // setUpMpdel();

    loginLabel = new QLabel(tr("Log in, &please"));
    usernameLabel = new QLabel(tr("&Username"));
    passwordLabel = new QLabel(tr("&Password"));
    usernameLineE = new QLineEdit();
    passwordLineE = new QLineEdit();
    loginButton = new QPushButton("&login");

    usernameLabel->setBuddy(usernameLineE);
    passwordLabel->setBuddy(passwordLineE);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(loginLabel, 0, 0, 1, 1);
    layout->addWidget(usernameLabel, 0, 1, 1, 1);
    layout->addWidget(usernameLineE, 0, 2, 1, 1);
    layout->addWidget(passwordLabel, 0, 3, 1, 1);
    layout->addWidget(passwordLineE, 1, 0, 1, 1);
    layout->addWidget(loginButton, 1, 1, 1, 1);

    layout->setContentsMargins(20,20,20,20);
    layout->setSpacing(10);

    setLayout(layout);

     setWindowTitle(tr("Autorisation"));
    // mapper->toFirst();

    Login login;
    do
    {
        if (login.exec() == Login::Rejected)
            throw new CUserFail();
    }
    while (!openDatabase(login.userName(), login.password()));
}

MainWindow::~MainWindow()
{

}

bool MainWindow::openDatabase(const QString &username, const QString &password)
{
    //TODO
    return false;
}

void MainWindow::closeDatabase()
{
    //TODO
}
