#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

namespace WebsiteManager {
    using namespace System;
    using namespace System::Windows::Forms;

    // ����� ��� ������������� �����
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

    // ������� ��� ���������� ������ �� ������
    void SortByDomain(std::vector<Website>& websites);

    // ������� ��� ���������� ������ �� ���������
    void SortByProtocol(std::vector<Website>& websites);

    // ������� ��� ���������� ������ �� ����
    void SortByPath(std::vector<Website>& websites);

    // ������� ��� �������� ������ �� �����
    void LoadWebsites(std::vector<Website>& websites);

    // ������� ��� ���������� ������ � ����
    void SaveWebsites(const std::vector<Website>& websites);

    // ������� ��� ������ ������ ������
    void ShowWebsites(const std::vector<Website>& websites);

    // ������� ��� ����������� ���� � ����������� �����������
    void ShowGUI(std::vector<Website>& websites);
}