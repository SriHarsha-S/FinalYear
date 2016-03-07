#pragma once
#include "Inclusions.h"
#include "MainForm.h"
#include "ChooseVideoType.h"
#include "ProgressWindow.h"

using namespace FinalYear;

/*void MainForm::trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {

if (trackBar1->Value == trackBar1->Maximum)
{
stop_video();
}
else
cap.set(CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
}*/

void MainForm::stop_video()
{
	cap.release();
	delete pictureBox1->Image;
	pictureBox1->Image = nullptr;
	timer1->Stop();
	StartBtn->Enabled = false;
	PauseBtn->Enabled = false;
	trackBar1->Enabled = false;
	StopBtn->Enabled = false;
	FileBtn->Enabled = true;
	WebCamBtn->Enabled = true;
	trackBar1->Value = 0;  trackBar1->Maximum = 0;
	textBox1->Text = "";
}

System::Void MainForm::PauseBtn_Click(System::Object^  sender, System::EventArgs^  e) {

	if (PauseBtn->Text == "Pause")
	{
		cap.release();
		PauseBtn->Text = "Continue";
		timer1->Stop();
	}
	else
	{
		char *fileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
		VideoCapture cap1(fileName); // open the default camera
		cap = cap1;
		if (!cap.isOpened())  // check if we succeeded
		{
			MessageBox::Show(this, "No capture", "Error!!!");
		}
		cap.set(CV_CAP_PROP_POS_FRAMES, trackBar1->Value + 1);
		timer1->Start();
		PauseBtn->Text = "Pause";
	}

}

System::Void MainForm::FileBtn_Click(System::Object^  sender, System::EventArgs^  e) {

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	vid_chosen = "file";
	PauseBtn->Text == "Pause";
	openFileDialog1->Filter = "Video files (*.mp4)|*.mp4|Video files (*.3gp)|*.3gp";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	openFileDialog1->FileName = "";
	haar_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");
	//haar_cascade.load("E:/Academics/8th sem/8th sem/Project/Other required things/body10/haarcascade_fullbody.xml");
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		char *fileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
		VideoCapture cap1(fileName); // open the default camera
		cap = cap1;
		if (!cap.isOpened())  // check if we succeeded
		{
			MessageBox::Show(this, "No capture", "Error!!!");
		}
		trackBar1->Minimum = 0;
		trackBar1->Maximum = (int)cap.get(CV_CAP_PROP_FRAME_COUNT);

		timer1->Interval = 1000 / cap.get(CV_CAP_PROP_FPS);
		//timer1->Start();

		FileBtn->Enabled = false;
		WebCamBtn->Enabled = false;
		StartBtn->Enabled = true;
		PauseBtn->Enabled = true;
		StopBtn->Enabled = true;
		trackBar1->Enabled = true;
		//std::cout << trackBar1->Maximum << "\n\n";

		(gcnew ChooseVideoType(this))->Show();
		this->Enabled = false;

	}
}

