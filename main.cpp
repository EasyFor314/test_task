
#include "filereader.h"

using namespace std;

int main(int argc, char *argv[]){
    filereader object_file_reader;
    if (argv[1]){
    object_file_reader.Load_file(argv[1]);
    object_file_reader.ShowFirstPage();
    object_file_reader.replace_line(rand() % 6 +1 ,"first replace");
    object_file_reader.replace_line(rand() % 6 +1 ,"second replace");
    }
    else cout<<"Pls add name file: a.out 2.txt "<<endl;
    return 0;
}