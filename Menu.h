#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Start.h"


using namespace sf;






    void menu(RenderWindow& window)
{
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture,
            menuBackground, Diff1, Diff2, Diff3, DiffBg, ComeBack;
    menuTexture1.loadFromFile("images/Play.png");
    menuTexture2.loadFromFile("images/Info.png");
    menuTexture3.loadFromFile("images/Exit.png");
    menuBackground.loadFromFile("images/BG.jpg");
    aboutTexture.loadFromFile("images/about.jpg");
    Diff1.loadFromFile("images/Ez.png");
    Diff2.loadFromFile("images/Med.png");
    Diff3.loadFromFile("images/Hard.png");
    DiffBg.loadFromFile("images/DiffBg.jpg");
    ComeBack.loadFromFile("images/comeback.png");

    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),
            menuBg(menuBackground), about(aboutTexture), Ez(Diff1), Med(Diff2),
            Hard(Diff3), DBg(DiffBg), Back(ComeBack);

    menu1.setPosition(480, 50);
    menu2.setPosition(480, 150);
    menu3.setPosition(480, 250);
    menuBg.setPosition(0, 0);

    Ez.setPosition(480, 50);
    Med.setPosition(480, 150);
    Hard.setPosition(480, 250);
    Back.setPosition(480, 350);
    DBg.setPosition(0, 0);

    int DB = 0;
    int diff = 0;
    int menuNum = 0;
    bool isMenu = true;
    bool isDiff = false;
    while (isMenu == true) {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(480, 100, 320, 70).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Green);
            menuNum = 1;
            
        }
        if (IntRect(480, 200, 320, 70).contains(Mouse::getPosition(window))) {
            menu2.setColor(Color::Yellow);
            menuNum = 2;
        }
        if (IntRect(480, 300, 320, 70).contains(Mouse::getPosition(window))) {
            menu3.setColor(Color::Red);
            menuNum = 3;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isDiff = true;
                isMenu = true;
                while (isDiff == true) {

                    if (!Mouse::isButtonPressed(Mouse::Left)) {
                    
                    DB = 1;
                    
                    }

                    Ez.setColor(Color::White);
                    Med.setColor(Color::White);
                    Hard.setColor(Color::White);
                    Back.setColor(Color::White);
                    
                    window.clear(Color(129, 181, 221));

                    if (IntRect(480, 100, 320, 70).contains(Mouse::getPosition(window))) {
                        Ez.setColor(Color::Green);
                        
                            diff = 1;

                        
                    }

                    if (IntRect(480, 200, 320, 70).contains(Mouse::getPosition(window))) {
                        Med.setColor(Color::Yellow);
                       
                            diff = 2;
                        
                    }

                    if (IntRect(480, 300, 320, 70).contains(Mouse::getPosition(window))) {
                        Hard.setColor(Color::Blue);
                        
                            diff = 3;
                        
                    }

                    if (IntRect(480, 400, 320, 70)
                                .contains(Mouse::getPosition(window))) {
                        Back.setColor(Color::Red);
                        if (Mouse::isButtonPressed(Mouse::Left)) {
                            break;
                        }
                         
                    }

                   
                     if (Mouse::isButtonPressed(Mouse::Left)) {
                        if (DB) {
                            startGame(window, diff);
                        }
                    }


                  


                    window.draw(DBg);
                    window.draw(Ez);
                    window.draw(Med);
                    window.draw(Hard);
                    window.draw(Back);

                    window.display();
                    sleep(milliseconds(1000 / 60));
                }
            }

            if (menuNum == 2) {
                window.draw(about);
                window.display();
                while (!Keyboard::isKeyPressed(Keyboard::Escape))
                    ;
            }
            if (menuNum == 3) {
                window.close();
                isMenu = false;
            }
        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);

        window.display();
        sleep(milliseconds(1000/60));
    }
}


