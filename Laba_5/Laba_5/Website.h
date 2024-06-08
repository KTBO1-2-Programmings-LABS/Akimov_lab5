#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

namespace WebsiteManager {
    using namespace System;
    using namespace System::Windows::Forms;

    // Класс для представления сайта
    class Website {
    public:
        std::string Url;
        std::string Protocol;
        std::string Domain;
        std::string Path;

        Website(const std::string& url);

        void ParseUrl();

        std::string GetDomain() const;
        std::string GetProtocol() const;
        std::string GetPath() const;
    };

    // Функция для сортировки сайтов по домену
    void SortByDomain(std::vector<Website>& websites);

    // Функция для сортировки сайтов по протоколу
    void SortByProtocol(std::vector<Website>& websites);

    // Функция для сортировки сайтов по пути
    void SortByPath(std::vector<Website>& websites);

    // Функция для загрузки сайтов из файла
    void LoadWebsites(std::vector<Website>& websites);

    // Функция для сохранения сайтов в файл
    void SaveWebsites(const std::vector<Website>& websites);

    // Функция для вывода списка сайтов
    void ShowWebsites(const std::vector<Website>& websites);

    // Функция для отображения окна с графическим интерфейсом
    void ShowGUI(std::vector<Website>& websites);
}