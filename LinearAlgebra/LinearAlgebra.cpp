#include <SDL2/SDL.h>
#include <iostream>
#include "graphics.h"
#include "vector_2d.h"
#include "matrix.h"

//undef (macro)main to be able to let the linker find the non SDL main.
#undef main

void run()
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		const float screen_buffer = 10;
		const float grid_size = 20;
		const float screen_width = 800 + screen_buffer;
		const float screen_height = 800 + screen_buffer;

		if (SDL_CreateWindowAndRenderer(static_cast<int>(screen_width), static_cast<int>(screen_height), 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;
			SDL_bool paused = SDL_TRUE;
			SDL_Event event;
			graphics graphics{ *renderer, screen_width, screen_height, screen_buffer, grid_size };

			while (!done) {

				//Clear screen
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

				//Draw coordinate grid
				graphics.draw_coordinate_grid();

				//Draw vectors example 
				#pragma region
				/*
				vector_2d vector1{ 5, 5 };
				graphics.draw_vector(vector1);
				vector1.scale(1.5f);
				graphics.draw_vector(vector1, 1);
				vector1.scale(0.33f);
				graphics.draw_vector(vector1, 2);
				vector1.add(vector_2d{ 1, 1 });
				graphics.draw_vector(vector1, 3);
				vector1.subtract(vector_2d{ 2.5, 2.5 });
				graphics.draw_vector(vector1, 4);
				vector_2d vector2{ 4, 3 };
				vector2.subtract(vector_2d{ 2, -3 });
				graphics.draw_vector(vector2, -3);
				*/
				#pragma endregion Draw vectors example

				matrix<float> m;
				std::vector<vector_2d> vectors;
				/*vectors.emplace_back(-0.5f, -0.5f);
				vectors.emplace_back(0.5f, -0.5f);
				vectors.emplace_back(1.5f, 1.5f);
				vectors.emplace_back(-1.5f, 1.5f);
				vectors.emplace_back(-5.0f, -5.0f);*/
				vectors.emplace_back(1, 1);
				vectors.emplace_back(3, 1);
				vectors.emplace_back(3, 3);
				vectors.emplace_back(1, 3);
				m.add_vector_list(vectors);

				graphics.draw_matrix(m);
				m.translate_2d_vector_matrix(-2, -2).scale_2d_vector_matrix(2, 2).translate_2d_vector_matrix(2, 2);
				graphics.draw_matrix(m);

				//Update screen
				SDL_RenderPresent(renderer);

				//Pause the rendering
				while (paused)
				{
					while (SDL_PollEvent(&event)) {
						if (event.type == SDL_QUIT) {
							done = SDL_TRUE;
							paused = SDL_FALSE;
						}
					}
				}
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	run();
	std::cout << "Memory leaks? (0 for no, 1 for yes. See output for details.)" << _CrtDumpMemoryLeaks() << std::endl;
	return 0;
}
