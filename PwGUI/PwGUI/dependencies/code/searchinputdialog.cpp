#include "searchinputdialog.h"


SearchInputDialog::SearchInputDialog(QWidget* parent)
    : QInputDialog(parent)
{
    m_spacing = new QLabel("\n\n\n");
    m_checkbox = new QCheckBox("Cerca nelle \nsottocartelle", this);
}

bool SearchInputDialog::getCheckboxValue(QWidget* parent, int src, QString& textValue, bool& checkboxValue)
{
    SearchInputDialog dialog(parent);
    switch(src){
    case 0: // name

        dialog.setLabelText("\n\nInserire il nome del file:");
        dialog.setWindowTitle("Cerca file per nome");
        break;
    case 1: //extension
        dialog.setLabelText("\n\nInserire l'estensione del file, senza il punto:");
        dialog.setWindowTitle("Cerca file per estensione");
        break;
    case 2: //text in files
        dialog.setLabelText("\n\nInserire il testo :");
        dialog.setWindowTitle("Cerca file per testo");
        break;

    }







    bool ok = dialog.exec();
    if (ok) {
        textValue = dialog.textValue();
        checkboxValue = dialog.m_checkbox->isChecked();
    }

    return ok;
}
