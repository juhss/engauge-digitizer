/******************************************************************************************************
 * (C) 2018 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef CREATE_LOAD_IMAGE_H
#define CREATE_LOAD_IMAGE_H

#include <QObject>

class MainWindow;

/// Class to create LoadImageFromUrl for MainWindow class. We derive from QObject and
/// use Q_OBJECT so translations work
class CreateLoadImage : public QObject
{
  Q_OBJECT

public:
  /// Single constructor.
  CreateLoadImage();

  /// Create LoadImageFromUrl instance
  void create (MainWindow &mw);

};

#endif // CREATE_LOAD_IMAGE_H
