//
// Created by noa on 17/01/2020.
//

#include <unistd.h>
#include <netinet/in.h>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socket, sockaddr_in address, istream in, ostream out) {
    while (true) {
        int is_connected = connect(socket, (struct sockaddr *) &address, sizeof(address));
        cout << "Client is connected "<< is_connected << endl;
        if (is_connected == -1) {
            sleep(1);
        } else {
            break;
        }
        //Close the socket whe the connection is done or do not succeed.
        close(client_socket);
    }
}
