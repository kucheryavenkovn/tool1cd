/*
    Tool1CD library provides access to 1CD database files.
    Copyright © 2009-2017 awa
    Copyright © 2017-2018 E8 Tools contributors

    This file is part of Tool1CD Library.

    Tool1CD Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Tool1CD Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Tool1CD Library.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef TV8FILESTREAMH
#define TV8FILESTREAMH

#include "../SystemClasses/TStream.hpp"
#include "V8File.h"

class V8File;

class TV8FileStream : public TStream {
public:
	TV8FileStream(V8File* f, bool ownfile = false);
	virtual ~TV8FileStream();
	virtual int64_t Read(void *Buffer, int64_t Count) override;
	virtual int Read(std::vector<uint8_t> Buffer, int Offset, int Count);
	virtual int64_t Write(const void *Buffer, int64_t Count) override;
	virtual int Write(const std::vector<uint8_t> Buffer, int Offset, int Count);
	virtual int64_t Seek(const int64_t Offset, const TSeekOrigin Origin) override;
	virtual int64_t GetSize() const override;
protected:
	V8File* file;
	bool own;
	int64_t pos;
};

#endif
