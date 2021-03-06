/******************************************************************************************************
 * (C) 2020 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef CENTIPEDE_ENDPOINTS_POLAR_H
#define CENTIPEDE_ENDPOINTS_POLAR_H

#include "CentipedeEndpointsAbstract.h"
#include "CentipedeIntersectionType.h"
#include "DocumentModelCoords.h"
#include "DocumentModelGuideline.h"
#include <QPointF>
#include "Transformation.h"

class CentipedeDebugPolar;

/// Compute endpoints for polar centipedes
class CentipedeEndpointsPolar : public CentipedeEndpointsAbstract
{
public:
  /// Constructor with individual coordinates
  CentipedeEndpointsPolar(const DocumentModelCoords &modelCoords,
                          const DocumentModelGuideline &modelGuideline,
                          const Transformation &transformation,
                          const QPointF &posClickScreen);
  virtual ~CentipedeEndpointsPolar ();
  
  /// Screen angle at origin from ellipse axis to circle-center/coordinate intersection. Works only for polar coordinates
  double angleScreenConstantRCenterAngle (double radiusAboutClick) const;

  /// Screen angle at origin from ellipse axis to circle/coordinate intersection in the increasing angle direction (high)
  /// or decreasing angle direction (low). Uses center angle from angleScreenConstantYRCenterAngle. Works only for polar coordinates
  void angleScreenConstantRHighLowAngles (double radiusAboutClick,
                                          double angleCenter,
                                          double &angleLow,
                                          double &angleHigh) const;

  /// Ellipse for R value of circle/coordinate intersection. Start/span angles are calculated separately
  void ellipseScreenConstantRForTHighLowAngles (const Transformation &transformation,
                                                const QPointF &posClickScreen,
                                                double &angleRotation,
                                                QRectF &rectBounding,
                                                CentipedeDebugPolar &DebugPolar);
  
  /// Screen point for R value of circle/coordinate intersection in the increasing T direction
  QPointF posScreenConstantRForHighT (double radius) const;

  /// Screen point for R value of circle/coordinate intersection in the decreasing T direction
  QPointF posScreenConstantRForLowT (double radius) const;
 
  /// Endpoints for radial line segmentin polar coordinates
  void posScreenConstantTForRHighLow (double radius,
                                            QPointF &posLow,
                                            QPointF &posHigh) const;
  
private:
  CentipedeEndpointsPolar();

  double closestAngleToCentralAngle (double angleCenter,
                                     double angleOld) const;

  /// Solves posScreenConstantRHighT and posScreenConstantRLowT  
  QPointF posScreenConstantRCommon (double radius,
                                    CentipedeIntersectionType intersectionType) const;

  double rAtOrigin () const;
  double tAtOrigin () const;

  DocumentModelCoords m_modelCoords;

};

#endif // CENTIPEDE_ENDPOINTS_POLAR_H
