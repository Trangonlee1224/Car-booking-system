#ifndef CODE2_H
#define CODE2_H

#include <QDialog>

namespace Ui {
class code2;
}

class code2 : public QDialog
{
    Q_OBJECT

public:
    explicit code2(QWidget *parent = nullptr);
    ~code2();

private:
    Ui::code2 *ui;
};

#endif // CODE2_H
