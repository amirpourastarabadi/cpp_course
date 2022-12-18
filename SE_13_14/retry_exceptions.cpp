#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Exception
{
public:
    Exception(string message = "Something went wrong.")
    {
        this->message = message;
    }
    string get_message()
    {
        return message;
    }

private:
    string message;
};

class Network
{
public:
    static bool is_connect()
    {
        return false;
    }
    static bool send(string recipient, string message)
    {
        return true;
    }
};

class Notification
{
public:
    static bool send(string mobile, string message)
    {
        if (!Network::is_connect())
            throw Exception("No network connection.");
        return Network::send(mobile, message);
    }
};

int main()
{
    for (int i = 0; i < 3; i++)
    {
        try
        {
            Notification::send("09302631762", "Hello Amir Pourastarabadi.");
            break;
        }
        catch (Exception e)
        {
            std::cerr << e.get_message() << '\n';
        }
    }

    // or
    int tries = 0;
    ofstream file_handler;
    file_handler.open("./exception.log", ios::app);
    while (true && tries < 10)
    {
        try
        {
            tries += 1;
            Notification::send("09302631762", "Hello Amir Pourastarabadi.");
            break;
        }
        catch (Exception e)
        {
            // log exception
            file_handler << e.get_message() << endl;
            std::cerr << e.get_message() << '\n';
        }
    }
    file_handler.close();
}