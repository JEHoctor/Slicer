/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by James Hoctor, Kitware Inc.
  and was funded by ?????

==============================================================================*/

#ifndef __qSlicerSettingsLoadOrientationPanel_h
#define __qSlicerSettingsLoadOrientationPanel_h

// Qt includes
#include <QWidget>

// CTK includes
#include <ctkSettingsPanel.h>

// QtGUI includes
#include "qSlicerBaseQTGUIExport.h"

class QSettings;
class qSlicerSettingsLoadOrientationPanelPrivate;

class Q_SLICER_BASE_QTGUI_EXPORT qSlicerSettingsLoadOrientationPanel
  : public ctkSettingsPanel
{
  Q_OBJECT
public:
  /// Superclass typedef
  typedef ctkSettingsPanel Superclass;

  /// Constructor
  explicit qSlicerSettingsLoadOrientationPanel(QWidget* parent = nullptr);

  /// Destructor
  ~qSlicerSettingsLoadOrientationPanel() override;

public slots:

protected slots:
  void enableOldDefaultLoadOrientation(bool value);

protected:
  QScopedPointer<qSlicerSettingsLoadOrientationPanelPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerSettingsLoadOrientationPanel);
  Q_DISABLE_COPY(qSlicerSettingsLoadOrientationPanel);
};

#endif
