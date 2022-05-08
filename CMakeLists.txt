# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES)
set(COMPONENT_PRIV_REQUIRES audio_sal audio_hal esp_dispatcher esp_peripherals display_service)

if(CONFIG_AUDIO_BOARD_CUSTOM)
if(CONFIG_M5StickC_SPK_HAT)
message(STATUS "Current board name is " CONFIG_M5StickC_SPK_HAT)
list(APPEND COMPONENT_ADD_INCLUDEDIRS ./m5stickc_spk_hat ./m5stickc_internaldac)
set(COMPONENT_SRCS
./m5stickc_spk_hat/board.c
./m5stickc_spk_hat/board_pins_config.c
./m5stickc_internaldac/m5stickc_internaldac.c
)
endif()

if(CONFIG_M5ECHO)
message(STATUS "Current board name is " CONFIG_M5ECHO)
list(APPEND COMPONENT_ADD_INCLUDEDIRS ./m5echo_board ./m5echo_codec)
set(COMPONENT_SRCS
./m5echo_board/board.c
./m5echo_board/board_pins_config.c
./m5echo_board/internal_led.c
./m5echo_codec/m5echo_codec.c
)
endif()

endif()

register_component()

IF (IDF_VERSION_MAJOR GREATER 3)
idf_component_get_property(audio_board_lib audio_board COMPONENT_LIB)
set_property(TARGET ${audio_board_lib} APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${COMPONENT_LIB})

ELSEIF (IDF_VERSION_MAJOR EQUAL 3)
set_property(TARGET idf_component_audio_board APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES  $<TARGET_PROPERTY:${COMPONENT_TARGET},INTERFACE_INCLUDE_DIRECTORIES>)

ENDIF (IDF_VERSION_MAJOR GREATER 3)