void MainForm::detectEntities() {

	         CompareImages();
			 Mat frame, edges;
			 std::string sing_frame;
			// std::cout << (int)cap.get(CV_CAP_PROP_FRAME_COUNT) << "\n";

			 this->Enabled = false;
			 
			 ProgressWindow^ progress = ProgressWindow::createProgressWindow();
			 ProgressBar^ pr_instance = progress->getProgressBarInstance();
			 pr_instance->Minimum = 0;
			 pr_instance->Maximum = (int)cap.get(CV_CAP_PROP_FRAME_COUNT);
			 Mat other_img;

			 for (int i = 0; i < (int)cap.get(CV_CAP_PROP_FRAME_COUNT); i++)
			 {
				 pr_instance->Value = i;
				 cap >> frame; // get a new frame from camera

				 std::vector< Rect_<int> > faces;
				 haar_cascade.detectMultiScale(frame, faces);

				 sing_frame = "";
				 for (int j = 0; j < faces.size(); j++) {
					 // Process face by face:

					 Rect face_i = faces[j];
					 sing_frame += std::to_string(face_i.x) + "," + std::to_string(face_i.y) +
						 "," + std::to_string(face_i.width) + "," + std::to_string(face_i.height) + ";";

					 /*if (i == 18){
						 other_img = frame(Rect(face_i.x, face_i.y, face_i.width, face_i.height));
						 imwrite("E:/Academics/image1.jpg", other_img);
					 }
					 else if (i == 21)
					 {
						 other_img = frame(Rect(face_i.x, face_i.y, face_i.width, face_i.height));
						 imwrite("E:/Academics/image2.jpg", other_img);
					 }
					 else if (i == 45)
					 {
						 other_img = frame(Rect(face_i.x, face_i.y, face_i.width, face_i.height));
						 imwrite("E:/Academics/image3.jpg", other_img);
					 }
					 else if (i == 40)
					 {
							 other_img = frame(Rect(face_i.x, face_i.y, face_i.width, face_i.height));
							 imwrite("E:/Academics/image4.jpg", other_img);
					 }*/
				 }
				 rect_points.push_back(sing_frame);
				// std::cout << rect_points[i] << "\n";
			 }

			 //std::cout << rect_points.size() << "\n";
			 /*for (int i = 0; i < 200; i++)
			     std::cout << i << ":- " << rect_points[i] << "\n";*/
			 progress->Close();
			 this->Enabled = true;
			 //MessageBox::Show(this, "Finished", "Error!!!");
			 cap.set(CV_CAP_PROP_POS_FRAMES, -1);
			 timer1->Start();


            }

 void MainForm::setVideoType(System::String^ text)
{
			//MessageBox::Show(this, "Hi", "Error!!!");
			//this->BringToFront();
			videotype = text;
			if (videotype == "Only Video")
				timer1->Start();
			else
			{
				detectEntities();
			}
}

 void MainForm::CompareImages()
 {
	 Mat src_base, hsv_base;
	 Mat src_test1, hsv_test1;
	 Mat src_test2, hsv_test2;
	


	 src_base = imread("E:/Academics/image6.jpg", 1);
	 src_test1 = imread("E:/Academics/image2.jpg", 1);
	 src_test2 = imread("E:/Academics/image3.jpg", 1);

	 /// Convert to HSV
	 cvtColor(src_base, hsv_base, COLOR_BGR2HSV);
	 cvtColor(src_test1, hsv_test1, COLOR_BGR2HSV);
	 cvtColor(src_test2, hsv_test2, COLOR_BGR2HSV);

	 

	 /// Using 50 bins for hue and 60 for saturation
	 int h_bins = 50; int s_bins = 60;
	 int histSize[] = { h_bins, s_bins };

	 // hue varies from 0 to 179, saturation from 0 to 255
	 float h_ranges[] = { 0, 180 };
	 float s_ranges[] = { 0, 256 };

	 const float* ranges[] = { h_ranges, s_ranges };

	 // Use the o-th and 1-st channels
	 int channels[] = { 0, 1 };


	 /// Histograms
	 MatND hist_base;
	 MatND hist_half_down;
	 MatND hist_test1;
	 MatND hist_test2;

	 /// Calculate the histograms for the HSV images
	 calcHist(&hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
	 normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());

	 calcHist(&hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
	 normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat());

	 calcHist(&hsv_test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false);
	 normalize(hist_test2, hist_test2, 0, 1, NORM_MINMAX, -1, Mat());

	 /// Apply the histogram comparison methods
	 
		
		 double base_base = compareHist(hist_base, hist_base, 0);
		 double base_test1 = compareHist(hist_base, hist_test1, 0);
		 double base_test2 = compareHist(hist_base, hist_test2, 0);

		 std::cout << base_base << " , " << base_test1 << " , " << base_test2 << ";\n";
	 

	 
 }


