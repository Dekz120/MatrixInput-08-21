/***************************************************************
 * Name:      MatrixInputMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Badger ()
 * Created:   2021-11-01
 * Copyright: Badger ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "MatrixInputMain.h"
#include <wx/msgdlg.h>
#include "..\MatrixInput\matrix\mathMatrix.h"
#include <typeinfo>


//(*InternalHeaders(MatrixInputFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MatrixInputFrame)
const long MatrixInputFrame::ID_TEXTCTRL2 = wxNewId();
const long MatrixInputFrame::ID_BUTTON1 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL3 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL4 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL5 = wxNewId();
const long MatrixInputFrame::ID_BUTTON2 = wxNewId();
const long MatrixInputFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL1 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL6 = wxNewId();
const long MatrixInputFrame::ID_RICHTEXTCTRL2 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL7 = wxNewId();
const long MatrixInputFrame::ID_BUTTON3 = wxNewId();
const long MatrixInputFrame::ID_STATICTEXT1 = wxNewId();
const long MatrixInputFrame::ID_BUTTON4 = wxNewId();
const long MatrixInputFrame::ID_BUTTON5 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL8 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL9 = wxNewId();
const long MatrixInputFrame::ID_BUTTON6 = wxNewId();
const long MatrixInputFrame::ID_TEXTCTRL10 = wxNewId();
const long MatrixInputFrame::ID_BUTTON7 = wxNewId();
const long MatrixInputFrame::ID_STATICTEXT2 = wxNewId();
const long MatrixInputFrame::ID_STATICTEXT3 = wxNewId();
const long MatrixInputFrame::idMenuQuit = wxNewId();
const long MatrixInputFrame::idMenuAbout = wxNewId();
const long MatrixInputFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MatrixInputFrame,wxFrame)
    //(*EventTable(MatrixInputFrame)
    //*)
END_EVENT_TABLE()

MatrixInputFrame::MatrixInputFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MatrixInputFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(605,461));
    StaticText1 = new wxStaticText(this, wxID_ANY, _("Lines/Columns"), wxPoint(8,8), wxDefaultSize, 0, _T("wxID_ANY"));
    DisplayMatrixText = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(336,64), wxSize(240,88), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    DiplayButton = new wxButton(this, ID_BUTTON1, _("Display Matrix"), wxPoint(8,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    DiplayButton->Disable();
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxPoint(728,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    LinesLengh = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(16,24), wxSize(24,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    ColumnLengh = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(48,24), wxSize(24,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Create"), wxPoint(80,24), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    InputMatrix1 = new wxRichTextCtrl(this, ID_RICHTEXTCTRL1, wxEmptyString, wxPoint(8,64), wxSize(120,88), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    StdLogBar = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(360,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    MatrixObjState = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(128,24), wxSize(32,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    MatrixObjState->Disable();
    InputMatrix2 = new wxRichTextCtrl(this, ID_RICHTEXTCTRL2, wxEmptyString, wxPoint(168,64), wxSize(120,88), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL2"));
    wxRichTextAttr rchtxtAttr_2;
    rchtxtAttr_2.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    ActionTextBar = new wxTextCtrl(this, ID_TEXTCTRL7, _("+"), wxPoint(136,96), wxSize(24,16), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    OperationButton = new wxButton(this, ID_BUTTON3, _("="), wxPoint(288,96), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT1, _("For unary operation put data to left field and press the button"), wxPoint(24,192), wxSize(328,24), 0, _T("ID_STATICTEXT1"));
    TranspositButton = new wxButton(this, ID_BUTTON4, _("Transposit"), wxPoint(112,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    TranspositButton->Disable();
    ReverseButton = new wxButton(this, ID_BUTTON5, _("Reverse"), wxPoint(192,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    ReverseButton->Disable();
    LinesLengh2 = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxPoint(168,24), wxSize(24,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    ColumnLengh2 = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxPoint(200,24), wxSize(24,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    Button1 = new wxButton(this, ID_BUTTON6, _("Create"), wxPoint(232,24), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    MatrixObjState2 = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxPoint(280,24), wxSize(32,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    MatrixObjState2->Disable();
    MatrDefinButton = new wxButton(this, ID_BUTTON7, _("Definitor"), wxPoint(272,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    MatrDefinButton->Disable();
    StaticText3 = new wxStaticText(this, ID_STATICTEXT2, _("Please, put matrix sizes first, i\'am too lazy to intercept exceptions for a while"), wxPoint(144,0), wxSize(424,16), 0, _T("ID_STATICTEXT2"));
    StaticText3->SetForegroundColour(wxColour(171,3,3));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxPoint(728,80), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::UnaryDisplay);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::InitMatrix);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::resultCalculation);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::matrxiTranposit);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::ReverseMatrix);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::InitMatrix2);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MatrixInputFrame::findMDefinition);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MatrixInputFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MatrixInputFrame::OnAbout);
    //*)
}

MatrixInputFrame::~MatrixInputFrame()
{
    //(*Destroy(MatrixInputFrame)
    //*)
}

void MatrixInputFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MatrixInputFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

mathMatrix<long double> Matrix1;//filled from 1t field
mathMatrix<long double> Matrix2;
mathMatrix<long double> ResultMatrix;

bool isInitedMatrix2=false;

//std::string readInput;
mathMatrix<long double> vovanMatrix;

void fill_matrix(mathMatrix<long double>& Matrix, wxTextCtrl& LogBarTxt, wxRichTextCtrl& InputMatrix, wxTextCtrl& resultMatix)
{   std::string readInput;
    readInput = InputMatrix.GetValue().ToStdString();
    string tmp;
    int mIndex = 0;
    bool push_elem;

    for(int i =0; i < readInput.size(); i++)
    {
        tmp.clear();
        push_elem = false;
        for(int j=0; !isspace(readInput[i]); j++)
        {

            tmp.push_back(readInput[i++]);
            push_elem = true;
        }

        if(push_elem)
        {
            if ( Matrix.addElem(mIndex++,stold(tmp)) == -1)
            {
                resultMatix.Clear();
                resultMatix.AppendText("index overflow error") ;
                break;

            }
        }
    }
}
void DisplayMatrix(mathMatrix<long double>& Matrix, wxTextCtrl& LogBarTxt, wxTextCtrl& resultMatrix)
{
    string tmp;
    resultMatrix.Clear();
    for(int i=0; i < Matrix.size(); i++)
    {
        tmp.clear();
        tmp = to_string(Matrix.getElem(i));
        /*for(int i=tmp.size()-1; tmp[i] == '0' || tmp[i] == '.' || i != 0; i--)
        {
            tmp.erase(i);
        }*/
        //resultMatrix.AppendText(to_string(Matrix.getElem(i)) + ' ');
        resultMatrix.AppendText(tmp + ' ');
        if(i>0 && (i+1) % Matrix.getLineSize() == 0) {resultMatrix.AppendText("\n");}
    }

}
void MatrixInputFrame::UnaryDisplay(wxCommandEvent& event)
{

    fill_matrix(Matrix1, *StdLogBar, *InputMatrix1, *DisplayMatrixText);
    StdLogBar->Clear();
    StdLogBar->AppendText("Display");
    DisplayMatrix(Matrix1, *StdLogBar, *DisplayMatrixText);
}
void MatrixInputFrame::matrxiTranposit(wxCommandEvent& event)
{
    mathMatrix<long double> MatrixR;
    fill_matrix(Matrix1, *StdLogBar, *InputMatrix1, *DisplayMatrixText);
    StdLogBar->Clear();
    StdLogBar->AppendText("Transpositional");
    MatrixR = transposit(Matrix1);
    DisplayMatrix(MatrixR, *StdLogBar, *DisplayMatrixText);

}



