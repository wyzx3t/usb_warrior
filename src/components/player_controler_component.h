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

#ifndef _UW_PLAYER_CONTROLER_COMPONENT_H_
#define _UW_PLAYER_CONTROLER_COMPONENT_H_


#include "../main_state.h"
#include "../input.h"
#include "../game_object.h"


class PlayerControlerComponent : public LogicComponent {
public:
	enum {
		P_FRONT,
		P_BACK,
		P_LEFT,
		P_RIGHT
	};

public:
	PlayerControlerComponent(MainState* state, GameObject* obj);

	void update();

public:
	Input left;
	Input right;
	Input jump;
	Input up;
	Input down;
	int direction;

protected:
	MainState* _state;

	int _animCounter;
};

#endif
