#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(256, 256), "TagGame");

	// Создание и загрузка текстуры
	Texture texture;
	texture.loadFromFile("Images/15.png");

	// Размер стороны одного квадратного блока составляет 64 пикселя
	int blockWidht = 64;

	// Логическое представление игрового поля
	int grid[6][6] = { 0 };

	// Массив спрайтов
	Sprite sprite[17];


	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			n++;
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(IntRect(i * blockWidht, j * blockWidht, blockWidht, blockWidht));
			grid[i + 1][j + 1] = n;
		}
	}
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
			{
				// тогда закрываем его
				window.close();
			}

		}
		// Устанавливаем цвет фона - белый
		window.clear(Color::White);

		// Установка каждого спрайта на свое место + Отрисовка спрайта
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// Считываем значение ячейки игрового поля…
				int n = grid[i + 1][j + 1];
				// …и устанавливаем на нее соответствующий спрайт
				sprite[n].setPosition(i * blockWidht, j * blockWidht);
				// Отрисовка спрайта
				window.draw(sprite[n]);
			}
		}
		// Отрисовка окна
		window.display();
	}

	return 0;
}