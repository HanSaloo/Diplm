#include <QString>
#include <QObject>

class Exceptions
{
public:
    Exceptions() {

    }
    virtual ~Exceptions( )  {  }

    virtual QString message() const = 0;
    virtual int code() const = 0;
};




class CUserFail : public Exceptions
{

public:

    QString message() const {
        return QObject::tr("User say NO AUTHORISATION");
    }

    int code() const {
        return 0;
    }
};
