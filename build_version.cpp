// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

///////////////////////////////////////////////////////////////////////////////
// Header
#include <build_version.h>
#include <build_version_defines.h>
#include <cstring>

// Include last!
#include "DebugNew.h" // IWYU pragma: keep

const char* GetWindowTitle()
{
    static char title[256];
    std::memset(title, 0, 256);
    std::strncpy(title, WINDOW_TITLE, 256);
    return title;
}

const char* GetWindowVersion()
{
    static char version[256];
    std::memset(version, 0, 256);
    std::strncpy(version, WINDOW_VERSION, 256);
    return version;
}

const char* GetWindowRevision()
{
    static char revision[256];
    std::memset(revision, 0, 256);
    std::strncpy(revision, WINDOW_REVISION, 256);
    return revision;
}

const char* GetWindowRevisionShort()
{
    static char revision[8];
    std::memset(revision, 0, 8);
    std::strncpy(revision, WINDOW_REVISION, 7);
    return revision;
}

const char* GetCurrentYear() //nasty but works, if versioning principle changes, we should make it use date function
{
    static char year[5];
    std::memset(year, 0, 5);
    std::strncpy(year, WINDOW_VERSION, 4);
    return year;
}
