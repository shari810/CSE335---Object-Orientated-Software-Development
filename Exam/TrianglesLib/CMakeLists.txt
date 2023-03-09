project(TrianglesLib)

set(SOURCE_FILES
        pch.h
        MainFrame.cpp MainFrame.h TrianglesView.cpp TrianglesView.h ids.h
        Triangle.h Triangle.cpp TriangleMesh.h TriangleMesh.cpp FilledTriangle.cpp FilledTriangle.h
        ObjLoader.h ObjLoader.cpp
        Vertex.cpp Vertex.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})