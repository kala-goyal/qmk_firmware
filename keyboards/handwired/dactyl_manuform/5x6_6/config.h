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

#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_COLS 6
#define MATRIX_ROWS 12

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3

// wiring of each half
//LHAND
// #define MATRIX_COL_PINS {E6, D7, C6, D4, D0, D1}
// #define MATRIX_ROW_PINS {F4, F5, F6, F7, B1, B3}

//RHAND
#define MATRIX_COL_PINS {F4, F5, F6, F7, B1, B3}
#define MATRIX_ROW_PINS {D1, D0, D4, C6, D7, E6}


#define DIODE_DIRECTION COL2ROW