#include"Header.h"
#include"planet.h"



int main()
{
    srand(time(0));
    int width = 900;
    int height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
 
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;
   
    int planet_numbers = 3;
    float dist = 0.0;
 
    int r1 = 0, r2 = 0;
    vector<planet> pl(planet_numbers);
    
    for (int i = 0; i < planet_numbers; i++)
    {
        r1 = rand() % width;
        r2 = rand() % height;

        pl[i].SetColor(255, 255, 255);
        pl[i].SetMass(20);
        pl[i].SetPosition(r1, r2);
        pl[i].SetRadius(5);
        pl[i].SetVelocity(0.1, 0.5);
        pl[i].SetMass(0);
        pl[i].turn_on_the_trajectory();
        pl[i].set_the_length_of_the_trajectory(150);
        pl[i].set_the_radius_of_the_trajectory(5);
        pl[i].set_the_color_of_the_trajectory(28, 255, 92);
      
        
    }
    
    pl[0].SetMass(200);
    pl[0].SetPosition(width / 2, height / 2);
    pl[0].SetRadius(20);
    pl[0].SetVelocity(0, 0);
    pl[0].disable_the_trajectory();
    pl[0].SetColor(255, 240, 28);

   
    
    const double G = 9.8;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


       

        window.clear();


        for (int j = 0; j < planet_numbers; j++)
        {


            if (j != 0) {


                dist = sqrt(pow(pl[j].GetPos().x - pl[0].GetPos().x, 2) + pow(pl[j].GetPos().y - pl[0].GetPos().y, 2));
            
                Vector2f currentVelocity = pl[j].GetVelocity();
                if (dist != 0) {


                    currentVelocity.x += G * pl[0].GetMass() / dist / dist * (pl[0].GetPos().x - pl[j].GetPos().x) / dist;
                    currentVelocity.y += G * pl[0].GetMass() / dist / dist * (pl[0].GetPos().y - pl[j].GetPos().y) / dist;
                    pl[j].SetVelocity(currentVelocity.x, currentVelocity.y);
                    pl[j].move();
                }
              

            }



            pl[j].draw(window);


        }

        window.display();


    }
    return 0;
}