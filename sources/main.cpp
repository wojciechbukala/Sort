#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "merge_sort.hpp"
#include "quicksort.hpp"
#include "introspectivesort.hpp"

using namespace std;

struct record
{   
    // title.basic.tsv.gz
    std::string title;
    std::string id;

    // title.ratings.tsv.gz
    float rating;

    inline record(std::string t = "", float r = 0)
    {
        title = t;
        rating = r;
    }

    inline void view() const
    {
        std::cout << "Title: " << title << ", Rating: " << rating << " Id: "<< id << std::endl;
    }

    inline bool operator < (record other_record)
    {
        return rating < other_record.rating;
    }

    inline bool operator > (record other_record)
    {
        return rating > other_record.rating;
    }

    inline bool operator == (record other_record)
    {
        return rating == other_record.rating;
    }
};

struct filtr_stats
{
    uint empty_lines = 0;
    uint id_conflict = 0;
};

bool filter(std::string infile_name, std::string outfile_name, uint size)
{
    std::ifstream infile;
    infile.open(infile_name);

    if(!infile.good())
    {
        return 0;
    }
    
    std::ofstream outfile;
    outfile.open(outfile_name);
    if(!outfile.good())
    {
        infile.close();
        return 0;
    }

    uint iter = 0;
    std::string line;
    while(std::getline(infile, line) && iter < size)
    {
        if(!line.empty())
        {
            outfile << line << std::endl;
            ++iter;
        }
    }

    infile.close();
    outfile.close();

    return 1;
}


int main()
{
    if(!filter("title_basic.tsv", "title_basic_filtered.tsv", 30000))
    {
        std::cerr << "Error filtration.";
        return 0;
    }

    if(!filter("title_ratings.tsv", "title_ratings_filtered.tsv", 2000))
    {
        std::cerr << "Error filtration.";
        return 0;
    }

    std::ifstream infile_basic;
    std::ifstream inflie_ratings;

    infile_basic.open("title_basic_filtered.tsv");
    inflie_ratings.open("title_ratings_filtered.tsv");

    std::string line1 = "", line2 = "";


    if(inflie_ratings.good() && infile_basic.good())
    {
        filtr_stats stats_basic, stats_ratings;
        std::getline(infile_basic, line1);
        std::getline(inflie_ratings, line2);
        line1.clear();
        line2.clear();

        record* dataset = new record[100];
        for(int i=0; i<100; ++i)
        {
            std::string id1 = "", id2 = "", cell = "",
            t = "", r = "";

            std::getline(infile_basic, line1);
            std::istringstream iss1(line1);

            std::getline(inflie_ratings, line2);
            std::istringstream iss2(line2);


            if(std::getline(iss1, cell, '\t'))
            {
                id1 = cell;
            }

            if(std::getline(iss2, cell, '\t'))
            {
                id2 = cell;
            }
            
            if(id1 != id2)
            {
                while(stoi(id1.substr(2)) < stoi(id2.substr(2)))
                {
                    std::getline(infile_basic, line1);
                    std::istringstream iss1(line1);
                    if(std::getline(iss1, cell, '\t'))
                    {
                        id1 = cell;
                    }
                }

                while(stoi(id1.substr(2)) < stoi(id2.substr(2)))
                {
                    std::getline(inflie_ratings, line2);
                    std::istringstream iss2(line2);
                    if(std::getline(iss2, cell, '\t'))
                    {
                        id2 = cell;
                    }
                }
            }
            dataset[i].id = id2;
            std::getline(iss2, cell, '\t');
            dataset[i].rating = stof(cell);
            std::getline(iss1, cell, '\t');
            std::getline(iss1, cell, '\t');
            dataset[i].title = cell;
            cell.clear();
            line1.clear();
            line2.clear();
            std::cout << i << ". ";
            dataset[i].view();
        }
    

    quicksort(dataset, 0, 99);

    cout << endl << "Posortowane." << endl;
    for(int i=0 ; i<100 ; ++i)
    {
        std::cout << i << ". ";
        dataset[i].view();
    }
    delete[] dataset;  
    }
    else
    {
        cout << "Blad otwrcia pliku" << endl;
    }





    return 0;
}