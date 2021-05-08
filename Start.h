#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <string>



using namespace sf;
using namespace std;



Sprite genNewButt(int code)
{

     string folder = "images/keys/";
     string exp = ".png";
     Texture BG, button;
     button.loadFromFile(folder + to_string(code) + exp);
     BG.loadFromFile("images/DiffBg.jpg");
     Sprite Bg(BG), Butt(button);
     Butt.setPosition(582, 302);
     
     
     Bg.setPosition(0, 0);
     
     return Butt;
}


void startEzDiff(RenderWindow& window){

        int count = 20;
        int code = rand()%25;
        bool EzGame = true;
        bool DS = false;
      

        Font font;
        font.loadFromFile("Fonts/mineFont.ttf");
        Text text("", font, 20);
        
        text.setStyle(sf::Text::Bold);
        text.setString(to_string(count));
        text.setPosition(100, 100);

    string folder = "images/keys/";
    string exp = ".png";
    Texture BG, button, HP1, HP2, HP3;
    HP1.loadFromFile("images/HP1.png");
    HP2.loadFromFile("images/HP2.png");
    HP3.loadFromFile("images/HP3.png");
    button.loadFromFile(folder + to_string(code) + exp);
    BG.loadFromFile("images/DiffBg.jpg");
    Sprite Bg(BG), Butt(button),Full(HP1), Half(HP2), Empty(HP3);
    Full.setPosition(80, 100);
    Butt.setPosition(582, 302);
    Bg.setPosition(0, 0);
    
    while (EzGame == true) {
        window.clear(Color(0, 0, 0, 0));
       

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                if (event.key.code == code) {
                    code = rand() % 25;
                    
                    button.loadFromFile(folder + to_string(code) + exp);
                    Butt.setTexture(button);
                    Butt.setPosition(582, 302);
                    Butt.setColor(Color::White);
                }  else {
                    count = count--;
                    
                    Butt.setColor(Color::Red);

                    if (count <= 20) {
                        
                    Full.setPosition(80, 100);
                        Full.setTexture(HP1);
                        
                    
                    
                    }

                    if (count <= 11) {
                        Full.setPosition(80, 100);
                        Full.setTexture(HP2);
                    }

                    if (count <= 5) {
                        Full.setPosition(80, 100);
                        Full.setTexture(HP3);
                    }
                    
                    font.loadFromFile("Fonts/mineFont.ttf");
                    text.setStyle(sf::Text::Bold);
                    text.setString(to_string(count));
                    text.setPosition(100, 100);

                    if (count == 0) {
                        
                        EzGame == false;
                        DS == true;
                        while (DS = true)
                        {
                            Texture End;
                            End.loadFromFile("images/GO.png");
                            Sprite GO(End);
                            GO.setPosition(0, 0);
                            Bg.setColor(Color::Red);
                            window.draw(Bg);
                            window.draw(GO);
                            window.display();
                        }
                    }
                    


                   }
            }
        }

       
            
            window.draw(Bg);
            window.draw(Full);
            window.draw(text);
            window.draw(Butt);
            window.display();
            

            sleep(milliseconds(1000 / 60));
        
    }
    
    
}

void startGame(RenderWindow & window, int diff)
{



	switch (diff) {
    
	case 1:
            startEzDiff(window);
            break;
   /* case 2:
            startMedDiff();
            break;
    case 3:
            startHardDiff();
            break;*/
    default:
	
        cout << "ERROR";
        break;
	}

}

