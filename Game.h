#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

class Game {
public:
	sf::RenderWindow* window = nullptr;
	sf::Event* event = nullptr;
	int width, height;
	sf::Clock* deltaClock = nullptr;

	Game(int width, int height) {
		this->width = width;
		this->height = height;
		window = new sf::RenderWindow(sf::VideoMode(width, height), "Unnamed Project", sf::Style::Close);
		event = new sf::Event();

		ImGui::SFML::Init(*window);
		deltaClock = new sf::Clock();
		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = NULL;
	}

	~Game() {
		ImGui::SFML::Shutdown();
		delete window;
		delete event;
		delete deltaClock;
	}

	int numPixels() {
		return width * height;
	}

	bool open() {
		return window->isOpen();
	}

	void eventHandler() {
		ImGui::SFML::Update(*window, deltaClock->restart());
		while (window->pollEvent(*event)) {
			ImGui::SFML::ProcessEvent(*event);
			if (event->type == sf::Event::Closed) {
				window->close();
				std::cout << "Simulation Ended\n";
			}
			if (event->key.code == sf::Keyboard::Enter) {
				window->close();
				std::cout << "Simulation Ended\n";
			}
		}
	}

	void draw() {
		window->clear(sf::Color(0, 0, 0));
		ImGui::SFML::Render(*window);
		window->display();
	}
};
