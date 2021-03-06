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

#ifndef SettingsTypes_h__
#define SettingsTypes_h__

#include <boost/array.hpp>

#define NUM_DISTRIBUTION 23
#define NUM_BUILD_ORDERS 31
#define NUM_TRANSPORT_ORDERS 14
#define NUM_TOOL_SETTINGS 12

typedef boost::array<unsigned char, NUM_DISTRIBUTION> Distributions;
typedef boost::array<unsigned char, NUM_BUILD_ORDERS> BuildOrders;
typedef boost::array<unsigned char, NUM_TRANSPORT_ORDERS> TransportOrders;
typedef boost::array<unsigned char, NUM_TOOL_SETTINGS> ToolSettings;

#endif // SettingsTypes_h__
