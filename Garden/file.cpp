#include "file.h"


File::File()
{
    sample_path = "sample_files";
}

void File::set_current_file(QString file)
{
    current_file = file;
}

QString File::get_current_file(){
    return current_file;
}
