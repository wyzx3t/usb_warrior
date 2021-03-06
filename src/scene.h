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

#ifndef _SCENE_H_
#define _SCENE_H_


#include <memory>
#include <vector>

#include "game_object.h"
#include "sprite_component.h"
#include "level.h"


class Game;

class LogicComponent;

class Scene {
public:
	Scene(Game* game);

	GameObject* addObject(const char* name = nullptr);

	void addSpriteComponent(GameObject* obj, const TileMap& tilemap,
	                        unsigned index = 0);
	void addLogicComponent(GameObject* obj, unsigned id, LogicComponent* lcomp);

	void clear();

	inline bool debug() const { return _debugView; }
	void setDebug(bool debug);

	inline Level& level() { return _level; }

	void beginUpdate();
	void updateLogic(unsigned id);

	void beginRender();
	void endRender();
	void render(double interp, Boxf viewBox, Boxf screenBox);
	void renderLevelLayer(unsigned layer, Boxf viewBox, Boxf screenBox);

	inline Game* game() const { return _game; }

private:
	typedef std::unique_ptr<GameObject>      ObjectPtr;
	typedef std::vector<ObjectPtr>           ObjectVector;

	typedef std::unique_ptr<SpriteComponent> SpritePtr;
	typedef std::vector<SpritePtr>           SpriteVector;

	typedef std::unique_ptr<LogicComponent>  LogicPtr;
	typedef std::vector<LogicPtr>            LogicVector;
	typedef std::vector<LogicVector>         LogicMap;

private:
	Game*         _game;

	bool          _debugView;

	Level         _level;

	std::size_t   _objectCounter;
	ObjectVector  _objects;

	SpriteVector  _sprites;
	
	LogicMap      _logicMap;
};


#endif
