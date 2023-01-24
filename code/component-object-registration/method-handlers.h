#ifndef METHOD_HANDLERS_N
#define METHOD_HANDLERS_N

#include "component-object-registration.h"

struct post_request_handler
    : public std::enable_shared_from_this<post_request_handler>
{
    explicit post_request_handler(const server::request& request)
        : content_length_(0){}

    void operator()(server::connection::input_range chunk,
        boost::system::error_code ec, size_t chunk_size,
        server::connection_ptr connection)
    {
        assert(chunk.size() == chunk_size);

        if (ec)
        {
            std::cerr << "Error code: " << ec << '\n';
            return;
        }

        body_.append(chunk.begin(), chunk.end());
        if (body_.size() < content_length_)
        {
            auto self = this->shared_from_this();
            connection->read([self](server::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                server::connection_ptr connection)
                {
                    (*self)(chunk, ec, chunk_size, connection);
                });
            return;
        }
        int i;
        std::string ans;
        try
        {
            json js = json::parse(body_);
            if (js.size() != 5) throw std::exception("Введены не все данные!\n");
            else if (to_string(js["name"]).size() == 0) throw std::exception("Вы не ввели имя!\n");
            else if (to_string(js["login"]).size() == 0) throw std::exception("Вы не ввели логин!\n");
            else if (to_string(js["password"]).size() == 0) throw std::exception("Вы не ввели пароль!\n");

            i = registration(js["name"], js["login"], js["password"], js["type"], js["hardwave_id"]);
            if (i == -1)
                ans = "Такой логин уже есть!\n";
            else
                ans = "Регистрация прошла успешно.\n";
        }
        catch (std::exception e)
        {
            ans = e.what();
        }
        std::vector<server::response_header> headers;
        headers.push_back({ "Content-Type", "text/plain" });
        headers.push_back({ "Content-Length", std::to_string(ans.size()) });
        connection->set_status(server::connection::ok);
        connection->set_headers(headers);
        connection->write(ans);
    }

private:
    size_t content_length_;
    std::string body_;
};

struct get_request_handler
    : public std::enable_shared_from_this<get_request_handler>
{
    explicit get_request_handler(const server::request& request)
        : content_length_(0) {}

    void operator()(server::connection::input_range chunk,
        boost::system::error_code ec, size_t chunk_size,
        server::connection_ptr connection)
    {
        assert(chunk.size() == chunk_size);

        if (ec)
        {
            std::cerr << "Error code: " << ec << '\n';
            return;
        }

        body_.append(chunk.begin(), chunk.end());
        if (body_.size() < content_length_)
        {
            auto self = this->shared_from_this();
            connection->read([self](server::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                server::connection_ptr connection)
                {
                    (*self)(chunk, ec, chunk_size, connection);
                });
            return;
        }
        int i;
        std::string ans;
        try
        {
            json js = json::parse(body_);
            if (js.size() != 4) throw std::exception("Введены не все данные!\n");
            else if (to_string(js["login"]).size() == 0) throw std::exception("Вы не ввели логин!\n");
            else if (to_string(js["password"]).size() == 0) throw std::exception("Вы не ввели пароль!\n");

            i = authorization(js["login"], js["password"], js["type"], js["hardwave_id"]);
            std::string name;
            for (const auto& row : db(sqlpp::select(u.name).from(u).where(u.login == js["login"] && u.password == js["password"])))
                name = row.name;
            ans = "Авторизация прошла успешно. Здравствуйте, " + name + ".\n";
        }
        catch (std::exception e)
        {
            ans = e.what();
        }
        std::vector<server::response_header> headers;
        headers.push_back({ "Content-Type", "text/plain" });
        headers.push_back({ "Content-Length", std::to_string(ans.size()) });
        connection->set_status(server::connection::ok);
        connection->set_headers(headers);
        connection->write(ans);
    }

private:
    size_t content_length_;
    std::string body_;
};

struct delete_request_handler
    : public std::enable_shared_from_this<delete_request_handler>
{
    explicit delete_request_handler(const server::request& request)
        : content_length_(0) {}

    void operator()(server::connection::input_range chunk,
        boost::system::error_code ec, size_t chunk_size,
        server::connection_ptr connection)
    {
        assert(chunk.size() == chunk_size);

        if (ec)
        {
            std::cerr << "Error code: " << ec << '\n';
            return;
        }

        body_.append(chunk.begin(), chunk.end());
        if (body_.size() < content_length_)
        {
            auto self = this->shared_from_this();
            connection->read([self](server::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                server::connection_ptr connection)
                {
                    (*self)(chunk, ec, chunk_size, connection);
                });
            return;
        }
        int i;
        std::string ans;
        try
        {
            json js = json::parse(body_);
            if (js.size() != 3) throw std::exception("Введены не все данные!\n");
            else if (to_string(js["login"]).size() == 0) throw std::exception("Вы не ввели логин!\n");
            else if (to_string(js["password"]).size() == 0) throw std::exception("Вы не ввели пароль!\n");

            i = sign_out(js["login"], js["password"], js["hardwave_id"]);
            std::string name;
            for (const auto& row : db(sqlpp::select(u.name).from(u).where(u.login == js["login"] && u.password == js["password"])))
                name = row.name;
            ans = "Вы вышли из системы. Досвидания, " + name + ".\n";
        }
        catch (std::exception e)
        {
            ans = e.what();
        }
        std::vector<server::response_header> headers;
        headers.push_back({ "Content-Type", "text/plain" });
        headers.push_back({ "Content-Length", std::to_string(ans.size()) });
        connection->set_status(server::connection::ok);
        connection->set_headers(headers);
        connection->write(ans);
    }

private:
    size_t content_length_;
    std::string body_;
};


#endif