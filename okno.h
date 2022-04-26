#ifndef OKNO_H
#define OKNO_H

#include <QDialog>

namespace Ui {
class okno;
}

class okno : public QDialog
{
    Q_OBJECT

public:
    explicit okno(QWidget *parent = nullptr);
    ~okno();

private:
    Ui::okno *ui;
};

#endif // OKNO_H
