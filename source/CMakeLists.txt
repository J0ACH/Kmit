
find_package(ScBridge 0.0.1 EXACT REQUIRED)
find_package(Jui 0.0.9 EXACT REQUIRED)
find_package(Qt5 5.8 COMPONENTS Core Widgets Gui Network REQUIRED)

add_executable(Kmit 
	${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

add_subdirectory (Time)

target_include_directories(Kmit 
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(Kmit 
	PUBLIC 
		Qt5::Core
		Qt5::Gui
		Qt5::Widgets
		ScBridge
		Jui
)

add_custom_command(TARGET Kmit
	PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ScBridge_LOCATION} ${CMAKE_BINARY_DIR}/bin
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${Jui_LOCATION} ${CMAKE_BINARY_DIR}/bin
)

string(TOUPPER ${CMAKE_CONFIGURATION_TYPES} configType)
set_target_properties( Kmit
    PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY_${configType} ${CMAKE_BINARY_DIR}/lib
		LIBRARY_OUTPUT_DIRECTORY_${configType} ${CMAKE_BINARY_DIR}/lib
		RUNTIME_OUTPUT_DIRECTORY_${configType} ${CMAKE_BINARY_DIR}/bin
		DEBUG_POSTFIX d
		WIN32_EXECUTABLE TRUE
)
