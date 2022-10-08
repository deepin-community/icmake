#include "main.ih"

namespace {
char const info[] = R"(

Icmake consists of a set of six programs. Together they can be used for
program maintenance, comparable to, e.g., the UNIX make facility, 
or they can be used for other tasks, comparable to the facilities offered 
by scripting languages.

Icmake was originally developed using the C programming language by 
Frank B. Brokken and (until version 6.xx) Karel Kubat.
Since version 10.00.00 icmake's source files are written in C++.

Icmake is available on various UNIX-platforms and is included in several 
Linux distributions (e.g., Debian). 

Icmake's home page is:

            https://fbb-git.gitlab.io/icmake/

Questions, remarks, etc. about Icmake should be sent to:

              Frank B. Brokken,

    phone:    (+31) 6 5353 2509
    e-mail:   f.b.brokken@rug.nl

              University of Groningen
              the Netherlands

)";

}

void about(char const *program)
{
    Tools::usageTop(program) << info;
}








