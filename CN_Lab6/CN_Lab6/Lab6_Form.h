#pragma once
#include <windows.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "IPHLPAPI.lib")

namespace CN_Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;


	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(342, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ping";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 97);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(400, 349);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(342, 68);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(271, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"osu.ppy.sh";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(15, 71);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(106, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"50";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(177, 71);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(106, 20);
			this->textBox4->TabIndex = 5;
			this->textBox4->Text = L"8192";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Remote host name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Number of packages";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(176, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Package size";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 461);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"Lab_6 CN";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int numberOfPackages = int::Parse(textBox3->Text);
		int packageSize = int::Parse(textBox4->Text);

		int totalSum = 0;

		WSADATA wsaData;
		int iResult;
		struct hostent *remoteHost;
		char *host_name;
		struct in_addr addr;
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		String ^name = Convert::ToString(textBox2->Text);
		IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(name);
		host_name = static_cast<char*>(ptrToNativeString.ToPointer());
		remoteHost = gethostbyname(host_name);
		textBox1->Text += "HOSTNAME: " + gcnew String(host_name) + "\r\n";

		addr.s_addr = *(u_long *)remoteHost->h_addr_list[0];
		std::string ip_add = inet_ntoa(addr);
		textBox1->Text += "IP: " + gcnew String(inet_ntoa(addr)) + "\r\n";

		for (int i = 0; i < numberOfPackages; i++) {
			HANDLE hIcmpFile = IcmpCreateFile();
			if (hIcmpFile != INVALID_HANDLE_VALUE)
			{
				DWORD ReplySize = sizeof(ICMP_ECHO_REPLY) + packageSize;
				char *ReplyBuffer = new char[ReplySize];
				const int addr = inet_addr(ip_add.c_str());
				if (addr != INADDR_NONE) {
					if (IcmpSendEcho(hIcmpFile, addr, new char[packageSize], packageSize, 0, ReplyBuffer, ReplySize, 1000) != 0) {
						PICMP_ECHO_REPLY icmpReply = (PICMP_ECHO_REPLY)ReplyBuffer;
						totalSum += icmpReply->RoundTripTime;
					}
				}
				delete[]ReplyBuffer;
				IcmpCloseHandle(hIcmpFile);
			}
		}
		textBox1->Text += "Send packages: " + numberOfPackages + "\r\n";
		textBox1->Text += "Package size: " + packageSize + "\r\n";
		textBox1->Text += "Average ping: " + (double)totalSum / numberOfPackages + "\r\n";
		textBox1->Text += "*****************************************************\r\n\r\n";
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	};
}