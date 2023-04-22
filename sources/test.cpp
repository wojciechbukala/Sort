#include <iostream>
#include <algorithm>
#include "merge_sort.hpp"
#include "quicksort.hpp"
#include "introspectivesort.hpp"

using namespace std;


int main()
{
    cout << "Project name: SORT" << endl;

    int T[40];
    for (int i = 0; i < 20; i++)
    {
        T[2*i] = i;
        T[2*i +1] = i;
    }
    srand(time(0));
    std::random_shuffle(&T[0], &T[39]);


    for(int i = 0; i< 40 ; ++i)
    {
        cout << T[i] << " ";
    }
    cout << endl;

    quicksort<int>(T, 0, 39);

    for (int i = 0; i < 40; i++)
    {
        cout << T[i] << " ";
    }
    

    return 0;
} 



/* struct record
{   
    // title.basic.tsv.gz
    std::string identifier;
    std::string titleType;
    std::string primaryTitle;
    bool isAdult;
    short startYear;
    short endYear;
    uint runtimeMinutes;
    std::string genres;

    // title.ratings.tsv.gz
    std::string averageRating;
    int numVotes;

    record(std::string ID = "", std::string TITLE = "", std::string pTITLE = "",
    bool ADULT = 0, short sYEAR = 0, short eYEAR = 0, uint rMIN = 0,
    std::string gen = "", int aRATING = 0, int numVOTES = 0)
    {
        std::string identifier = ID;
        std::string titleType = TITLE;
        std::string primaryTitle = pTITLE;
        bool isAdult = ADULT;
        short startYear = sYEAR;
        short endYear = eYEAR;
        uint runtimeMinutes = rMIN;
        std::string genres = gen;

        // title.ratings.tsv.gz
        int averageRating = aRATING;
        int numVotes = numVOTES;
    }

    void view()
    {
        std::cout << identifier << " " << primaryTitle << " " << averageRating << std::endl;
    }
};


/* int main()
{
    std::ifstream infile_basic;
    std::ifstream inflie_ratings;

    infile_basic.open("title_basic.tsv");
    inflie_ratings.open("title_ratings.tsv");

    std::string line = "";

    //std::string film_list[1000];

    

    if(inflie_ratings.good() && infile_basic.good())
    {
        std::getline(infile_basic, line);
        std::getline(inflie_ratings, line);
        line.clear();
        int j = 0;
        std::string id = "";

        record* dataset = new record[1000];
        for(int i=0; i<1000; ++i)
        {
            std::getline(infile_basic, line);
            std::string cell = "";
            std::istringstream iss1(line);
            j = 0;
            while (std::getline(iss1, cell, '\t'))
            {
                if(j == 0) id = cell;
                if(j == 2) dataset[i].title = cell;
                j++;
            }
            line.clear();
            cell.clear();

            std::getline(inflie_ratings, line);
            std::istringstream iss2(line);
            j = 0;
            while (std::getline(iss2, cell, '\t'))
            {
                if(j == 0 && cell != id) throw(runtime_error("Niezgodnosc id"));
                if(j == 1) dataset[i].rating = stof(cell);
                j++;
            }
            line.clear();
            cell.clear();
            id.clear();
            cout << i << ". ";
            dataset[i].view();
        }
    
    delete[] dataset;  
    }
    else
    {
        cout << "Blad otwrcia pliku" << endl;
    } */

/* int main()
{
    std::string s = "tt000001";
    cout << s << endl;
    cout << s.substr(2) << endl;
    

    cout << stoi(s.substr(2)) << endl; 

    return 0;
} */