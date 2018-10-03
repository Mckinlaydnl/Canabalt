// --------------------------------------
// Includes
// --------------------------------------
// Libraries
#include <SFML/Graphics.hpp>

// Project Includes
#include "AssetManager.h"
#include "Player.h"
#include "Platform.h"



int main()
{
	// --------------------------------------
	// Game Setup
	// --------------------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Canabalt",
		sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;

	//Create AssetManager
	AssetManager assets;

	// Seed random number generator
	srand(time(NULL));
	//Create Player
	Player myPlayer;
	myPlayer.Spawn();

	

	std::vector<Platform> myPlatforms;
	for (int i = 0; i < 5; ++i)
	{
		myPlatforms.push_back(Platform());
		myPlatforms.back().Spawn();
	}

	// Create game camera
	sf::View camera = gameWindow.getDefaultView();

	//create the player

	// end game setup
	// --------------------------------------


	// --------------------------------------
	// Game Loop
	// --------------------------------------
	while (gameWindow.isOpen())
	{
		// --------------------------------------
		// Input
		// --------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// Pass input to game objects
			myPlayer.Input(event);


			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			} // End if (closed)
		} // end event polling loop

		// end input
		// --------------------------------------


		// --------------------------------------
		// Update
		// --------------------------------------
		sf::Time frameTime = gameClock.restart();
		
		//Process al game objects
		myPlayer.Update(frameTime);

		// Collision detection
		std::vector<sf::FloatRect > platformColliders;
		for (auto it = myPlatforms.begin(); it != myPlatforms.end(); ++it) 
		{
			platformColliders.push_back(it->GetCollider());
		}
		

		//Update camera positon
		camera.setCenter(myPlayer.GetPosition().x + camera.getSize().x * 0.4f, camera.getCenter().y);
		// end update
		// --------------------------------------



		// --------------------------------------
		// Draw
		// --------------------------------------

		// Clear the window to a single colour
		gameWindow.clear();

		// Draw Everything
		gameWindow.setView(camera);
		myPlayer.Draw(gameWindow);
		for (auto it = myPlatforms.begin(); it != myPlatforms.end(); ++it)
		{
			it -> Draw(gameWindow);
		}


		//Draw the UI to the window
		gameWindow.setView(gameWindow.getDefaultView());

		// Display the window contents to the screen
		gameWindow.display();

		// end draw
		// --------------------------------------

	} // end of the game while loop

	// end game loop
	// --------------------------------------

	// exit point for the program
	return 0;

} // end of the main() function
