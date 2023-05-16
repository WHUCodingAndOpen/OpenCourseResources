#ifndef USER_H
#define USER_H

#include <QWidget>
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    int i=2;
    int j=2;
private slots:
    void ShowUserInfo(int,int);
    void on_lineEditUserName_editingFinished();
    void on_lineEditUserTel_editingFinished();
    void on_lineEditUserParkingCarID_editingFinished();
    void ShowUserR();
    void ShowUserC();
    void UserRup();
    void UserCup();
    void UserRclear();
    void UserCclear();
    void on_dateEditRDate_dateChanged(const QDate &date);
    void on_textEditRDetail_textChanged();
    void on_lineEditR_textChanged(const QString &arg1);

    void on_dateEditCDate_dateChanged(const QDate &date);

    void on_lineEditC_textChanged(const QString &arg1);

    void on_textEditCDetail_textChanged();

private:
    Ui::User *ui;
};

#endif // USER_H
