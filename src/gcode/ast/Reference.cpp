/******************************************************************************\

  CAMotics is an Open-Source simulation and CAM software.
  Copyright (C) 2011-2019 Joseph Coffland <joseph@cauldrondevelopment.com>

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

\******************************************************************************/

#include "Reference.h"

#include <cmath>

using namespace std;
using namespace GCode;


address_t Reference::evalAddress(Evaluator &evaluator) {
  double num = expr->eval(evaluator);

  if (num < 1 || MAX_ADDRESS < num || !isfinite(num))
    THROW(getLocation() << " Invalid reference number " << num);

  // NOTE MSVC does not allow direct conversion from double to address_t
  return addr = (address_t)(unsigned)round(num);
}


double Reference::eval(Evaluator &evaluator) {
  evalAddress(evaluator);
  return evaluator.eval(*this);
}


void Reference::print(ostream &stream) const {
  stream << '#' << *expr;
}
