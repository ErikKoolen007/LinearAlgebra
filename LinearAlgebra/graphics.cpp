#include "graphics.h"

void graphics::draw_coordinate_grid() const
{
	//Draw blue grid
	SDL_SetRenderDrawColor(renderer_, 0, 0, 255, SDL_ALPHA_OPAQUE);
	for (int i = zero_; i < end_x_; i += step_)
	{
		SDL_RenderDrawLine(renderer_, i, zero_, i, end_y_);
	}
	for (int i = zero_; i < end_y_; i += step_)
	{
		SDL_RenderDrawLine(renderer_, zero_, i, end_x_, i);
	}

	//Draw black horizontal and vertical line
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer_, zero_, center_y_, end_x_, center_y_);
	SDL_RenderDrawLine(renderer_, center_x_, zero_, center_x_, end_y_);
	//Draw borders
	SDL_RenderDrawLine(renderer_, zero_, zero_, end_x_, zero_);
	SDL_RenderDrawLine(renderer_, zero_, end_y_, end_x_, end_y_);
	SDL_RenderDrawLine(renderer_, zero_, zero_, zero_, end_y_);
	SDL_RenderDrawLine(renderer_, end_x_, zero_, end_x_, end_y_);
}

void graphics::draw_vector(vector_2d& vector, float start_x, float start_y) const
{
	const int starting_x = start_x == 0 ? center_x_ : center_x_ + start_x * step_;
	const int starting_y = start_y == 0 ? center_y_ : center_y_ - start_y * step_;

	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer_, starting_x, starting_y, starting_x + vector.get_x() * step_, starting_y - vector.get_y() * step_);
}
