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
#include "MySensorsOutputLight.h"
#include "MySensorsController.h"
#include "MySensors.h"
#include "IOFactory.h"

using namespace Calaos;

REGISTER_OUTPUT(MySensorsOutputLight)

MySensorsOutputLight::MySensorsOutputLight(Params &p):
    OutputLight(p)
{
    string nodeId = get_param("node_id");
    string sensorId = get_param("sensor_id");

    MySensorsController::Instance(get_params()).registerIO(nodeId, sensorId, [=]() { /*nothing*/ });

    cInfoDom("output") << "MySensorsOutputLight::MySensorsOutputLight()";
}

MySensorsOutputLight::~MySensorsOutputLight()
{
    cInfoDom("output") << "MySensorsOutputLight::~MySensorsOutputLight()";
}

void MySensorsOutputLight::readValue()
{
}

bool MySensorsOutputLight::set_value_real(bool val)
{
    string nodeId = get_param("node_id");
    string sensorId = get_param("sensor_id");

    int dataType = MySensors::V_LIGHT;
    if (MySensors::String2DataType(get_param("data_type")) != MySensors::V_ERROR)
        dataType = MySensors::String2DataType(get_param("data_type"));

    MySensorsController::Instance(get_params()).setValue(nodeId, sensorId, dataType, Utils::to_string(val));

    return true;
}

