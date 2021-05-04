#include <QDialog>

class QLineEdit;

// auth. window
class Login : public QDialog
{
public:
    Login(QWidget *pOwner = nullptr);
    ~Login();

    QString userName() const;
    QString password() const;

protected:
    void showEvent(QShowEvent * pEvent);

private:
    typedef QDialog inherited;

    QLineEdit *m_ptxtUserName;
    QLineEdit *m_ptxtPassword;
};
