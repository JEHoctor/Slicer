#ifndef __qSlicerMainWindowCore_h
#define __qSlicerMainWindowCore_h 

// qCTK includes
#include <qCTKPimpl.h>

// QT includes
#include <QObject>

#include "qSlicerQTExport.h"

class qSlicerMainWindow; 
class qSlicerMainWindowCorePrivate;

class Q_SLICERQT_EXPORT qSlicerMainWindowCore : public QObject
{
  Q_OBJECT
  
public:
  typedef QObject Superclass;
  qSlicerMainWindowCore(qSlicerMainWindow *parent);

public slots: 
  // Description:
  // Handle actions
  void onEditUndoActionTriggered();
  void onEditRedoActionTriggered();
  
protected:
  qSlicerMainWindow* widget() const;

private:
  QCTK_DECLARE_PRIVATE(qSlicerMainWindowCore);
};

#endif
