#include "imgui.h"
#include "imgui-SFML.h"

#include "kernel.cuh"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Vec3f.h"
#include "Game.h"

int main() {
	Game game(1200, 800);

	// CUDA demo
	int arraySize = 5;
	int* a = new int[arraySize] {1, 2, 3, 4, 5};
	int* b = new int[arraySize] {10, 20, 30, 40, 50};
	int* c = new int[arraySize];
	go(a, b, c, arraySize);
	std::cout << "{1, 2, 3, 4, 5} + {10, 20, 30, 40, 50} = {" << c[0] << ", " << c[1] << ", " << c[2] << ", " << c[3] << ", " << c[4] << "}\n";
	delete[] a;
	delete[] b;
	delete[] c;
	
	while (game.open()) {
		game.eventHandler();

		// ImGUI demo
		ImGui::Begin("A Window Title!");
		ImGui::Text("Some text in the window!");
		ImGui::Text("Yet More Text! :3c");
		ImGui::End();

		game.draw();
	}

	return 0;
}
