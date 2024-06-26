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

#pragma once

namespace CAMotics {
  class VBO {
    unsigned id;
    unsigned buffer = 0;
    unsigned size = 0;
    unsigned fill = 0;

  public:
    VBO(unsigned id = 0) : id(id) {}
    ~VBO();

    unsigned getSize() const {return size;}
    unsigned getFill() const {return fill;}

    unsigned get();
    void allocate(unsigned size);
    void add(unsigned count, const float *data);
    void enable(unsigned stride);
    void disable();
  };
}
