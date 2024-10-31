# Main
set(SOURCE_CODE
  main.cpp
)

add_executable("MusicLab" ${SOURCE_CODE})
target_link_libraries("MusicLab"
  PRIVATE
    ImGui-SFML::ImGui-SFML
)

# Copy DLLs needed for runtime on Windows
if(WIN32)
  if (BUILD_SHARED_LIBS)
    add_custom_command(TARGET MusicLab POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE_DIR:MusicLab>)
  endif()
endif()