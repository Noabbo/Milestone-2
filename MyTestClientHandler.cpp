//
// Created by noa on 17/01/2020.
//

#include <unistd.h>
#include <netinet/in.h>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int client_socket) {
    while (true) {
        sockaddr_in address;
        int is_connected = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
        cout << "Client is connected "<< is_connected << endl;
        if (is_connected == -1) {
            sleep(1);
        } else {
            break;
        }
        //Close the socket whe the connection is done or do not succeed.
        close(client_socket);
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    // address.sin_addr.s_addr = inet_addr(IP);
    address.sin_port = htons(port);

    if(inet_pton(AF_INET, IP, &address.sin_addr) <= 0) {
        cout << "Client Error" << IP <<" " << port << endl;

        throw("Invalid address - Address not supported");
    }
    //Request a connection with the server on local host, try until the connection is made.
    while (true) {
        int is_connected = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
        cout << "Client is connected "<< is_connected << endl;
        if (is_connected == -1) {
            sleep(1);
        } else {
            int i = 0;
            //Send information to our server
            for (i;  i < game_operation.size(); ++i) {
                runExecute(game_operation[i], client_socket);
            }
            // executions have finished
            if (i == game_operation.size()){
                cout << "Connection Over " << endl;
                break;
            }
        }
        //Close the socket whe the connection is done or do not succeed.
        close(client_socket);
    }
    //Close the socket whe the connection is done or do not succeed.
    close(client_socket);
    ClientDone = true;

}
