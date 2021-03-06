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
	SDL_RenderDrawLine(renderer_, zero_, center_y_ + 1, end_x_, center_y_ + 1);
	SDL_RenderDrawLine(renderer_, zero_, center_y_ - 1, end_x_, center_y_ - 1);
	SDL_RenderDrawLine(renderer_, center_x_, zero_, center_x_, end_y_);
	SDL_RenderDrawLine(renderer_, center_x_ + 1, zero_, center_x_ + 1, end_y_);
	SDL_RenderDrawLine(renderer_, center_x_ - 1, zero_, center_x_ - 1, end_y_);
	//Draw borders
	SDL_RenderDrawLine(renderer_, zero_, zero_, end_x_, zero_);
	SDL_RenderDrawLine(renderer_, zero_, end_y_, end_x_, end_y_);
	SDL_RenderDrawLine(renderer_, zero_, zero_, zero_, end_y_);
	SDL_RenderDrawLine(renderer_, end_x_, zero_, end_x_, end_y_);

	/*SDL_SetRenderDrawColor(renderer_, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(renderer_, 0.5, 0.5);*/
}

void graphics::draw_vector(vector_2d& vector, float start_x, float start_y) const
{
	const int starting_x = start_x == 0 ? center_x_ : center_x_ + start_x * step_;
	const int starting_y = start_y == 0 ? center_y_ : center_y_ - start_y * step_;

	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer_, starting_x, starting_y, starting_x + vector.get_x() * step_, starting_y - vector.get_y() * step_);
}

void graphics::draw_matrix(matrix<float> m) const
{
	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, SDL_ALPHA_OPAQUE);

	for (unsigned i = 0; i < m.get_cols(); i++) {
		
		if(i != 0)
		{
			const int previous_point_x = center_x_ + m(0, i - 1) * step_;
			const int previous_point_y = center_y_ - m(1, i - 1) * step_;
			const int current_point_x = center_x_ + m(0, i) * step_;
			const int current_point_y = center_y_ - m(1, i) * step_;
			
			SDL_RenderDrawLine(renderer_, previous_point_x, previous_point_y, current_point_x, current_point_y);
		}
	}
	SDL_RenderDrawLine(renderer_, 
		center_x_ + m(0, 0) * step_, center_y_ - m(1, 0) * step_, 
		center_x_ + m(0, m.get_cols() - 1) * step_, center_y_ - m(1, m.get_cols() - 1) * step_);
}

void graphics::draw_point(vector_2d& vector) const
{
	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, SDL_ALPHA_OPAQUE);

	SDL_RenderDrawPoint(renderer_, center_x_ + vector.get_x() * step_, center_y_ - vector.get_y() * step_);
}
