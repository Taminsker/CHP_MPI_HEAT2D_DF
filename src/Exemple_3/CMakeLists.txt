

option(EXAMPLE_3 "Build Example_3" ON)

if(EXAMPLE_3)
    message("-- Example_3 ON")
else(EXAMPLE_3)
    message("-- Example_3 OFF")
endif(EXAMPLE_3)

if(EXAMPLE_3)
    add_executable(
        Example_3
        main.cpp
        listfunctions.cpp
        listfunctions.h
        )

    target_link_libraries(Example_3 HeatMPI)
    target_link_libraries(Example_3 ${MPI_LIBRARIES})

    set_target_properties(Example_3 PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
    set_target_properties(Example_3 PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif(EXAMPLE_3)
