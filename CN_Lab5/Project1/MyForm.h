#pragma once
#include <windows.h>
#include <iphlpapi.h>
#include <iostream>

#pragma comment (lib, "IPHlpApi.Lib")
#define MALLOC(param) HeapAlloc(GetProcessHeap(), 0, (param))

namespace WinForms_CN {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Объявление класса формы
	public ref class ComputerNetworkForm : public System::Windows::Forms::Form
	{
		public:
		ComputerNetworkForm(void)
		{
			InitializeComponent();
		}
		protected:
		~ComputerNetworkForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private:
		//элементы пользовательского интерфейса
		System::Windows::Forms::Button^  ShowButton;
		System::Windows::Forms::TextBox^  ResultBox;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			//Создание элементов
			this->ShowButton = (gcnew System::Windows::Forms::Button());
			this->ResultBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			//Кнопка
			this->ShowButton->Location = System::Drawing::Point(12, 12);
			this->ShowButton->Name = L"ShowButton";
			this->ShowButton->Size = System::Drawing::Size(130, 23);
			this->ShowButton->TabIndex = 0;
			this->ShowButton->Text = L"Получить информацию";
			this->ShowButton->UseVisualStyleBackColor = true;
			//Присваиваем событию делеат функции
			this->ShowButton->Click += gcnew System::EventHandler(this, &ComputerNetworkForm::Show);
			this->ResultBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ResultBox->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultBox->Location = System::Drawing::Point(12, 41);
			this->ResultBox->Multiline = true;
			this->ResultBox->Name = L"ResultBox";
			this->ResultBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ResultBox->Size = System::Drawing::Size(400, 405);
			this->ResultBox->TabIndex = 1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 461);
			this->Controls->Add(this->ResultBox);
			this->Controls->Add(this->ShowButton);
			this->Name = L"MyForm";
			this->Text = L"Определение параметров сети";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
		String ^ addressToStr(BYTE* address) {
		String ^st;
		int max = sizeof(address) / sizeof(address[0]) + 2;
		for (int i = 0; i < max; i++)
		{
			char buff[4];
			if (i<max - 1)
				sprintf(buff, "%02x-", (unsigned char)address[i]);
			else
				sprintf(buff, "%02x", (unsigned char)address[i]);
			st = st + gcnew String(buff);
		}
		return st;
	}
		//Функция, выводящая информацию о сети
		System::Void Show(System::Object^  sender, System::EventArgs^  e) {
			ResultBox->Text += "*** Basic Network Settings ***\r\n";
			FIXED_INFO *pFixedInfo;
			ULONG ulOutBufLen;
			DWORD dwRetVal;
			IP_ADDR_STRING *pIPAddr;
			pFixedInfo = (FIXED_INFO *)MALLOC(sizeof(FIXED_INFO));
			ulOutBufLen = sizeof(FIXED_INFO);
			GetNetworkParams(pFixedInfo, &ulOutBufLen);

			ResultBox->Text += "1.Host Name.............." + gcnew String(pFixedInfo->HostName) + "\r\n";
			ResultBox->Text += "2.Domain Name............" + gcnew String(pFixedInfo->DomainName) + "\r\n";

			switch (pFixedInfo->NodeType) {
			case BROADCAST_NODETYPE:
				ResultBox->Text += "3.Net BIOS..............." + gcnew String("Broadcast") + "\r\n";
				break;
			case PEER_TO_PEER_NODETYPE:
				ResultBox->Text += "3.Net BIOS..............." + gcnew String("Peer to Peer") + "\r\n";
				break;
			case MIXED_NODETYPE:
				ResultBox->Text += "3.Net BIOS..............." + gcnew String("Mixed") + "\r\n";
				break;
			case HYBRID_NODETYPE:
				ResultBox->Text += "3.Net BIOS..............." + gcnew String("Hybrid") + "\r\n";
				break;
			}
			if (pFixedInfo->EnableRouting)
				ResultBox->Text += "4.Routing................Enabled\r\n";
			else
				ResultBox->Text += "4.Routing................Disabled\r\n";
			if (pFixedInfo->EnableProxy)
				ResultBox->Text += "5.Proxy..................Enabled\r\n";
			else
				ResultBox->Text += "5.Proxy..................Disabled\r\n";
			ResultBox->Text += "6.DNS Servers............" + gcnew String(pFixedInfo->DnsServerList.IpAddress.String) + "\r\n";

			ResultBox->Text += "*** Installed network adapters ***\r\n";

			PIP_ADAPTER_INFO pAdapterInfo;
			pAdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
			unsigned long buflen = sizeof(IP_ADAPTER_INFO);

			if (GetAdaptersInfo(pAdapterInfo, &buflen) == ERROR_BUFFER_OVERFLOW) {
				free(pAdapterInfo);
				pAdapterInfo = (IP_ADAPTER_INFO *)malloc(buflen);
			}

			if (GetAdaptersInfo(pAdapterInfo, &buflen) == NO_ERROR) {
				PIP_ADAPTER_INFO pAdapter = pAdapterInfo;
				while (pAdapter) {
					ResultBox->Text += "\r\n";
					ResultBox->Text += gcnew String(pAdapter->AdapterName) + "\r\n";
					ResultBox->Text += "1.Adapter Name..........." + gcnew String(pAdapter->AdapterName) + "\r\n";
					ResultBox->Text += "2.Adapter Description...." + gcnew String(pAdapter->Description) + "\r\n";
					ResultBox->Text += "3.Index.................." + pAdapter->Index.ToString() + "\r\n";
					ResultBox->Text += "4.MAC Address............" + addressToStr(pAdapter->Address) + "\r\n";
					ResultBox->Text += "5.Local IP Address......." + gcnew String(pAdapter->IpAddressList.IpAddress.String) + "\r\n";
					ResultBox->Text += "6.IP Mask................" + gcnew String(pAdapter->IpAddressList.IpMask.String) + "\r\n";
					ResultBox->Text += "7.Gateway................" + gcnew String(pAdapter->GatewayList.IpAddress.String) + "\r\n";
					if (pAdapter->DhcpEnabled) {
						ResultBox->Text += "DHCP....................." + "Enabled\r\n";
						if ((gcnew String(pAdapter->DhcpServer.IpAddress.String))->Length != 0) {
							ResultBox->Text += "DHCP Server.............." + gcnew String(pAdapter->DhcpServer.IpAddress.String) + "\r\n";
							struct tm newtime;
							char buffer[32];
							_localtime32_s(&newtime, (__time32_t*)&pAdapter->LeaseObtained);
							asctime_s(buffer, 32, &newtime);
							ResultBox->Text += "Lease Obtained..........." + gcnew String(buffer) + "\r\n";
							_localtime32_s(&newtime, (__time32_t*)&pAdapter->LeaseExpires);
							asctime_s(buffer, 32, &newtime);
							ResultBox->Text += "Lease Expires............" + gcnew String(buffer) + "\r\n";
						}
					}
					else {
						ResultBox->Text += "DHCP....................." + "Disabled\r\n";
					}
					pAdapter = pAdapter->Next;
				}
			}
			else {
				ResultBox->Text += "Call to GetAdaptersInfo failed.\r\n";
			}
		}
	};
}