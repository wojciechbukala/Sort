#ifndef MAIN_FUNCTIONS
#define MAIN_FUNCTIONS

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "merge_sort.hpp"
#include "quicksort.hpp"
#include "bucketsort.hpp"

using namespace std::chrono;

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

    inline bool operator != (int num)
    {
        return rating != num;
    }

    explicit operator int()
    {
        return int(rating);
    }
};

struct filter_stats
{
    uint empty_lines = 0;
    uint id_conflict = 0;
};

bool filter(std::string infile_name, std::string outfile_name, uint size)
{
    std::ifstream infile;
    infile.open(infile_name);
    filter_stats stats;

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

std::string find(std::string id, uint size, record* array)
{
    uint left = 0, right = size - 1;

    int to_find = stoi(id.substr(2));

    while(left <= right)
    {
        int pivot = (left + right)/2;

        if(stoi(array[pivot].id.substr(2)) == to_find)
        {
        return array[pivot].title;
        }

        if(stoi(array[pivot].id.substr(2)) > to_find)
        {
            right = pivot - 1;
        }
        else 
        {
            left = pivot + 1;
        }
    }


}

enum Option 
{
    //QUICKSORT, 
    INTROSORT, 
    MERGESORT
};

struct time_test
{
    struct tests
    {
        uint array_size;
        uint time;
    };

    tests test_data[15];
};


void program(uint size, char option, std::string file_to_save = "none")
{
    if(!filter("title_basic.tsv", "title_basic_filtered.tsv", size*4))
    {
        std::cerr << "Error filtration.";
        return;
    }

    if(!filter("title_ratings.tsv", "title_ratings_filtered.tsv", size*2))
    {
        std::cerr << "Error filtration.";
        return;
    }

    std::ifstream infile_ratings;

    infile_ratings.open("title_ratings_filtered.tsv");

    std::string line = "";
    record* dataset1 = new record[size];
    record* dataset2 = new record[3*size];


    if(infile_ratings.good())
    {
        std::getline(infile_ratings, line);
        line.clear();

        for(uint i=0; i<size; ++i)
        {
            std::string id = "", cell = "",
            t = "", r = "";

            std::getline(infile_ratings, line);
            std::istringstream iss(line);


            if(std::getline(iss, cell, '\t'))
            {
                id = cell;
            }
            
            dataset1[i].id = id;
            std::getline(iss, cell, '\t');
            dataset1[i].rating = stof(cell);
            cell.clear();
            line.clear();
        }
        infile_ratings.close();
    }
    else
    {
        throw std::runtime_error("Blad otwarcia pliku title_ratings_filtred.tsv");
    }


    std::ifstream infile_basic;
    infile_basic.open("title_basic_filtered.tsv");

    if(infile_basic.good())
    {
        std::getline(infile_basic, line);
        line.clear();

        for(uint i=0; i<3*size; ++i)
        {
            std::string id = "", cell = "";
            std::getline(infile_basic, line);
            std::istringstream iss(line);


            if(std::getline(iss, cell, '\t'))
            {
                id = cell;
            }
            
            dataset2[i].id = id;
            std::getline(iss, cell, '\t');
            std::getline(iss, cell, '\t');
            dataset2[i].title = cell;
            cell.clear();
            line.clear();
        }
        infile_basic.close();
    }
    else
    {
        throw std::runtime_error("Blad otwarcia pliku title_basic_filtred.tsv");
    }

    switch(option)
    {
        case 'q' : 
        {
            auto start_qsort = high_resolution_clock::now();
            quicksort(dataset1, 0, size-1);
            auto stop_qsort = high_resolution_clock::now();
            auto duration_qsort = duration_cast<milliseconds>(stop_qsort-start_qsort);
            std::cout << "Quicksort_" << size << ": " << duration_qsort.count() << std::endl;
            break;
        }

        case 'b' :
        {
            auto start_bsort = high_resolution_clock::now(); 
            bucket_sort(dataset1, size, 50);
            auto stop_bsort = high_resolution_clock::now();
            auto duration_bsort = duration_cast<milliseconds>(stop_bsort-start_bsort);
            std::cout << "Bucketsort_" << size << ": " << duration_bsort.count() << std::endl;
            break;
        }

        case 'm' :
        {
            auto start_msort = high_resolution_clock::now(); 
            merge_sort(dataset1, 0, size-1);
            auto stop_msort = high_resolution_clock::now();
            auto duration_msort = duration_cast<milliseconds>(stop_msort-start_msort);
            std::cout << "Mergesort_" << size << ": " << duration_msort.count() << std::endl;
            break;
        } 

        default:
        throw std::runtime_error("Wrong sorting option");
        break;

    }

    if(file_to_save != "none")
    {
        std::ofstream outfile;
        outfile.open(file_to_save);
        if(!outfile.good())
        {
            throw std::runtime_error("Blad otwarcia pliku do zapisu.");
        }
        for(uint i=0; i<size; ++i)
        {
            dataset1[i].title = find(dataset1[i].id, 3*size, dataset2);
            outfile << i+1 << '\t' << dataset1[i].title << '\t' << dataset1[i].rating << std::endl;
        }
    }
    


    delete[] dataset1;
    delete[] dataset2;


    return;
}


#endif