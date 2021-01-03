/*map 관련 헤더
 * */

#ifndef __MAP_H__
#define __MAP_H__
#define W 20  //높이
#define H 10  //가로길이

/* multiple defination 해결을 위해 수정 */
extern int Map[W][H];

bool boundaryCheck(); // boundaryCheck

bool checkLine();//checkLine

void downLine();//downLine
#endif
