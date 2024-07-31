# FindAndroidGlue.cmake

# Locate Android Glue headers and libraries

find_path(ANDROID_GLUE_INCLUDE_DIR
        NAMES android_glue.h
        PATHS ${ANDROID_NDK}/sources/android/native_app_glue
)

find_library(ANDROID_GLUE_LIBRARY
        NAMES android-glue
        PATHS ${ANDROID_NDK}/sources/android/native_app_glue
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(AndroidGlue DEFAULT_MSG
        ANDROID_GLUE_INCLUDE_DIR
        ANDROID_GLUE_LIBRARY
)

if (ANDROID_GLUE_FOUND)
    set(ANDROID_GLUE_LIBRARIES ${ANDROID_GLUE_LIBRARY})
    set(ANDROID_GLUE_INCLUDE_DIRS ${ANDROID_GLUE_INCLUDE_DIR})
else ()
    set(ANDROID_GLUE_LIBRARIES)
    set(ANDROID_GLUE_INCLUDE_DIRS)
endif ()