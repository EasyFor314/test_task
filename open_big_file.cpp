#include <iostream>
#include <fstream>
using namespace std;

class File_reader
{
private:
    static const int PAGE_SIZE=2;
    static const int PAGE_COUNT=1000;
    ifstream file_read;
    ofstream file_write;
    char buffer[PAGE_SIZE];
    string  page_buffer[PAGE_SIZE];
    int page_counter_line=0;
public:
    void load_file(string file_name)
    {
    file_read.open(file_name); 
    if (!file_read.is_open())
    {
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    } 
    }
    void ShowFirstPage(){
    OnLoadPage(0);
    ShowLoadPage();
    }

    void OnLoadPage(int found_number_page){
    cout<<"Load_page"<<endl;   
    int page_counter_line=0;
    int number_page=0;
    file_read.seekg(0);

    while(getline(file_read,page_buffer[page_counter_line]) )
    {   
        
       
        page_counter_line++;
        
        if(page_counter_line==PAGE_SIZE)
        {
           
            if (number_page==found_number_page)
            {      
                          
                break;
            }
            number_page++;
            page_counter_line=0;      
          
            ClearPage();        
        }
       
     
    }
    //  ShowLoadPage(page_counter_line);
    };
    void ShowLoadPage(int size_page){    
          
        for(int i=0;i<size_page;i++)
        {
            cout<<i<<"__"<<page_buffer[i]<<endl;
        }  

    }
     void ShowLoadPage(){    
            
        for(int i=0;i<PAGE_SIZE;i++)
        {
            cout<<i<<"__"<<page_buffer[i]<<endl;
        }  

    }
    void ClearPage(){
     
        for(int i=0;i<PAGE_SIZE;i++)
        {
           page_buffer[i]="";
        }  

    }
    void save_file(string file_name)
    {
        file_write.open(file_name);
        
       
    }
    void get_line(int number_line)
    {
        cout<< page_buffer[check_number(number_line)];
        
    }
    int check_number(int number_line)
    {
        if (number_line<=PAGE_SIZE)
        {
            return number_line;            
        }
        else {      
            int PageNumberLine=(number_line)/PAGE_SIZE;
            OnLoadPage(PageNumberLine);
            return number_line - (PAGE_SIZE*PageNumberLine);     
        }

    }
    void insert_line(int number_line,string line_to_insert)
    {}
    void replace_line(int number_line, string line_to_replace)
    {
       page_buffer[check_number(number_line)]= line_to_replace;
       ShowLoadPage(); 
    }
    void delete_line(int number_line){}
    void check_file_name(string file_name){

    }
    void delete_file_stack(){
        file_read.close();
        file_write.close();
    }

};
int main(){

    File_reader object_file_reader;
    object_file_reader.ShowFirstPage();
    object_file_reader.load_file("2.txt");
    object_file_reader.replace_line(3,"qwe");
   object_file_reader.get_line(3);
    return 0;
}