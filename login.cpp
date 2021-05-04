#include "login.h"

Login::Login(QWidget *parent) : QDialog(parent)
{

}

Login::~Login()
{

}

QString Login::userName() const
{
    return "UserName";  //TODO
}

QString Login::password() const
{
    return "Password";      //TODO
}

void Login::showEvent(QShowEvent *pEvent)
{
    //TODO
}


