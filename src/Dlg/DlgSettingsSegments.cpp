#include "CmdMediator.h"
#include "DlgSettingsSegments.h"
#include "Logger.h"
#include <QCheckBox>
#include <QComboBox>
#include <QIntValidator>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QLabel>
#include <QLineEdit>
#include "ViewPreview.h"

const int LINE_SIZE_MIN = 1;
const int LINE_SIZE_MAX = 10000;
const int MIN_LENGTH_MIN = 1;
const int MIN_LENGTH_MAX = 10000;
const int POINT_SEPARATION_MIN = 1;
const int POINT_SEPARATION_MAX = 10000;

DlgSettingsSegments::DlgSettingsSegments(QWidget *parent) :
  DlgSettingsAbstractBase ("Segments", parent)
{
  QWidget *subPanel = createSubPanel ();
  finishPanel (subPanel);
}

void DlgSettingsSegments::createControls (QGridLayout *layout,
                                          int &row)
{
  QLabel *labelMinLength = new QLabel("Minimum length:");
  layout->addWidget(labelMinLength, row, 1);

  m_editMinLength = new QLineEdit;
  m_editMinLength->setWhatsThis (tr ("Select a minimum number of points in a segment.\n\n"
                                     "Only segments with more points will be created.\n\n"
                                     "This value should be as large as possible to reduce memory usage. This value has "
                                     "a lower limit"));
  m_editMinLength->setValidator (new QIntValidator (MIN_LENGTH_MIN, MIN_LENGTH_MAX));
  connect (m_editMinLength, SIGNAL (textChanged (const QString &)), this, SLOT (slotMinLength (const QString &)));
  layout->addWidget(m_editMinLength, row++, 2);

  QLabel *labelPointSeparation = new QLabel("Point separation:");
  layout->addWidget (labelPointSeparation, row, 1);

  m_editPointSeparation = new QLineEdit;
  m_editPointSeparation->setWhatsThis (tr ("Select a point separation in pixels.\n\n"
                                           "Successive points added to a segment will be separated by this number of pixels. "
                                           "If Fill Corners is enabled, then additional points will be inserted at corners so some points "
                                           "will be closer.\n\n"
                                           "This value has a lower limit"));
  m_editPointSeparation->setValidator (new QIntValidator (POINT_SEPARATION_MIN, POINT_SEPARATION_MAX));
  connect (m_editPointSeparation, SIGNAL (textChanged (const QString &)), this, SLOT (slotPointSeparation (const QString &)));
  layout->addWidget (m_editPointSeparation, row++, 2);

  QLabel *labelFillCorners = new QLabel ("Fill corners:");
  layout->addWidget (labelFillCorners, row, 1);

  m_chkFillCorners = new QCheckBox;
  m_chkFillCorners->setWhatsThis (tr ("Fill corners.\n\n"
                                      "In addition to the points placed at regular intervals, this option causes a point to be "
                                      "placed at each corner. This option can capture important information in piecewise linear graphs, "
                                      "but gradually curving graphs may not benefit from the additional points"));
  connect (m_chkFillCorners, SIGNAL (stateChanged (int)), this, SLOT (slotFillCorners (int)));
  layout->addWidget (m_chkFillCorners, row++, 2);

  QLabel *labelLineSize = new QLabel("Line size:");
  layout->addWidget (labelLineSize, row, 1);

  m_cmbLineSize = new QComboBox;
  m_cmbLineSize->setWhatsThis (tr ("Select a size for the lines drawn along a segment"));
  connect (m_cmbLineSize, SIGNAL (currentTextChanged (const QString &)), this, SLOT (slotLineSize (const QString &)));
  layout->addWidget (m_cmbLineSize, row++, 2);

  QLabel *labelLineColor = new QLabel("Line color:");
  layout->addWidget (labelLineColor, row, 1);

  m_cmbLineColor = new QComboBox;
  m_cmbLineColor->setWhatsThis (tr ("Select a color for the lines drawn along a segment"));
  connect (m_cmbLineColor, SIGNAL (currentTextChanged (const QString &)), this, SLOT (slotLineColor (const QString &)));
  layout->addWidget (m_cmbLineColor, row++, 2);
}

void DlgSettingsSegments::createPreview (QGridLayout *layout,
                                         int &row)
{
  QLabel *labelPreview = new QLabel ("Preview");
  layout->addWidget (labelPreview, row++, 0, 1, 4);

  m_scenePreview = new QGraphicsScene (this);
  m_viewPreview = new ViewPreview (m_scenePreview, this);
  m_viewPreview->setWhatsThis (tr ("Preview window shows the shortest line that can be segment filled, "
                                   "and the effects of current settings on segments and points generated by segment fill"));
  m_viewPreview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_viewPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_viewPreview->setMinimumHeight (MINIMUM_PREVIEW_HEIGHT);

  layout->addWidget (m_viewPreview, row++, 0, 1, 4);
}

QWidget *DlgSettingsSegments::createSubPanel ()
{
  QWidget *subPanel = new QWidget ();
  QGridLayout *layout = new QGridLayout (subPanel);
  subPanel->setLayout (layout);

  layout->setColumnStretch (0, 1); // Empty first column
  layout->setColumnStretch (1, 0); // Labels
  layout->setColumnStretch (2, 0); // User controls
  layout->setColumnStretch (3, 1); // Empty last column

  int row = 0;
  createControls(layout, row);
  createPreview (layout, row);

  return subPanel;
}

void DlgSettingsSegments::load (CmdMediator &cmdMediator)
{
  LOG4CPP_INFO_S ((*mainCat)) << "DlgSettingsSegments::load";

  setCmdMediator (cmdMediator);
}

void DlgSettingsSegments::slotFillCorners (int /* state */)
{
  LOG4CPP_INFO_S ((*mainCat)) << "DlgSettingsSegments::slotFillCorner";
}

void DlgSettingsSegments::slotLineColor (const QString &)
{
  LOG4CPP_INFO_S ((*mainCat)) << "DlgSettingsSegments::slotLineColor";
}

void DlgSettingsSegments::slotLineSize (const QString &)
{
  LOG4CPP_INFO_S ((*mainCat)) << "DlgSettingsSegments::slotLineSize";
}

void DlgSettingsSegments::slotMinLength (const QString &)
{
  LOG4CPP_INFO_S ((*mainCat)) << "DlgSettingsSegments::slotMinLength";
}

void DlgSettingsSegments::slotPointSeparation (const QString &)
{
  LOG4CPP_INFO_S ((*mainCat)) << "DlgSettingsSegments::slotPointSeparation";
}
