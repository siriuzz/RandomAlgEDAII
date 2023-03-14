#pragma once
#include <random>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(740, 459);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(85, 488);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 65);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Iniciar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(507, 488);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 65);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(764, 583);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"RandomAlgth";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Drawing::Graphics^ g;

	public: System::Int16 GetX(Rectangle circle, Rectangle circle4) {
		return (circle.X + circle4.X) / 2;
	}

	public: System::Int16 GetY(Rectangle circle, Rectangle circle4) {
		return (circle.Y + circle4.Y) / 2;
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		g = pictureBox1->CreateGraphics();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->Enabled = false;
		button2->Enabled = false;


		Brush^ blueBrush = gcnew Drawing::SolidBrush(Color::Blue);
		Brush^ redBrush = gcnew Drawing::SolidBrush(Color::Red);
		Brush^ greenBrush = gcnew Drawing::SolidBrush(Color::Green);
		Brush^ cyanBrush = gcnew Drawing::SolidBrush(Color::Cyan);

		Random^ ran = gcnew Random();
		Random^ ran2 = gcnew Random();
		int RandKey = ran->Next(0, 100); //Generate random number  

		Rectangle circle1(145, 260, 8, 8);
		Rectangle circle2(445, 260, 8, 8);
		/*Rectangle circle3((circle2.X+circle1.X)/2,circle1.X-RandKey + 10, 10, 10);*/
		Rectangle circle3((circle2.X + circle1.X) / 2, 50, 8, 8);
		Rectangle circle4(90, 110, 8, 8);


		g->FillEllipse(greenBrush, circle1);
		g->FillEllipse(redBrush, circle2);
		g->FillEllipse(blueBrush, circle3);
		g->FillEllipse(cyanBrush, circle4);

		for (int i = 0; i < 10000; i++) {
			int rnd = ran2->Next(1, 4);
			if (rnd == 1) {
				circle4.X = GetX(circle1,circle4);
				circle4.Y = GetY(circle1,circle4);
			}

			if (rnd == 2) {
				circle4.X = GetX(circle2, circle4);
				circle4.Y = GetY(circle2, circle4);
			}

			if (rnd == 3) {
				circle4.X = GetX(circle3, circle4);
				circle4.Y = GetY(circle3, circle4);
			}

			g->FillEllipse(cyanBrush, circle4);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		button1->Enabled = true;
		button2->Enabled = true;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Refresh();
	}
	};
}
