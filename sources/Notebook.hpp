#ifndef BOARD_CPP
#define BOARD_CPP

#include "Direction.hpp"
#include <map>
#include <string>

struct Bound {
    // public:
     int min_x;
     int size_x;
     int min_y;
     int size_y;
    Bound() {
        size_x = 0;
        size_y = 0;
        min_x = (int long)(-1);
        min_y = (int long)(-1);
    }
};
struct defChar{
    char d = '_';
};
namespace ariel {
    class Notebook {
    private:
        static char empty_val;
        Bound bound;
        std::map<int, std::map<int, defChar[100]>> noteBook;
        void setCharAt( int page,  int x,  int y, char c);
        char charAt( int page,  int x,  int y) const;
        void updateBound(int start_x, int start_y, int size_x, int size_y);

    public:
     
        void write(int page, int row, int column, Direction direction, const std::string &message);
       
        std::string read( int page, int row, int column, Direction direction,int length);
        void erase( int page, int row, int column, Direction direction, int length);

       
        void show(int pages) const;

    };
} 

#endif
