#ifndef DESCRIPTIONS_H
#define DESCRIPTIONS_H
#include<QString>

class Descriptions
{
private:
    QString file_tab_desc;
    QString manual_tab_desc;

    QString single_field_desc;
    QString multi_field_desc;
public:
    Descriptions();

    QString get_file_tab_desc();
    QString get_manual_tab_desc();

    QString get_single_field_desc();
    QString get_multi_field_desc();
};

#endif // DESCRIPTIONS_H
