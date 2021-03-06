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

#include "defines.h" // IWYU pragma: keep
#include "FindWhConditions.h"
#include "buildings/nobBaseWarehouse.h"
#include "gameData/ShieldConsts.h"

// Include last!
#include "DebugNew.h" // IWYU pragma: keep

namespace FW
{

    bool HasMinWares::operator()(const nobBaseWarehouse& wh) const
    {
        return wh.GetRealWaresCount(type) >= count;
    }

    bool HasFigure::operator()(const nobBaseWarehouse& wh) const
    {
        if(wh.GetRealFiguresCount(type) > 0)
            return true;
        else if(recruitingAllowed && type != JOB_PACKDONKEY)
            return wh.CanRecruit(type);
        else
            return false;
    }

    bool HasWareAndFigure::operator()(const nobBaseWarehouse& wh) const
    {
        return HasMinWares::operator()(wh) && HasFigure::operator()(wh);
    }

    bool HasMinSoldiers::operator()(const nobBaseWarehouse& wh) const
    {
        return wh.GetSoldiersCount() >= count;
    }

    bool AcceptsWare::operator()(const nobBaseWarehouse& wh) const
    {
        // Einlagern darf nicht verboten sein
        // Schilder beachten!
        const GoodType good = ConvertShields(type);
        return !wh.GetInventorySetting(good).IsSet(EInventorySetting::STOP);
    }

    bool AcceptsFigure::operator()(const nobBaseWarehouse& wh) const
    {
        // Einlagern darf nicht verboten sein, Bootstypen zu normalen Tr�gern machen
        Job job = type;
        if(job == JOB_BOATCARRIER)
            job = JOB_HELPER;

        return !wh.GetInventorySetting(job).IsSet(EInventorySetting::STOP);
    }

    bool CollectsWare::operator()(const nobBaseWarehouse& wh) const
    {
        // Einlagern muss gewollt sein
        // Schilder beachten!
        GoodType gt = ConvertShields(type);
        return (wh.GetInventorySetting(gt).IsSet(EInventorySetting::COLLECT));
    }

    bool CollectsFigure::operator()(const nobBaseWarehouse& wh) const
    {
        // Einlagern muss gewollt sein
        Job job = type;
        if(job == JOB_BOATCARRIER)
            job = JOB_HELPER;
        return (wh.GetInventorySetting(job).IsSet(EInventorySetting::COLLECT));
    }

    bool HasWareButNoCollect::operator()(const nobBaseWarehouse& wh) const
    {
        return HasMinWares::operator()(wh) && !CollectsWare::operator()(wh);
    }

    bool HasFigureButNoCollect::operator()(const nobBaseWarehouse& wh) const
    {
        return HasFigure::operator()(wh) && !CollectsFigure::operator()(wh);
    }

    bool AcceptsWareButNoSend::operator()(const nobBaseWarehouse& wh) const
    {
        const GoodType good = ConvertShields(type);
        return AcceptsWare::operator()(wh) && !wh.GetInventorySetting(good).IsSet(EInventorySetting::SEND);
    }

    bool AcceptsFigureButNoSend::operator()(const nobBaseWarehouse& wh) const
    {
        Job job = type;
        if(job == JOB_BOATCARRIER)
            job = JOB_HELPER;

        return AcceptsFigure::operator()(wh) && !wh.GetInventorySetting(job).IsSet(EInventorySetting::SEND);
    }

} // namespace FW
