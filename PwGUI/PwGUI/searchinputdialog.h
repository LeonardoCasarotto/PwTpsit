#ifndef SEARCHINPUTDIALOG_H
#define SEARCHINPUTDIALOG_H

#include <QInputDialog>
#include <QCheckBox>
#include <QLabel>


class SearchInputDialog : public QInputDialog
{
public:
    SearchInputDialog(QWidget* parent = nullptr);

    static bool getCheckboxValue(QWidget* parent, int searchBy, QString& textValue, bool& checkboxValue);

private:
    QCheckBox* m_checkbox;
    QLabel* m_spacing;



};

#endif // MYINPUTDIALOG_H
