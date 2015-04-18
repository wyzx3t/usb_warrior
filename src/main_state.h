/*
 *  Copyright (C) 2015 the authors
 *
 *  This file is part of usb_warrior.
 *
 *  usb_warrior is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  usb_warrior is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with usb_warrior.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MAIN_STATE_H_
#define _MAIN_STATE_H_


#include <Eigen/Geometry>

#include <SDL2/SDL_render.h>

#include "game_state.h"


class MainState : public GameState {
public:
	MainState(Game* game);

	void update();
	void frame(double interp);

protected:
	void initialize();
	void shutdown();

	void start();
	void stop();

protected:
	Eigen::Vector2f _pos;
	Eigen::Vector2f _prevPos;

	SDL_Texture*    _sprite;
};


#endif