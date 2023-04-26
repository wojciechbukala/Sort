#include <iostream>
#include <algorithm>
#include "merge_sort.hpp"
#include "quicksort.hpp"
#include "bucketsort.hpp"

using namespace std;


int main()
{
    cout << "Project name: SORT" << endl;

    float T[100];// = {1.2, 1.3, 3.4, 5.5, 5.2, 2.1, 2.4, 7.1, 3.7, 10};

    float a = 0;

    for(int i =0; i<100; i++)
    {
        T[i] = a;
        //cout << T[i] << " ";
        a += 0.1;
    }

    srand(time(0));
    std::random_shuffle(&T[0], &T[99]);

    bucket_sort(T, 100, 10);
    for (int i=0; i<100 ; i++)
    {
        cout << T[i] << " ";
    }
    cout << endl;
    

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



/* 
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


template <typename T>
void bucket_sort(T* array, int n, int max_value) 
{
    T** buckets = new T*[max_value];

    for(int i=0; i<max_value; ++i)
    {
        buckets[i] = nullptr;
    }

    for(int i=0; i<n; ++i)
    {
        int iter = array[i];
        if(buckets[iter] == nullptr)
        {
            buckets[iter] = new T[1];
            buckets[iter][0] = array[i];
        }
        else
        {
            int length = 0;
            while(buckets[iter][length] != 0)
            {
                length++;
            }
            T* tmp = new T[length+1];
            
            for(int j=0; j<length; ++j)
            {
                tmp[j] = buckets[iter][j];
            }
            tmp[length] = array[i];
            delete[] buckets[iter];
            buckets[iter] = tmp;
/*              for(int j=0; j<=length; ++j)
            {
                std::cout << buckets[iter][j] << " ";
            }
            std::cout << std::endl;  */
/*         }
            
    }

    for(int i=0; i<max_value; ++i)
    {
        if(buckets[i] != nullptr)
        {
            int size =  sizeof(buckets[i]) / sizeof(buckets[0]);
            quicksort(buckets[i], 0, size);
        }
    }

    int ii=0;
    for(int i=0; i<max_value; ++i)
    {
        if(buckets[i] != nullptr)
        {
            int length = 0; 
            while(buckets[i][length] != 0 && length < n)
            {
                array[ii] = buckets[i][length];
                ++ii;
                ++length;
            }
        delete[] buckets[i];
        }
    }
}

Przy wywołaniu z tablicą dataset1 1000 elementów z ratingami od 0 do 10 w podany sposób występuje segmentation fault.
bucket_sort(dataset1, size, 10);  */