void MatrixInputFrame::InitMatrix(wxCommandEvent& event)
{
    int line = stoi(LinesLengh->GetValue().ToStdString());
    Matrix1.mtrxResize(stoi(LinesLengh->GetValue().ToStdString()), stoi(ColumnLengh->GetValue().ToStdString()));
    MatrixObjState->Clear();
    MatrixObjState->AppendText(to_string(Matrix1.getLineSize()));
    MatrixObjState->AppendText('x' + to_string(Matrix1.getColumnSize()));
    DiplayButton->Enable(true);
    TranspositButton->Enable(true);
    MatrDefinButton->Enable(true);
    ReverseButton->Enable(true);
    if(isInitedMatrix2){OperationButton->Enable(true); StdLogBar->AppendText("Matrix 1 was initialized");};
}



void MatrixInputFrame::InitMatrix2(wxCommandEvent& event)
{

    int line = stoi(LinesLengh2->GetValue().ToStdString());
    Matrix2.mtrxResize(stoi(LinesLengh2->GetValue().ToStdString()), stoi(ColumnLengh2->GetValue().ToStdString()));
    MatrixObjState2->Clear();
    MatrixObjState2->AppendText(to_string(Matrix2.getLineSize()));
    MatrixObjState2->AppendText('x' + to_string(Matrix2.getColumnSize()));

}

