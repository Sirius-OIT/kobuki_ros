/*
 * Copyright (c) 2012, Yujin Robot.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Yujin Robot nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @file /kobuki_driver/include/kobuki_driver/modules/dock_drive.hpp
 *
 * @brief Simple module for the docking drive algorithm
 *
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef KOBUKI_DOCK_DRIVE_HPP_
#define KOBUKI_DOCK_DRIVE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <ecl/mobile_robot.hpp>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace kobuki {

/*****************************************************************************
** Interfaces
*****************************************************************************/

class DockDrive {
public:
  enum Station {
    NEAR_LEFT=1,
    NEAR_CENTER=2,
    NEAR_RIGHT=4,
    FAR_CENTER=8,
    FAR_LEFT=16,
    FAR_RIGHT=32
  };
  DockDrive();
  void init();
  void update(std::vector<unsigned char> &dock_ir
                , ecl::Pose2D<double> &pose_update
                , ecl::linear_algebra::Vector3d &pose_update_rates);
  void velocityCommands(const double &vx, const double &wz);

  /*********************
  ** Command Accessors
  **********************/
  std::vector<short> velocityCommands() const;

private:
  double vx, wz;
  short speed, radius;
  double bias;
  std::vector<std::vector<unsigned char> > dock_ir_history;
};

} // namespace kobuki

#endif /* KOBUKI_DOCK_DRIVE_HPP_ */