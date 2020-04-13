#include <iostream>
#include "ApiConnection/ApiConnection.hpp"
#include "QueryGenerators/QueryGenerators.hpp"
#include "WeatherCore/WeatherCore.hpp"

using json = nlohmann::json;
using namespace boost::beast::http;

int main()
{
    WeatherCore core;
    short buf;

    std::cout << "Enter mode:\n"
                 "[0] - by coordinates\n"
                 "[1] - by city name" << std::endl;
    std::cin >> buf;

    if (buf == 0)
    {
        std::string Latitude;
        std::string Longitude;

        std::cout << "Enter Latitude:" << std::endl;
        std::cin >> Latitude;

        std::cout << "Enter Longitude:" << std::endl;
        std::cin >> Longitude;

        std::cout << "\n" << core.GetWeatherByLocation(Latitude, Longitude) << std::endl;
    }
    else if (buf == 1)
    {
        std::string city_name;

        std::cout << "Enter city name:" << std::endl;
        std::cin >> city_name;

        std::cout << "\n" << core.GetWeatherByCityName(city_name) << std::endl;
    }

    return 0;
}