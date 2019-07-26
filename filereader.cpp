    #include "filereader.h"

    void    filereader::Load_file(string file_name)
            {
                name_file_saved=file_name;
                file_read.open(name_file_saved); 
                    if (!file_read.is_open())
                        {
                            cout << "Program terminating.\n";
                            exit(EXIT_FAILURE);
                        } 
                file_read.close();
            }

    void    filereader::ShowFirstPage()
            {
                OnLoadPage(0); 
            }

    void    filereader::OnLoadPage(int found_number_page){
        check_load_file();
        file_read.open(name_file_saved); 
        cout<<"Load_page number -  "<<found_number_page+1<<endl;  
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
            if (number_page<found_number_page){
                cout<<"Page not found";
            } 
            else {
                number_page_buffer=found_number_page;
                ShowLoadPage(page_counter_line);
            }
            
            file_read.close();
            
            };


    void    filereader::ShowLoadPage(int size_page){    
          
        for(int i=0;i<size_page;i++)
        {
            cout<<i<<"__"<<page_buffer[i]<<endl;
        }  

    }
     void   filereader::ShowLoadPage(){    
            
        for(int i=0;i<PAGE_SIZE;i++)
        {
            cout<<i<<"__"<<page_buffer[i]<<endl;
        }  

    }
    
    void    filereader::save_file(string file_name)
    {
        
    check_load_file();
    file_write.open(file_name);
    for(int i=0;i<savedfile.length();i++)
        {
            file_write<<savedfile[i];
        } 
    savedfile.clear();
    

    for(int i=0;i<savedfile.length();i++)
        {
            savedfile[i]='\0';
        }

    file_write.close();   
    }
    void    filereader::get_line(int number_line_found)
    {
        //cout<< page_buffer[check_number(number_line_found)];
        cashing_file();
        int number_line=0;
        string line="";
        for(int i=0;i<file.length();i++){
            line+=file[i];
            if(file[i]=='\n'){
                number_line++;
                
                
            if (number_line==number_line_found)
            {
                cout<<line<<endl;
            }
            line="";
            }

        }
         if(number_line<(number_line_found-1)){
             
              cout<<"Line not found"<<endl;
         }
    }
    
    void    filereader::insert_line(int number_line_insert,string line_to_insert)
    {   
        cashing_file();
        int number_line=0;
       
        for(int i=0;i<file.length();i++){
            savedfile+=file[i];
            
            if(file[i]=='\n'){
                number_line++;
                
            if (number_line==(number_line_insert-1))
            {
                savedfile+=line_to_insert+'\n';
                //cout<<"Line is inserted"<<endl;
            }
            }

        }
         if(number_line<(number_line_insert-1)){
              savedfile+=line_to_insert+'\n';
              //cout<<"Line is inserted"<<endl;
         }
         save_file(name_file_saved);

    }
    void    filereader::replace_line(int number_line_replace, string line_to_replace)
    {
       
    delete_line(number_line_replace);
    insert_line(number_line_replace,line_to_replace);
        
    }
    void    filereader::delete_line(int number_line_delete)
    {
        cashing_file();
         int number_line=0;
       
        for(int i=0;i<file.length();i++){
            if(number_line!=number_line_delete-1)
            {savedfile+=file[i];  
            }
            if(file[i]=='\n'){
                number_line++;               
            }
        }
        if(number_line<(number_line_delete-1)){
            cout<<"Fail deleted"<<endl;
        }
        else{
            //cout<<"Line is deleted"<<endl;
        }
        save_file(name_file_saved);
    }
   void    filereader::cashing_file(){
        check_load_file();
        file_read.open(name_file_saved); 
        file_read.seekg(0);
        file.clear();
       
        while(getline(file_read,page_buffer[page_counter_line]) )
            {   
                    file+= page_buffer[page_counter_line]+'\n';
                    
            }
        file_read.close();
    }
    void    filereader::delete_file_stack(){
        file_read.close();
        file_write.close();
    }

    void filereader::check_load_file(){
        if(name_file_saved.length()==0)
        {
            cout << "File no opened";
            exit(EXIT_FAILURE);
        }
    }
    int filereader::check_number(int number_line)
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
    void    filereader::cashe_page( string cashe[]){
        for(int i=0;i<PAGE_SIZE;i++)
        {
           cashe[i]= page_buffer[i];
        }  
       
    }
    void    filereader::ClearPage(){
     
        for(int i=0;i<PAGE_SIZE;i++)
        {
           page_buffer[i]="";
        }  

    }
    