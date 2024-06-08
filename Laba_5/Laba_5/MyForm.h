#pragma once

#include "Website.h"

namespace WebsiteManager {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ sortByDomainButton;
    private: System::Windows::Forms::Button^ sortByProtocolButton;
    private: System::Windows::Forms::Button^ sortByPathButton;
    private: System::Windows::Forms::ListBox^ listBoxWebsites;
    private: System::ComponentModel::Container^ components;

           void InitializeComponent(void)
           {
               this->sortByDomainButton = (gcnew System::Windows::Forms::Button());
               this->sortByProtocolButton = (gcnew System::Windows::Forms::Button());
               this->sortByPathButton = (gcnew System::Windows::Forms::Button());
               this->listBoxWebsites = (gcnew System::Windows::Forms::ListBox());
               this->SuspendLayout();
               // 
               // sortByDomainButton
               // 
               this->sortByDomainButton->Location = System::Drawing::Point(12, 12);
               this->sortByDomainButton->Name = L"sortByDomainButton";
               this->sortByDomainButton->Size = System::Drawing::Size(120, 23);
               this->sortByDomainButton->TabIndex = 0;
               this->sortByDomainButton->Text = L"Сортировать по домену";
               this->sortByDomainButton->UseVisualStyleBackColor = true;
               this->sortByDomainButton->Click += gcnew System::EventHandler(this, &MyForm::sortByDomainButton_Click);
               // 
               // sortByProtocolButton
               // 
               this->sortByProtocolButton->Location = System::Drawing::Point(12, 41);
               this->sortByProtocolButton->Name = L"sortByProtocolButton";
               this->sortByProtocolButton->Size = System::Drawing::Size(120, 23);
               this->sortByProtocolButton->TabIndex = 1;
               this->sortByProtocolButton->Text = L"Сортировать по протоколу";
               this->sortByProtocolButton->UseVisualStyleBackColor = true;
               this->sortByProtocolButton->Click += gcnew System::EventHandler(this, &MyForm::sortByProtocolButton_Click);
               // 
               // sortByPathButton
               // 
               this->sortByPathButton->Location = System::Drawing::Point(12, 70);
               this->sortByPathButton->Name = L"sortByPathButton";
               this->sortByPathButton->Size = System::Drawing::Size(120, 23);
               this->sortByPathButton->TabIndex = 2;
               this->sortByPathButton->Text = L"Сортировать по пути";
               this->sortByPathButton->UseVisualStyleBackColor = true;
               this->sortByPathButton->Click += gcnew System::EventHandler(this, &MyForm::sortByPathButton_Click);
               // 
               // listBoxWebsites
               // 
               this->listBoxWebsites->FormattingEnabled = true;
               this->listBoxWebsites->Location = System::Drawing::Point(138, 12);
               this->listBoxWebsites->Name = L"listBoxWebsites";
               this->listBoxWebsites->Size = System::Drawing::Size(200, 173);
               this->listBoxWebsites->TabIndex = 3;
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(350, 200);
               this->Controls->Add(this->listBoxWebsites);
               this->Controls->Add(this->sortByPathButton);
               this->Controls->Add(this->sortByProtocolButton);
               this->Controls->Add(this->sortByDomainButton);
               this->Name = L"MyForm";
               this->Text = L"Website Manager";
               this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
               this->ResumeLayout(false);

           }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // Загрузка списка сайтов из файла
        std::vector<Website> websites;
        LoadWebsites(websites);
        for (const auto& website : websites) {
            listBoxWebsites->Items->Add(gcnew String(website.Url.c_str()));
        }
    }

    private: System::Void sortByDomainButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Сортировка и отображение сайтов по домену
        listBoxWebsites->Items->Clear();
        std::vector<Website> websites;
        LoadWebsites(websites);
        SortByDomain(websites);
        for (const auto& website : websites) {
            listBoxWebsites->Items->Add(gcnew String(website.Url.c_str()));
        }
    }

    private: System::Void sortByProtocolButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Сортировка и отображение сайтов по протоколу
        listBoxWebsites->Items->Clear();
        std::vector<Website> websites;
        LoadWebsites(websites);
        SortByProtocol(websites);
        for (const auto& website : websites) {
            listBoxWebsites->Items->Add(gcnew String(website.Url.c_str()));
        }
    }

    private: System::Void sortByPathButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Сортировка и отображение сайтов по пути
        listBoxWebsites->Items->Clear();
        std::vector<Website> websites;
        LoadWebsites(websites);
        SortByPath(websites);
        for (const auto& website : websites) {
            listBoxWebsites->Items->Add(gcnew String(website.Url.c_str()));
        }
    }
    };
}
