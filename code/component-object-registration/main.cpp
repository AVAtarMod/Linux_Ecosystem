#include "Method_Handlers.h"

struct request_handler
{
    void operator()(const server::request& request,
        server::connection_ptr connection)
    {
        if (request.method == "POST")
        {
            auto h = std::make_shared<post_request_handler>(request);
            connection->read([h](server::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                server::connection_ptr connection)
                {
                    (*h)(chunk, ec, chunk_size, connection);
                });
        }
        else if (request.method == "GET")
        {
            auto h = std::make_shared<get_request_handler>(request);
            connection->read([h](server::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                server::connection_ptr connection)
                {
                    (*h)(chunk, ec, chunk_size, connection);
                });
        }
        if (request.method == "DELETE")
        {
            auto h = std::make_shared<delete_request_handler>(request);
            connection->read([h](server::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                server::connection_ptr connection)
                {
                    (*h)(chunk, ec, chunk_size, connection);
                });
        }
    }
};

int main(int argc, char* argv[])
{
    /*if (argc != 4) return -1;
    config->user = argv[1];
    config->dbname = argv[2];
    config->password = argv[3];
    db.connectUsing(config);*/
    config->user = "postgres";
    config->dbname = "ecosystem";
    config->debug = true;
    config->password = "102957";
    db.connectUsing(config);
    try
    {
        request_handler handler;
        auto io_service = std::make_shared<boost::asio::io_service>();
        server ser(
            server::options(handler).io_service(io_service).address("127.0.0.1").port("8000"));

        // Clean shutdown when pressing Ctrl+C.
        boost::asio::signal_set signals(*io_service, SIGINT, SIGTERM);
        signals.async_wait([&ser](const boost::system::error_code& ec,
            int /* signal_number */)
            {
                if (!ec)
                {
                    std::cout << "Stopping server... ";
                    ser.stop();
                    std::cout << "done.\n";
                }
            });

        std::cout << "Press Ctrl+C to stop the server.\n";
        ser.run();

        return EXIT_SUCCESS;
    }
    catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        return EXIT_FAILURE;
    }
}