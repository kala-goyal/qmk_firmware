/*
Copyright 2022 fgoodwin <fgoodwin@north-tech.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "5x6_6.h"
#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

#ifdef RIGHTHANDKALA
bool encoder_update_kb(uint8_t index, bool clockwise) {
#ifdef CONSOLE_ENABLE
	print("got to encoder_update_kb");
	#endif
    return encoder_update_user(index, clockwise);
}

bool dip_switch_update_kb(uint8_t index, bool active) { 
#ifdef CONSOLE_ENABLE
	print("got to dip_switch_update_kb");
#endif
    return dip_switch_update_user(index, active);
}
#endif