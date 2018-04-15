#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

void drawTriangle()
{
	glBegin(GL_TRIANGLES);//�izim yapmaya ba�layaca��m�z�, ve �izece�imiz �ekli belirtiyoruz bu sat�rda. 
	glColor3f(1.0f, 1.0f, 1.0f);//3 paremetre alan bu fonksiyonun paremetreleri red, green, blue�dur. 0-1 aras� de�erler vererek istedi�imiz rengi se�ebiliriz.
	glVertex2f(0.0f, 0.5);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);//�izece�imiz �eklin noktalar�n� belirtmek i�in kullan�r�z.
	glEnd();//End fonksiyonuyla �izimimiz bitiyor.

}

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "OpenGL Odevi", sf::Style::Default, sf::ContextSettings(32));//Sfml k�t�phanesinde varl�klar� �izmemiz i�in �zel pencere s�n�f� tan�m�
	window.setVerticalSyncEnabled(true);//Dikey senkronizasyonu etkinle�tirir veya devre d��� b�rak�r.

	window.setActive(true);//Pencereyi OpenGL olu�turma i�in ge�erli hedef olarak etkinle�tirir veya devre d��� b�rak�r.

	bool running = true;
	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))//Etkinli�i, varsa etkinlik d�ng�s�n�n �st�ne getirir ve d�nd�r�r.
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;//Etkinlik kapat�ld���nda d�ng�den ��kar
			}
			else if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);//Etkinlik penceresinin boyutunu yeniden ayarlanabilir k�lar.
			}
		}

		
		glClearColor(0.3f, 0.3f, 0.3f, 1.f);//Renk arabelleklerini temizlemek i�in glClear taraf�ndan kullan�lan k�rm�z�, ye�il, mavi ve alfa de�erlerini belirtir.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//OpenGL renk ve derinlik tamponlar�n� temizler.

		glMatrixMode(GL_PROJECTION);//Projeksiyon matrisi, d�nya koordinat �er�evesindeki nesneleri g�r�nt�leyen kameran�n �zelliklerini tan�mlar. Burada tipik olarak zoom fakt�r�n�, en boy oran�n� ve yak�n ve uzak k�rpma d�zlemlerini ayarlar.
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//Pikselle�tirme i�in �okgenlerin yorumlanmas�n� kontrol eder.

		glLoadIdentity();//Bu fonksiyon ile birim matris haf�zaya y�klenir.
		sf::Vector2u wsize = window.getSize();//Pencerenin olu�turma b�lgesinin boyutunu al�r.
		glViewport(0, 0, wsize.x, wsize.y);

		glMatrixMode(GL_MODELVIEW);//ModelView bakt���m�z noktay� temsil eden matristir (pozisyon, i�aret ve yukar� vekt�r).
		glLoadIdentity();
		glPushMatrix();//�st matrisi kopyalar ve stack'in �st�ne iter

		glRotatef(50, 10.f, 10.f, 0.f);//D�nd�rme fonksiyonu

		drawTriangle();

		glPopMatrix();//�st matrisi stack'ten al�r.

		window.display();//Ekran g�r�nt�lenir.
	}

	return EXIT_SUCCESS;
}