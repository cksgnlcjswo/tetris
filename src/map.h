/*map 관련 헤더
 * */

#ifndef __MAP_H__
#define __MAP_H__
#define W 20  //높이
#define H 10  //가로길이

<<<<<<< HEAD
//bool boundaryCheck() 
//bool checkLine
//bool downLine
=======
/* multiple defination 해결을 위해 수정 */
extern int Map[W][H];

bool boundaryCheck(); // boundaryCheck

bool checkLine();//checkLine

void downLine(int f_line, int l_line);	 //downLine

void clearLine(int f_line, int l_line);  //erase a line if it has to be cleared.
>>>>>>> d0e92dcfe312a89993c42b43f8c8f41b99aafdea
#endif
