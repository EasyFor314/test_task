
#include "filereader.h"

using namespace std;

int main(){
    filereader object_file_reader;
    object_file_reader.load_file("2.txt");
    object_file_reader.ShowFirstPage();
    //object_file_reader.delete_line(3);
   // object_file_reader.delete_line(4);
    //object_file_reader.save_file("2.txt");
    object_file_reader.replace_line(3,"qwe");
   /*  object_file_reader.save_file("3.txt");
   object_file_reader.get_line(3);*/
    return 0;
}