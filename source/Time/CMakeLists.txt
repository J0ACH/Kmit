
target_include_directories(Kmit PRIVATE	${CMAKE_CURRENT_LIST_DIR})

target_sources(Kmit
	PRIVATE 
		${CMAKE_CURRENT_LIST_DIR}/Clocks.cpp
	PUBLIC 
		${CMAKE_CURRENT_LIST_DIR}/Clocks.h
)