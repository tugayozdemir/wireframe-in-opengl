#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

void drawTriangle()
{
	glBegin(GL_TRIANGLES);//Çizim yapmaya baþlayacaðýmýzý, ve çizeceðimiz þekli belirtiyoruz bu satýrda. 
	glColor3f(1.0f, 1.0f, 1.0f);//3 paremetre alan bu fonksiyonun paremetreleri red, green, blue’dur. 0-1 arasý deðerler vererek istediðimiz rengi seçebiliriz.
	glVertex2f(0.0f, 0.5);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);//Çizeceðimiz þeklin noktalarýný belirtmek için kullanýrýz.
	glEnd();//End fonksiyonuyla çizimimiz bitiyor.

}

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "OpenGL Odevi", sf::Style::Default, sf::ContextSettings(32));//Sfml kütüphanesinde varlýklarý çizmemiz için özel pencere sýnýfý tanýmý
	window.setVerticalSyncEnabled(true);//Dikey senkronizasyonu etkinleþtirir veya devre dýþý býrakýr.

	window.setActive(true);//Pencereyi OpenGL oluþturma için geçerli hedef olarak etkinleþtirir veya devre dýþý býrakýr.

	bool running = true;
	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))//Etkinliði, varsa etkinlik döngüsünün üstüne getirir ve döndürür.
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;//Etkinlik kapatýldýðýnda döngüden çýkar
			}
			else if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);//Etkinlik penceresinin boyutunu yeniden ayarlanabilir kýlar.
			}
		}

		
		glClearColor(0.3f, 0.3f, 0.3f, 1.f);//Renk arabelleklerini temizlemek için glClear tarafýndan kullanýlan kýrmýzý, yeþil, mavi ve alfa deðerlerini belirtir.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//OpenGL renk ve derinlik tamponlarýný temizler.

		glMatrixMode(GL_PROJECTION);//Projeksiyon matrisi, dünya koordinat çerçevesindeki nesneleri görüntüleyen kameranýn özelliklerini tanýmlar. Burada tipik olarak zoom faktörünü, en boy oranýný ve yakýn ve uzak kýrpma düzlemlerini ayarlar.
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//Pikselleþtirme için çokgenlerin yorumlanmasýný kontrol eder.

		glLoadIdentity();//Bu fonksiyon ile birim matris hafýzaya yüklenir.
		sf::Vector2u wsize = window.getSize();//Pencerenin oluþturma bölgesinin boyutunu alýr.
		glViewport(0, 0, wsize.x, wsize.y);

		glMatrixMode(GL_MODELVIEW);//ModelView baktýðýmýz noktayý temsil eden matristir (pozisyon, iþaret ve yukarý vektör).
		glLoadIdentity();
		glPushMatrix();//Üst matrisi kopyalar ve stack'in üstüne iter

		glRotatef(50, 10.f, 10.f, 0.f);//Döndürme fonksiyonu

		drawTriangle();

		glPopMatrix();//Üst matrisi stack'ten alýr.

		window.display();//Ekran görüntülenir.
	}

	return EXIT_SUCCESS;
}