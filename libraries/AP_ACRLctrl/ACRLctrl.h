/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "../ArduCopter/Copter.h"

/*
    This file contains the self-defined parameters for ARCL controls.
    Default values are defined in config.h.
*/

class ACRLctrl
{
public:
    /// Constructor
    ACRLctrl(void);

    // var_info for holding Parameter information
    static const struct AP_Param::GroupInfo var_info[];

    AP_Float circSpeed; // speed for the circular trajectory
    AP_Float circRadiusX; // circle radius or figure8's x radius
    AP_Float circRadiusY; // figure8's y radius (not used for circle radius)
    AP_Int8 trajIndex; // index of the trajectory to run
    AP_Int8 l1enable; // enabling switch for L1 adaptive controller
    AP_Int8 LandFlag; // flag of landing

    // L1 adaptive controller
    AP_Float Asv; // As for the velocity state
    AP_Float Asomega; // As for the rotational velocity state
    AP_Float ctoffq1Thrust; // LPF1's cutoff frequency for thrust channel
    AP_Float ctoffq1Moment; // LPF1's cutoff frequency for moment channel
    AP_Float ctoffq2Moment; // LPF2's cutoff frequency for moment channel

    // Geometric controller
    AP_Float GeoCtrl_Kpx; // kpx for geometric controller
    AP_Float GeoCtrl_Kpy; // kpy for geometric controller
    AP_Float GeoCtrl_Kpz; // kpz for geometric controllerF
    AP_Float GeoCtrl_Kvx; // kvx for geometric controller
    AP_Float GeoCtrl_Kvy; // kvy for geometric controller
    AP_Float GeoCtrl_Kvz; // kvz for geometric controllerF
    AP_Float GeoCtrl_KRx; // kRx for geometric controller
    AP_Float GeoCtrl_KRy; // kRy for geometric controller
    AP_Float GeoCtrl_KRz; // kRz for geometric controllerF
    AP_Float GeoCtrl_KOx; // kOmegax for geometric controller
    AP_Float GeoCtrl_KOy; // kOmegay for geometric controller
    AP_Float GeoCtrl_KOz; // kOmegaz for geometric controller
};
