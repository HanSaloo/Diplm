#include <QtWidgets>
#include <QtSql>

#include "window.h"

//! [Set up widgets]
Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setupModel();

    nameLabel = new QLabel(tr("Na&me:"));
    nameEdit = new QLineEdit();
    addressLabel = new QLabel(tr("&Address:"));
    addressEdit = new QTextEdit();
    costLabel = new QLabel(tr("Co&st:"));//
    costEdit = new QLineEdit(); //
    typeLabel = new QLabel(tr("&Status:"));
    typeComboBox = new QComboBox();
    nextButton = new QPushButton(tr("&Next"));
    previousButton = new QPushButton(tr("&Previous"));

    nameLabel->setBuddy(nameEdit);
    addressLabel->setBuddy(addressEdit);
    costLabel->setBuddy(costEdit); //
    typeLabel->setBuddy(typeComboBox);
//! [Set up widgets]

//! [Set up the mapper]
    QSqlTableModel *relModel = model->relationModel(typeIndex);
    typeComboBox->setModel(relModel);
    typeComboBox->setModelColumn(relModel->fieldIndex("description"));

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(nameEdit, model->fieldIndex("name"));
    mapper->addMapping(addressEdit, model->fieldIndex("address"));
    mapper->addMapping(costEdit, model->fieldIndex("cost"));
    mapper->addMapping(typeComboBox, typeIndex);
//! [Set up the mapper]

//! [Set up connections and layouts]
    connect(previousButton, &QPushButton::clicked,
            mapper, &QDataWidgetMapper::toPrevious);
    connect(nextButton, &QPushButton::clicked,
            mapper, &QDataWidgetMapper::toNext);
    connect(mapper, &QDataWidgetMapper::currentIndexChanged,
            this, &Window::updateButtons);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(nameLabel, 0, 0, 1, 1);
    layout->addWidget(nameEdit, 0, 1, 1, 1);
    layout->addWidget(nextButton, 0, 2, 1, 1);
    layout->addWidget(previousButton, 0, 3, 1, 1);
    layout->addWidget(costLabel, 1, 0, 1, 1);
    layout->addWidget(costEdit, 1, 1, 1, 1);
    layout->addWidget(addressLabel, 2, 0, 1, 1);
    layout->addWidget(addressEdit, 2, 1, 1, 1);
    layout->addWidget(typeLabel, 3, 0, 1, 1);
    layout->addWidget(typeComboBox, 3, 1, 1, 1);

    layout->setContentsMargins(20,20,20,20);
    layout->setSpacing(10);

    setLayout(layout);

    setWindowTitle(tr("Databases"));
    mapper->toFirst();
}
//! [Set up connections and layouts]

//! [Set up the main table]
void Window::setupModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(0, tr("Cannot open database"),
            tr("Unable to establish a database connection.\n"
               "This example needs SQLite support. Please read "
               "the Qt SQL driver documentation for information how "
               "to build it."), QMessageBox::Cancel);
        return;
    }

    QSqlQuery query;
    query.exec("create table person (id int primary key, "
               "name varchar(20), address varchar(200),cost varchar(10) , typeid int)");

    query.exec("insert into person values(1, 'Іванович В.В', "
               "'<qt>вул Шевченка<br/>20 буд 4</qt>', 2500, 101)");

    query.exec("insert into person values(2, 'Петренко О.Д', "
               "'<qt>Л. Українки<br/>41 буд 1"
               "<br/>Service City</qt>',2102, 102)");

//! [Set up the main table]

//! [Set up the address type table]
    query.exec("create table status (id int, description varchar(20))");
    query.exec("insert into status values(101, 'Сплачено')");
    query.exec("insert into status values(102, 'Не сплачено')");
    query.exec("insert into status values(103, 'Очікується')");

    model = new QSqlRelationalTableModel(this);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    typeIndex = model->fieldIndex("typeid");

    model->setRelation(typeIndex,
           QSqlRelation("status", "id", "description"));
    model->select();
}
//! [Set up the address type table]

//! [Slot for updating the buttons]
void Window::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
}
//! [Slot for updating the buttons]
