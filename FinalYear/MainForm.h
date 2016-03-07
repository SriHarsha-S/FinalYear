#pragma once
#include "Inclusions.h"

namespace FinalYear {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace cv;
	static VideoCapture cap;
	static CascadeClassifier haar_cascade;
	static std::vector<std::string> rect_points;


	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  WebCamBtn;
	private: System::Windows::Forms::Button^  FileBtn;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  StopBtn;
	private: System::Windows::Forms::Button^  PauseBtn;
	private: System::Windows::Forms::Button^  StartBtn;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	private:  System::String^ vid_chosen;
			  System::String^ videotype;



			  /// <summary>
			  /// Required designer variable.
			  /// </summary>



#pragma region Windows Form Designer generated code
			  /// <summary>
			  /// Required method for Designer support - do not modify
			  /// the contents of this method with the code editor.
			  /// </summary>
			  void InitializeComponent(void)
			  {
				  this->components = (gcnew System::ComponentModel::Container());
				  this->panel1 = (gcnew System::Windows::Forms::Panel());
				  this->WebCamBtn = (gcnew System::Windows::Forms::Button());
				  this->FileBtn = (gcnew System::Windows::Forms::Button());
				  this->label1 = (gcnew System::Windows::Forms::Label());
				  this->panel2 = (gcnew System::Windows::Forms::Panel());
				  this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				  this->panel3 = (gcnew System::Windows::Forms::Panel());
				  this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				  this->label2 = (gcnew System::Windows::Forms::Label());
				  this->StopBtn = (gcnew System::Windows::Forms::Button());
				  this->PauseBtn = (gcnew System::Windows::Forms::Button());
				  this->StartBtn = (gcnew System::Windows::Forms::Button());
				  this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
				  this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				  this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				  this->panel1->SuspendLayout();
				  this->panel2->SuspendLayout();
				  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				  this->panel3->SuspendLayout();
				  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
				  this->SuspendLayout();
				  // 
				  // panel1
				  // 
				  this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				  this->panel1->Controls->Add(this->WebCamBtn);
				  this->panel1->Controls->Add(this->FileBtn);
				  this->panel1->Controls->Add(this->label1);
				  this->panel1->Location = System::Drawing::Point(61, 15);
				  this->panel1->Margin = System::Windows::Forms::Padding(4);
				  this->panel1->Name = L"panel1";
				  this->panel1->Size = System::Drawing::Size(866, 121);
				  this->panel1->TabIndex = 0;
				  // 
				  // WebCamBtn
				  // 
				  this->WebCamBtn->Location = System::Drawing::Point(543, 55);
				  this->WebCamBtn->Margin = System::Windows::Forms::Padding(4);
				  this->WebCamBtn->Name = L"WebCamBtn";
				  this->WebCamBtn->Size = System::Drawing::Size(176, 46);
				  this->WebCamBtn->TabIndex = 2;
				  this->WebCamBtn->Text = L"Open WebCam";
				  this->WebCamBtn->UseVisualStyleBackColor = true;
				  this->WebCamBtn->Click += gcnew System::EventHandler(this, &MainForm::WebCamBtn_Click);
				  // 
				  // FileBtn
				  // 
				  this->FileBtn->Location = System::Drawing::Point(155, 55);
				  this->FileBtn->Margin = System::Windows::Forms::Padding(4);
				  this->FileBtn->Name = L"FileBtn";
				  this->FileBtn->Size = System::Drawing::Size(188, 46);
				  this->FileBtn->TabIndex = 1;
				  this->FileBtn->Text = L"Choose from file";
				  this->FileBtn->UseVisualStyleBackColor = true;
				  this->FileBtn->Click += gcnew System::EventHandler(this, &MainForm::FileBtn_Click);
				  // 
				  // label1
				  // 
				  this->label1->AutoSize = true;
				  this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 10));
				  this->label1->Location = System::Drawing::Point(24, 16);
				  this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				  this->label1->Name = L"label1";
				  this->label1->Size = System::Drawing::Size(340, 20);
				  this->label1->TabIndex = 0;
				  this->label1->Text = L"Choose a method of Video Selection  :";
				  this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
				  // 
				  // panel2
				  // 
				  this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				  this->panel2->Controls->Add(this->pictureBox1);
				  this->panel2->Location = System::Drawing::Point(61, 161);
				  this->panel2->Margin = System::Windows::Forms::Padding(4);
				  this->panel2->Name = L"panel2";
				  this->panel2->Size = System::Drawing::Size(866, 397);
				  this->panel2->TabIndex = 1;
				  // 
				  // pictureBox1
				  // 
				  this->pictureBox1->Location = System::Drawing::Point(-1, -1);
				  this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
				  this->pictureBox1->Name = L"pictureBox1";
				  this->pictureBox1->Size = System::Drawing::Size(867, 398);
				  this->pictureBox1->TabIndex = 0;
				  this->pictureBox1->TabStop = false;
				  // 
				  // panel3
				  // 
				  this->panel3->Controls->Add(this->textBox1);
				  this->panel3->Controls->Add(this->label2);
				  this->panel3->Controls->Add(this->StopBtn);
				  this->panel3->Controls->Add(this->PauseBtn);
				  this->panel3->Controls->Add(this->StartBtn);
				  this->panel3->Controls->Add(this->trackBar1);
				  this->panel3->Location = System::Drawing::Point(50, 566);
				  this->panel3->Margin = System::Windows::Forms::Padding(4);
				  this->panel3->Name = L"panel3";
				  this->panel3->Size = System::Drawing::Size(902, 126);
				  this->panel3->TabIndex = 2;
				  // 
				  // textBox1
				  // 
				  this->textBox1->Location = System::Drawing::Point(701, 71);
				  this->textBox1->Margin = System::Windows::Forms::Padding(4);
				  this->textBox1->Name = L"textBox1";
				  this->textBox1->ReadOnly = true;
				  this->textBox1->Size = System::Drawing::Size(132, 22);
				  this->textBox1->TabIndex = 5;
				  
				  // 
				  // label2
				  // 
				  this->label2->AutoSize = true;
				  this->label2->Location = System::Drawing::Point(633, 74);
				  this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				  this->label2->Name = L"label2";
				  this->label2->Size = System::Drawing::Size(59, 17);
				  this->label2->TabIndex = 4;
				  this->label2->Text = L"Time  :  ";
				  
				  // 
				  // StopBtn
				  // 
				  this->StopBtn->Enabled = false;
				  this->StopBtn->Location = System::Drawing::Point(437, 68);
				  this->StopBtn->Margin = System::Windows::Forms::Padding(4);
				  this->StopBtn->Name = L"StopBtn";
				  this->StopBtn->Size = System::Drawing::Size(100, 28);
				  this->StopBtn->TabIndex = 3;
				  this->StopBtn->Text = L"Stop";
				  this->StopBtn->UseVisualStyleBackColor = true;
				  this->StopBtn->Click += gcnew System::EventHandler(this, &MainForm::StopBtn_Click);
				  // 
				  // PauseBtn
				  // 
				  this->PauseBtn->Enabled = false;
				  this->PauseBtn->Location = System::Drawing::Point(229, 68);
				  this->PauseBtn->Margin = System::Windows::Forms::Padding(4);
				  this->PauseBtn->Name = L"PauseBtn";
				  this->PauseBtn->Size = System::Drawing::Size(147, 28);
				  this->PauseBtn->TabIndex = 2;
				  this->PauseBtn->Text = L"Pause";
				  this->PauseBtn->UseVisualStyleBackColor = true;
				  this->PauseBtn->Click += gcnew System::EventHandler(this, &MainForm::PauseBtn_Click);
				  // 
				  // StartBtn
				  // 
				  this->StartBtn->Enabled = false;
				  this->StartBtn->Location = System::Drawing::Point(51, 68);
				  this->StartBtn->Margin = System::Windows::Forms::Padding(4);
				  this->StartBtn->Name = L"StartBtn";
				  this->StartBtn->Size = System::Drawing::Size(100, 28);
				  this->StartBtn->TabIndex = 1;
				  this->StartBtn->Text = L"Start";
				  this->StartBtn->UseVisualStyleBackColor = true;
				  
				  // 
				  // trackBar1
				  // 
				  this->trackBar1->Enabled = false;
				  this->trackBar1->Location = System::Drawing::Point(0, 21);
				  this->trackBar1->Margin = System::Windows::Forms::Padding(4);
				  this->trackBar1->Name = L"trackBar1";
				  this->trackBar1->Size = System::Drawing::Size(886, 56);
				  this->trackBar1->TabIndex = 0;
				  this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainForm::trackBar1_Scroll);
				  // 
				  // timer1
				  // 
				  this->timer1->Interval = 30;
				  this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
				  // 
				  // MainForm
				  // 
				  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				  this->ClientSize = System::Drawing::Size(1019, 738);
				  this->Controls->Add(this->panel3);
				  this->Controls->Add(this->panel2);
				  this->Controls->Add(this->panel1);
				  this->Margin = System::Windows::Forms::Padding(4);
				  this->MaximizeBox = false;
				  this->Name = L"MainForm";
				  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				  this->Text = L"Entity Recognizer";
				  this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
				  this->panel1->ResumeLayout(false);
				  this->panel1->PerformLayout();
				  this->panel2->ResumeLayout(false);
				  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				  this->panel3->ResumeLayout(false);
				  this->panel3->PerformLayout();
				  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
				  this->ResumeLayout(false);

			  }
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void PauseBtn_Click(System::Object^  sender, System::EventArgs^  e);

	
	
	private: System::Void WebCamBtn_Click(System::Object^  sender, System::EventArgs^  e) {

				 vid_chosen = "webcam";
				 VideoCapture cap1(0); // open the default camera
				 cap = cap1;
				 if (!cap.isOpened())  // check if we succeeded
				 {
					 MessageBox::Show(this, "No capture", "Error!!!");
				 }
				 StartBtn->Enabled = false;
				 PauseBtn->Enabled = false;
				 StopBtn->Enabled = true;
				 trackBar1->Enabled = false;
				 FileBtn->Enabled = false;
				 WebCamBtn->Enabled = false;
				 timer1->Start();

				 haar_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml");

	}
	private: System::Void StopBtn_Click(System::Object^  sender, System::EventArgs^  e) {

				 stop_video();
	}


	private:  std::vector<std::string> split(std::string str, char delimiter) {
						 std::vector<std::string> internal;
						 std::stringstream ss(str); // Turn the string into a stream.
						 std::string tok;

				         while (getline(ss, tok, delimiter)) {
					           internal.push_back(tok);
				         }

				 return internal;
             }

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 
				 if (vid_chosen == "file" && trackBar1->Value == trackBar1->Maximum)
				 {
					 //std::cout << "Inside";
					 stop_video();
				 }
				 else
				 {
					 //std::cout << trackBar1->Value << "\n";
					 
					 Mat frame, edges;
					 cap >> frame; // get a new frame from camera

					 if (vid_chosen == "file") {
						 trackBar1->Value = (int)cap.get(CV_CAP_PROP_POS_FRAMES);
						 textBox1->Text = (TimeSpan::FromMilliseconds(cap.get(CV_CAP_PROP_POS_MSEC)).ToString())->Substring(0, 8);
						 //std::cout << trackBar1->Value << "\n";

						 if (videotype == "Video With Entity Recognition")
						 {

							 std::string faces = rect_points[trackBar1->Value - 1];
							 //std::cout << "1\n";

							 std::vector<std::string> ind_line;

							 ind_line = split(faces, ';');
							 std::vector<std::string> ind_face;
							 int x1, y1, x2, y2;
							 for (int i = 0; i < ind_line.size(); i++)
							 {
								 ind_face = split(ind_line[i], ',');
								 x1 = std::stoi(ind_face[0]);
								 y1 = std::stoi(ind_face[1]);
								 x2 = x1 + std::stoi(ind_face[2]);
								 y2 = y1 + std::stoi(ind_face[3]);
								 cv::Point p1(x1, y1);
								 cv::Point p2(x2, y2);
								 Rect_<int> r1(p1, p2);
								 rectangle(frame, r1, CV_RGB(0, 255, 0), 1);
							 }
						 }

					 }
					 else
					 {
						 std::vector< Rect_<int> > faces;
						 haar_cascade.detectMultiScale(frame, faces);

						 for (int i = 0; i < faces.size(); i++) {
							 // Process face by face:
							 Rect face_i = faces[i];

							 rectangle(frame, face_i, CV_RGB(0, 255, 0), 1);
						 }
					 }

					 System::Drawing::Graphics^ graphics2 = pictureBox1->CreateGraphics();
					 System::IntPtr ptr2(frame.ptr());
					 System::Drawing::Bitmap^ b2 = gcnew System::Drawing::Bitmap(frame.cols,
						 frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
					 System::Drawing::RectangleF rect2(0, 0, pictureBox1->Width, pictureBox1->Height);
					 graphics2->DrawImage(b2, rect2);					 
						 
				 }
				 
	}

	private: System::Void FileBtn_Click(System::Object^  sender, System::EventArgs^  e); 

	private: void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {

				 if (trackBar1->Value == trackBar1->Maximum)
				 {
					 stop_video();
				 }
				 else
					 cap.set(CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
	}

	private:  void stop_video();

	public: void setVideoType(System::String^ text);
	

	private: void detectEntities();
	private: void CompareImages();

	};

	

}
