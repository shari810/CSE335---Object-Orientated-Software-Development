project(GameLib)

set(SOURCE_FILES MainFrame.h MainFrame.cpp GameView.cpp GameView.h Game.cpp Game.h pch.h Item.cpp Item.h Player.cpp Player.h Content.cpp Content.h Emitter.cpp Emitter.h Uml.cpp Uml.h Scoreboard.cpp Scoreboard.h Pen.cpp Pen.h Scorestreak.cpp Scorestreak.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
