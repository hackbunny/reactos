
spec2def(hidclass.sys hidclass.spec ADD_IMPORTLIB)

list(APPEND SOURCE
    fdo.c
    hidclass.c
    pdo.c
    precomp.h)

add_library(hidclass SHARED
    ${SOURCE}
    guid.c
    hidclass.rc
    ${CMAKE_CURRENT_BINARY_DIR}/hidclass.def)

set_entrypoint(hidclass 0)
set_subsystem(hidclass native)
set_target_properties(hidclass PROPERTIES SUFFIX ".sys")


add_importlibs(hidclass ntoskrnl hidparse hal)
add_dependencies(hidclass bugcodes)
add_pch(hidclass precomp.h SOURCE)
add_cd_file(TARGET hidclass DESTINATION reactos/system32/drivers NO_CAB FOR all)
