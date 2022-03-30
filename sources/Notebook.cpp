//
// Created by cheer on 3/19/2022.
//

#include "Notebook.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
const int maxSym = 100;
namespace ariel {

    typedef  int uint;
    typedef  long ulong;

    void Notebook::write(int page,  int row, int column, Direction direction, const std::string &message) {
         if (page < 0 || row < 0 || column < 0 || column + (int)message.length()< 0)
        {
            throw invalid_argument("you have a negative index");
        }
        if (direction == Direction::Vertical && column >= maxSym)
        {
            throw invalid_argument("you have more than 100 lines");
        }
         if (direction == Direction::Horizontal && (column + (int)message.length() >= maxSym))
        {
            throw invalid_argument("you have more than 100 to read");
        }
        int length = message.length();
        if (length == 0) {
            return ;
        }
        if(column + length > maxSym){
            cout << "throw invalid_argument(\"error\")" << endl;
        }
        if (direction == Direction::Horizontal) {
            ulong size_y = 1;
            if (column > bound.min_x) {
                length += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length) {
                bound.size_x = length;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
//             for (int i = 0; i < length; i++) {
//                 int x = column + i;
// //                 if(checkCharAt(page, x, row)){
// // //                    throw invalid_argument("error");
// //                     return;
// //                 }

         //   }
        } else {
            ulong size_y = length;
            ulong length_1 = 1;
            if (column > bound.min_x) {
                length_1 += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length_1) {
                bound.size_x = length_1;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
//             for (int i = 0; i < length; i++) {
//                 int y = row + i;
// //                 if(checkCharAt(page, column, y)){
// // //                    throw invalid_argument("error");
// //                     return;
// //                 }

//             }
//         }
        }
        if (direction == Direction::Horizontal) {
            ulong size_y = 1;
            if (column > bound.min_x) {
                length += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length) {
                bound.size_x = length;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }            
//             for (int i = 0; i < length; i++) {
//                 int x = column + i;
//                 noteBook[{page, {x, row}}] = message.at(i);
// //                setCharAt(page, x, row, message.at(i));
// //                noteBook[{page, {x, y}}] = c;
//             }
            int len = 0;
            const int maximum = 126;
            const int minimum = 32;
            for(auto str : message){
                int x = column + len;
                //||(str<=maximum&&str>=minimum)
                if((noteBook[page][row][x].d!='_')||(noteBook[page][row][x].d=='~')||(str=='~')||!(str<=maximum&&str>=minimum))
                {
                    throw invalid_argument("no write");
                }
                noteBook[page][row][x].d = str;
                len++;
            }

        } else {
            ulong size_y = length;
            ulong length_1 = 1;
            if (column > bound.min_x) {
                length_1 += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length_1) {
                bound.size_x = length_1;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
//             for (int i = 0; i < length; i++) {
//                 int y = row + i;
//                 noteBook[{page, {column, y}}] = message.at(i);
// //                setCharAt(page, column, y, message.at(i));
// //                noteBook[{page, {x, y}}] = c;
//             }
            int len = 0;
            const int maximum = 126;
            const int minimum = 32;
            for(auto str : message){
                int x = row + len;
                if((noteBook[page][x][column].d!='_')||(noteBook[page][x][column].d=='~')||(str=='~')||!(str<=maximum&&str>=minimum))
                {
                    throw invalid_argument("no write");
                }
                noteBook[page][x][column].d = str;
                len++;
            }

        }
    }

    string Notebook::read( int page, int row, int column, Direction direction, int length) {
        
       
         if (page < 0 || row < 0 || column < 0 || (column + length) - 1 < 0)
        {
            throw invalid_argument("you have a negative index");
        }
        if (direction == Direction::Vertical && column >= maxSym)
        {
            throw invalid_argument("you have more than 100 lines");
        }
         if (direction == Direction::Horizontal && ((column + length) - 1 >= maxSym))
        {
            throw invalid_argument("you have more than 100 to read");
        }

        if (length == 0) {
            return "";
        }
        if(direction == Direction::Horizontal && column + length > maxSym){
            cout << "throw invalid_argument(\"error\")" << endl;
        }

        string message;
        if (direction == Direction::Horizontal) {
            for (int i = 0; i < length; i++) {
                int x = column + i;            
                message += noteBook[page][row][x].d;
            }
        } else {
            for (int i = 0; i < length; i++) {
                int y = row + i;
                message += noteBook[page][y][column].d;
            }
        }

        return message;
    }

    void Notebook::show(int pages) const {
        if(pages<=0){
           throw invalid_argument("error-you have to give apostive num of page");
        }
        if (bound.size_x == 0) {
            return;
        }
        for (int i = 0; i < bound.size_y + 2; i++) {
            auto space = to_string(bound.min_y + i - 1) + ": ";
            while (space.length() < to_string(bound.min_y + bound.size_y + 2).length() + 2) {
                space += " ";
            }
            // if(!(bound.min_y + i - 1<0&&bound.min_x - 2<0)){
            //   cout << space << read(pages, bound.min_y + i - 1, bound.min_x - 2, Direction::Horizontal, bound.size_x + 4) << endl;

            // }
            // cout <<read( pages, 0, 0, Direction::Horizontal, 100)<< endl;

        }
    }

    void Notebook::erase( int page,  int row, int column, Direction direction,int length) {
         if (page < 0 || row < 0 || column < 0 || (column + length)  < 0)
        {
            throw invalid_argument("you have a negative index");
        }
        if (direction == Direction::Vertical && column >= maxSym)
        {
            throw invalid_argument("you have more than 100 lines");
        }
         if (direction == Direction::Horizontal && ((column + length) >= maxSym))
        {
            throw invalid_argument("you have more than 100 to read");
        }

        if (length == 0) {
            // do nothing
            return;
        }
        if(direction == Direction::Horizontal && column + length > maxSym){
            cout << "throw invalid_argument(\"error\")" << endl;
        }
        char del = '~';
        if (direction == Direction::Horizontal) {
            for(int i = column; i<column+length; i++){
                noteBook[page][row][i].d = del;
            }
        }
        else
            for(int i = row; i<row+length; i++){
                noteBook[page][i][column].d = del;
            }
        
    }

}

