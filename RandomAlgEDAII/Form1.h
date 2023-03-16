// Enunciado:
// Realizar un programa que 
// 
// Participantes:
// 1- John Luis Del Rosario Sánchez - ID 1106940
// 2- Ashly Marisell Paula Ynoa - ID 1108023
// 3- Elián Matos Díaz - ID 1106901
// 4- Juan Daniel Ubiera Méndez - ID 1107248
// 5- Kelvin Arístides García Espinal - ID 1107646
// 
// Fecha de entrega: 16/3/2023
// 
// Profesor: Casimiro Cordero

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

	protected:

	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;






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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
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
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->Location = System::Drawing::Point(507, 488);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 65);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->MinimumSize = System::Drawing::Size(740, 459);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(746, 472);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeChanged += gcnew System::EventHandler(this, &Form1::pictureBox1_SizeChanged);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSize = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 10);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(746, 472);
			this->panel1->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(764, 583);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(782, 630);
			this->Name = L"Form1";
			this->Text = L"RandomAlgth";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Drawing::Graphics^ g;

		// Punto medio en x.
	public: System::Int16 GetX(Rectangle circle, Rectangle circle4) {
		return (circle.X + circle4.X) / 2;
	}
		  //Punto medio en y.
	public: System::Int16 GetY(Rectangle circle, Rectangle circle4) {
		return (circle.Y + circle4.Y) / 2;
	}
		  //Crea el canva o gráfico para dibujar los triangulos.
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		g = pictureBox1->CreateGraphics();

	}
		   //Botones de iniciar y limpiar apagados, en caso de no haber seleccionado iniciar
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->Enabled = false;
		button2->Enabled = false;

		//Brochas que utilizamos para dibujar los circulos.
		Brush^ blueBrush = gcnew Drawing::SolidBrush(Color::Blue);
		Brush^ redBrush = gcnew Drawing::SolidBrush(Color::Red);
		Brush^ greenBrush = gcnew Drawing::SolidBrush(Color::Green);
		Brush^ cyanBrush = gcnew Drawing::SolidBrush(Color::Cyan);


		//Generador de las posiciones random.
		Random^ ran = gcnew Random();

		//Limites del canva, para que sea visible correctamente.
		Rectangle circle1(pictureBox1->Size.Width*0.1, pictureBox1->Size.Height -100, 10, 10);
		Rectangle circle2(pictureBox1->Size.Width * 0.9, pictureBox1->Size.Height -100, 10,10);
		
		// Punto medio del circulo 1 y circulo 2.
		int circle3X = (circle2.X + circle1.X) / 2;

		Rectangle circle3(circle3X, 50, 10, 10);
		Rectangle circle4(circle2.Location.X, circle2.Location.Y * 0.5, 6,6);

		//Llena los circulos.
		g->FillEllipse(greenBrush, circle1);
		g->FillEllipse(redBrush, circle2);
		g->FillEllipse(blueBrush, circle3);
		g->FillEllipse(cyanBrush, circle4);

		//Itera 10000 veces dentro del rango del canva establecido y dibuja con la funcion random
		for (int i = 0; i < 10000; i++) {
			int rnd = ran->Next(1, 4);
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
			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		button1->Enabled = true;
		button2->Enabled = true;
	}
		   //Boton de limpiar.
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Refresh();
	}
			//Crea un nuevo canva para que las coordenadas vayan acorde a la dimension de la ventana.
	private: System::Void pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		g = pictureBox1->CreateGraphics();
	}
		   //IGNORAR
		   /*Rectangle circle3((circle2.X+circle1.X)/2,circle1.X-RandKey + 10, 10, 10);*/
};
}
