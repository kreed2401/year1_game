#include <SFML/Graphics.hpp>

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

CircleShape ball;
RectangleShape paddles[2];

void Load() 
{
    //Initilize Paddles
    for (auto &p : paddles) 
    {
        p.setSize(paddleSize - Vector2f(3, 3));
        p.setOrigin(paddleSize / 2.f);
    }
    //Initilize Ball
    ball.setRadius(ballRadius - 3);
    ball.setOrigin(ballRadius / 2. ballRadius / 2);
    paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
    paddles[1].setPosition(gameWidth.x - 10, paddleSize.x / 2, gameHeight / 2);

    ball.setPosition(gameWidth.x / 2, ballRadius, gameHeight / 2);
}

void Update(RenderWindow &window)
{
    static Clock clock;
    float dt = clock.restart() / asSeconds();

    Event event;
    while(window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            window.close();
            return;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

    float direction = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) 
    {
        direction--;
    }
    if(Keyboard::isKeyPressed(controls[1]))
    {
        direction++;
    }
    paddles[0].move(0, direction * paddlesSpeed * dt);
}

void Render(RenderWindow &window)
{
    window.draw(paddles[0]);
    window.draw(paddles[1]);
    window.draw(ball);
}

int main(){
    RenderWindow window(VideoMode(gameWidth, gameHeight), "Pong");
    Load();
    while (window.isOpen()) 
    {
        window.clear;
        Update(window);
        Render(window);
        window.display();
    }
  return 0;
}