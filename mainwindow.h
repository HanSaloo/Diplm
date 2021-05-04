#include <QMainWindow>
#include <QSqlDatabase>
#include <QWidget>

class QSqlDatabase;
class QAction;

QT_BEGIN_NAMESPACE
class QComboBox;
class QDataWidgetMapper;
class QItemSelectionModel;
class QLabel;
class QLineEdit;
class QPushButton;
class QSqlRelationalTableModel;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;
QT_END_NAMESPACE

/* main window class prototype */
class MainWindow : public QMainWindow
     //  :  public QWidget
{
        Q_OBJECT

public:
    MainWindow(QWidget *pOwner = nullptr);
    ~MainWindow();

protected:
    bool openDatabase(const QString &username, const QString &password);
    void closeDatabase();

private:
    typedef QMainWindow inherited;

    QSqlDatabase m_database;

    //window elements
   // void setUpMpdel();


    QLabel *loginLabel;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLineEdit *usernameLineE;
    QLineEdit *passwordLineE;
    QPushButton *loginButton;

};
