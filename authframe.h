#ifndef AUTHFRAME_H
#define AUTHFRAME_H
#include <QtWidgets>

class AuthFrame : public QWidget
{
    Q_OBJECT
public:
    AuthFrame() {}
    virtual ~AuthFrame() {}

private:
    void askPassword();
};
#endif // AUTHFRAME_H
