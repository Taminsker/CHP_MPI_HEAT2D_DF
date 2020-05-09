

option(EXAMPLES_123 "Build Examples_123" ON)

if(EXAMPLES_123)
    message("-- Examples_123 ON")
else(EXAMPLES_123)
    message("-- Examples_123 OFF")
endif(EXAMPLES_123)

if(EXAMPLES_123)
    add_executable(
        Examples_123
        main.cpp
        listfunctions.cpp
        listfunctions.h
        )

    target_link_libraries(Examples_123 HeatMPI)
    target_link_libraries(Examples_123 ${MPI_LIBRARIES})

    set_target_properties(Examples_123 PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
    set_target_properties(Examples_123 PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif(EXAMPLES_123)
