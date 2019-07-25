#ifndef FILEREADER
#define FILEREADER

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class filereader{
private:
    static const int PAGE_SIZE=256;
    ifstream file_read;
    ofstream file_write;
    string  page_buffer[PAGE_SIZE];
    string name_file_saved;
    string file;
    string savedfile;
    int number_page_buffer;
    int page_counter_line=0;
public:
    void load_file(string file_name);
    void ShowFirstPage();
    void cashing_file();
    void OnLoadPage(int found_number_page);
    void ShowLoadPage(int size_page);
    void ShowLoadPage();
    void ClearPage();
    void cashe_page( string cashe[]);
    void save_file(string file_name);
    void get_line(int number_line);
    int check_number(int number_line);
    void insert_line(int number_line_insert,string line_to_insert);  
    void replace_line(int number_line_replace, string line_to_replace);
    void delete_line(int number_line_delete);
    void delete_file_stack();
};
#endif