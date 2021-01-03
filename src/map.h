/*map 관련 헤더
 * */

#ifndef __MAP_H__
#define __MAP_H__
#define H 20  //높이
#define W 10  //가로길이

/* multiple defination 해결을 위해 수정 */
extern int Map[H][W];

bool boundaryCheck(); // boundaryCheck

bool checkLine();//checkLine

void downLine(int f_line, int l_line);	 //downLine

void clearLine(int f_line, int l_line);  //erase a line if it has to be cleared.
#endif
