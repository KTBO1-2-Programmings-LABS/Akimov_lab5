#include "Website.h"

namespace WebsiteManager {

    // Реализация методов класса Website
    Website::Website(const std::string& url) : Url(url) {
        ParseUrl();
    }

    void Website::ParseUrl() {
        std::string url = Url;
        size_t protocolEnd = url.find("://");
        if (protocolEnd != std::string::npos) {
            Protocol = url.substr(0, protocolEnd);
            url = url.substr(protocolEnd + 3);
        }

        size_t domainEnd = url.find('/');
        if (domainEnd != std::string::npos) {
            Domain = url.substr(0, domainEnd);
            Path = url.substr(domainEnd);
        }
        else {
            Domain = url;
        }
    }

    std::string Website::GetDomain() const {
        return Domain;
    }

    std::string Website::GetProtocol() const {
        return Protocol;
    }

    std::string Website::GetPath() const {
        return Path;
    }

    // Реализация функций
    void SortByDomain(std::vector<Website>& websites) {
        std::sort(websites.begin(), websites.end(), [](const Website& a, const Website& b) {
            return a.GetDomain() < b.GetDomain();
            });
    }

    void SortByProtocol(std::vector<Website>& websites) {
        std::sort(websites.begin(), websites.end(), [](const Website& a, const Website& b) {
            return a.GetProtocol() < b.GetProtocol();
            });
    }

    void SortByPath(std::vector<Website>& websites) {
        std::sort(websites.begin(), websites.end(), [](const Website& a, const Website& b) {
            return a.GetPath() < b.GetPath();
            });
    }

    void LoadWebsites(std::vector<Website>& websites) {
        try {
            std::ifstream inputFile("input.txt");
            std::string line;
            while (std::getline(inputFile, line)) {
                websites.push_back(Website(line));
            }
        }
        catch (const std::exception& e) {
            // Обработка ошибок
        }
    }

    void SaveWebsites(const std::vector<Website>& websites) {
        try {
            std::ofstream outputFile("output.txt");
            for (const auto& website : websites) {
                outputFile << website.Url << std::endl;
            }
        }
        catch (const std::exception& e) {
            // Обработка ошибок
        }
    }

    void ShowWebsites(const std::vector<Website>& websites) {
        for (const auto& website : websites) {
            std::cout << website.Url << std::endl;
        }
    }

    void ShowGUI(std::vector<Website>& websites) {
        // Реализация графического интерфейса
        Application::Run(gcnew MyForm());
    }
}
