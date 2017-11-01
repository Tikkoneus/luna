//
//      _
//  ___/_)
// (, /      ,_   _
//   /   (_(_/ (_(_(_
// CX________________
//                   )
//
// Luna
// A web application and API framework in modern C++
//
// Copyright © 2016–2017 D.E. Goodman-Wilson
//

#include <string>
#include <iostream>
#include <luna/luna.h>

using namespace luna;

int main(void)
{
    // set up an endpoint that serves some JSON on /endpoint
    router api{"/"};

    api.set_mime_type("application/json"); //the default is "text/html; charset=UTF-8"

    // Handle GET requests to "localhost:8080/endpoint"
    // Respond with a tiny bit of fun JSON
    api.handle_request(request_method::GET, "/endpoint",
                       [](auto request) -> response
                       {
                           return {"{\"made_it\": true}"};
                       });

    //start a server on port 8080;
    server server;

    server.add_router(api);

    std::cout << "curl -v http://localhost:8080/endpoint" << std::endl;

    server.start(8080);
}