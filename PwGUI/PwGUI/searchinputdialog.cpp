#include "searchinputdialog.h"

SearchInputDialog::SearchInputDialog(QWidget* parent)
    : QInputDialog(parent)
{
    m_spacing = new QLabel("\n\n\n");
    m_checkbox = new QCheckBox("Cerca nelle \nsottocartelle", this);
}

bool SearchInputDialog::getCheckboxValue(QWidget* parent, QString& textValue, bool& checkboxValue)
{
    SearchInputDialog dialog(parent);


    dialog.setLabelText("\n\nEnter text:");


    bool ok = dialog.exec();
    if (ok) {
        textValue = dialog.textValue();
        checkboxValue = dialog.m_checkbox->isChecked();
    }

    return ok;
}
