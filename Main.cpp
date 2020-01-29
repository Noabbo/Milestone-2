#include "Main.h"


using namespace std ;

int main(int argc, char *argv[]) {
    try {
        if (argv[1] != nullptr) {
            boot::Main().main(stoi(argv[1]));
        } else {
            boot::Main().main(5600);

        }
    } catch (char const* e) {
        cout << e << endl;
    }
    return 0;
}