#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
#include "bitmap.h"
#include "platform.h"
#include "projectile.h"
#include "player.h"
#include "enemy.h"
#include "random.h"
using namespace sf;
static float viewheight = 1080.0f;

void resizeView(const RenderWindow&, View&);

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Castle!", Style::Close | Style::Resize);
	View view(Vector2f(0.0f, 0.0f), Vector2f(viewheight + 840, viewheight));
	window.setFramerateLimit(90);
	int Hp = 100;
	Texture jack;
	jack.loadFromFile("jack.png");
	player player(&jack, Vector2u(8, 8), 0.07f, 500.0f, Hp, 10);


	// weaponloadfile 

	Texture weapon1;
	weapon1.loadFromFile("sword.png");
	weapon weaponPlayer(&weapon1,Vector2u(6 , 2), 0.07f , Vector2f(0.0f,0.0f));
	weaponPlayer.setPositon(player.getPosition()); 


	Texture fireball;
	fireball.loadFromFile("Fireball1.png");
	enemy enemy1(&fireball, Vector2u(5, 1), Vector2f(200.0f, 100.0f), Vector2f(0.0f, 0.0f), 0.70f, 10.0f, 100);
	enemy1.setPosition(Vector2f(500.0f, 1710.0f));

	float deltaTime;
	float time;
	Clock clock[4];

	int state = 1;
	Texture mapHome;
	mapHome.loadFromFile("map_home.png");
	platform background1(&mapHome, Vector2f(1800.0f, 2070.0f), Vector2f(900.0f, 1035.f));
	vector<bitmap> blockH;
	int home[23][20]
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }
	};
	for (int mapX = 0; mapX < 20; mapX++)
	{
		for (int mapY = 0; mapY < 23; mapY++)
		{
			if (home[mapY][mapX] == 0)
			{
				bitmap outdoor(nullptr, Vector2f(((mapX) * 90) + 45, ((mapY) * 90) + 45), Vector2f(90.f, 90.f));
				blockH.push_back(outdoor);
			}
		}
	}
	player.setPosition(Vector2f(1250.0f, 1910.0f));

	while (!Keyboard::isKeyPressed(Keyboard::Escape))
	{
		if (state == 1)
		{


			while (window.isOpen())
			{
				deltaTime = clock[0].restart().asSeconds();
				time = clock[1].restart().asSeconds();
				Event evt;
				while (window.pollEvent(evt))
				{
					if (evt.type == Event::Closed) window.close();
					if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Escape) window.close();
				}

				player.update(deltaTime,&weaponPlayer);
				enemy1.updateEnemyFollow(enemy1.getPosition(), player.getPosition(), deltaTime ,weaponPlayer.getBounds());
				weaponPlayer.update(deltaTime , player.getPosition());
				//cout << "Hp = " << Hp << endl;
				//cout << "x = " << player.getPosition().x << " y = " << player.getPosition().y << std::endl;
				//cout << "Enemy x = " << enemy1.getPosition().x << "Enemy y = " << enemy1.getPosition().y << endl;
				//cout << deltaTime << endl;


				collider playerCollision = player.getCollider();
				collider enemy1Collision = enemy1.getCollider();
				for (int i = 0; i < blockH.size(); i++)
				{
					blockH[i].getCollider().checkCollider(playerCollision, 1.0f);
					blockH[i].getCollider().checkCollider(enemy1Collision, 1.0f);
				}
				
				/*if (weapon.getBounds().intersects(enemy1.getGlobals()))
				{
						
						enemy1.takeDamage(enemy1.getDamage());
				}*/
				if (player.getGlobals().intersects(enemy1.getGlobals())) {	player.takeDamage(10);}
				if (enemy1.getGlobals().intersects(weaponPlayer.getBounds()))  {  enemy1.takeDamage(10); }; 
					view.setCenter(player.getPosition());
					
					window.clear();
					window.setView(view);
					
					
					background1.draw(window);
					weaponPlayer.draw(window);
					player.draw(window);
					enemy1.draw(window);
					if (player.getPosition().x >= 1200.f && player.getPosition().x <= 1320.f && player.getPosition().y >= 1990.f && player.getPosition().y <= 2080.f)
					{
						window.clear(Color(150, 150, 150));
						player.setPosition(Vector2f(0.0f, 0.0f));
						state = 2;
						break;
					}
					window.display();
			}


				if (state == 2)

				{
					Texture mapDun;
					mapDun.loadFromFile("mapdungeon1.png");
					platform background2(&mapDun, Vector2f(1800.0f, 900.0f), Vector2f(900.0f, 450.f));
					vector<bitmap> blockD;
					int dun[10][20]
					{
						{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
						{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
						{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
						{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
						{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					};
					for (int mapX = 0; mapX < 20; mapX++)
					{
						for (int mapY = 0; mapY < 10; mapY++)
						{
							if (dun[mapY][mapX] == 0)
							{
								bitmap dungeon(nullptr, Vector2f(((mapX) * 90) + 45, ((mapY) * 90) + 45), Vector2f(90.f, 90.f));
								blockD.push_back(dungeon);
							}
						}
					}
					player.setPosition(Vector2f(1750.0f, 500.0f));
					while (window.isOpen())
					{
						deltaTime = clock[0].restart().asSeconds();
						Event evt;
						while (window.pollEvent(evt))
						{
							if (evt.type == Event::Closed) window.close();
							if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Escape) window.close();
						}

						player.update(deltaTime  ,&weaponPlayer);
						cout << "x = " << player.getPosition().x << " y = " << player.getPosition().y << std::endl;
						cout << deltaTime << endl;
						collider playerCollision = player.getCollider();
						for (int i = 0; i < blockD.size(); i++)	blockD[i].getCollider().checkCollider(playerCollision, 1.0f);

						view.setCenter(player.getPosition());
						window.clear();
						window.setView(view);

						background2.draw(window);
						player.draw(window);
						window.display();
					}
					return 0;
				}
			}
		}
	}


void resizeView(const RenderWindow& window, View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(viewheight * aspectRatio, viewheight);
}
