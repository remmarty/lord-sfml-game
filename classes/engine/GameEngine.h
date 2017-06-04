//
// Created by jackie-chan on 03.06.17.
//

#ifndef SFMLGAME_GAMEENGINE_H       // zapobiega circular dependency
#define SFMLGAME_GAMEENGINE_H

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class GameEngine {
private:
    sf::RenderWindow m_window;

public:
    static const int ScreenWidth = 400;
    static const int ScreenHeight = 300;
    static const int ColorBitDepth = 32;

    //static const std::string WindowTitle = "REMI GRA";
    //static const int WindowMode = sf::Style::Close;
    sf::Time TimePerFrame;

    GameEngine() :
            m_window(sf::VideoMode(ScreenWidth, ScreenHeight, ColorBitDepth), "Remi Gra", sf::Style::Close) // inicjalizacja pól
    {
        TimePerFrame = sf::seconds(1.f/60.f);
    }

    void run()
    {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (m_window.isOpen())
        {
            sf::Time elapsedTime = clock.restart();
            timeSinceLastUpdate += elapsedTime;
            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;

                processEvents();
                //update(TimePerFrame);
            }

            //updateStatistics(elapsedTime);
            render();
        }
    }
    
    void processEvents() 
    {
        while (m_window.isOpen()) {

            sf::Event event;

            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window.close();


                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        m_window.close();
                    }
                }
            }
        }
    }

    void render()
    {
        m_window.clear();
        //m_window.draw();
        m_window.display();
    }
        
};


#endif SFMLGAME_GAMEENGINE_H