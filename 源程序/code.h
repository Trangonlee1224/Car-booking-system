#ifndef CODE_H
#define CODE_H

#include <QWidget>

namespace Ui {
class code;
}

class code : public QWidget
{
    Q_OBJECT

public:
    explicit code(QWidget *parent = nullptr);
    ~code();

private:
    Ui::code *ui;
};

#endif // CODE_H
