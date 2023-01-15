#include "file.h"

File::File()
{
    current_file = "";
}

void File::set_current_file(QString file)
{
    current_file = file;
}

QString File::get_current_file(){
    return current_file;
}
