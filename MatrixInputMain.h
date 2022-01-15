/***************************************************************
 * Name:      MatrixInputMain.h
 * Purpose:   Defines Application Frame
 * Author:    Badger ()
 * Created:   2021-11-01
 * Copyright: Badger ()
 * License:
 **************************************************************/

#ifndef MATRIXINPUTMAIN_H
#define MATRIXINPUTMAIN_H

//(*Headers(MatrixInputFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class MatrixInputFrame: public wxFrame
{
    public:

        MatrixInputFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MatrixInputFrame();

    private:

        //(*Handlers(MatrixInputFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void PutVovanChar(wxCommandEvent& event);
        void DisplayMatrixElem(wxTextUrlEvent& event);
        void InitMatrix(wxCommandEvent& event);
        void addSpace(wxCommandEvent& event);
        void UnaryDisplay(wxCommandEvent& event);
        void InitMatrix2(wxCommandEvent& event);
        void resultCalculation(wxCommandEvent& event);
        void matrxiTranposit(wxCommandEvent& event);
        void findMDefinition(wxCommandEvent& event);
        void ReverseMatrix(wxCommandEvent& event);
        void OnOperationButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(MatrixInputFrame)
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON2;
        static const long ID_RICHTEXTCTRL1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL6;
        static const long ID_RICHTEXTCTRL2;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_TEXTCTRL8;
        static const long ID_TEXTCTRL9;
        static const long ID_BUTTON6;
        static const long ID_TEXTCTRL10;
        static const long ID_BUTTON7;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(MatrixInputFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* DiplayButton;
        wxButton* MatrDefinButton;
        wxButton* OperationButton;
        wxButton* ReverseButton;
        wxButton* TranspositButton;
        wxRichTextCtrl* InputMatrix1;
        wxRichTextCtrl* InputMatrix2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStatusBar* StatusBar1;
        wxTextCtrl* ActionTextBar;
        wxTextCtrl* ColumnLengh2;
        wxTextCtrl* ColumnLengh;
        wxTextCtrl* DisplayMatrixText;
        wxTextCtrl* LinesLengh2;
        wxTextCtrl* LinesLengh;
        wxTextCtrl* MatrixObjState2;
        wxTextCtrl* MatrixObjState;
        wxTextCtrl* StdLogBar;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MATRIXINPUTMAIN_H
