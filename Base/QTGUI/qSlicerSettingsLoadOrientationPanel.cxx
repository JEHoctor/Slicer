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

// Qt includes
#include <QSettings>

// QtGUI includes
#include "qSlicerApplication.h"
#include "qSlicerSettingsLoadOrientationPanel.h"
#include "ui_qSlicerSettingsLoadOrientationPanel.h"

// --------------------------------------------------------------------------
// qSlicerSettingsLoadOrientationPanelPrivate

//-----------------------------------------------------------------------------
class qSlicerSettingsLoadOrientationPanelPrivate: public Ui_qSlicerSettingsLoadOrientationPanel
{
  Q_DECLARE_PUBLIC(qSlicerSettingsLoadOrientationPanel);
protected:
  qSlicerSettingsLoadOrientationPanel* const q_ptr;

public:
  qSlicerSettingsLoadOrientationPanelPrivate(qSlicerSettingsLoadOrientationPanel& object);
  void init();
};

// --------------------------------------------------------------------------
// qSlicerSettingsLoadOrientationPanelPrivate methods

// --------------------------------------------------------------------------
qSlicerSettingsLoadOrientationPanelPrivate
::qSlicerSettingsLoadOrientationPanelPrivate(qSlicerSettingsLoadOrientationPanel& object)
  :q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerSettingsLoadOrientationPanelPrivate::init()
{
  Q_Q(qSlicerSettingsLoadOrientationPanel);

  this->setupUi(q);

  // Default values
  this->OldDefaultLoadOrientationEnabledCheckBox->setChecked(false);

  // Register settings
  q->registerProperty("LoadOrientation/UseOldDefault",
		      this->OldDefaultLoadOrientationEnabledCheckBox,
                      "checked", SIGNAL(toggled(bool)),
                      "Enable/Disable use of old default orientation (RAS) over new (LPS)",
		      ctkSettingsPanel::OptionNone);

  // Actions to propagate to the application when settings are changed
  QObject::connect(this->OldDefaultLoadOrientationEnabledCheckBox, SIGNAL(toggled(bool)),
                   q, SLOT(enableOldDefaultLoadOrientation(bool)));
}

// --------------------------------------------------------------------------
// qSlicerSettingsDeveloperPanel methods

// --------------------------------------------------------------------------
qSlicerSettingsLoadOrientationPanel::qSlicerSettingsLoadOrientationPanel(QWidget* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerSettingsLoadOrientationPanelPrivate(*this))
{
  Q_D(qSlicerSettingsLoadOrientationPanel);
  d->init();
}

// --------------------------------------------------------------------------
qSlicerSettingsLoadOrientationPanel::~qSlicerSettingsLoadOrientationPanel()
= default;

// --------------------------------------------------------------------------
void qSlicerSettingsLoadOrientationPanel::enableOldDefaultLoadOrientation(bool value)
{
  Q_UNUSED(value);
}
