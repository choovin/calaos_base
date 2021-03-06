/******************************************************************************
 **  Copyright (c) 2006-2014, Calaos. All Rights Reserved.
 **
 **  This file is part of Calaos.
 **
 **  Calaos is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Calaos is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Foobar; if not, write to the Free Software
 **  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 **
 ******************************************************************************/
#include "ActivityConfigClockView.h"
#include "GengridItemConfig.h"
#include <GenlistItemSimpleHeader.h>
#include <GenlistItemSimple.h>
#include <Calendar.h>

ActivityConfigClockView::ActivityConfigClockView(Evas *_e, Evas_Object *_parent):
    ActivityView(_e, _parent, "calaos/page/config/clock")
{
    TimeZone tz;
    tzList = elm_genlist_add(_parent);

    setPartText("tab1.text", _("Action and positions of widgets"));
    setPartText("tab1.text.detail", _("Resume : <light_blue>Current settings</light_blue><br><small>Configure Date and Time !</small"));
    setPartText("tab2.text", _("About"));
    setPartText("tab2.text.detail", _("About : <light_blue>Calaos products</light_blue><br><small>Touchscreen solutions.</small>"));

    elm_object_style_set(tzList, "calaos");
    elm_genlist_select_mode_set(tzList, ELM_OBJECT_SELECT_MODE_ALWAYS);
    evas_object_size_hint_fill_set(tzList, EVAS_HINT_FILL, EVAS_HINT_FILL);
    evas_object_size_hint_weight_set(tzList, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
    evas_object_show(tzList);
    Swallow(tzList, "timezone_list.swallow");

    for(unsigned int i = 0; i < tz.timeZone.size(); i++)
    {

        GenlistItemSimple *_item;

        _item = new GenlistItemSimple(evas, tzList, tz.timeZone[i].key, true);
        _item->Append(tzList);
    }



}

ActivityConfigClockView::~ActivityConfigClockView()
{
    evas_object_del(tzList);
}

void ActivityConfigClockView::resetView()
{
}

