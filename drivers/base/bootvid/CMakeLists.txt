
spec2def(bootvid.dll bootvid.spec ADD_IMPORTLIB)

if((ARCH STREQUAL "i386") OR (ARCH STREQUAL "amd64"))
    list(APPEND SOURCE
        i386/bootvid.c
        i386/bootdata.c
        i386/vga.c)
elseif(ARCH STREQUAL "arm")
    list(APPEND SOURCE
        arm/bootvid.c
        arm/bootdata.c)
endif()

list(APPEND SOURCE precomp.h)

add_library(bootvid SHARED
    ${SOURCE}
    bootvid.rc
    ${CMAKE_CURRENT_BINARY_DIR}/bootvid.def)

set_entrypoint(bootvid 0)
set_subsystem(bootvid native)
set_image_base(bootvid 0x00010000)

add_importlibs(bootvid ntoskrnl hal)
add_pch(bootvid precomp.h SOURCE)
add_dependencies(bootvid psdk bugcodes)
add_cd_file(TARGET bootvid DESTINATION reactos/system32 NO_CAB FOR all)

