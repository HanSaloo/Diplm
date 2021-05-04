
//    Window window;
//    window.show();
//    return app.exec();
//}

#include <QApplication>
//#include <QTextCodec>
#include <Qt>
#include <QDebug>

#include "mainwindow.h"
#include "exceptions.h"
#include "login.h"
#include "window.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

  // QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    try
    {
      MainWindow Window;
      Window.show();

  //  Window w2;
 //   w2.show();

        return app.exec();
    }
    catch (CUserFail *pException)
    {
        delete pException;
        return 0;
    }
    catch (Exceptions *pException)
    {
        int code = pException->code();
        qDebug() << pException->message();

        delete pException;

        return code;
    }
}