void MatrixInputFrame::resultCalculation(wxCommandEvent& event)
{
    string sign;
    sign = ActionTextBar->GetValue().ToStdString();

    fill_matrix(Matrix1, *StdLogBar, *InputMatrix1, *DisplayMatrixText);
    fill_matrix(Matrix2, *StdLogBar, *InputMatrix2, *DisplayMatrixText);

    if(sign == '+' )
    {

        if( Matrix1.getColumnSize() ==  Matrix2.getColumnSize() && Matrix1.getLineSize() == Matrix2.getLineSize() )
        {
            StdLogBar->AppendText("Summ");
            ResultMatrix= Matrix1+Matrix2;
            DisplayMatrix(ResultMatrix, *StdLogBar, *DisplayMatrixText);
        }
        else
        {
            DisplayMatrixText->Clear();
            DisplayMatrixText->AppendText("you, matrix are not same size");
        }

    }
    if(sign == '*')
    {

        if( Matrix1.getLineSize() ==  Matrix2.getColumnSize())
        {
            StdLogBar->Clear();
            StdLogBar->AppendText("Multyply:");
            ResultMatrix= Matrix1*Matrix2;
            DisplayMatrix(ResultMatrix, *StdLogBar, *DisplayMatrixText);
        }
        else
        {
            DisplayMatrixText->Clear();
            DisplayMatrixText->AppendText("you can't multiply this");
        }

    }
    if(sign == '/')
    {

        if( Matrix1.getLineSize() ==  Matrix2.getColumnSize())
        {
            StdLogBar->Clear();
            StdLogBar->AppendText("Division:");
            ResultMatrix= Matrix1/Matrix2;
            DisplayMatrix(ResultMatrix, *StdLogBar, *DisplayMatrixText);
        }
        else
        {
            DisplayMatrixText->Clear();
            DisplayMatrixText->AppendText("you, you can't devide this");
        }

    }




}


void MatrixInputFrame::findMDefinition(wxCommandEvent& event)
{
    string sign;
    sign = ActionTextBar->GetValue().ToStdString();

    fill_matrix(Matrix1, *StdLogBar, *InputMatrix1, *DisplayMatrixText);

    StdLogBar->Clear();
    StdLogBar->AppendText("Definitor :");
    auto def = findDefinitor(std::move(Matrix1));
    DisplayMatrixText->Clear();
    DisplayMatrixText->AppendText(to_string(def));
}

void MatrixInputFrame::ReverseMatrix(wxCommandEvent& event)
{
    string sign;
    sign = ActionTextBar->GetValue().ToStdString();

    fill_matrix(Matrix1, *StdLogBar, *InputMatrix1, *DisplayMatrixText);

    StdLogBar->Clear();
    StdLogBar->AppendText("Reverse:");
    ResultMatrix = Reverse(std::move(Matrix1));

    DisplayMatrix(ResultMatrix, *StdLogBar, *DisplayMatrixText);
}
