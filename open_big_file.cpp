#include <iostream>
#include <fstream>
using namespace std;

class File_reader
{
private:
    static const int PAGE_SIZE=50;
    static const int PAGE_COUNT=1000;
    ifstream file_in;
    char buffer[PAGE_SIZE];
    string page_buffer[PAGE_COUNT][PAGE_SIZE];
public:
    void load_file(string file_name)
    {
    file_in.open(file_name);
    int number_line_page=0;
    int number_page=0;
    while(getline(file_in,page_buffer[number_page][number_line_page]))
    {   
        cout<<page_buffer[number_page][number_line_page]<<endl;
        number_line_page++;
        if(number_line_page==PAGE_SIZE){
            number_page++;
            number_line_page=0;
            cout<<"PAGE_"<<number_page<<endl;
        }
    }

        
    }
    void save_file(string file_name)
    {}
    void get_line(int number_line)
    {}
    void insert_line(int number_line,string line_to_insert)
    {}
    void replace_line(int number_line, string line_to_replace)
    {}
    void delete_line(int number_line){}

};
int main(){

    File_reader object_file_reader;
    object_file_reader.load_file("1.txt");
   
    return 0;
}