/**
 * @file TrianglesView.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <wx/stdpaths.h>

#include "TrianglesView.h"
#include "TriangleMesh.h"
#include "ObjLoader.h"
#include "ids.h"

#include <wx/dcbuffer.h>


using namespace std;




/**
 * Constructor
 * @param parent
 */
void TrianglesView::Initialize(wxFrame* parent)
{
    auto std_paths = wxStandardPaths::Get();
    mResourcesDir = std_paths.GetResourcesDir();

    Create(parent, wxID_ANY);

    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &TrianglesView::OnPaint, this);

    // Menu handlers
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnTrianglesOne, this, IDM_SHOW_TRIANGLES_1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnTrianglesTwo, this, IDM_SHOW_TRIANGLES_2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnTrianglesThree, this, IDM_SHOW_TRIANGLES_3);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnMeshEmpty, this, IDM_SHOW_MESH_EMPTY);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnMeshM, this, IDM_SHOW_MESH_M);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnMeshMI, this, IDM_SHOW_MESH_MI);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnMeshMSU, this, IDM_SHOW_MESH_MSU);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnToggleFill, this, IDM_TOGGLE_FILLMESH);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &TrianglesView::OnToggleRandomColor, this, IDM_TOGGLE_RANDCOLOR);
    parent->Bind(wxEVT_UPDATE_UI, &TrianglesView::OnUpdateMeshFill, this, IDM_TOGGLE_FILLMESH);
    parent->Bind(wxEVT_UPDATE_UI, &TrianglesView::OnUpdateMeshRandomColor, this, IDM_TOGGLE_RANDCOLOR);

    NoMeshFile();  // Give us defaults when starting up

}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void TrianglesView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mMesh->Draw(&dc);
}

/**
 *
 * @param name wstring the filename of the mesh to load
 */
void TrianglesView::MeshFile(const wstring &name)
{
    mMeshFile = name;
    SetMesh();
}


/**
 * Set the mesh file to empty string and set the triangle mesh
 * to an empty.
 */
void TrianglesView::NoMeshFile()
{
    mMeshFile = L"";
    mMesh = make_shared<TriangleMesh>();
}

/**
 * Set the mesh file (if any) and load it if needed
 */
void TrianglesView::SetMesh()
{
    if (mMeshFile.empty())
    {
        return;
    }

    ObjLoader loader(&mRandom);
    loader.SetFilled(mFillType == FillType::Filled);
    loader.SetRandomColors(mRandomColors);

    mMesh = loader.Load(mMeshFile);
}


/**
 * Example mesh: Empty, not triangles
 * @param event Menu Event
 */
void TrianglesView::OnMeshEmpty(wxCommandEvent& event) {
    NoMeshFile();
    Refresh();
}


/**
 * Example mesh: Letter M
  * @param event Menu Event
 */
void TrianglesView::OnMeshM(wxCommandEvent& event) {
    mMeshFile = mResourcesDir + L"/m.obj";
    SetMesh();
    Refresh();
}


/**
 * Example mesh: State of Michigan
  * @param event Menu Event
 */
void TrianglesView::OnMeshMI(wxCommandEvent& event) {
    mMeshFile = mResourcesDir + L"/michigan.obj";
    SetMesh();
    Refresh();
}


/**
 * Example mesh: MSU
  * @param event Menu Event
 */
void TrianglesView::OnMeshMSU(wxCommandEvent& event) {
    mMeshFile = mResourcesDir +  L"/msu.obj";
    SetMesh();
    Refresh();
}


/**
 * Example mesh: One triangle
  * @param event Menu Event
 */
void TrianglesView::OnTrianglesOne(wxCommandEvent& event)
{
    wxColourDatabase colors;

    NoMeshFile();

    // Create the three vertices
    auto mesh = std::make_shared<TriangleMesh>();
    mMesh = mesh;

    auto v1 = mesh->AddVertex(200, 100);
    auto v2 = mesh->AddVertex(300, 200);
    auto v3 = mesh->AddVertex(100, 200);

    auto triangle = mesh->AddTriangle(v1, v2, v3, colors.Find("DARK GREEN"));
    Refresh();
}


/**
 * Example of two triangles making a box.
 * @param event Menu Event
 */
void TrianglesView::OnTrianglesTwo(wxCommandEvent& event)
{
    wxColourDatabase colors;

    NoMeshFile();

    // Create the three vertices
    auto mesh = std::make_shared<TriangleMesh>();
    mMesh = mesh;

    auto v1 = mesh->AddVertex(100, 100);
    auto v2 = mesh->AddVertex(100, 400);
    auto v3 = mesh->AddVertex(400, 400);
    auto v4 = mesh->AddVertex(400, 100);

    auto triangle = mesh->AddFilledTriangle(v1, v2, v3, colors.Find("BLUE"));
    triangle = mesh->AddFilledTriangle(v1, v3, v4, colors.Find("RED"));

    Refresh();
}



/**
 * Example of three triangles.
 * @param event Menu event
 */
void TrianglesView::OnTrianglesThree(wxCommandEvent& event)
{
    wxColourDatabase colors;

    NoMeshFile();

    // Create the three vertices
    auto mesh = std::make_shared<TriangleMesh>();
    mMesh = mesh;

    auto v1 = mesh->AddVertex(100, 100);
    auto v2 = mesh->AddVertex(100, 400);
    auto v3 = mesh->AddVertex(400, 400);
    auto v4 = mesh->AddVertex(400, 100);
    auto v5 = mesh->AddVertex(500, 250);

    auto triangle = mesh->AddFilledTriangle(v1, v2, v3, colors.Find("BLUE"));
    triangle = mesh->AddFilledTriangle(v1, v3, v4, colors.Find("RED"));
    triangle = mesh->AddFilledTriangle(v4, v3, v5, colors.Find("DARK GREEN"));
    Refresh();
}

/**
 * Toggles between filled and unfilled meshes
 * @param event Menu event
 */
void TrianglesView::OnToggleFill(wxCommandEvent &event)
{
    if (mFillType == FillType::Lines){
        mFillType = FillType::Filled;
    } else {
        mFillType = FillType::Lines;
    }
    SetMesh();
    Refresh();
}

/**
 * Toggles between black and white or random colors
 * @param event Menu event
 */
void TrianglesView::OnToggleRandomColor(wxCommandEvent &event)
{
    mRandomColors = !mRandomColors;
    SetMesh();
    Refresh();
}


/**
 * Handles what to do when the menu check for filling triangles is changed
 * @param event
 */
void TrianglesView::OnUpdateMeshFill(wxUpdateUIEvent &event)
{
    event.Check(mFillType == FillType::Filled);
}


/**
 * Handles what to do when the menu check for random colors is changed
 * @param event
 */
void TrianglesView::OnUpdateMeshRandomColor(wxUpdateUIEvent &event)
{
    event.Check(mRandomColors);
}


