#ifndef FILEREADER
#define FILEREADER

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class filereader{
private:
    static const int PAGE_SIZE=256; // Размер страницы в строчках
    ifstream file_read; 
    ofstream file_write;
    string  page_buffer[PAGE_SIZE];// буфер отображаемой страницы
    string name_file_saved; // имя загруженного файла
    string file;    // кэш файла
    string savedfile; //кэш изменения
    int number_page_buffer; //номер загруженной страницы
    int page_counter_line=0;
public:
    void Load_file(string file_name); // загрузка страницы
    void ShowFirstPage();   // отображение первой страницы
    void OnLoadPage(int found_number_page); // загрузка определенной страницы
    void ShowLoadPage(int size_page);   //отображение загруженной страницы, определенного размера
    void ShowLoadPage();    //отображение загруженной страницы размеро PAGE_SIZE
    void save_file(string file_name); //сохранение файла
   
    
   
    void get_line(int number_line); // вывод строки
    void insert_line(int number_line_insert,string line_to_insert);  // вставка строки
    void replace_line(int number_line_replace, string line_to_replace); // замена строки
    void delete_line(int number_line_delete); //удаление строки

protected:
    void cashing_file(); //кэширование файла для проведения изменений
    void delete_file_stack(); // очистка файловых потоков
    void cashe_page( string cashe[]); // кэширование страницы   
    int check_number(int number_line); // номер строки на определенной странице 
    void check_load_file(); // проверка загрузки файла
    void ClearPage(); // очистка буфера загруженной страницы
};
#endif