/******************************************************************************
**  Copyright (c) 2007-2008, Calaos. All Rights Reserved.
**
**  This file is part of Calaos Home.
**
**  Calaos Home is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 3 of the License, or
**  (at your option) any later version.
**
**  Calaos Home is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar; if not, write to the Free Software
**  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**
******************************************************************************/
#include "module.h"

CalaosModuleBase * constructor(Evas *evas, const char *id, const char *path)
{
        return new ModuleClock(evas, id, path);
}
CalaosModuleApi calaos_modapi =
{
        CALAOS_MODULE_API_VERSION,
        CMOD_WIDGET,
        "Horloge",
        "L'heure numérique ou analogique avec cette horloge placé sur votre bureau",
        "2.0",
        "Calaos",
        constructor
};

ModuleClock::ModuleClock(Evas *_e, string _id, string _path):
        CalaosModuleBase(_e, _id, _path)
{
        string theme = module_path + "module.edj";
        edje_clock = new EdjeObject(theme, evas);
        edje_clock->LoadEdje("widget/clock");
}

ModuleClock::~ModuleClock()
{
        delete edje_clock;
}

string ModuleClock::getStringInfo()
{
        Calendar c;

        //hour
        string heure = c.hoursToString() + ":" + c.minutesToString() + ":" + c.secondesToString();

        //date
        string date = c.getDayFromDate() + " " + Utils::to_string(c.day) + " " +
                      c.getMonthFromDate() + " " + Utils::to_string(c.year);

        //timezone
        int tid = c.timeZone.loadCurrentTimeZone();
        string tzone;
        if (tid > 0)
        {
                tzone = c.timeZone.timeZone[tid].decalageStr;
        }

        return date + " " + heure + " (" + tzone + ")";
}

void ModuleClock::getSizeMin(int &w, int &h)
{
        edje_object_size_min_get(edje_clock->getEvasObject(), &w, &h);
}

void ModuleClock::getSizeMax(int &w, int &h)
{
        edje_object_size_max_get(edje_clock->getEvasObject(), &w, &h);
}

Evas_Object *ModuleClock::getEvasObject()
{
        return edje_clock->getEvasObject();
}

