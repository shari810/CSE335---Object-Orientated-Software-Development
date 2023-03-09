/**
 * @file TrianglesView.h
 * @author Charles B. Owen
 *
 * View class for our project
 */
#ifndef PROJECTLIB_TrianglesView_H
#define PROJECTLIB_TrianglesView_H

#include <memory>
#include <string>
#include <random>

class TriangleMesh;

/**
 * View class for our project
 */
class TrianglesView : public wxWindow {
private:
    /// The resources directory
    std::wstring mResourcesDir;

    /// The triangle mesh we wish to draw
    std::shared_ptr<TriangleMesh> mMesh = nullptr;

    /// True if we fill with random colors
    bool mRandomColors = false;

    /// The type of filling
    enum class FillType {Lines, Filled};

    /// The current fill type
    FillType mFillType = FillType::Lines;

    void MeshFile(const std::wstring& name);
    void NoMeshFile();
    void SetMesh();

    /// The currently loaded mesh OBJ file
    std::wstring mMeshFile;

    // Random number generator
    std::mt19937 mRandom;

    void OnPaint(wxPaintEvent &event);

    void OnTrianglesOne(wxCommandEvent& event);
    void OnTrianglesTwo(wxCommandEvent& event);
    void OnTrianglesThree(wxCommandEvent& event);

    void OnMeshEmpty(wxCommandEvent& event);
    void OnMeshM(wxCommandEvent& event);
    void OnMeshMI(wxCommandEvent& event);
    void OnMeshMSU(wxCommandEvent& event);

    void OnToggleFill(wxCommandEvent& event);
    void OnToggleRandomColor(wxCommandEvent& event);
    void OnUpdateMeshFill(wxUpdateUIEvent& event);
    void OnUpdateMeshRandomColor(wxUpdateUIEvent& event);

public:
    void Initialize(wxFrame *parent);
};

#endif //PROJECTLIB_TrianglesView_H
