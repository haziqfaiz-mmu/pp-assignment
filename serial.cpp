#include <iostream>
#include <string>
#include<vector>
#include <unordered_map>
#include <map>
#include <fstream>
#include <boost/algorithm/string.hpp>
//using namespace std;
void user_input(std::vector<std::string> &name_vector,int &max_length,int &min_length,char &order);
void read_file(std::fstream &file, std::string file_name);
std::map<std::string, int> words_counter(std::fstream &file);

int main() {

    std::vector<std::string> name_vector;
    int min_length,max_length;
    char order;
    std::fstream file; 
    std::string file_name;

    user_input(name_vector,max_length,min_length,order);

    words_counter(file);

    //Test input
    /* for(auto i:name_vector){
        std::cout<<i<<std::endl;
    }
    std::cout<<max_length<<" "<<min_length<<" "<<order; */

    file_name="gutenberg.org_cache_epub_100_pg100.txt";
    file.open(file_name);
    words_counter(file);
    

}

void user_input(std::vector<std::string> &name_vector,int &max_length,int &min_length,char &order){

    int file_count;
    std::string file_name;

    std::cout<<"Enter the number of the textfile: ";
    std::cin>> file_count;
    std::cout<<std::endl;
    for(int i=0;i<file_count;i++){
        std::cout<<"Enter the path of text file "<<i+1<<": ";
        std::cin>>file_name;
        name_vector.push_back(file_name);
    }

    std::cout<<"Enter the minimum length of words to consider: ";
    std::cin>>min_length;

    std::cout<<"Enter the maximum length of words to consider: ";
    std::cin>>max_length;

    std::cout<<"Enter \'a\' to sort alphabetcally or \'n\' to sort by  frequency: ";
    std::cin>>order;

}

std::map<std::string, int> words_counter(std::fstream &file){
    std::map<std::string, int> map;
    std::string word;

    while (file>>word){
        /* char end = word.back();
        if (end==','||end=='.'||end==')'||end=='\"'){

            word.pop_back();
        }

        char start = word.front();
        if (start==','||start=='.'||start==')'||start=='\"'){

            word.erase(0,1);
        } */

        boost::erase_all(word, ",");
        boost::erase_all(word, ".");
        boost::erase_all(word, "(");
        boost::erase_all(word, ")");
        boost::erase_all(word, "[");
        boost::erase_all(word, "]");
        boost::erase_all(word, "-");
        boost::erase_all(word, "_");


        for (auto & c: word) c = tolower(c);

        std::cout<<word<<std::endl;
    }


    return map;

}