include(FetchContent)

add_subdirectory(glm)
add_subdirectory(yajl)

if(UNITTESTS)
    add_subdirectory(gtest)
endif()

if (APPLE OR WIN32)
	FetchContent_Declare(
		lua
		GIT_REPOSITORY "https://github.com/marovira/lua"
		GIT_TAG 5.4.4
	)
	FetchContent_MakeAvailable(lua)

	FetchContent_Declare(
		sqlite3
		GIT_REPOSITORY https://github.com/sjinks/sqlite3-cmake
		GIT_TAG v3.45.1
	)
	FetchContent_MakeAvailable(sqlite3)

	FetchContent_Declare(
		SDL2
		GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
		GIT_TAG release-2.32.0
	)
	set(SDL_CMAKE_DEBUG_POSTFIX "")
	set(SDL2_DISABLE_INSTALL ON)
	set(SDL2_DISABLE_UNINSTALL ON)
	set(SDL_FORCE_STATIC_VCRT ON)
	set(SDL_STATIC_ENABLED_BY_DEFAULT OFF)
	set(SDL_TEST_ENABLED_BY_DEFAULT OFF)
	set(BUILD_SHARED_LIBS OFF)
	FetchContent_MakeAvailable(SDL2)
	add_library(SDL2::SDL2 ALIAS SDL2-static)

	FetchContent_Declare(
		SDL2_mixer
		GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
		GIT_TAG release-2.8.1
		GIT_SUBMODULES_RECURSE ON
	)
	set(BUILD_SHARED_LIBS OFF)
	set(SDL2MIXER_FLAC OFF)
	set(SDL2MIXER_GME OFF)
	set(SDL2MIXER_CMD OFF)
	set(SDL2MIXER_MOD OFF)
	set(SDL2MIXER_MIDI OFF)
	set(SDL2MIXER_MP3 OFF)
	set(SDL2MIXER_WAVPACK OFF)
	set(SDL2MIXER_OPUS OFF)
	FetchContent_MakeAvailable(SDL2_mixer)

	FetchContent_Declare(
		SDL2_image
		GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
		GIT_TAG release-2.8.5
		GIT_SUBMODULES_RECURSE ON
	)
	set(BUILD_SHARED_LIBS OFF)
	set(SDL2IMAGE_AVIF OFF)
	set(SDL2IMAGE_BMP OFF)
	set(SDL2IMAGE_GIF OFF)
	set(SDL2IMAGE_JPG OFF)
	set(SDL2IMAGE_JXL OFF)
	set(SDL2IMAGE_LBM OFF)
	set(SDL2IMAGE_PCX OFF)
	set(SDL2IMAGE_PNM OFF)
	set(SDL2IMAGE_QOI OFF)
	set(SDL2IMAGE_SVG OFF)
	set(SDL2IMAGE_TGA OFF)
	set(SDL2IMAGE_TIF OFF)
	set(SDL2IMAGE_WEBP OFF)
	set(SDL2IMAGE_XCF OFF)
	set(SDL2IMAGE_XV OFF)
	FetchContent_MakeAvailable(SDL2_image)

	FetchContent_Declare(
		SDL2_net
		GIT_REPOSITORY https://github.com/libsdl-org/SDL_net.git
		GIT_TAG release-2.2.0
	)
	set(BUILD_SHARED_LIBS OFF)
	FetchContent_MakeAvailable(SDL2_net)

	FetchContent_Declare(
		box2d
		GIT_REPOSITORY https://github.com/erincatto/box2d.git
		GIT_TAG v2.4.2
	)
	set(BOX2D_BUILD_UNIT_TESTS OFF)
	set(BOX2D_BUILD_TESTBED OFF)
	set(BOX2D_BUILD_DOCS OFF)
	set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
	FetchContent_MakeAvailable(box2d)
else()
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CP_CMAKE_DIR})
	find_package(lua REQUIRED)
	add_library(lua::lua ALIAS lua)
	find_package(sqlite3 REQUIRED)
	add_library(SQLite::SQLite3 ALIAS sqlite3)
	find_package(sdl2 REQUIRED)
	add_library(SDL2::SDL2 ALIAS sdl2)
	find_package(SDL2_mixer REQUIRED)
	find_package(SDL2_image REQUIRED)
	find_package(SDL2_net REQUIRED)
	find_package(box2d REQUIRED)
endif()
