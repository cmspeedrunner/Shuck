#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <locale>
#include <codecvt>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
using std::string;

string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}




void runshuck(std::string command){
    using std::string;
    using std::cout;
    using std::min;
    using std::max;
    using std::sqrt;

    wchar_t wbuffer[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, wbuffer);
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wbuffer, -1, NULL, 0, NULL, NULL);
    std::string currentPath(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, wbuffer, -1, &currentPath[0], size_needed, NULL, NULL);

    command = command.substr(6,command.length());
    if(command == "help"){
        cout<<MAGENTA<<"-----"<<CYAN<<"Shuck Commands"<<MAGENTA<<"-----\n";
        cout<<GREEN<<"help: "<<CYAN<<"Displays all the Shuck commands"<<GREEN<<"\n";
        cout<<GREEN<<"read: "<<CYAN<<"Displays a files content"<<GREEN<<"\n";
        cout<<GREEN<<"head: "<<CYAN<<"Displays the first 10 lines of a file"<<GREEN<<"\n";
        cout<<GREEN<<"open: "<<CYAN<<"Opens a given url or file"<<GREEN<<"\n";
        cout<<GREEN<<"ls: "<<CYAN<<"Lists all folders, and their contents."<<GREEN<<"\n";
        cout<<GREEN<<"search: "<<CYAN<<"Searches a query on google"<<GREEN<<"\n";
        cout<<GREEN<<"quit: "<<CYAN<<"Exits shuck"<<GREEN<<"\n";
    }
    if(command.substr(0, 4) == "read"){
        string filename = command.substr(5, command.length());
        string line;
        int linenum = 0;
        std::ifstream filecontent(filename);
        if(filecontent.is_open()){
            cout<<MAGENTA<<"\n------>"<<CYAN<<filename<<MAGENTA<<"<------\n";
            while(std::getline(filecontent, line)){
  
                cout<<GREEN<<linenum<<": "<<CYAN<<line<<"\n";
                linenum++;
            }
            
            filecontent.close();
        }
    } else
    if(command.substr(0, 4) == "head"){
        string filename = command.substr(5, command.length());
        string line;
        int linenum = 0;
        std::ifstream filecontent(filename);
        if(filecontent.is_open()){
            cout<<MAGENTA<<"\n------>"<<CYAN<<filename<<MAGENTA<<"<------\n";
            while(std::getline(filecontent, line)){
                if(linenum < 11){
                cout<<GREEN<<linenum<<": "<<CYAN<<line<<"\n";
                linenum++;
            }}
            filecontent.close();
        }
    }else
    if(command.substr(0, 4) == "open"){
        std::string url = command.substr(5, command.length());
        
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wideurl = converter.from_bytes(url);

        ShellExecuteW(0, L"open", wideurl.c_str(), 0, 0, SW_SHOW);
    }else
    if(command.substr(0, 2) == "ls"){

        system("tree /f");
    }else
    if(command.substr(0, 6) == "search"){

        std::string query = command.substr(6);  
        for (char& c : query) { 
            if (c == ' ') {
                c = '+';  
            }
        }
    string formattedQuery = query.substr(1,query.length());
    formattedQuery = "start https://www.google.com/search?q="+formattedQuery;
    system(formattedQuery.c_str());
    }else
    if(command.substr(0, 4) == "quit"||command.substr(0, 4) == "exit"){
        cout<<RESET;
        exit(1);
    }else

    if(command.substr(0, 3)=="hyp"){
        double a;
        double b;

        double aSq;
        double bSq;

        double c;
        string buffer = " ";
        string bRepr = "_";

        cout<<MAGENTA<<"Enter A: "<<CYAN;
        std::cin >> a;
        cout<<MAGENTA<<"Enter B: "<<CYAN;
        std::cin >> b;
        aSq = pow(a, 2);
        bSq = pow(b, 2);
        c = aSq+bSq;
        c = sqrt(c);
        cout<<MAGENTA<<"\n<---"<<CYAN<<"Triangle Representation"<<MAGENTA<<"--->\n"<<BLUE<<"|"<<GREEN<<"\\\n";
        for(int i = 1; i < a-1; i++){
            int MaxBuffer = min((double)i, b);
            cout <<BLUE<<"|"<<RESET;
            cout <<(buffer * MaxBuffer);
            cout <<GREEN<<"\\\n"<<RESET;
        }
        cout <<BLUE<<"|"<<RESET;
        cout <<MAGENTA<<(bRepr * b)<<RESET;
        cout <<GREEN<<"\\"<<CYAN;
        cout<<BLUE<<"\nA squared"<<CYAN<<" + "<<MAGENTA<<"B squared"<<CYAN<<" = "<<GREEN<<"C squared";
        cout<< "\n\nHypotenuse "<<CYAN<<"= "<<GREEN<<c<<"\n";
        cout<<MAGENTA<<"<-------------------------------->\n";
  
    }
}
int main() {
    using std::cout;
    using std::cin;
    using std::string;
    using std::getline;
    using std::ws;
    system("");
    cout<<MAGENTA<<"-"<<CYAN<<"Shuck"<<MAGENTA<<"-"<<"\nV: "<<CYAN<<"0.1\n"<<RESET;
    bool readLoop = true;

    while(readLoop){
        string command;
        cout<<MAGENTA<<"Shuck"<<BLUE">"<<CYAN;
        getline(cin>>ws, command);
        if(command.find("shuck") != string::npos){
            
            if(command != "shuck"){
                runshuck(command);
            }
            if(command == "shuck"){
                cout<<MAGENTA<<"-----"<<CYAN<<"Shuck Commands"<<MAGENTA<<"-----\n";
                cout<<GREEN<<"help: "<<CYAN<<"Displays all the shuck commands"<<GREEN<<"\n";
                cout<<GREEN<<"read: "<<CYAN<<"Displays a files content"<<GREEN<<"\n";
                cout<<GREEN<<"head: "<<CYAN<<"Displays the first 10 lines of a file"<<GREEN<<"\n";
                cout<<GREEN<<"open: "<<CYAN<<"Opens a given url or file"<<GREEN<<"\n";
                cout<<GREEN<<"ls: "<<CYAN<<"Lists all folders, and their contents."<<GREEN<<"\n";
                cout<<GREEN<<"search: "<<CYAN<<"Searches a query on google"<<GREEN<<"\n";
                cout<<GREEN<<"quit: "<<CYAN<<"Exits shuck"<<GREEN<<"\n";
            }
        }else{
            char *com = command.data();
            system(com);
        }
    }
    return 0;
}
