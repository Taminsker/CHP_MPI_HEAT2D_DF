#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    //    for (std::string exec : {"Example_1", "Example_2", "Example_3"})
    for (std::string exec : {"Example_1", "Example_2"})
    {
        std::ofstream out;
        out.open(exec+".csv");
        out.close ();

        std::string command;

        for (int i = 0; i < 15; ++i)
        {
            if (i == 0)
                command = std::string ("./"+exec);
            else
                command = std::string ("mpiexec -n ") + std::to_string (i) + std::string (" ./"+exec);

            out.open(exec+".csv", std::ios::app);
            out << "#" << i << " " << std::flush;
            out.close ();

            for (int j = 0; j < 30; ++j)
            {
                auto r = system (command.c_str ());
                (void)r;
                printf ("%s [%i] %i\n", exec.c_str (), i, j);
            }
            printf ("\n");


            out.open(exec+".csv", std::ios::app);
            out << std::endl;
            out.close ();
        }
    }

    return 0;
}
