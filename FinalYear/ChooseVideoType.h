#pragma once
#include "MainForm.h"

namespace FinalYear {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChooseVideoType
	/// </summary>
	public ref class ChooseVideoType : public System::Windows::Forms::Form
	{
	public:
		ChooseVideoType(MainForm^ frm)
		{
			formInstance = frm;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChooseVideoType()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Button^  button1;
			 MainForm^ formInstance;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 10));
			this->label1->Location = System::Drawing::Point(52, 44);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(324, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Choose one of the following options:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Verdana", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(78, 99);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(187, 24);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->Text = L"Play Normal Video";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Verdana", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(78, 147);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(394, 24);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Text = L"Play Video with entity recognition enabled";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(501, 224);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 51);
			this->button1->TabIndex = 4;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChooseVideoType::button1_Click);
			// 
			// ChooseVideoType
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 345);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label1);
			this->Name = L"ChooseVideoType";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ChooseVideoType";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ChooseVideoType::ChooseVideoType_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 

				/* if (radioButton1->Checked == true || radioButton2->Checked == true) 
					 this->Close();
				 else
					 MessageBox::Show(this, "Please select an option", "Error!!!");*/
				 formInstance->Enabled = true;
				 formInstance->BringToFront();
				 if (radioButton1->Checked == true) {
					 formInstance->setVideoType("Only Video"); this->Close();
				 }
				 else if (radioButton2->Checked == true) {
					 formInstance->setVideoType("Video With Entity Recognition"); this->Close();
				 }
				 else
					 MessageBox::Show(this, "Please select an option", "Error!!!"); 

				 
				
	}
private: System::Void ChooseVideoType_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

			/* formInstance->Enabled = true;
			 if (radioButton1->Checked == true)
				 formInstance->setVideoType("Only Video");
			 else
				 formInstance->setVideoType("Video With Entity Recognition");*/
}
};
}
