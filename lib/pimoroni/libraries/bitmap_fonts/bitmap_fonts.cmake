add_library(bitmap_fonts 
    ${CMAKE_CURRENT_LIST_DIR}/bitmap_fonts.cpp
)

#PUBLIC was interface...why does that work
target_include_directories(bitmap_fonts PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${PIMORONI_PATH})

