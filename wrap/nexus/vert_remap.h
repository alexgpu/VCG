/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *  
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/****************************************************************************
  History

$Log: not supported by cvs2svn $

****************************************************************************/
#ifndef NXS_VERTEX_REMAP_H
#define NXS_VERTEX_REMAP_H

#include <string>
#include "vfile.h"
#include "mfhash.h"

namespace nxs {

class VertRemap {
 public:
  bool Create(const std::string &file);
  bool Load(const std::string &file);
  void Resize(unsigned int n_vert);

  unsigned int Size();
  unsigned int Count(unsigned int key);
  void Insert(unsigned int key, unsigned int value);
  unsigned int GetValue(unsigned int key); //return first value
  template <class C> void GetValues(unsigned int key, 
			       C &container) {
    assert(key < Size());
    container.clear();
    if(all[key] == 0xffffffff) return;
    container.push_back(all[key]);
    borders.GetValue(key, container);
  }

 private:
  VFile<unsigned int> all;
  MFHash borders;
};
} //namespace bmt

#endif
