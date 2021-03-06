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

#ifndef _INPUT_H_
#define _INPUT_H_


#include <string>
#include <vector>
#include <unordered_map>

#include <SDL2/SDL_events.h>

#include "json.h"


#define INVALID_INPUT 0xffffffff

class Game;


typedef unsigned Input;
typedef unsigned ScanCode;


class InputManager {
public:
	InputManager(Game* game);
	~InputManager();

	Input addInput(const char* name);
	void  mapScanCode(Input input, ScanCode scanCode);
	void  bindJsonKeys(Input input, const char* name, ScanCode scanCode);
	void  loadKeyBindingFile(const char* filename);

	void sync();

	bool isPressed   (Input input) const;
	bool justPressed (Input input) const;
	bool justReleased(Input input) const;

private:
	struct InputDesc {
		std::string name;
		unsigned    count;
		unsigned    prevCount;

		inline InputDesc(const std::string& name)
		    : name(name), count(0) {}
	};

	typedef std::vector<InputDesc> InputMap;
	typedef std::unordered_map<ScanCode, Input> ScanCodeMap;

private:
	Game*       _game;

	json_t*     _bindings;
	InputMap    _inputMap;
	ScanCodeMap _scanCodeMap;
};


#endif
