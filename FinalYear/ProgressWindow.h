#pragma once

namespace FinalYear {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProgressWindow
	/// </summary>
	public ref class ProgressWindow : public System::Windows::Forms::Form
	{
	public:
		ProgressWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProgressWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	protected:
	private: System::Windows::Forms::Label^  label1;

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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(74, 90);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(452, 39);
			this->progressBar1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 10));
			this->label1->Location = System::Drawing::Point(154, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(302, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Working on it.......Please Wait......";
			// 
			// ProgressWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 188);
			this->ControlBox = false;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ProgressWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"In Progress";
			this->ResumeLayout(false);

		}
#pragma endregion

	public: ProgressBar^ getProgressBarInstance()
	{ 
				return progressBar1;
	}

	public: static ProgressWindow^ createProgressWindow()
	{
				ProgressWindow^ progress = gcnew ProgressWindow();
				progress->Show();
				return progress;
	}
	
	};
}
