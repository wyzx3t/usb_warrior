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

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_


#include <cassert>
#include <string>

#include "math.h"
#include "geometry_component.h"


class Scene;

class SpriteComponent;
class SoundComponent;


enum {
	OBJECT_DESTROYED
};

enum {
	CURR_UP = 0,
	PREV_UP = 1
};


class GameObject {
public:
	GameObject(Scene* scene, const char* name);

	inline       Scene*       scene() const { return _scene; }
	inline const std::string& name () const { return _name;  }

	inline GeometryComponent& geom(unsigned updateIndex = 0)
	{ assert(updateIndex < 2u); return _geom[updateIndex]; }

	void computeBoxFromSprite(const Vec2& anchor = Vec2::Zero(), float scale=1.f);

	inline bool isDestroyed() const { return _flags & OBJECT_DESTROYED; }

	void _nextUpdate();
	inline void _setFlags(unsigned flags) { _flags = flags; }

public:
	SpriteComponent*   sprite;
	SoundComponent*    sound;

private:
	Scene*             _scene;

	unsigned           _flags;
	std::string        _name;

	GeometryComponent  _geom[2];
};


#endif