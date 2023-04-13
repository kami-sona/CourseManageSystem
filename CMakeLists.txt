cmake_minimum_required(VERSION 3.10)

project(ManageSystem)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME}
					${SOURCE_DIR}/Choose.c
					${SOURCE_DIR}/CList.c
					${SOURCE_DIR}/Main.c
					${SOURCE_DIR}/Menu.c
					${SOURCE_DIR}/PutDataIn.c
					${SOURCE_DIR}/SList.c
					${SOURCE_DIR}/WrAddRe.c)

target_include_directories(${PROJECT_NAME} 
					PRIVATE ${PROJECT_SOURCE_DIR}/includes)