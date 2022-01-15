/***************************************************************
 * Name:      MatrixInputApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Badger ()
 * Created:   2021-11-01
 * Copyright: Badger ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "MatrixInputApp.h"

//(*AppHeaders
#include "MatrixInputMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MatrixInputApp);

bool MatrixInputApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MatrixInputFrame* Frame = new MatrixInputFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
