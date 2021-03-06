/**
 *  @file writer.h
 *  @author Ivan Dryanovski <ivan.dryanovski@gmail.com>
 * 
 *  @section LICENSE
 * 
 *  Copyright (C) 2013, Ivan Dryanovski
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RGBD_2_SCHEMATIC_WRITER_H
#define RGBD_2_SCHEMATIC_WRITER_H

#define BUFLEN      16384

#include <iostream>
#include <fstream>
#include <zlib.h>

#include "schematic.h"

namespace rgbd_2_schematic {

const char TAG_END        = 0;
const char TAG_SHORT      = 2;
const char TAG_BYTE_ARRAY = 7;
const char TAG_STRING     = 8;
const char TAG_LIST       = 9;
const char TAG_COMPOUND   = 10;

class Writer
{ 
  public:

    Writer(const std::string& path);

    void write(const Schematic& schematic);              
         
  private:

    std::string path_;
    std::ofstream stream_;

    void writeSchematic(const Schematic& schematic);
    bool compressSchematic();
    
    void write_schematic_short(short value);
    void write_schematic_int(int value);
    void write_schematic_string(const std::string& text);
};

} // namespace rgbd_2_schematic

#endif // RGBD_2_SCHEMATIC_WRITER_H
