#include <SFML/Graphics.hpp>

using namespace sf;

int main(void) {
  RenderWindow window(VideoMode(320,480), "Tetris");
  /* append music */
  while(window.isOpen()) {
   Event e;
   while(window.pollEvent(e)) {
     if(e.type == Event::Closed) window.close();
   }
   
   /*other options */

   window.clear(Color::Black); 
   window.display();
  }
  return 0;
}
