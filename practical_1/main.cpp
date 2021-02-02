#include <SFML/Graphics.hpp>
# include <windows.h>
#include <iostream>


using namespace sf;
using namespace std;

//Initilize Keyboard Controls
const Keyboard::Key controls[4] =
{
    Keyboard::W,//P1 Up
    Keyboard::S,//P1 Down
    Keyboard::Up,//P2 Up
    Keyboard::Down//P2 Down
};
const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;

int p1Score = 0;
int p2Score = 0;

Vector2f ballVelocity;
bool server = false;

bool aiControlled = false;

CircleShape ball;
RectangleShape paddles[2];

sf::Font font;
sf::Text text;

void Load() 
{
    //Initilize Paddles
    for (auto &p : paddles) 
    {
        p.setSize(paddleSize - Vector2f(3, 3));
        p.setOrigin(paddleSize / 2.f);
    }
    //Initilize Ball
    ball.setRadius(ballRadius);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);
    paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
    paddles[1].setPosition(gameWidth - 30 + paddleSize.x / 2, gameHeight / 2);

    ball.setPosition(gameWidth / 2 + ballRadius, gameHeight / 2);
    ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

    //Initilize Score
    font.loadFromFile("res/RobotoMono-VariableFont_wght.ttf");
    text.setFont(font);
    text.setCharacterSize(24);

    text.setString(p1Score + "|" + p2Score);
    text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void Reset()
{
    std::cout << "Reset";
    ball.setPosition(gameWidth / 2 + ballRadius, gameHeight / 2);
    ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };
    text.setString(p1Score + "|" + p2Score);
    std:cout << (p1Score + "|" + p2Score);
}

void ballCollision()
{
    //Ball Collision
    const float bx = ball.getPosition().x;
    const float by = ball.getPosition().y;

    if (by > gameHeight)
    {
        ballVelocity.x *= 1.1f;
        ballVelocity.y *= -1.1f;
        ball.move(0, -10);
    }
    else if (by < 0)
    {
        ballVelocity.x *= 1.1f;
        ballVelocity.y *= -1.1f;
        ball.move(0, 10);
    }
    else if (bx > gameWidth)
    {
        std::cout << "RightWall Reset";
        Reset();
        std::cout << bx;
        p1Score++;
    }
    else if (bx < 0)
    {
        std::cout << "LeftWall Reset";
        Reset();
        p2Score++;
    }
    else if (bx < paddleSize.x
        && by > paddles[0].getPosition().y - (paddleSize.y * 0.5)
        && by < paddles[0].getPosition().y + (paddleSize.y * 0.5))
    {
        std::cout << "Boing";
        ballVelocity.x *= -1.1f;
        ballVelocity.y *= 1.1f;
        ball.move(20, 0);
        std::cout << bx;
    }
    else if (bx > gameWidth - paddleSize.x
        && by > paddles[1].getPosition().y - (paddleSize.y * 0.5)
        && by < paddles[1].getPosition().y + (paddleSize.y * 0.5))
    {
        std::cout << "Boing";
        ballVelocity.x *= -1.1f;
        ballVelocity.y *= 1.1f;
        ball.move(-20, 0);
    }
}

void timer(int sec) 
{
    Sleep(sec * 1000);
}


void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
            return;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
    if (Keyboard::isKeyPressed(Keyboard::I)){ aiControlled = !aiControlled; }

    float direction = 0.0f;
    float p2Direction = 0.0f;
    if (Keyboard::isKeyPressed(controls[0]))
    {
        if (paddles[0].getPosition().y - 50 > 0) 
        {
            direction--;
        }
    }
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if (paddles[0].getPosition().y + 50 < gameHeight)
        {
            direction++;
        }
    }
    if (Keyboard::isKeyPressed(controls[2]) && !aiControlled)
    {
        if (paddles[1].getPosition().y - 50 > 0)
        {
            p2Direction--;
        }
    }
    if (Keyboard::isKeyPressed(controls[3]) && !aiControlled)
    {
        if (paddles[1].getPosition().y + 50 < gameHeight)
        {
            p2Direction++;
        }
    }

    paddles[0].move(0, direction * paddleSpeed * dt);
    paddles[1].move(0, p2Direction * paddleSpeed * dt);

    ball.move(ballVelocity * dt);

    ballCollision();

    //Control the P2 with AI
    if (aiControlled) 
    {
            if (ball.getPosition().y > paddles[1].getPosition().y)
            {
                paddles[1].move(0, 1 * paddleSpeed * dt);
            }
            else
            {
                paddles[1].move(0, -1 * paddleSpeed * dt);
            }
    }
    
    if (p1Score == 5) 
    {
        std::cout << "P1 Wins";
        timer(5);
        window.close();
    }
    else if(p2Score == 5)
    {
        std::cout << "P2 Wins";
        timer(5);
        window.close();
    }

}



void Render(RenderWindow &window)
{
    window.draw(paddles[0]);
    window.draw(paddles[1]);
    window.draw(ball);
    window.draw(text);
}

int main(){
    RenderWindow window(VideoMode(gameWidth, gameHeight), "Pong");
    Load();
    while (window.isOpen()) 
    {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
  return 0;
}