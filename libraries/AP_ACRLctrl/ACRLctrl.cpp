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

#include "Copter.h"

#include "ACRLctrl.h"

/*
    This file contains the self-defined parameters for ARCL controls.
*/

const AP_Param::GroupInfo ACRLctrl::var_info[] = {
    // List of self-defined parameters

    // @Param: CIRCSPEED
    // @DisplayName: Circular speed
    // @Description: speed for the circular trajectory
    // @Units: m/s
    // @Range:0 - 4
    // @User: Advanced
    AP_GROUPINFO("CIRCSPEED", 1, ACRLctrl, circSpeed, CIRCSPEED_DEFAULT),

    // @Param: CIRCRADIUSX
    // @DisplayName: X radius
    // @Description: circle radius or figure8's x radius
    // @Units: m
    // @Range: 0 - 2
    // @User: Advanced
    AP_GROUPINFO("CIRCRADIUSX", 2, ParametersG2, circRadiusX, CIRCRADIUSX_DEFAULT),

    // @Param: CIRCRADIUSY
    // @DisplayName: Y radius
    // @Description: figure8's y radius (not used for circle radius)
    // @Units: m
    // @Range: 0 - 2
    // @User: Advanced
    AP_GROUPINFO("CIRCRADIUSY", 3, ParametersG2, circRadiusY, CIRCRADIUSY_DEFAULT),

    // @Param: TRAJINDEX
    // @DisplayName: Trajectory index
    // @Description: index of the trajectory to run
    // @Units: integers
    // @Range: 0 - 10
    // @User: Advanced
    AP_GROUPINFO("TRAJINDEX", 4, ParametersG2, trajIndex, TRAJINDEX_DEFAULT),

    // @Param: L1ENABLE
    // @DisplayName: L1 enable
    // @Description: enabling switch for L1 adaptive controller
    // @Units: none
    // @Values: 0:Off,1:On
    // @User: Advanced
    AP_GROUPINFO("L1ENABLE", 5, ACRLctrl, l1enable, L1ENABLE_DEFAULT),

    // @Param: LANDFLAG
    // @DisplayName: land flag 
    // @Description: flag of landing signal
    // @Units: integers
    // @Values: 0:None,1:Land
    // @User: Advanced
    AP_GROUPINFO("LANDFLAG", 6, ParametersG2, LandFlag, LANDFLAG_DEFAULT),

    // @Param: ASV
    // @DisplayName: As velocity
    // @Description: As for the velocity state in the L1 adaptive controller
    // @Units: none
    // @Range:-1000 - 0
    // @User: Advanced
    AP_GROUPINFO("ASV", 7, ACRLctrl, Asv, ASV_DEFAULT),

    // @Param: ASOMEGA
    // @DisplayName: As omega
    // @Description: As for the rotational state in the L1 adaptive controller
    // @Units: none
    // @Range:-1000 - 0
    // @User: Advanced
    AP_GROUPINFO("ASOMEGA", 8, ACRLctrl, Asomega, ASOMEGA_DEFAULT),

    // @Param: CTOFFQ1THRUST
    // @DisplayName: LPF1 cutoff freq thrust
    // @Description: LPF1's cutoff frequency on the thrust channel in the L1 adaptive controller (rad/s)
    // @Units: rad
    // @Range:0 - 1000
    // @User: Advanced
    AP_GROUPINFO("CTOFFQ1THRUST", 9, ACRLctrl, ctoffq1Thrust, CTOFFQ1THRUST_DEFAULT),

    // @Param: CTOFFQ1MOMENT
    // @DisplayName: LPF1 cutoff freq moment
    // @Description: LPF1's cutoff frequency on the moment channels in the L1 adaptive controller (rad/s)
    // @Units: rad
    // @Range:0 - 1000
    // @User: Advanced
    AP_GROUPINFO("CTOFFQ1MOMENT", 10, ACRLctrl, ctoffq1Moment, CTOFFQ1MOMENT_DEFAULT),

    // @Param: CTOFFQ2MOMENT
    // @DisplayName: LPF2 cutoff freq moment
    // @Description: LPF2's cutoff frequency on the moment channels in the L1 adaptive controller (rad/s)
    // @Units: rad
    // @Range:0 - 1000
    // @User: Advanced
    AP_GROUPINFO("CTOFFQ2MOMENT", 11, ACRLctrl, ctoffq2Moment, CTOFFQ2MOMENT_DEFAULT),

    // @Param: GEOCTRL_KPX
    // @DisplayName: Kpx for geometric controller
    // @Description: The P term in translational control for the x axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KPX", 12, ACRLctrl, GeoCtrl_Kpx, GEOCTRL_KPX_DEFAULT),

    // @Param: GEOCTRL_KPY
    // @DisplayName: Kpy for geometric controller
    // @Description: The P term in translational control for the y axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KPY", 13, ACRLctrl, GeoCtrl_Kpy, GEOCTRL_KPY_DEFAULT),
    
    // @Param: GEOCTRL_KPZ
    // @DisplayName: Kpz for geometric controller
    // @Description: The P term in translational control for the z axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KPZ", 14, ACRLctrl, GeoCtrl_Kpz, GEOCTRL_KPZ_DEFAULT),

    // @Param: GEOCTRL_KVX
    // @DisplayName: Kvx for geometric controller
    // @Description: The D term in translational control for the x axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KVX", 15, ACRLctrl, GeoCtrl_Kvx, GEOCTRL_KVX_DEFAULT),

    // @Param: GEOCTRL_KVY
    // @DisplayName: Kvy for geometric controller
    // @Description: The D term in translational control for the y axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KVY", 16, ACRLctrl, GeoCtrl_Kvy, GEOCTRL_KVY_DEFAULT),
    
    // @Param: GEOCTRL_KVZ
    // @DisplayName: Kvz for geometric controller
    // @Description: The D term in translational control for the z axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KVZ", 17, ACRLctrl, GeoCtrl_Kvz, GEOCTRL_KVZ_DEFAULT),

    // @Param: GEOCTRL_KRX
    // @DisplayName: KRx for geometric controller
    // @Description: The P term in rotational control for the x axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KRX", 18, ACRLctrl, GeoCtrl_KRx, GEOCTRL_KRX_DEFAULT),

    // @Param: GEOCTRL_KRY
    // @DisplayName: KRy for geometric controller
    // @Description: The P term in rotational control for the y axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KRY", 19, ACRLctrl, GeoCtrl_KRy, GEOCTRL_KRY_DEFAULT),
    
    // @Param: GEOCTRL_KRZ
    // @DisplayName: KRz for geometric controller
    // @Description: The P term in rotational control for the z axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KRZ", 20, ACRLctrl, GeoCtrl_KRz, GEOCTRL_KRZ_DEFAULT),

    // @Param: GEOCTRL_KOX
    // @DisplayName: KOx for geometric controller
    // @Description: The D term in rotational control for the x axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KOX", 21, ACRLctrl, GeoCtrl_KOx, GEOCTRL_KOX_DEFAULT),

    // @Param: GEOCTRL_KOY
    // @DisplayName: KOy for geometric controller
    // @Description: The D term in rotational control for the y axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KOY", 22, ACRLctrl, GeoCtrl_KOy, GEOCTRL_KOY_DEFAULT),
    
    // @Param: GEOCTRL_KOZ
    // @DisplayName: KOz for geometric controller
    // @Description: The D term in rotational control for the z axis.
    // @Units: none
    // @Range: 0 - 1000
    // @User: Advanced
    AP_GROUPINFO("GEOCTRL_KOZ", 23, ACRLctrl, GeoCtrl_KOz, GEOCTRL_KOZ_DEFAULT),

    AP_GROUPEND
};

ACRLctrl::ACRLctrl(void)
    : temp_calibration() // this doesn't actually need constructing, but removing it here is problematic syntax-wise
{
    AP_Param::setup_object_defaults(this, var_info);
}