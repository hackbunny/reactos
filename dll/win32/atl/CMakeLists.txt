
add_definitions(
    -D__WINESRC__
    -D_ATL_VER=_ATL_VER_30)

include_directories(${REACTOS_SOURCE_DIR}/include/reactos/wine)

spec2def(atl.dll atl.spec ADD_IMPORTLIB)

list(APPEND SOURCE
    atl.c
    atl30.c
    atl_ax.c
    registrar.c
    precomp.h
    ${CMAKE_CURRENT_BINARY_DIR}/atl_stubs.c
    ${CMAKE_CURRENT_BINARY_DIR}/atl.def)

add_library(atl SHARED ${SOURCE} rsrc.rc)
set_module_type(atl win32dll)
target_link_libraries(atl uuid wine)
add_importlibs(atl oleaut32 ole32 user32 gdi32 advapi32 shlwapi msvcrt kernel32 ntdll)
add_pch(atl precomp.h SOURCE)
add_cd_file(TARGET atl DESTINATION reactos/system32 FOR all)
