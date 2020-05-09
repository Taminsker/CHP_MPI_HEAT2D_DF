

option(COMPEXE "Build CompExe" ON)

if(COMPEXE)
    message("-- CompExe ON")
else(COMPEXE)
    message("-- CompExe OFF")
endif(COMPEXE)

if(COMPEXE)
    add_executable(
        CompExe
        main.cpp
        )
endif(COMPEXE)
