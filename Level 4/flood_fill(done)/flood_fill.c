/*
Write a function that takes a 
    1. char ** as a 2-dimensional array of char, 
    2. a t_point as the dimensions of this array 
    3. a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

*/

#include "flood_fill.h"

void    fill(char **tab, t_point size, t_point cur ,char to_fill)
{
    if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y || tab[cur.y][cur.x] != to_fill)
        return;
    tab[cur.y][cur.x] = 'F';
    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill); // left
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill); // right
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill); // down
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill); // up
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
}


/*
METHOD: Recursion

Base Case:
    1. if out of map (check for x & y)
    2. if at wall

else:
    fill that point with 'F'
    4 Recursive Function calls (left, right, down, up)
        - if Base Case is true, func returns, 
            try next direction(func on the following line is called) 
        - if Base Case is true for all 4 directions
            - end.
*/