/*-------------------------------------------------------------------------
  Copyright 2009 Sandia Corporation.
  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
  the U.S. Government retains certain rights in this software.
-------------------------------------------------------------------------*/

#include "ui_AnatomyBrowser.h"
#include "anatomyBrowser.h"

#include <vtkAnnotationLink.h>
#include <vtkCommand.h>
#include <vtkDataRepresentation.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkGraphLayoutView.h>
#include <vtkRenderer.h>
#include <vtkSelection.h>
#include <vtkSelectionNode.h>
#include <vtkViewTheme.h>

#include <vtkSmartPointer.h>
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

// Constructor
AnatomyBrowser::AnatomyBrowser()
{
  // Setup UI from .ui
  this->ui = new Ui_AnatomyBrowser;
  this->ui->setupUi(this);

  this->GraphView = vtkSmartPointer<vtkGraphLayoutView>::New();

  // Graph View needs to get my render window
  this->GraphView->SetInteractor(this->ui->vtkGraphViewWidget->GetInteractor());
  this->ui->vtkGraphViewWidget->SetRenderWindow(this->GraphView->GetRenderWindow());

  // Set up the theme on the graph view :)
  vtkViewTheme* theme = vtkViewTheme::CreateNeonTheme();
  this->GraphView->ApplyViewTheme(theme);
  theme->Delete();

  // Set up action signals and slots
  connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
  connect(this->ui->actionStartBrowser, SIGNAL(triggered()), this, SLOT(slotStartBrowser()));
  connect(this->ui->actionPauseBrowser, SIGNAL(triggered()), this, SLOT(slotPauseBrowser()));

  this->GraphView->Render();
};

AnatomyBrowser::~AnatomyBrowser()
{

}

void AnatomyBrowser::slotExit()
{
  qApp->exit();
}

void AnatomyBrowser::slotStartBrowser()
{
}

void AnatomyBrowser::slotPauseBrowser()
{
}
